#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Idoso.h"

struct idoso{
  char *nome;
  ListAmigos *amigos;
  ListCuidador *cuidadores;
};

Idoso* criaIdoso(char *nome){
  Idoso* idoso = (Idoso*)malloc(sizeof(Idoso));
  idoso->nome = strdup(nome);
  idoso->cuidadores = inicializaListCuidadores();
  idoso->amigos = inicializaListaAmigo();

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

void destroiIdoso(Idoso *idoso){
  free(idoso->nome);
  destroiListCuidadores(idoso->cuidadores);
  destroiListaAmigos(idoso->amigos);

  free(idoso);
}

void imprimeIdoso(Idoso* idoso){
  printf("Nome: %s\n", idoso->nome);
  imprimeListCuidadores(idoso->cuidadores);
  imprimeListAmigos(idoso->amigos);
}


