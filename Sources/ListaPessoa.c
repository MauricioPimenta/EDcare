/*
 * INCLUSAO DE BIBLIOTECAS
 */


// BIBLIOTECAS PADRÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BIBLIOTECAS DO USUÁRIO
#include "ListaPessoa.h"
#include "ListaCuidadores.h"
#include "Pessoa.h"

/*
 * Definição daS EstruturaS do TAD ListaPessoa
 */
struct node{
  Pessoa *pessoa;
  Node *prox;
};

struct listPessoa{
  Node *prim;
  Node *ult;
};

ListPessoa* CriaListaPessoa()
{
	ListPessoa* lista = (ListPessoa*)malloc(sizeof(ListPessoa));
	lista->prim = NULL;
	lista->ult = NULL;
	return lista;
}

/***********************************************************
 *
 * FUNCOES GET - RETORNAM UM ATRIBUTO DA LISTA DE CUIDADORES
 * 
 ***********************************************************/
Node *getPrimeiro(ListPessoa* lista){
  return lista->prim;
}

Node *getUltimo(ListPessoa* lista){
  return lista->ult;
}

Node *getProximo(Node* p){
  return p->prox;
}

Pessoa *getPessoaCelula(Node* p){
  return p->pessoa;
}


/***********************************************************
 *
 * FUNCOES SET - ATRIBUEM UM ATRIBUTO DA LISTA DE CUIDADORES
 * 
 ***********************************************************/

void novaAmizade(ListPessoa *listPessoa, char* amigo1, char* amigo2){
  Pessoa *pessoa1, *pessoa2;
  ListPessoa *listAmigos1, *listAmigos2;

  pessoa1 = buscaPessoa(listPessoa, amigo1);
  pessoa2 = buscaPessoa(listPessoa, amigo2);

  listAmigos1 = getListAmigosPessoa(pessoa1);
  listAmigos2 = getListAmigosPessoa(pessoa2);

  insereAmigoNaLista(listAmigos1, pessoa2);
  insereAmigoNaLista(listAmigos2, pessoa1);

}

void insereAmigoNaLista(ListPessoa *lista, Pessoa *amigo){
    Node* nova = (Node*)malloc(sizeof(Node));
    nova->pessoa = amigo;
    nova->prox = NULL;

	if (lista == NULL)
	{
		lista = (ListPessoa*)malloc(sizeof(ListPessoa));
		lista->prim = NULL;
		lista->ult = NULL;
	}


    if(lista->prim == NULL){
      lista->prim = nova;
      lista->ult = nova;
    }
    else{
      Node *p = lista->prim;

      while(p->prox != NULL){
        p = p->prox;
      }
      p->prox = nova;
      lista->ult = nova;


    }
}

// Insere pessoa na lista
void inserePessoa(ListPessoa* lista, Pessoa *pessoa){
    Node* nova = (Node*)malloc(sizeof(Node));
    nova->pessoa = pessoa;
    nova->prox = NULL;

    if(lista->prim == NULL){
      lista->prim = nova;
      lista->ult = nova;
    }
    else{
      Node *p = lista->prim;

      while(p->prox != NULL){
        p = p->prox;
      }
      p->prox = nova;
      lista->ult = nova;
    }
}


