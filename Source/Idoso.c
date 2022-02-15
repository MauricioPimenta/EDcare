#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Idoso.h"


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

Idoso* criaIdoso(char *nome){
  Idoso* idoso = (Idoso*)malloc(sizeof(Idoso));
  idoso->nome = strdup(nome);
  idoso->amigos = CriaListAmigos();
  idoso->cuidadores = inicializaListaCuidador();
  idoso->latitude = 0;
  idoso->longitude = 0;
  idoso->temperatura = 0;
  idoso->queda = 0;
  idoso->numFebresBaixas = 0;

  return idoso;
}

/*****************************************************
 *
 * FUNCOES GET - RETORNAM UM ATRIBUTO DO IDOSO
 * 
 *****************************************************/

//  Retorna o nome do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: nome do idoso
//  pre-condicao: idoso existe
//  pos-condicao: idoso nao é modificado e nome do idoso disponível
char *getNomeIdoso(Idoso *idoso){
  return idoso->nome;
}

//  Retorna Lista de amigos do idoso
//  inputs: ponteiro para estrutura Idoso
//  output: ponteiro para estrutura ListAmigos
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é alterado e lista de amigos disponível
ListAmigos *getListAmigosIdoso(Idoso *idoso){
  return idoso->amigos;
}

//  Retona a lista de cuidadores do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: ponteiro para a estrutura ListCuidadores
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e estrutura dos cuidadores disponível
ListCuidador *getListCuidadores(Idoso *idoso){
  return idoso->cuidadores;
}


float getLatitudeIdoso(Idoso *idoso){
	return idoso->latitude;
}

float getLongitudeIdoso(Idoso *idoso){
	return idoso->longitude;
}

float getTemperaturaIdoso(Idoso* idoso){
	return idoso->temperatura;
}

int getQuedaIdoso(Idoso* idoso){
	return idoso->queda;
}

int getNumFebresBaixas(Idoso* idoso){
	return idoso->numFebresBaixas;
}


/*****************************************************
 *
 * FUNCOES SET - MODIFICAM UM ATRIBUTO DO IDOSO
 * 
 */

void setLatitudeIdoso(Idoso *idoso, float lat){
	idoso->latitude = lat;
}

void setLongitudeIdoso(Idoso *idoso, float longit){
	idoso->longitude = longit;
}

void setTemperaturaIdoso(Idoso* idoso, float temp){
	idoso->temperatura = temp;
}

void setQuedaIdoso(Idoso* idoso, int queda){
	idoso->queda = queda;
}

void setNumFebresBaixas(Idoso* idoso, int febres){
	idoso->numFebresBaixas = febres;
}


void destroiIdoso(Idoso *idoso){
  free(idoso->nome);
  //destroiListCuidadores(idoso->cuidadores);
  //destroiListaAmigos(idoso->amigos);

  free(idoso);
}

void imprimeIdoso(Idoso* idoso){
  printf("Nome: %s\n", idoso->nome);
  //imprimeListCuidadores(idoso->cuidadores);
  imprimeListAmigos(idoso->amigos);
  printf("%f, %f, %f, %i", idoso->temperatura, idoso->latitude, idoso->longitude, idoso->queda);
}





