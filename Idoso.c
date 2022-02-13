#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Idoso.h"


struct idoso{
  char *nome;
  ListAmigos *amigos;
  //ListCuidador *cuidadores;
  int latitude;
  int longitude;
  float temperatura;
  int queda;
};

Idoso* criaIdoso(char *nome){
  Idoso* idoso = (Idoso*)malloc(sizeof(Idoso));

  idoso->nome = strdup(nome);

  idoso->amigos = CriaListAmigos();
  idoso->latitude = 0;
  idoso->longitude = 0;
  idoso->temperatura = 0;
  idoso->queda = 0;

  return idoso;
}

char *retornaNomeIdoso(Idoso *idoso){
  return idoso->nome;
}

ListAmigos *retornaListAmigosIdoso(Idoso *idoso){
  return idoso->amigos;
}

//ListCuidadores *retornaListCuidadores(Idoso *idoso){
  //return idoso->cuidadores;
//}

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
}

