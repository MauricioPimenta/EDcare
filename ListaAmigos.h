#ifndef LISTA_AMIGOS_H_
#define LISTA_AMIGOS_H_

typedef struct listAmigos ListAmigos;
typedef struct celAmigos CelAmigos;

#include "ListaIdoso.h"


//  Inicializa a lista de amigos de um idoso
//  inputs: nenhum
//  output: ponteiro para a estrutura ListAmigos
//  pre-condicao: nenhuma
//  pos-condicao: ponteiro de retorno existe e esta alocado pronto para uso
ListAmigos *inicializaListaAmigo(void);

//  Libera mem�ria alocada para a lista de amigos
//  inputs: ponteiro para ListAmigos
//  output: nenhum
//  pre-condicao: lista de amigos existe
//  pos-condicao: a mem�ria alocada para ListAmigos foi liberada
void destroiListaAmigos(ListAmigos *listAmigos);

//  Insere o idoso no final da lista de amigos
//  inputs: ponteiro para ListAmigos e para idoso
//  output: nenhum
//  pre-condicao: lista de amigos existe e usuario existe
//  pos-condicao: lista de amigos continua existindo, agora com um novo idoso
void insereAmigoNaLista(ListAmigos *lista, Idoso *amigo);

//  Insere dois idosos como amigo um do outro(amizade reciproca) em suas pr�prias listas de amigos
//  inputs: ponteiro para ListIdoso e dois ponteiros para char
//  output: nenhum
//  pre-condicao: lista de idosos existe e idosos existem
//  pos-condicao: lista de idosos n�o � modificada e as listas de amigos de cada idoso sao modificadas
void insereAmizade(ListIdoso *listIdoso, char* amigo1, char* amigo2);

//  Busca amigo pelo seu nome
//  inputs: ponteiro para ListAmigos e para char
//  output: ponteiro para idoso
//  pre-condicao: lista de amigos existe
//  pos-condicao: lista de amigos nao � alterada
Idoso* buscaAmigoPorNome(ListAmigos* lista, char* nome);

//  Imprime lista de amigos
//  inputs: ponteiro para ListAmigos
//  output: nenhum
//  pre-condicao: lista de amigos existe
//  pos-condicao: lista de amigos nao � alterada
void imprimeListAmigos(ListAmigos *listAmigos);







/* Retira o amigo da lista de amigos
 * inputs: lista de amigos e nome do amigo a ser retirado
 * output: nenhum
 * pre-condicao: lista de amigos precisa existir e usuario do amigo precisa existir
 * pos-condicao: lista de amigos continua existindo, agora com um amigo retirado
 */
//void retiraAmigo(ListAmigos* lista, char *nome);

#endif
