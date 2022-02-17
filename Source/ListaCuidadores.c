#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> //Diretorio
#include <sys/stat.h> //Diretorio


#include "ListaCuidadores.h"


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

struct idoso{
  char *nome;
  ListAmigos *amigos;
  ListCuidador *cuidadores;
  float latitude;
  float longitude;
  float temperatura;
  int queda;
  int numFebresBaixas;
  //char *strFileIn;
  //char *strFileOut;
  //FILE *fileIn;
  //FILE *fileOut;
};

//  Funcao que inicializa a lista de cuidadores
//  inputs: nenhum
//  output: ponteiro para a estrutura ListCuidador
//  pre-condicao: nenhuma
//  pos-condicao: ponteiro de retorno existe e esta alocado
ListCuidador* inicializaListaCuidador(){
  ListCuidador* lista = (ListCuidador*)malloc(sizeof(ListCuidador));

  lista->prim = NULL;
  lista->ult = NULL;

  return lista;
}

//  Funcao que preenche a lista de cuidadores
//  inputs: string com o nome do arquivo com os nomes dos cuidadores
//  output: nenhum
//  pre-condicao: lista de cuidadores cujos nomes sao separados com ";", todos dispostos na primeira linha do arquivo de texto
//  pos-condicao: lista de cuidadores criada

// so coloquei os cuidadores em si, sem relacoes com nada
ListCuidador *preencheListCuidador(char* arquivo){
  ListCuidador *lista = inicializaListaCuidador();

  //CelCuidador* p = lista->prim;

  // Abre o arquivo para leitura

  FILE *fp = fopen(arquivo, "r");
  char conteudo[10000];

   if (fp == NULL)
    printf("Nao foi possivel abrir o arquivo. %s\n", arquivo);

  // Pega informacoes somente da primeira linha

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

CelCuidador* CriaCelulaCuidador(Cuidador* cuidador){
    CelCuidador* nova = (CelCuidador*)malloc(sizeof(CelCuidador));
    nova->cuidador = cuidador;
    nova->prox = NULL;
    return nova;
}

Cuidador* retornaCuidadorDaCelula(CelCuidador* p){
  return p->cuidador;
}

CelCuidador *retornaProximoCuidador(CelCuidador *p){
  return p->prox;
}

CelCuidador *retornaPrimeiroCuidador(ListCuidador *lista){
  return lista->prim;
}

CelCuidador* retornaUltimoCuidador(ListCuidador* lista){
    return lista->ult;
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
    while (p != NULL && strcmp(retornaNomeCuidador(p->cuidador), nome)){
        p = p->prox;
    }
    return p->cuidador;
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
  printf("----------LISTA DE CUIDADORES:----------\n");
  for (p = lista->prim; p != NULL; p = p->prox, i++){
    printf("Cuidador %d", i);
    imprimeCuidador(p->cuidador);
  }
}





void insereLinhaDeMedidaCuidador(ListCuidador* lista, int linha){
    CelCuidador* p;
    for(p = lista->prim; p != NULL; p = p->prox){
        Cuidador* cuidador = retornaCuidadorDaCelula(p);
        char* nomeCuidador = strdup(retornaNomeCuidador(cuidador));

        char* arquivo = strcat(nomeCuidador, ".txt");
        InsereMedidasCuidador(cuidador, linha, arquivo);

        free(nomeCuidador);
    }
}


Cuidador* RetornaCuidadorMaisPerto(Idoso* idoso, ListCuidador* listacuidador){
    float latIdoso = retornaLatitudeIdoso(idoso);
    float longiIdoso = retornaLongitudeIdoso(idoso);

    float latCuidador, longiCuidador;
    float distancia, menor;

    CelCuidador* p;
    for(p = listacuidador->prim; p != NULL; p = p->prox){
        latCuidador = retornaLatitudeCuidador(p->cuidador);
        longiCuidador = retornaLongitudeCuidador(p->cuidador);

        distancia = calculaDistancia(latIdoso, longiIdoso, latCuidador, longiCuidador);
        if(p == listacuidador->prim){  //só para inicializar o valor da distancia com base no primeiro cuidador
            menor = distancia;
        }
        if(distancia < menor){
            menor = distancia;
        }
    }

    for(p = listacuidador->prim; p != NULL; p = p->prox){ //for para "capturar" o cuidador cuja distancia do idoso é a menor
        latCuidador = retornaLatitudeCuidador(p->cuidador);
        longiCuidador = retornaLongitudeCuidador(p->cuidador);

        distancia = calculaDistancia(latIdoso, longiIdoso, latCuidador, longiCuidador);
        if(distancia == menor){
            Cuidador* cuidadorPerto = retornaCuidadorDaCelula(p);
            return cuidadorPerto;
        }
    }
}










