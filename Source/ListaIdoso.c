/*
 * INCLUSAO DE BIBLIOTECAS
 */


// BIBLIOTECAS PADRÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BIBLIOTECAS DO USUÁRIO
#include "ListaIdoso.h"
#include "ListaCuidadores.h"
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

void novaAmizade(ListIdoso *listIdoso, char* amigo1, char* amigo2){
  Idoso *idoso1, *idoso2;
  ListAmigos *listAmigos1, *listAmigos2;

  idoso1 = buscaIdoso(listIdoso, amigo1);
  idoso2 = buscaIdoso(listIdoso, amigo2);

  listAmigos1 = getListAmigosIdoso(idoso1);
  listAmigos2 = getListAmigosIdoso(idoso2);

  insereAmigoNaLista(listAmigos1, idoso2);
  insereAmigoNaLista(listAmigos2, idoso1);

}

void insereAmigoNaLista(ListAmigos *lista, Idoso *amigo){
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


ListAmigos* CriaListAmigos(void){
    ListAmigos* lista = (ListAmigos*)malloc(sizeof(ListAmigos));
    lista->prim = NULL;
    lista->ult = NULL;
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


void insereLinhaDeMedidaIdoso(ListIdoso* lista, int linha){
    CelIdoso* p;
    for(p = lista->prim; p != NULL; p = p->prox){
        Idoso* idoso = getIdosoCelula(p);
        char* nomeIdoso = strdup(getNomeIdoso(idoso));

        char* arquivo = strcat(nomeIdoso, ".txt");
        InsereMedidasIdoso(idoso, linha, arquivo);

        free(nomeIdoso);
    }
}

void verificaIdoso(ListIdoso* listaidoso, ListCuidador* listacuidador){
    CelIdoso* p;
    for(p = listaidoso->prim; p != NULL; p = p->prox){
        if(getQuedaIdoso(p->idoso) == 1){  //queda prevalece, por isso est� no primeiro if()
            //fazer aparecer no arquivo o seguinte: "queda, acionou Cuidador1"
            Cuidador* cuidadorQuedaProximo = RetornaCuidadorMaisPerto(p->idoso, listacuidador);
            char* arquivo = strcat(strdup(getNomeIdoso(p->idoso)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "queda, acionou %s\n", getNomeCuidador(cuidadorQuedaProximo));

            fclose(arq);
            //free(arquivo);

            if(getTemperaturaIdoso(p->idoso) >= 38){//se tiver queda e febre alta no mesmo dia, mesmo priorizando acao da queda, qtd de dias de febre deve ser zerada
                setNumFebresBaixas(p->idoso, 0);
            }
            else if(getTemperaturaIdoso(p->idoso) > 37 && getTemperaturaIdoso(p->idoso) < 38){//situacao parecida com a de cima
                increaseNumFebresBaixas(p->idoso);
            }

        }
        else if(getTemperaturaIdoso(p->idoso) >= 38){  //depois verifica se idoso tem febre alta
            //fazer aparecer no arquivo o seguinte: "febre alta, acionou Cuidador1"
            Cuidador* CuidadorFebreAlta = RetornaCuidadorMaisPerto(p->idoso, listacuidador);
            char* arquivo = strcat(strdup(getNomeIdoso(p->idoso)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "febre alta, acionou %s\n", getNomeCuidador(CuidadorFebreAlta));

            fclose(arq);
            //free(arquivo);

            setNumFebresBaixas(p->idoso, 0);
        }
        else if(getTemperaturaIdoso(p->idoso) > 37 && getTemperaturaIdoso(p->idoso) < 38){  //depois se o idoso tem febre baixa
            increaseNumFebresBaixas(p->idoso);
            //fazer aparecer no arquivo o seguinte: "febre baixa, acionou amigo Maria"
            if(getNumFebresBaixas(p->idoso) < 4){
                Idoso* amigoProximo = RetornaAmigoMaisPerto(p->idoso, getListAmigosIdoso(p->idoso));
                char* arquivo = strcat(strdup(getNomeIdoso(p->idoso)), "-saida.txt");

                FILE* arq = fopen(arquivo, "a");
                fprintf(arq, "febre baixa, acionou amigo %s\n", getNomeIdoso(amigoProximo));

                fclose(arq);
                //free(arquivo);
            }

            if(getNumFebresBaixas(p->idoso) >= 4){
                setNumFebresBaixas(p->idoso, 0);
                //fazer aparecer no arquivo o seguinte: "febre baixa pela quarta vez, acionou Cuidador1"

                Cuidador* cuidadorQuatroFebresBaixas = RetornaCuidadorMaisPerto(p->idoso, listacuidador);
                char* arquivo = strcat(strdup(getNomeIdoso(p->idoso)), "-saida.txt");

                FILE* arq = fopen(arquivo, "a");
                fprintf(arq, "febre baixa pela quarta vez, acionou %s\n", getNomeCuidador(cuidadorQuatroFebresBaixas));

                fclose(arq);
                //free(arquivo);
            }
        }
        else{  //se esta tudo ok
            //fazer aparecer no arquivo o seguinte: "tudo ok"
            char* arquivo = strcat(strdup(getNomeIdoso(p->idoso)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "tudo ok\n");

            fclose(arq);
            //free(arquivo);
        }
    }
}





Idoso* RetornaAmigoMaisPerto(Idoso* idoso, ListAmigos* listaAmigo){
    float latIdoso = getLatitudeIdoso(idoso);
    float longiIdoso = getLongitudeIdoso(idoso);

    float latAmigo, longiAmigo;
    float distancia, menor;

    CelIdoso* p;
    for(p = listaAmigo->prim; p != NULL; p = p->prox){
        latAmigo = getLatitudeIdoso(p->idoso);
        longiAmigo = getLongitudeIdoso(p->idoso);

        distancia = calculaDistancia(latIdoso, longiIdoso, latAmigo, longiAmigo);
        if(p == listaAmigo->prim){  //s� para inicializar o valor da distancia com base no primeiro amigo
            menor = distancia;
        }
        if(distancia < menor){
            menor = distancia;
        }
    }

    for(p = listaAmigo->prim; p != NULL; p = p->prox){ //for para "capturar" o amigo cuja distancia do idoso � a menor
        latAmigo = getLatitudeIdoso(p->idoso);
        longiAmigo = getLongitudeIdoso(p->idoso);

        distancia = calculaDistancia(latIdoso, longiIdoso, latAmigo, longiAmigo);
        if(distancia == menor){
            Idoso* amigoPerto = getIdosoCelula(p);
            return amigoPerto;
        }
    }
    return NULL;
}


Cuidador* RetornaCuidadorMaisPerto(Idoso* idoso, ListCuidador* listacuidador){
    float latIdoso = getLatitudeIdoso(idoso);
    float longiIdoso = getLongitudeIdoso(idoso);

    float latCuidador, longiCuidador;
    float distancia, menor;

    CelCuidador* p;
    for(p = getPrimeiroCuidador(listacuidador); p != NULL; p = getProximoCuidador(p)){
        latCuidador = getLatitudeCuidador(getCuidadorDaCelula(p));
        longiCuidador = getLongitudeCuidador(getCuidadorDaCelula(p));

        distancia = calculaDistancia(latIdoso, longiIdoso, latCuidador, longiCuidador);
        if(p == getPrimeiroCuidador(listacuidador)){  //só para inicializar o valor da distancia com base no primeiro cuidador
            menor = distancia;
        }
        if(distancia < menor){
            menor = distancia;
        }
    }

    for(p = getPrimeiroCuidador(listacuidador); p != NULL; p = getProximoCuidador(p)){ //for para "capturar" o cuidador cuja distancia do idoso é a menor
        latCuidador = getLatitudeCuidador(getCuidadorDaCelula(p));
        longiCuidador = getLongitudeCuidador(getCuidadorDaCelula(p));

        distancia = calculaDistancia(latIdoso, longiIdoso, latCuidador, longiCuidador);
        if(distancia == menor){
            Cuidador* cuidadorPerto = getCuidadorDaCelula(p);
            return cuidadorPerto;
        }
    }

    return NULL;
}
