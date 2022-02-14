#ifndef LISTAIDOSO_H_
#define LISTAIDOSO_H_

typedef struct celIdoso CelIdoso;
typedef struct listIdoso ListIdoso;
typedef struct listAmigos ListAmigos;

#include "Idoso.h"
#include "Cuidador.h"
#include "ListaCuidadores.h"

//ListIdoso* CriaListaIdoso(void);

ListAmigos* CriaListAmigos(void);

//  Inicializa a lista de idoso
//  inputs: string com o nome do arquivo com os dados
//  output: ponteiro para a estrutura ListIdoso
//  pre-condicao: nenhuma
//  pos-condicao: ponteiro de retorno existe e está alocado
ListIdoso* inicializaListIdoso(char* arquivo);

//  Insere dois idosos como amigo um do outro(amizade reciproca) em suas próprias listas de amigos
//  inputs: ponteiro para ListIdoso e dois ponteiros para char
//  output: nenhum
//  pre-condicao: lista de idosos existe e idosos existem
//  pos-condicao: lista de idosos não é modificada e as listas de amigos de cada idoso sao modificadas
void insereAmizade(ListIdoso *listIdoso, char* amigo1, char* amigo2);

//  Insere o idoso no final da lista de amigos
//  inputs: ponteiro para ListAmigos e para idoso
//  output: nenhum
//  pre-condicao: lista de amigos existe e usuario existe
//  pos-condicao: lista de amigos continua existindo, agora com um novo idoso
void insereAmigoNaLista(ListAmigos *lista, Idoso *amigo);


//  Função que libera a memória alocada da lista
//  inputs: ponteiro para a estrutura ListIdoso
//  output: nenhum
//  pre-condicao: ListIdoso existe
//  pos-condicao: toda a memória alocada para ListIdoso foi liberada
void destroiListIdoso(ListIdoso* lista);

//  Função que insere um idoso no final de uma lista
//  inputs: ponteiro para a estrutura ListIdoso e o ponteiro para o idoso
//  output: nenhum
//  pre-condicao: lista de idoso e idoso existem
//  pos-condicao: lista continua existindo, agora com idoso inseridos
void insereIdoso(ListIdoso* lista, Idoso *usuario);

//  Função que retira um idoso de uma lista
//  inputs: ponteiro para estrutura listIdoso e string do nome do idoso
//  output: nenhum
//  pre-condicao: lista de idoso existe
//  pos-condicao: lista continua existindo, agora com idoso em questao retirado
void retiraIdoso(ListIdoso* lista, char *nome);

//  Função que retorna o idoso desejado através do nome, supondo que não haja idosos de mesmo nome
//  inputs: ponteiro para ListaIdoso e para char
//  output: ponteiro para idoso
//  pre-condicao: lista de idosos existe
//  pos-condicao: lista de idosos nao é modificada
Idoso *buscaIdoso(ListIdoso *lista, char *nome);

//  Função que retorna a primeira célula da lista
//  inputs: ponteiro para ListaIdoso
//  output: ponteiro para CelIdoso
//  pre-condicao: lista de idosos existe
//  pos-condicao: lista de idosos nao é modificada
CelIdoso *retornaPrimeiro(ListIdoso* lista);

//  Função que retorna a última célula da lista
//  inputs: ponteiro para ListaIdoso
//  output: ponteiro para CelIdoso
//  pre-condicao: lista de idosos existe
//  pos-condicao: lista de idosos nao é modificada
CelIdoso *retornaUltimo(ListIdoso* lista);

//  Função que retorna a próxima célula em relação à célula de input
//  inputs: ponteiro para CelIdoso
//  output: ponteiro para CelIdoso
//  pre-condicao: lista de idosos existe
//  pos-condicao: lista de idosos nao é modificada
CelIdoso *retornaProximo(CelIdoso* p);

//  Função que retorna o idoso de dada célula
//  inputs: ponteiro para celula de idoso
//  output: ponteiro para idoso
//  pre-condicao: celula existe
//  pos-condicao: celula nao é modificada
Idoso *retornaIdosoCelula(CelIdoso* p);

//  Função que imprime os idosos de uma lista
//  inputs: ponteiro para lista de idosos
//  output: nenhum
//  pre-condicao: lista de idosos existe
//  pos-condicao: lista de idosos nao é alterada
void imprimeListIdoso(ListIdoso* lista);

//  Imprime lista de amigos
//  inputs: ponteiro para ListAmigos
//  output: nenhum
//  pre-condicao: lista de amigos existe
//  pos-condicao: lista de amigos nao é alterada
void imprimeListAmigos(ListAmigos *listAmigos);

#endif
