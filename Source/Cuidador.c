/*
 * INCLUSAO DE BIBLIOTECAS
 */

// BIBLIOTECAS PADRÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BIBLIOTECAS DO USUÁRIO
#include "Cuidador.h"

/*
 * Definição da Estrutura do TAD Cuidador
 */
struct cuidador{
  char *nome;
  float Latitude;
  float Longitude;
};

Cuidador* criaCuidador(char* nome){

	// Alloca espaço para o cuidador
	Cuidador* cuidador = (Cuidador*)malloc(sizeof(Cuidador));

	// Alloca espaço para o nome do cuidador
  	cuidador->nome = strdup(nome);

  	cuidador->Latitude = 0;
  	cuidador->Longitude = 0;

  return cuidador;
}



/*****************************************************
 *
 * FUNCOES GET - RETORNAM UM ATRIBUTO DO CUIDADOR
 * 
 *****************************************************/

/*
 * Retorna o Nome do Cuidador
 */
char* getNomeCuidador(Cuidador* cuidador){
  return cuidador->nome;
}

/*
 * Retorna a Latitude do Cuidador
 */
int getLatitudeCuidador(Cuidador* cuidador){
  return cuidador->Latitude;
}

/*
 * Retorna a Longitude do Cuidador
 */
int getLongitudeCuidador(Cuidador* cuidador){
  return cuidador->Longitude;
}


/*****************************************************
 *
 * FUNCOES SET - MODIFICAM UM ATRIBUTO DO IDOSO
 * 
 ****************************************************/

/*
 * Modifca a Latitude do Cuidador
 */
void setLatitudeCuidador(Cuidador* c, float lat){
	c->Latitude = lat;
}

/*
 * Modifca a Longitude do Cuidador
 */
void setLongitudeCuidador(Cuidador* c, float l){
	c->Longitude = l;
}




//  Funcao que libera memoria alocada para o cuidador
//  inputs: ponteiro para a estrutura cuidador
//  output: nenhum
//  pre-condicao: Cuidador existe
//  pos-condicao: toda a memoria alocada para cuidador foi liberada
void destroiCuidador(Cuidador* cuidador){
  free(cuidador->nome);
  free(cuidador);
}


//  Imprime cuidador
//  inputs: ponteiro para cuidador
//  output: nenhum
//  pre-condicao: cuidador existe
//  pos-condicao: cuidador nao e alterado
void imprimeCuidador(Cuidador* cuidador){
  printf("\nNome: %s\n", cuidador->nome);
  printf("Posicao: %0.2f,%0.2f\n\n", cuidador->Latitude, cuidador->Longitude);

}

void InsereMedidasCuidador(Cuidador* cuidador, int linhaArquivo, char* arquivo){

    FILE *fp = fopen(arquivo, "r");

    if(fp == NULL){
        printf("Erro no arquivo de medidas de %s\n.", getNomeCuidador(cuidador));
        return;
    }

    if(linhaArquivo == 1){
        char linha[1000];
        fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
        char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

        int k = 0;  //auxilia na inser��o das medidas nos campos corretos atrav�s das condicoes
        while(medida != NULL){
            k++;
            if(k == 1){
                cuidador->Latitude = atof(medida);
            }
            else{
                cuidador->Longitude = atof(medida);
            }

            medida = strtok(NULL, ";");
        }
    }
    else{
        char linha[1000];
        int i;
        for(i = 0; i < linhaArquivo - 1; i++){
            fscanf(fp, "%[^\n]\n", linha);  //le at� a ultima linha antes da linha de interesse
        }

        fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
        char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

        int k = 0;  //auxilia na inser��o das medidas nos campos corretos atrav�s das condicoes
        while(medida != NULL){
            k = k + 1;
            if(k == 1){
                cuidador->Latitude = atof(medida);
            }
            else{
                cuidador->Longitude = atof(medida);
            }

            medida = strtok(NULL, ";");
        }
    }

    fclose(fp);
}