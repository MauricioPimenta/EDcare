#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Idoso.h"
#include "Cuidador.h"
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

  return idoso;
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
    FILE* fp = fopen(arquivo, "r");

    if(fp == NULL){
        printf("Arquivo invalido.\n");
    }

    char conteudo[10000];
    fscanf(fp, "%[^\n]\n", conteudo);  //fazendo isso para ignorar a primeira linha

    fscanf(fp, "%[^EOF]", conteudo);  //lendo da segunda linha ate o final

    char* nomes = strtok(conteudo, "\n");
    char nomeIdoso[10000], nomeCuidador[10000];

    int i, j;

    while(nomes != NULL){
        for(i = 0; nomes[i] != ';'; i++){
        nomeIdoso[i] = nomes[i];
        }
        nomeIdoso[i] = '\0';

        //parei aqui------------------------------------------------------------------------------------------------------ erro abaixo, nesta função
        for(i += 1, j = 0; nomes[i] != '\n'; i++, j++){  //pelo que to pensando nao contempla o ultimo cuidador da linha
            if(nomes[i] == ';'){
                nomeCuidador[j] = '\0';


                Idoso* idoso = buscaIdoso(listaIdoso, nomeIdoso);
                Cuidador* cuidador = buscaCuidador(listaCuidador, nomeCuidador);

                InsereCuidadorNoIdoso(idoso, cuidador);

                j = 0;
            }
            else{
                nomeCuidador[j] = nomes[i];
            }
        }
        nomes = strtok(NULL, "\n");
    }
}



void InsereCuidadorNoIdoso(Idoso* idoso, Cuidador* cuidador){
    CelCuidador* nova = (CelCuidador*)malloc(sizeof(CelCuidador));
    nova->cuidador = cuidador;
    nova->prox = NULL;

    if(idoso->cuidadores->prim == NULL){
      idoso->cuidadores->prim = nova;
      idoso->cuidadores->ult = nova;
    }

    else{
      CelCuidador *p = idoso->cuidadores->prim;

      while(p->prox != NULL){
        p = p->prox;
      }
      p->prox = nova;
      idoso->cuidadores->ult = nova;
    }
}










void InsereMedidasIdoso(Idoso* idoso, int linhaArquivo, char* arquivo){

    FILE *fp = fopen(arquivo, "r");

    if(fp == NULL){
        printf("Erro no arquivo de medidas de %s.\n", retornaNomeIdoso(idoso));
    }

    if(linhaArquivo == 1){
        char linha[100];
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
        char linha[100];
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
  //destroiListCuidadores(idoso->cuidadores);
  //destroiListaAmigos(idoso->amigos);

  free(idoso);
}

void imprimeIdoso(Idoso* idoso){
  printf("Nome: %s\n", idoso->nome);
  //imprimeListCuidadores(idoso->cuidadores);
  imprimeListAmigos(idoso->amigos);
  printf("%f, %f, %f, %i", idoso->temperatura, idoso->latitude, idoso->longitude, idoso->queda);
}

