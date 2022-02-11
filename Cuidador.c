#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cuidador.h"

struct cuidador{
  char *nome;
  ListMedidasCuidador *medidas;
};

Cuidador* criaCuidador(char* nome){
  Cuidador* cuidador = (Cuidador*)malloc(sizeof(Cuidador));
  cuidador->nome = strdup(nome);
  cuidador->medidas = inicializaListMedidas();

  return cuidador;
}

char* retornaNomeCuidador(Cuidador* cuidador){
  return cuidador->nome;
}

ListMedidas* retornaListMedidas(Cuidador* cuidador){
  return cuidador->medidas;
}

void destroiCuidador(Cuidador* cuidador){
  destroiListMedidas(cuidador->medidas);
  free(cuidador->nome);
  free(cuidador);
}

void imprimeCuidador(Cuidador* cuidador){
  printf("Nome: %s\n", cuidador->nome);
  imprimeListMedidas(cuidador->medidas);
}


