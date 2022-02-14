#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaIdoso.h"
#include "Idoso.h"


struct celIdoso{
  Idoso *idoso;
  CelIdoso *prox;
};

struct listIdoso{
  CelIdoso *prim;
  CelIdoso *ult;
};

struct listAmigos{
  CelIdoso *prim;
  CelIdoso *ult;
};


ListIdoso* inicializaListIdoso(char* arquivo){
  ListIdoso* lista = (ListIdoso*)malloc(sizeof(ListIdoso));
  lista->prim = NULL;
  lista->ult = NULL;

  // Abre o arquivo para leitura

  FILE *fp = fopen(arquivo, "r");
  char conteudo[70];

   if (fp == NULL){
    printf("Nao foi possivel abrir o arquivo. %s.\n", arquivo);
  }

  // Pega informa��es somente da primeira linha

  fscanf(fp, "%[^\n]\n", conteudo);

  char* nome = strtok(conteudo, ";");

  while( nome != NULL ) {
        insereIdoso(lista, criaIdoso(nome));

        nome = strtok(NULL, ";");
  }

  // Agora trabalhando com as informa��es(linhas) restantes



  fscanf(fp, "%[^EOF]", conteudo);
  char aux1[100], aux2[100];
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




void insereAmizade(ListIdoso *listIdoso, char* amigo1, char* amigo2){
  Idoso *idoso1, *idoso2;
  ListAmigos *listAmigos1, *listAmigos2;

  idoso1 = buscaIdoso(listIdoso, amigo1);
  idoso2 = buscaIdoso(listIdoso, amigo2);

  listAmigos1 = retornaListAmigosIdoso(idoso1);
  listAmigos2 = retornaListAmigosIdoso(idoso2);

  insereAmigoNaLista(listAmigos1, idoso2);
  insereAmigoNaLista(listAmigos2, idoso1);

}


void insereAmigoNaLista(ListAmigos *lista, Idoso *amigo){
    CelIdoso* nova = (CelIdoso*)malloc(sizeof(CelIdoso));
    nova->idoso = amigo;
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
      printf("Idoso n�o encontrado\n");
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
        destroiIdoso(p->idoso);////////
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


void imprimeListAmigos(ListAmigos *listAmigos){
  CelIdoso* p;
  int i = 1;
  printf("LISTA DE AMIGOS:\n");
  for (p = listAmigos->prim; p != NULL; p = p->prox, i++){
    printf("Amigo %d: ", i);
    printf("%s\n", retornaNomeIdoso(p->idoso));
  }
}







