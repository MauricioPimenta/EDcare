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

/*****************************************************
 *
 * FUNCOES GET - RETORNAM UM ATRIBUTO DO IDOSO
 * 
 *****************************************************/

//  Retorna o nome do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: nome do idoso
//  pre-condicao: idoso existe
//  pos-condicao: idoso nao é modificado e nome do idoso disponível
char *getNomeIdoso(Idoso *idoso){
  return idoso->nome;
}

//  Retorna Lista de amigos do idoso
//  inputs: ponteiro para estrutura Idoso
//  output: ponteiro para estrutura ListAmigos
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é alterado e lista de amigos disponível
ListAmigos *getListAmigosIdoso(Idoso *idoso){
  return idoso->amigos;
}

//  Retona a lista de cuidadores do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: ponteiro para a estrutura ListCuidadores
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e estrutura dos cuidadores disponível
ListCuidador *getListCuidadores(Idoso *idoso){
  return idoso->cuidadores;
}


float getLatitudeIdoso(Idoso *idoso){
	return idoso->latitude;
}

float getLongitudeIdoso(Idoso *idoso){
	return idoso->longitude;
}

float getTemperaturaIdoso(Idoso* idoso){
	return idoso->temperatura;
}

int getQuedaIdoso(Idoso* idoso){
	return idoso->queda;
}

int getNumFebresBaixas(Idoso* idoso){
	return idoso->numFebresBaixas;
}


/*****************************************************
 *
 * FUNCOES SET - MODIFICAM UM ATRIBUTO DO IDOSO
 * 
 */

void setLatitudeIdoso(Idoso *idoso, float l){
	idoso->latitude = l;
}

void setLongitudeIdoso(Idoso *idoso, float l){
	idoso->longitude = l;
}

void setTemperaturaIdoso(Idoso* idoso, float temp){
	idoso->temperatura = temp;
}

void setQuedaIdoso(Idoso* idoso, int q){
	idoso->queda = q;
}

int getNumFebresBaixas(Idoso* idoso){
	return idoso->numFebresBaixas;
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







void LeLinhaCuidadorNoIdoso(char* arquivo, ListIdoso* listaIdoso, ListCuidador* listaCuidador){
    // FILE* fp = fopen(arquivo, "r");

    // if(fp == NULL){
    //     printf("Arquivo invalido.\n");
    // }

    // char conteudo[10000];
    // fscanf(fp, "%[^\n]\n", conteudo);  //fazendo isso para ignorar a primeira linha

    // fscanf(fp, "%[^EOF]", conteudo);  //lendo da segunda linha ate o final

    // char* nomes = strtok(conteudo, "\n");
    // char nomeIdoso[10000], nomeCuidador[10000];

    // int i, j;

    // while(nomes != NULL){
    //     for(i = 0; nomes[i] != ';'; i++){
    //     nomeIdoso[i] = nomes[i];
    //     }
    //     nomeIdoso[i] = '\0';

    //     //parei aqui------------------------------------------------------------------------------------------------------ erro abaixo, nesta função
    //     for(i += 1, j = 0; nomes[i] != '\n'; i++, j++){  //pelo que to pensando nao contempla o ultimo cuidador da linha
    //         if(nomes[i] == ';'){
    //             nomeCuidador[j] = '\0';


    //             Idoso* idoso = buscaIdoso(listaIdoso, nomeIdoso);
    //             Cuidador* cuidador = buscaCuidador(listaCuidador, nomeCuidador);

    //             InsereCuidadorNoIdoso(idoso, cuidador);

    //             j = 0;
    //         }
    //         else{
    //             nomeCuidador[j] = nomes[i];
    //         }
    //     }
    //     nomes = strtok(NULL, "\n");
    // }
}



void InsereCuidadorNoIdoso(Idoso* idoso, Cuidador* cuidador){
    // CelCuidador* nova = criaCuidador();
    // nova->cuidador = cuidador;
    // nova->prox = NULL;

    // if(idoso->cuidadores->prim == NULL){
    //   idoso->cuidadores->prim = nova;
    //   idoso->cuidadores->ult = nova;
    // }

    // else{
    //   CelCuidador *p = idoso->cuidadores->prim;

    //   while(p->prox != NULL){
    //     p = p->prox;
    //   }
    //   p->prox = nova;
    //   idoso->cuidadores->ult = nova;
    // }
}










void InsereMedidasIdoso(Idoso* idoso, int linhaArquivo, char* arquivo){

    // FILE *fp = fopen(arquivo, "r");

    // if(fp == NULL){
    //     printf("Erro no arquivo de medidas de %s.\n", getNomeIdoso(idoso));
    // }

    // if(linhaArquivo == 1){
    //     char linha[100];
    //     fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
    //     char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

    //     int k = 0;  //auxilia na inserção das medidas nos campos corretos através das condicoes
    //     while(medida != NULL){
    //         k++;
    //         if(k == 1){
    //             idoso->temperatura = atof(medida);
    //         }
    //         else if(k == 2){
    //             idoso->latitude = atof(medida);
    //         }
    //         else if(k == 3){
    //             idoso->longitude = atof(medida);
    //         }
    //         else{
    //             idoso->queda = atoi(medida);
    //         }

    //         medida = strtok(NULL, ";");
    //     }
    // }
    // else{
    //     char linha[100];
    //     int i;
    //     for(i = 0; i < linhaArquivo - 1; i++){
    //         fscanf(fp, "%[^\n]\n", linha);  //le até a ultima linha antes da linha de interesse
    //     }

    //     fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
    //     char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

    //     int k = 0;  //auxilia na inserção das medidas nos campos corretos através das condicoes
    //     while(medida != NULL){
    //         k++;
    //         if(k == 1){
    //             idoso->temperatura = atof(medida);
    //         }
    //         else if(k == 2){
    //             idoso->latitude = atof(medida);
    //         }
    //         else if(k == 3){
    //             idoso->longitude = atof(medida);
    //         }
    //         else{
    //             idoso->queda = atoi(medida);
    //         }

    //         medida = strtok(NULL, ";");
    //     }
    // }

    // fclose(fp);
}


