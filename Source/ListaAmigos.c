/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaAmigos.h"
#include "Idoso.h"

struct celAmigos{
  Idoso *idoso;
  CelAmigos *prox;
};

struct listAmigos{
  CelAmigos *prim;
  CelAmigos *ult;
};

ListAmigos *inicializaListaAmigo(void){
  ListAmigos *listAmigos = (ListAmigos*) malloc(sizeof(ListAmigos));
  listAmigos->prim = NULL;
  listAmigos->ult = NULL;
  return listAmigos;
}

void insereAmigoNaLista(ListAmigos *lista, Idoso *amigo){
  CelAmigos* nova = (CelAmigos*)malloc(sizeof(CelAmigos));
    nova->idoso = amigo;
    nova->prox = NULL;

    if(lista->prim == NULL){
      lista->prim = nova;
      lista->ult = nova;
    }
    else{
      CelAmigos *p = lista->prim;

      while(p->prox != NULL){
        p = p->prox;
      }
      p->prox = nova;
      lista->ult = nova;
    }
}

void insereAmizade(ListIdoso *listIdoso, char* amigo1, char* amigo2){
  Idoso *idoso1, *idoso2;
  ListAmigos *listAmigos1, *listAmigos2;

  idoso1 = buscaIdoso(listIdoso, amigo1);
  idoso2 = buscaIdoso(listIdoso, amigo2);

  listAmigos1 = getListAmigosIdoso(idoso1);
  listAmigos2 = getListAmigosIdoso(idoso2);

  insereAmigoNaLista(listAmigos1, idoso2);
  insereAmigoNaLista(listAmigos2, idoso1);

}

Idoso* buscaAmigoPorNome(ListAmigos* lista, char* nome){
  CelAmigos* p = lista->prim;
    while (p != NULL && strcmp(getNomeIdoso(p->idoso), nome)){
        p = p->prox;
    }
    if(p != NULL){
      return p->idoso;
    }
    return NULL;
}

void imprimeListAmigos(ListAmigos *listAmigos){
  CelAmigos* p;
  int i = 1;
  printf("LISTA DE AMIGOS:\n");
  for (p = listAmigos->prim; p != NULL; p = p->prox, i++){
    printf("Amigo %d: ", i);
    printf("%s\n", getNomeIdoso(p->idoso));
  }
}

void destroiListaAmigos(ListAmigos *listAmigos){
  CelAmigos* p;
  CelAmigos* t;

  p = listAmigos->prim;
  while(p != NULL){
    t = p->prox;
    free(p);
    p = t;
  }

  free(listAmigos);
}
 */