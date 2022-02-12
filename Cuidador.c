#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cuidador.h"

struct cuidador{
  char *nome;
  int Latitude;
  int Longitude;
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

int retornaLatitude(Cuidador* cuidador){
  return cuidador->Latitude;
}

int retornaLongitude(Cuidador* cuidador){
  return cuidador->Longitude;
}

void destroiCuidador(Cuidador* cuidador){
  free(cuidador->nome);
  free(cuidador);
}

void imprimeCuidador(Cuidador* cuidador){
  printf("\nNome: %s\n", cuidador->nome);
  printf("Posição: %d,%d\n\n", cuidador->Latitude, cuidador->Longitude);
  
}