ListPessoa* CriaListAmigos(void){
    ListPessoa* lista = (ListPessoa*)malloc(sizeof(ListPessoa));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

// Retira pessoa da lista
void retiraPessoa(ListPessoa* lista, char *nome){
  Node* p = lista->prim;
  Node* ant = NULL;

    while (p != NULL && strcmp(getNomePessoa(p->pessoa), nome)){
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
      printf("Pessoa nao encontrado\n");
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

    destroiPessoa(p->pessoa);
    free(p);

}

Pessoa *buscaPessoa(ListPessoa *lista, char *nome){
    Node* p = lista->prim;
    while (p != NULL && strcmp(getNomePessoa(p->pessoa), nome)){
        p = p->prox;
    }
    return p->pessoa;
}

void destroiListPessoa(ListPessoa* lista){
  Node* p;
  Node* t;

  p = lista->prim;
  while(p != NULL){
        t = p->prox;
        destroiPessoa(p->pessoa);
        free(p);
        p = t;
    }

  free(lista);
}

void imprimeListPessoa(ListPessoa* lista){
  Node* p;
  int i = 1;
  for (p = lista->prim; p != NULL; p = p->prox, i++){
    printf ("Pessoa %d:\n", i);
    imprimePessoa(p->pessoa);
    printf("\n");
  }
}

void imprimeListAmigos(ListPessoa *listAmigos){

	if (listAmigos == NULL)
	{
		return;
	}

  Node* p;
  int i = 1;
  printf("LISTA DE AMIGOS:\n");
  for (p = listAmigos->prim; p != NULL; p = p->prox, i++){
    printf("Amigo %d: %s\n", i, getNomePessoa(p->pessoa));
  }
}


void insereLinhaDeMedidaPessoa(ListPessoa* lista, int linha){
    Node* p;
    for(p = lista->prim; p != NULL; p = p->prox){
        Pessoa* pessoa = getPessoaCelula(p);
        char* nomePessoa = strdup(getNomePessoa(pessoa));

        char* arquivo = strcat(nomePessoa, ".txt");
        InsereMedidasPessoa(pessoa, linha, arquivo);

        free(nomePessoa);
    }
}

void verificaPessoa(ListPessoa* listapessoa, ListPessoa* listacuidador){
    Node* p;
    for(p = listapessoa->prim; p != NULL; p = p->prox){
        if(getQuedaPessoa(p->pessoa) == 1){  //queda prevalece, por isso est� no primeiro if()
            //fazer aparecer no arquivo o seguinte: "queda, acionou Cuidador1"
            Cuidador* cuidadorQuedaProximo = RetornaCuidadorMaisPerto(p->pessoa, listacuidador);
            char* arquivo = strcat(strdup(getNomePessoa(p->pessoa)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "queda, acionou %s\n", getNomeCuidador(cuidadorQuedaProximo));

            fclose(arq);
            //free(arquivo);

            if(getTemperaturaPessoa(p->pessoa) >= 38){//se tiver queda e febre alta no mesmo dia, mesmo priorizando acao da queda, qtd de dias de febre deve ser zerada
                setNumFebresBaixas(p->pessoa, 0);
            }
            else if(getTemperaturaPessoa(p->pessoa) > 37 && getTemperaturaPessoa(p->pessoa) < 38){//situacao parecida com a de cima
                increaseNumFebresBaixas(p->pessoa);
            }

        }
        else if(getTemperaturaPessoa(p->pessoa) >= 38){  //depois verifica se pessoa tem febre alta
            //fazer aparecer no arquivo o seguinte: "febre alta, acionou Cuidador1"
            Cuidador* CuidadorFebreAlta = RetornaCuidadorMaisPerto(p->pessoa, listacuidador);
            char* arquivo = strcat(strdup(getNomePessoa(p->pessoa)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "febre alta, acionou %s\n", getNomeCuidador(CuidadorFebreAlta));

            fclose(arq);
            //free(arquivo);

            setNumFebresBaixas(p->pessoa, 0);
        }
        else if(getTemperaturaPessoa(p->pessoa) > 37 && getTemperaturaPessoa(p->pessoa) < 38){  //depois se o pessoa tem febre baixa
            increaseNumFebresBaixas(p->pessoa);
            //fazer aparecer no arquivo o seguinte: "febre baixa, acionou amigo Maria"
            if(getNumFebresBaixas(p->pessoa) < 4){
                Pessoa* amigoProximo = RetornaAmigoMaisPerto(p->pessoa, getListAmigosPessoa(p->pessoa));
                char* arquivo = strcat(strdup(getNomePessoa(p->pessoa)), "-saida.txt");

                FILE* arq = fopen(arquivo, "a");
                fprintf(arq, "febre baixa, acionou amigo %s\n", getNomePessoa(amigoProximo));

                fclose(arq);
                //free(arquivo);
            }

            if(getNumFebresBaixas(p->pessoa) >= 4){
                setNumFebresBaixas(p->pessoa, 0);
                //fazer aparecer no arquivo o seguinte: "febre baixa pela quarta vez, acionou Cuidador1"

                Cuidador* cuidadorQuatroFebresBaixas = RetornaCuidadorMaisPerto(p->pessoa, listacuidador);
                char* arquivo = strcat(strdup(getNomePessoa(p->pessoa)), "-saida.txt");

                FILE* arq = fopen(arquivo, "a");
                fprintf(arq, "febre baixa pela quarta vez, acionou %s\n", getNomeCuidador(cuidadorQuatroFebresBaixas));

                fclose(arq);
                //free(arquivo);
            }
        }
        else{  //se esta tudo ok
            //fazer aparecer no arquivo o seguinte: "tudo ok"
            char* arquivo = strcat(strdup(getNomePessoa(p->pessoa)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "tudo ok\n");

            fclose(arq);
            //free(arquivo);
        }
    }
}





Pessoa* RetornaAmigoMaisPerto(Pessoa* pessoa, ListPessoa* listaAmigo){
    float latPessoa = getLatitudePessoa(pessoa);
    float longiPessoa = getLongitudePessoa(pessoa);

    float latAmigo, longiAmigo;
    float distancia, menor;

    Node* p;
    for(p = listaAmigo->prim; p != NULL; p = p->prox){
        latAmigo = getLatitudePessoa(p->pessoa);
        longiAmigo = getLongitudePessoa(p->pessoa);

        distancia = calculaDistancia(latPessoa, longiPessoa, latAmigo, longiAmigo);
        if(p == listaAmigo->prim){  //s� para inicializar o valor da distancia com base no primeiro amigo
            menor = distancia;
        }
        if(distancia < menor){
            menor = distancia;
        }
    }

    for(p = listaAmigo->prim; p != NULL; p = p->prox){ //for para "capturar" o amigo cuja distancia do pessoa � a menor
        latAmigo = getLatitudePessoa(p->pessoa);
        longiAmigo = getLongitudePessoa(p->pessoa);

        distancia = calculaDistancia(latPessoa, longiPessoa, latAmigo, longiAmigo);
        if(distancia == menor){
            Pessoa* amigoPerto = getPessoaCelula(p);
            return amigoPerto;
        }
    }
    return NULL;
}


Cuidador* RetornaCuidadorMaisPerto(Pessoa* pessoa, ListPessoa* listacuidador){
    float latPessoa = getLatitudePessoa(pessoa);
    float longiPessoa = getLongitudePessoa(pessoa);

    float latCuidador, longiCuidador;
    float distancia, menor;

    CelCuidador* p;
    for(p = getPrimeiroCuidador(listacuidador); p != NULL; p = getProximoCuidador(p)){
        latCuidador = getLatitudeCuidador(getCuidadorDaCelula(p));
        longiCuidador = getLongitudeCuidador(getCuidadorDaCelula(p));

        distancia = calculaDistancia(latPessoa, longiPessoa, latCuidador, longiCuidador);
        if(p == getPrimeiroCuidador(listacuidador)){  //só para inicializar o valor da distancia com base no primeiro cuidador
            menor = distancia;
        }
        if(distancia < menor){
            menor = distancia;
        }
    }

    for(p = getPrimeiroCuidador(listacuidador); p != NULL; p = getProximoCuidador(p)){ //for para "capturar" o cuidador cuja distancia do pessoa é a menor
        latCuidador = getLatitudeCuidador(getCuidadorDaCelula(p));
        longiCuidador = getLongitudeCuidador(getCuidadorDaCelula(p));

        distancia = calculaDistancia(latPessoa, longiPessoa, latCuidador, longiCuidador);
        if(distancia == menor){
            Cuidador* cuidadorPerto = getCuidadorDaCelula(p);
            return cuidadorPerto;
        }
    }

    return NULL;
}
