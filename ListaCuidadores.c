#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> //Diretorio
#include <sys/stat.h> //Diretorio

#include "ListaCuidadores.h"

struct CelCuidador{
    Cuidador* cuidador;
    CelCuidador *prox;
};

struct listCuidador{
    CelCuidador *prim;
    CelCuidador *ult;
};


ListCuidador* inicializaListaCuidador(){
  ListCuidador* lista = (ListCuidador*)malloc(sizeof(ListCuidador));

  lista->prim = NULL;
  lista->ult = NULL;

  return lista;
}






// só coloquei os cuidadores em si, sem relações com nada
ListCuidador *preencheListCuidador(char* arquivo){
  ListCuidador *lista = inicializaListaCuidador();

  CelCuidador* p = lista->prim;

  // Abre o arquivo para leitura

  FILE *fp = fopen(arquivo, "r");
  char conteudo[70];

   if (fp == NULL){
    printf("Nao foi possivel abrir o arquivo. %s\n", arquivo);
  }

  // Pega informações somente da primeira linha

  fscanf(fp, "%[^\n]\n", conteudo);

  char* nome = strtok(conteudo, ";");

  //colocando os cuidadores na lista
  while( nome != NULL ) {
        insereNovoCuidador(lista, criaCuidador(nome));

        nome = strtok(NULL, ";");
  }

  fclose(fp);

  lista->ult->prox = NULL;

  return lista;
}












/*
void preencheListCuidador(ListIdoso* listaIdoso, char* arquivo){
  listCuidador* lista = (ListCuidador*)malloc(sizeof(ListCuidador));
  lista->prim = NULL;
  lista->ult = NULL;

  CelCuidador* p;

  // ------ Leitura do arquivo ------

  char *diretorio = '\0';

  FILE *fp = fopen(arquivo, "r");
  char conteudo[10000] = "\0";

   if (fp == NULL){
    printf("Erro.\n");
  }

  // Pega informações somente da primeira linha

  fscanf(fp, "%[^\n]\n", conteudo);
  char* nome = strtok(conteudo, ";");

  //colocando os cuidadores na lista
  while( nome != NULL ) {
        insereNovoCuidador(lista, criaCuidador(nome));

        nome = strtok(NULL, ";");
  }


  // lendo as linhas seguintes
  fscanf(fp, "%[^EOF]", conteudo);

  char* test = NULL;
  char* linha;
  int i = 0, j = 0, k = 0;
  char nome[20];
  char num[10];
  char musica[50];
  int qtd = 0;

 // ------ Coleta de informacao de cada linha ------

  for (linha = strtok_r(conteudo, "\n", &test); linha != NULL; linha = strtok_r(NULL, "\n", &test)){ //for de linha em linha

        for(i = 0; linha[i] != ';'; i++){
          nome[i] = linha[i];
        }
        nome[i] = '\0';

        for(i += 1, j = 0; linha[i] != ';'; i++, j++){
          num[j] = linha[i];
        }
        num[j] = '\0';

        qtd = atof(num);

        for (j = 0; j < atof(num); j++){
          for(i += 1, k = 0; linha[i] != ';' && linha[i] != '\0'; i++, k++){
            musica[k] = linha[i];
          }
          musica[k] = '\0';

          // ------ Insercao nas listas ------

          p = inserePlaylist(retornaListPlaylist(buscaUsuario(listaUsuarios,nome)), musica);

          criaListaMusica(retornaListMusica(retornaPlaylistaDaCelula(p)), musica);
        }
  }
  fclose(fp);
}
*/

Cuidador* retornaCuidadorDaCelula(CelCuidador* p){
  return p->cuidador;
}

CelCuidador *retornaProximoCuidador(CelCuidador *p){
  return p->prox;
}

CelCuidador *retornaPrimeiroCuidador(ListCuidador *lista){
  return lista->prim;
}

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
      printf("Item não encontrado.\n");
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
    while (p != NULL && strcmp(retornaNomeCuidador(p->cuidador), nome)){
        p = p->prox;
    }
    if(p != NULL){
      return p->cuidador;
    }
    return NULL;
}

CelCuidador* buscaCuidadorERetornaCelula(ListCuidador* lista, char* nome){
  CelCuidador* p = lista->prim;
    while (p != NULL && strcmp(retornaNomeCuidador(p->cuidador), nome)){
        p = p->prox;
    }
    if(p != NULL){
      return p;
    }
    return NULL;
}

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

void imprimeListCuidador(ListCuidador* lista){
  CelCuidador* p;
  int i = 1;
  printf("LISTA DE CUIDADORES:\n");
  for (p = lista->prim; p != NULL; p = p->prox, i++){
    printf("Cuidador %d\n", i);
    imprimeCuidador(p->cuidador);
  }
}
