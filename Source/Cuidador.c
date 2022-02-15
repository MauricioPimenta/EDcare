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

