#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaIdoso.h"


struct celIdoso{
  Idoso *idoso;
  CelIdoso *prox;
};

struct listIdoso{
  CelIdoso *prim;
  CelIdoso *ult;
};


ListIdoso* inicializaListIdoso(char* arquivo){
  ListIdoso* lista = (ListIdoso*)malloc(sizeof(ListIdoso));
  lista->prim = NULL;
  lista->ult = NULL;

  CelIdoso* p = lista->prim;

  // Abre o arquivo para leitura

  FILE *fp = fopen(arquivo, "r");
  char conteudo[70];

   if (fp == NULL){
    printf("Nao foi possivel abrir o arquivo. %s\n", arquivo);
  }

  // Pega informações somente da primeira linha

  fscanf(fp, "%[^\n]\n", conteudo);

  char* nome = strtok(conteudo, ";");

  while( nome != NULL ) {
        insereIdoso(lista, criaIdoso(nome));

        nome = strtok(NULL, ";");
  }

  // Agora trabalhando com as informações(linhas) restantes

  char aux1[40], aux2[40];

  fscanf(fp, "%[^EOF]", conteudo);
  int i = 0;
  int j = 0;
  nome = strtok(conteudo, "\n");
//pegando o primeiro nome da linha
  while (nome != NULL){
        for (i = 0; nome[i] != ';'; i++){ //pegando o primeiro nome da linha
            aux1[i] = nome[i];
        }
        aux1[i] = '\0';
        for (i += 1, j = 0; nome[i] != '\0'; i++, j++){ //pegando o segundo nome da linha
            aux2[j] = nome[i];
        }
        aux2[j] = '\0';

      insereAmizade(lista, aux1, aux2);
      nome = strtok(NULL, "\n");
  }

  fclose(fp);

  lista->ult->prox = NULL;

  return lista;
}



// Insere idoso na lista
void insereIdoso(ListIdoso* lista, Idoso *idoso){
    CelIdoso* nova = (CelIdoso*)malloc(sizeof(CelIdoso));
    nova->idoso = idoso;
    nova->prox = NULL;

    if(lista->prim == NULL){
      lista->prim = nova;
      lista->ult = nova;
    }
    else{
      CelIdoso *p = lista->prim;

      while(p->prox != NULL){
        p = p->prox;
      }
      p->prox = nova;
      lista->ult = nova;
    }
}


// Retira idoso da lista
void retiraIdoso(ListIdoso* lista, char *nome){
  CelIdoso* p = lista->prim;
  CelIdoso* ant = NULL;

    while (p != NULL && strcmp(retornaNomeIdoso(p->idoso), nome)){
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
      printf("Idoso não encontrado\n");
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
        lista->ult = ant;
        lista->ult->prox = NULL;
    }
    else{
        ant->prox = p->prox;
    }

    destroiIdoso(p->idoso);
    free(p);

}



Idoso *buscaIdoso(ListIdoso *lista, char *nome){
    CelIdoso* p = lista->prim;
    while (p != NULL && strcmp(retornaNomeIdoso(p->idoso), nome)){
        p = p->prox;
    }
    return p->idoso;
}



CelIdoso *retornaPrimeiro(ListIdoso* lista){
  return lista->prim;
}



CelIdoso *retornaUltimo(ListIdoso* lista){
  return lista->ult;
}



CelIdoso *retornaProximo(CelIdoso* p){
  return p->prox;
}



Idoso *retornaIdosoCelula(CelIdoso* p){
  return p->idoso;
}



void destroiListIdoso(ListIdoso* lista){
  CelIdoso* p;
  CelIdoso* t;

  p = lista->prim;
  while(p != NULL){
        t = p->prox;
        destroiIdoso(p->idoso);
        free(p);
        p = t;
    }

  free(lista);
}



void imprimeListIdoso(ListIdoso* lista){
  CelIdoso* p;
  int i = 1;
  for (p = lista->prim; p != NULL; p = p->prox, i++){
    printf ("Idoso %d:\n", i);
    imprimeIdoso(p->idoso);
    printf("\n");
  }
}










