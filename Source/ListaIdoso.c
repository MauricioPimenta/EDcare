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

struct listAmigos{
  CelIdoso *prim;
  CelIdoso *ult;
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
};


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
        insereIdoso(lista, criaIdoso(nome));

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




// Retira idoso da lista
void retiraIdoso(ListIdoso* lista, char *nome){
  CelIdoso* p = lista->prim;
  CelIdoso* ant = NULL;

    while (p != NULL && strcmp(retornaNomeIdoso(p->idoso), nome)){
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
    printf("\n\n===============IDOSO===============\n");
    printf ("Idoso %d:\n", i);
    imprimeIdoso(p->idoso);
    printf("\n\n");
  }
}


void imprimeListAmigos(ListAmigos *listAmigos){

	if (listAmigos == NULL)
	{
		return;
	}

  CelIdoso* p;
  int i = 1;
  printf("----------LISTA DE AMIGOS:----------\n");
  for (p = listAmigos->prim; p != NULL; p = p->prox, i++){
    printf("Amigo %d: %s\n", i, retornaNomeIdoso(p->idoso));
  }
}




void insereLinhaDeMedidaIdoso(ListIdoso* lista, int linha){
    CelIdoso* p;
    for(p = lista->prim; p != NULL; p = p->prox){
        Idoso* idoso = retornaIdosoCelula(p);
        char* nomeIdoso = strdup(retornaNomeIdoso(idoso));

        char* arquivo = strcat(nomeIdoso, ".txt");
        InsereMedidasIdoso(idoso, linha, arquivo);

        free(nomeIdoso);
    }
}


void verificaIdoso(ListIdoso* listaidoso, ListCuidador* listacuidador){
    CelIdoso* p;
    for(p = listaidoso->prim; p != NULL; p = p->prox){
        if(retornaQueda(p->idoso) == 1){  //queda prevalece, por isso está no primeiro if()
            //fazer aparecer no arquivo o seguinte: "queda, acionou Cuidador1"
            Cuidador* cuidadorQuedaProximo = RetornaCuidadorMaisPerto(p->idoso, listacuidador);
            char* arquivo = strcat(strdup(retornaNomeIdoso(p->idoso)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "queda, acionou %s\n", retornaNomeCuidador(cuidadorQuedaProximo));

            fclose(arq);
            //free(arquivo);

            if(retornaTemperatura(p->idoso) >= 38){//se tiver queda e febre alta no mesmo dia, mesmo priorizando acao da queda, qtd de dias de febre deve ser zerada
                setNumFebresBaixas(p->idoso, 0);
            }
            else if(retornaTemperatura(p->idoso) > 37 && retornaTemperatura(p->idoso) < 38){//situacao parecida com a de cima
                increaseNumFebresBaixas(p->idoso);
            }

        }
        else if(retornaTemperatura(p->idoso) >= 38){  //depois verifica se idoso tem febre alta
            //fazer aparecer no arquivo o seguinte: "febre alta, acionou Cuidador1"
            Cuidador* CuidadorFebreAlta = RetornaCuidadorMaisPerto(p->idoso, listacuidador);
            char* arquivo = strcat(strdup(retornaNomeIdoso(p->idoso)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "febre alta, acionou %s\n", retornaNomeCuidador(CuidadorFebreAlta));

            fclose(arq);
            //free(arquivo);

            setNumFebresBaixas(p->idoso, 0);
        }
        else if(retornaTemperatura(p->idoso) > 37 && retornaTemperatura(p->idoso) < 38){  //depois se o idoso tem febre baixa
            increaseNumFebresBaixas(p->idoso);
            //fazer aparecer no arquivo o seguinte: "febre baixa, acionou amigo Maria"
            if(retornaNumFebresBaixas(p->idoso) < 4){
                Idoso* amigoProximo = RetornaAmigoMaisPerto(p->idoso, retornaListAmigosIdoso(p->idoso));
                char* arquivo = strcat(strdup(retornaNomeIdoso(p->idoso)), "-saida.txt");

                FILE* arq = fopen(arquivo, "a");
                fprintf(arq, "febre baixa, acionou amigo %s\n", retornaNomeIdoso(amigoProximo));

                fclose(arq);
                //free(arquivo);
            }

            if(retornaNumFebresBaixas(p->idoso) >= 4){
                setNumFebresBaixas(p->idoso, 0);
                //fazer aparecer no arquivo o seguinte: "febre baixa pela quarta vez, acionou Cuidador1"

                Cuidador* cuidadorQuatroFebresBaixas = RetornaCuidadorMaisPerto(p->idoso, listacuidador);
                char* arquivo = strcat(strdup(retornaNomeIdoso(p->idoso)), "-saida.txt");

                FILE* arq = fopen(arquivo, "a");
                fprintf(arq, "febre baixa pela quarta vez, acionou %s\n", retornaNomeCuidador(cuidadorQuatroFebresBaixas));

                fclose(arq);
                //free(arquivo);
            }
        }
        else{  //se esta tudo ok
            //fazer aparecer no arquivo o seguinte: "tudo ok"
            char* arquivo = strcat(strdup(retornaNomeIdoso(p->idoso)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "tudo ok\n");

            fclose(arq);
            //free(arquivo);
        }
    }
}



Idoso* RetornaAmigoMaisPerto(Idoso* idoso, ListAmigos* listaAmigo){
    float latIdoso = retornaLatitudeIdoso(idoso);
    float longiIdoso = retornaLongitudeIdoso(idoso);

    float latAmigo, longiAmigo;
    float distancia, menor;

    CelIdoso* p;
    for(p = listaAmigo->prim; p != NULL; p = p->prox){
        latAmigo = retornaLatitudeIdoso(p->idoso);
        longiAmigo = retornaLongitudeIdoso(p->idoso);

        distancia = calculaDistancia(latIdoso, longiIdoso, latAmigo, longiAmigo);
        if(p == listaAmigo->prim){  //só para inicializar o valor da distancia com base no primeiro amigo
            menor = distancia;
        }
        if(distancia < menor){
            menor = distancia;
        }
    }

    for(p = listaAmigo->prim; p != NULL; p = p->prox){ //for para "capturar" o amigo cuja distancia do idoso é a menor
        latAmigo = retornaLatitudeIdoso(p->idoso);
        longiAmigo = retornaLongitudeIdoso(p->idoso);

        distancia = calculaDistancia(latIdoso, longiIdoso, latAmigo, longiAmigo);
        if(distancia == menor){
            Idoso* amigoPerto = retornaIdosoCelula(p);
            return amigoPerto;
        }
    }
}


