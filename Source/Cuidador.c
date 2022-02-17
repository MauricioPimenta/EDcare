#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cuidador.h"



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

char* retornaNomeCuidador(Cuidador* cuidador){
  return cuidador->nome;
}

float retornaLatitudeCuidador(Cuidador* cuidador){
  return cuidador->Latitude;
}

float retornaLongitudeCuidador(Cuidador* cuidador){
  return cuidador->Longitude;
}

void InsereMedidasCuidador(Cuidador* cuidador, int linhaArquivo, char* arquivo){

    FILE *fp = fopen(arquivo, "r");

    if(fp == NULL){
        printf("Erro no arquivo de medidas de %s\n.", retornaNomeCuidador(cuidador));
        return NULL;
    }

    if(linhaArquivo == 1){
        char linha[1000];
        fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
        char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

        int k = 0;  //auxilia na inserção das medidas nos campos corretos através das condicoes
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
            fscanf(fp, "%[^\n]\n", linha);  //le até a ultima linha antes da linha de interesse
        }

        fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
        char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

        int k = 0;  //auxilia na inserção das medidas nos campos corretos através das condicoes
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

void destroiCuidador(Cuidador* cuidador){
  free(cuidador->nome);
  free(cuidador);
}

void imprimeCuidador(Cuidador* cuidador){
  printf("\nNome: %s\n", cuidador->nome);
  printf("Posicao: %0.2f,%0.2f\n\n", cuidador->Latitude, cuidador->Longitude);
}

