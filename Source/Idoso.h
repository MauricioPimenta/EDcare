#ifndef IDOSO_H_
#define IDOSO_H_

#include <stdbool.h>

typedef struct idoso Idoso;



#include "ListaCuidadores.h"
#include "ListaIdoso.h"


//  Cria estrutura idoso
//  inputs: nome do idoso
//  output: ponteiro para a estrutura Idoso
//  pre-condicao: não existe
//  pos-condicao: ponteiro da estrutura alocado pronto para uso

Idoso *criaIdoso(char *nome);


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
//
char *getNomeIdoso(Idoso *idoso);


//  Retorna Lista de amigos do idoso
//  inputs: ponteiro para estrutura Idoso
//  output: ponteiro para estrutura ListAmigos
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é alterado e lista de amigos disponível
//
ListAmigos *getListAmigosIdoso(Idoso *idoso);


//  Retona a lista de cuidadores do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: ponteiro para a estrutura ListCuidadores
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e estrutura dos cuidadores disponível
//
ListCuidador *getListCuidadores(Idoso *idoso);


//  Retona a latitude do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: numero real type float
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e latitude disponível
//
float getLatitudeIdoso(Idoso *idoso);

//  Retona a longitude do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: numero real type float
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e longitude disponível
//
float getLongitudeIdoso(Idoso *idoso);

//  Retona a temperatura do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: temperatura, um numero real type float
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e temperatura disponível
//
float getTemperaturaIdoso(Idoso* idoso);

//  Retona informacao de queda do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: boolean que indica se idoso sofreu queda
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e 'informacao de queda' disponível
//
bool getQuedaIdoso(Idoso* idoso);

//  Retona a quantidade de febres baixas do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: inteiro com a quantidade de febres baixas
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e quantidade de febres disponível
//
int getNumFebresBaixas(Idoso* idoso);


/*****************************************************
 *
 * FUNCOES SET - MODIFICAM UM ATRIBUTO DO IDOSO
 * 
 *****************************************************/

//  Modifica a Latitude do Idoso
//  inputs: 
//		- Idoso* idoso = ponteiro para a estrutura Idoso
//		- float lat = latitude do idoso, do tipo float
//
//  output: nada
//  pre-condicao: idoso precisa existir e latituda positiva
//  pos-condicao: latitude do idoso modificada
//
void setLatitudeIdoso(Idoso *idoso, float lat);

//  Modifica a Longitude do Idoso
//  inputs: 
//		- Idoso* idoso = ponteiro para a estrutura Idoso
//		- float longit = longitude do idoso, do tipo float
//
//  output: nada
//  pre-condicao: idoso precisa existir e longitude não negativa
//  pos-condicao: logitude do idoso modificada
//
void setLongitudeIdoso(Idoso *idoso, float longit);


//  Modifica a Temperatura do Idoso
//  inputs: 
//		- Idoso* idoso = ponteiro para a estrutura Idoso
//		- float temp = temperatura do idoso, do tipo float
//
//  output: nada
//  pre-condicao: idoso precisa existir e temperatura positiva
//  pos-condicao: temperatura do idoso modificada
//
void setTemperaturaIdoso(Idoso* idoso, float temp);

//  Define o valor de queda do Idoso
//  inputs: 
//		- Idoso* idoso = ponteiro para a estrutura Idoso
//		- bool queda = true ou false, indica se houve queda
//
//  output: nada
//  pre-condicao: idoso precisa existir
//  pos-condicao: queda do idoso modificada
//
void setQuedaIdoso(Idoso* idoso, bool queda);

//  Define o valor de queda do Idoso
//  inputs: 
//		- Idoso* idoso = ponteiro para a estrutura Idoso
//		- int febres = quantidade de febres baixas
//
//  output: nada
//  pre-condicao: idoso precisa existir e febres >= 0
//  pos-condicao: quantidade de febres do idoso modificada
//
void setNumFebresBaixas(Idoso* idoso, int febres);


/*****************************************************************************
 * 
 * OUTRAS FUNÇÕES
 * 
 *****************************************************************************/

/*  Incrementa o valor de queda do Idoso
 *  Inputs: 
 *		- Idoso* idoso = ponteiro para a estrutura Idoso
 * 
 *  pre-condicao: idoso precisa existir
 *  pos-condicao: quantidade de febres baixas do idoso incrementada em 1.
 */
void increaseNumFebresBaixas(Idoso *idoso);

//  Libera memória alocada para o idoso
//  inputs: ponteiro para a estrutura Idoso
//  output:  0	->	tudo certo
//			-1	->	idoso não existe
//  pre-condicao: idoso existe
//  pos-condicao: a memória alocada para a estrutura Idoso foi liberada
//
int destroiIdoso(Idoso *idoso);

//  Imprime idoso
//  inputs: ponteiro para Usuario
//  output: nenhum
//  pre-condicao: Usuario precisa existir
//  pos-condicao: Usuario nao eh alterado
void imprimeIdoso(Idoso* usuario);


// Outras funcoes






#endif
