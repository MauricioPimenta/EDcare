#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Idoso.h"
#include "ListaCuidadores.h"



struct idoso{
  char *nome;
  ListAmigos *amigos;
  ListCuidador *cuidadores;
  float latitude;
  float longitude;
  float temperatura;
  int queda;
  int numFebresBaixas;
  //char *strFileIn;
  //char *strFileOut;
  //FILE *fileIn;
  //FILE *fileOut;
};

Idoso* criaIdoso(char *nome){
  Idoso* idoso = (Idoso*)malloc(sizeof(Idoso));
  idoso->nome = strdup(nome);
  idoso->amigos = CriaListAmigos();
  idoso->cuidadores = inicializaListaCuidador();
  idoso->latitude = 0;
  idoso->longitude = 0;
  idoso->temperatura = 0;
  idoso->queda = 0;
  idoso->numFebresBaixas = 0;
  //idoso->strFileIn = strcat(nome, ".txt");
  //idoso->strFileOut = strcat(nome, "-saida.txt");

  return idoso;
}

void increaseNumFebresBaixas(Idoso* idoso){
    idoso->numFebresBaixas++;
}

float retornaTemperatura(Idoso* idoso){
    return idoso->temperatura;
}

int retornaNumFebresBaixas(Idoso* idoso){
    return idoso->numFebresBaixas;
}

void setNumFebresBaixas(Idoso* idoso, int febres){
		idoso->numFebresBaixas = febres;
}

float retornaLatitudeIdoso(Idoso* idoso){
    return idoso->latitude;
}

float retornaLongitudeIdoso(Idoso* idoso){
    return idoso->longitude;
}

int retornaQueda(Idoso* idoso){
    return idoso->queda;
}

char *retornaNomeIdoso(Idoso *idoso){
  return idoso->nome;
}

ListAmigos *retornaListAmigosIdoso(Idoso *idoso){
  return idoso->amigos;
}

ListCuidador *retornaListCuidadores(Idoso *idoso){
  return idoso->cuidadores;
}


void LeLinhaCuidadorNoIdoso(char* arquivo, ListIdoso* listaIdoso, ListCuidador* listaCuidador){
    // Abre o arquivo para leitura
    FILE *fp = fopen(arquivo, "r");
    char conteudo[10000];


    if (fp == NULL){
        printf("Nao foi possivel abrir o arquivo. %s\n", arquivo);
        destroiListCuidador(listaCuidador);
        // Exit Status -2 -> Arquivo de entrada dos cuidadores não encontrado
    }

    // Pega informacoes somente da primeira linha
    fscanf(fp, "%[^\n]\n", conteudo);

    /*
    * Lê o restante do arquivo e armazena os cuidadores de cada idoso
    */
    fscanf(fp, "%[^EOF]", conteudo);  //lendo da segunda linha ate o final

    // Armazena a linha
    char* nomes = strtok(conteudo, "\n");

    // Variaveis para armazenar os nomes
    char nomeIdoso[10000], nomeCuidador[10000];

    while(nomes != NULL){
        int i, j;
        // armazena o nome do idoso na linha
        for(i = 0; nomes[i] != ';'; i++){
            nomeIdoso[i] = nomes[i];
        }

        // Adiciona terminador de string ao nome do idoso
        nomeIdoso[i] = '\0';

        // coloca o indice no proximo nome
        i++;

        /* Le os nomes dos cuidadores e os acrescenta à lista do idoso */

        // for() indo do nome do primeiro cuidador depois do idoso até o final da linha
        for(j = 0; nomes[i] != '\0'; i++){
            // se acaba o nome do cuidador, busca ele na lista de cuidadores cadastrados
            // e cadastra ele na lista de cuidadores do idoso
            if(nomes[i] == ';'){

                // no lugar do ";" coloca '\0' pra terminar o nome do cuidador corretamente
                nomeCuidador[j] = '\0';

                // identifica o idoso e o cuidador já cadastrados
                Idoso* idoso = buscaIdoso(listaIdoso, nomeIdoso);
                Cuidador* cuidador = buscaCuidador(listaCuidador, nomeCuidador);

                // Insere o cuidador na lista de cuidadores do idoso
                insereNovoCuidador(retornaListCuidadores(idoso), cuidador);

                j = 0;  //zerando j para preencher um novo nome de cuidador
            }
            else{
                nomeCuidador[j] = nomes[i];
                j++;
            }
        }
        //só entra aqui se for o ultimo cuidador, para colocar '\0' e inserir o respectivo cuidador no respectivo idoso
        if(nomes[i] == '\0'){
				        // no lugar do "\n" coloca '\0' pra terminar o nome do cuidador corretamente
            nomeCuidador[j] = '\0';

            // identifica o idoso e o cuidador já cadastrados
            Idoso* idoso = buscaIdoso(listaIdoso, nomeIdoso);
            Cuidador* cuidador = buscaCuidador(listaCuidador, nomeCuidador);

            // Insere o cuidador na lista de cuidadores do idoso
            insereNovoCuidador(retornaListCuidadores(idoso), cuidador);
        }

        nomes = strtok(NULL, "\n");
    }

    fclose(fp);
}



