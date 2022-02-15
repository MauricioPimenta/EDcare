/*
 * INCLUSAO DE BIBLIOTECAS
 */

// BIBLIOTECAS PADRÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> //Diretorio
#include <sys/stat.h> //Diretorio

// BIBLIOTECAS DO USUÁRIO
#include "ListaCuidadores.h"


/*
 * Definição das Estruturas do TAD ListaCuidadores
 */
struct celCuidador
{
    Cuidador* cuidador;
    CelCuidador *prox;
};

struct listCuidador
{
    CelCuidador *prim;
    CelCuidador *ult;
};


//  Funcao que inicializa a lista de cuidadores
//  inputs: nenhum
//  output: ponteiro para a estrutura ListCuidador
//  pre-condicao: nenhuma
//  pos-condicao: ponteiro de retorno existe e esta alocado
ListCuidador* novaListaCuidador(){
  ListCuidador* lista = (ListCuidador*)malloc(sizeof(ListCuidador));

  lista->prim = NULL;
  lista->ult = NULL;

  return lista;
}

//  Libera memoria alocada para a lista de cuidadores
//  inputs: ponteiro para a estrutura ListCuidador
//  output: nenhum
//  pre-condicao: ListCuidador precisa existir
//  pos-condicao: toda a memoria alocada para ListCuidador foi liberada
void destroiListCuidador(ListCuidador *lista){
  CelCuidador* p;
  CelCuidador* t;

  p = lista->prim;
  while(p != NULL){
        t = p->prox;
        destroiCuidador(p->cuidador);
        free(p);
        p = t;
    }

  free(lista);
}




/***********************************************************
 *
 * FUNCOES GET - RETORNAM UM ATRIBUTO DA LISTA DE CUIDADORES
 * 
 ***********************************************************/

Cuidador* getCuidadorDaCelula(CelCuidador* p){
  return p->cuidador;
}

CelCuidador *getProximoCuidador(CelCuidador *p){
  return p->prox;
}

CelCuidador *getPrimeiroCuidador(ListCuidador *lista){
  return lista->prim;
}




/***********************************************************
 *
 * FUNCOES SET - INSEREM UM ATRIBUTO DA LISTA DE CUIDADORES
 * 
 ***********************************************************/


CelCuidador* insereCuidador (ListCuidador* lista, char* nome){
  CelCuidador* nova = (CelCuidador*)malloc(sizeof(CelCuidador));
  nova->cuidador = criaCuidador(nome);
  nova->prox = NULL;

  if(lista->prim == NULL){
      lista->prim = nova;
      lista->ult = nova;
    }
  else{
    CelCuidador *p = lista->prim;
    while(p->prox != NULL){
      p = p->prox;
    }
    p->prox = nova;
    lista->ult = nova;
  }

  return nova;
}

void insereNovoCuidador(ListCuidador* lista, Cuidador *cuidador){
    CelCuidador* nova = (CelCuidador*)malloc(sizeof(CelCuidador));
    nova->cuidador = cuidador;
    nova->prox = lista->prim;

    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}



void retiraCuidadorDaLista(ListCuidador* lista, CelCuidador* cuidador){
  CelCuidador* p = lista->prim;
  CelCuidador* anterior = NULL;

    while (p != NULL && p != cuidador){
        anterior = p;
        p = p->prox;
    }

    if(p == NULL){
      printf("Item n�o encontrado.\n");
      exit(1);
    }

    if (p == lista->prim && p == lista->ult){
        lista->prim = NULL;
        lista->ult = NULL;
    }
    else if (p == lista->prim){
        lista->prim = p->prox;
    }
    else if (p == lista->ult){
        lista->ult = anterior;
        lista->ult->prox = NULL;
    }
    else{
        anterior->prox = p->prox;
    }

    destroiCuidador(p->cuidador);

    free(p);
}

Cuidador* buscaCuidador(ListCuidador* lista, char* nome){
  CelCuidador* p = lista->prim;
    while (p != NULL && strcmp(getNomeCuidador(p->cuidador), nome)){
        p = p->prox;
    }
    if(p != NULL){
      return p->cuidador;
    }
    return NULL;
}

CelCuidador* buscaCuidadorERetornaCelula(ListCuidador* lista, char* nome){
  CelCuidador* p = lista->prim;
    while (p != NULL && strcmp(getNomeCuidador(p->cuidador), nome)){
        p = p->prox;
    }
    if(p != NULL){
      return p;
    }
    return NULL;
}


void imprimeListCuidador(ListCuidador* lista){
  CelCuidador* p;
  int i = 1;
  printf("LISTA DE CUIDADORES:\n");
  for (p = lista->prim; p != NULL; p = p->prox, i++){
    printf("Cuidador %d\n", i);
    imprimeCuidador(p->cuidador);
  }
}
