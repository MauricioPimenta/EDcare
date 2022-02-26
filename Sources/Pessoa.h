#ifndef PESSOA_H_
#define PESSOA_H_

#include <stdbool.h>

typedef struct pessoa Pessoa;


//#include "ListaCuidadores.h"
#include "ListaPessoa.h"


//  Cria estrutura pessoa
//  inputs: nome do pessoa
//  output: ponteiro para a estrutura Pessoa
//  pre-condicao: não existe
//  pos-condicao: ponteiro da estrutura alocado pronto para uso

Pessoa *criaPessoa(char *nome);


/*****************************************************
 *
 * FUNCOES GET - RETORNAM UM ATRIBUTO DO IDOSO
 * 
 *****************************************************/

//  Retorna o nome do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: nome do pessoa
//  pre-condicao: pessoa existe
//  pos-condicao: pessoa nao é modificado e nome do pessoa disponível
//
char *getNomePessoa(Pessoa *pessoa);


//  Retorna Lista de amigos do pessoa
//  inputs: ponteiro para estrutura Pessoa
//  output: ponteiro para estrutura ListPessoa
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é alterado e lista de amigos disponível
//
ListPessoa *getListAmigosPessoa(Pessoa *pessoa);


//  Retona a lista de cuidadores do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: ponteiro para a estrutura ListCuidadores
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e estrutura dos cuidadores disponível
//
ListPessoa *getListCuidadores(Pessoa *pessoa);


//  Retona a latitude do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: numero real type float
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e latitude disponível
//
float getLatitudePessoa(Pessoa *pessoa);

//  Retona a longitude do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: numero real type float
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e longitude disponível
//
float getLongitudePessoa(Pessoa *pessoa);

//  Retona a temperatura do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: temperatura, um numero real type float
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e temperatura disponível
//
float getTemperaturaPessoa(Pessoa* pessoa);

//  Retona informacao de queda do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: boolean que indica se pessoa sofreu queda
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e 'informacao de queda' disponível
//
bool getQuedaPessoa(Pessoa* pessoa);

//  Retona a quantidade de febres baixas do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: inteiro com a quantidade de febres baixas
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e quantidade de febres disponível
//
int getNumFebresBaixas(Pessoa* pessoa);

//  Retona o nome do arquivo de entradas (infos) do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: string com o nome do arquivo
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e nome do arquivo disponível
//
char* getNomeArquivoEntradaPessoa(Pessoa* pessoa);

//  Retona o nome do arquivo de saidas (log) do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: string com o nome do arquivo
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e nome do arquivo disponível
//
char* getNomeArquivoSaidaPessoa(Pessoa* pessoa);

/*****************************************************
 *
 * FUNCOES SET - MODIFICAM UM ATRIBUTO DO IDOSO
 * 
 *****************************************************/

//  Modifica a Latitude do Pessoa
//  inputs: 
//		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
//		- float lat = latitude do pessoa, do tipo float
//
//  output: nada
//  pre-condicao: pessoa precisa existir e latituda positiva
//  pos-condicao: latitude do pessoa modificada
//
void setLatitudePessoa(Pessoa *pessoa, float lat);

//  Modifica a Longitude do Pessoa
//  inputs: 
//		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
//		- float longit = longitude do pessoa, do tipo float
//
//  output: nada
//  pre-condicao: pessoa precisa existir e longitude não negativa
//  pos-condicao: logitude do pessoa modificada
//
void setLongitudePessoa(Pessoa *pessoa, float longit);


//  Modifica a Temperatura do Pessoa
//  inputs: 
//		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
//		- float temp = temperatura do pessoa, do tipo float
//
//  output: nada
//  pre-condicao: pessoa precisa existir e temperatura positiva
//  pos-condicao: temperatura do pessoa modificada
//
void setTemperaturaPessoa(Pessoa* pessoa, float temp);

//  Define o valor de queda do Pessoa
//  inputs: 
//		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
//		- bool queda = true ou false, indica se houve queda
//
//  output: nada
//  pre-condicao: pessoa precisa existir
//  pos-condicao: queda do pessoa modificada
//
void setQuedaPessoa(Pessoa* pessoa, bool queda);

//  Define o valor de queda do Pessoa
//  inputs: 
//		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
//		- int febres = quantidade de febres baixas
//
//  output: nada
//  pre-condicao: pessoa precisa existir e febres >= 0
//  pos-condicao: quantidade de febres do pessoa modificada
//
void setNumFebresBaixas(Pessoa* pessoa, int febres);


/*****************************************************************************
 * 
 * OUTRAS FUNÇÕES
 * 
 *****************************************************************************/

/*  Incrementa o valor de queda do Pessoa
 *  Inputs: 
 *		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
 * 
 *  pre-condicao: pessoa precisa existir
 *  pos-condicao: quantidade de febres baixas do pessoa incrementada em 1.
 */
void increaseNumFebresBaixas(Pessoa *pessoa);

//  Libera memória alocada para o pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output:  0	->	tudo certo
//			-1	->	pessoa não existe
//  pre-condicao: pessoa existe
//  pos-condicao: a memória alocada para a estrutura Pessoa foi liberada
//
int destroiPessoa(Pessoa *pessoa);

//  Imprime pessoa
//  inputs: ponteiro para Usuario
//  output: nenhum
//  pre-condicao: Usuario precisa existir
//  pos-condicao: Usuario nao eh alterado
void imprimePessoa(Pessoa* usuario);


// Outras funcoes

void InsereMedidasPessoa(Pessoa* pessoa, int linhaArquivo, char* arquivo);

float calculaDistancia(float lat1, float long1, float lat2, float long2);




#endif