int ContadorDeTokensLinha(char* linha){
    int cont = 0;
    char* a = strtok(linha, ";");

    while(a != NULL){
        a = strtok(NULL, ";");
        cont++;
    }
    return cont;
}


void InsereMedidasIdoso(Idoso* idoso, int linhaArquivo, char* arquivo){

    FILE *fp = fopen(arquivo, "r");

    if(fp == NULL){
        printf("Erro no arquivo de medidas de %s.\n", retornaNomeIdoso(idoso));
        return ;
    }
    if(linhaArquivo == 1){
        char linha[1000];
        fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
        char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

        int k = 0;  //auxilia na inserção das medidas nos campos corretos através das condicoes
        while(medida != NULL){
            k++;
            if(k == 1){
                idoso->temperatura = atof(medida);
            }
            else if(k == 2){
                idoso->latitude = atof(medida);
            }
            else if(k == 3){
                idoso->longitude = atof(medida);
            }
            else{
                idoso->queda = atoi(medida);
            }

            medida = strtok(NULL, ";");
        }
    }
    else{
        char linha[1000];
        int i;
        for(i = 0; i < linhaArquivo - 1; i++){
            fscanf(fp, "%[^\n]\n", linha);  //le até a ultima linha antes da linha de interesse
        }

        fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
        char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

        int k = 0;  //auxilia na inserção das medidas nos campos corretos através das condicoes
        while(medida != NULL){
            k++;
            if(k == 1){
                idoso->temperatura = atof(medida);
            }
            else if(k == 2){
                idoso->latitude = atof(medida);
            }
            else if(k == 3){
                idoso->longitude = atof(medida);
            }
            else{
                idoso->queda = atoi(medida);
            }

            medida = strtok(NULL, ";");
        }
    }

    fclose(fp);
}


void destroiIdoso(Idoso *idoso){
  free(idoso->nome);
  destroiListCuidador(idoso->cuidadores);
  destroiListIdoso(idoso->amigos);

  free(idoso);
}

void imprimeIdoso(Idoso* idoso){
  printf("Nome: %s\n", idoso->nome);
  printf("----------MEDIDAS:----------\n");
  printf("Temperatura: %.2f;\nLatitude: %.2f;\nLongitude: %.2f;\nQueda: %i.\n", idoso->temperatura, idoso->latitude, idoso->longitude, idoso->queda);
  imprimeListCuidador(idoso->cuidadores);
  imprimeListAmigos(idoso->amigos);
}


float calculaDistancia(float lat1, float long1, float lat2, float long2){
        float resultado = sqrt(pow(fabs(lat1 - lat2), 2) + pow(fabs(long1 - long2), 2));
        return resultado;
    }

