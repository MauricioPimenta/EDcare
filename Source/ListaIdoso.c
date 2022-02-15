/*
 * INCLUSAO DE BIBLIOTECAS
 */


// BIBLIOTECAS PADRÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BIBLIOTECAS DO USUÁRIO
#include "ListaIdoso.h"
#include "Idoso.h"

/*
 * Definição daS EstruturaS do TAD ListaIdoso
 */
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

ListIdoso* CriaListaIdoso()
{
	ListIdoso* lista = (ListIdoso*)malloc(sizeof(ListIdoso));
	lista->prim = NULL;
	lista->ult = NULL;
	return lista;
}

/***********************************************************
 *
 * FUNCOES GET - RETORNAM UM ATRIBUTO DA LISTA DE CUIDADORES
 * 
 ***********************************************************/
CelIdoso *getPrimeiro(ListIdoso* lista){
  return lista->prim;
}

CelIdoso *getUltimo(ListIdoso* lista){
  return lista->ult;
}

CelIdoso *getProximo(CelIdoso* p){
  return p->prox;
}

Idoso *getIdosoCelula(CelIdoso* p){
  return p->idoso;
}


/***********************************************************
 *
 * FUNCOES SET - ATRIBUEM UM ATRIBUTO DA LISTA DE CUIDADORES
 * 
 ***********************************************************/

void setAmizade(ListIdoso *listIdoso, char* amigo1, char* amigo2){
  Idoso *idoso1, *idoso2;
  ListAmigos *listAmigos1, *listAmigos2;

  idoso1 = buscaIdoso(listIdoso, amigo1);
  idoso2 = buscaIdoso(listIdoso, amigo2);

  listAmigos1 = getListAmigosIdoso(idoso1);
  listAmigos2 = getListAmigosIdoso(idoso2);

  setAmigoNaLista(listAmigos1, idoso2);
  setAmigoNaLista(listAmigos2, idoso1);

}

void setAmigoNaLista(ListAmigos *lista, Idoso *amigo){
    CelIdoso* nova = (CelIdoso*)malloc(sizeof(CelIdoso));
    nova->idoso = amigo;
    nova->prox = NULL;

	if (lista == NULL)
	{
		lista = (ListAmigos*)malloc(sizeof(ListAmigos));
		lista->prim = NULL;
		lista->ult = NULL;
	}


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
void setIdoso(ListIdoso* lista, Idoso *idoso){
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






/* ListIdoso* CriaListaIdoso()
{
	ListIdoso* lista = (ListIdoso*)malloc(sizeof(ListIdoso));
	lista->prim = NULL;
	lista->ult = NULL;
	return lista;
} */

ListAmigos* CriaListAmigos(void){
    ListAmigos* lista = (ListAmigos*)malloc(sizeof(ListAmigos));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

ListIdoso* inicializaListIdoso(char* arquivo){
  ListIdoso* lista = (ListIdoso*)malloc(sizeof(ListIdoso));
  lista->prim = NULL;
  lista->ult = NULL;

  // Abre o arquivo para leitura

  FILE *fp = fopen(arquivo, "r");
  char conteudo[10000];

   if (fp == NULL){
    printf("Nao foi possivel abrir o arquivo. %s.\n", arquivo);
  }

  // Pega informações somente da primeira linha

  fscanf(fp, "%[^\n]\n", conteudo);

  char* nome = strtok(conteudo, ";");

  while( nome != NULL ) {
        setIdoso(lista, criaIdoso(nome));

        nome = strtok(NULL, ";");
  }

  // Agora trabalhando com as informações(linhas) restantes

  fscanf(fp, "%[^EOF]", conteudo);
  char aux1[10000], aux2[10000];
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

        setAmizade(lista, aux1, aux2);
        nome = strtok(NULL, "\n");
  }

  fclose(fp);

  lista->ult->prox = NULL;

  return lista;
}

// Retira idoso da lista
void retiraIdoso(ListIdoso* lista, char *nome){
  CelIdoso* p = lista->prim;
  CelIdoso* ant = NULL;

    while (p != NULL && strcmp(getNomeIdoso(p->idoso), nome)){
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
      printf("Idoso nao encontrado\n");
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
    while (p != NULL && strcmp(getNomeIdoso(p->idoso), nome)){
        p = p->prox;
    }
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

void imprimeListAmigos(ListAmigos *listAmigos){

	if (listAmigos == NULL)
	{
		return;
	}

  CelIdoso* p;
  int i = 1;
  printf("LISTA DE AMIGOS:\n");
  for (p = listAmigos->prim; p != NULL; p = p->prox, i++){
    printf("Amigo %d: %s\n", i, getNomeIdoso(p->idoso));
  }
}






