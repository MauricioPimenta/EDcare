#ifndef IDOSO_H_
#define IDOSO_H_

typedef struct idoso Idoso;

#include "ListaAmigos.h"
#include "ListaCuidadores.h"


//  Cria estrutura idoso
//  inputs: nome do idoso
//  output: ponteiro para a estrutura Idoso
//  pre-condicao: n�o existe
//  pos-condicao: ponteiro da estrutura alocado pronto para uso

Idoso *criaIdoso(char *nome);

//  Libera mem�ria alocada para o idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: nenhum
//  pre-condicao: idoso existe
//  pos-condicao: a mem�ria alocada para a estrutura Idoso foi liberada
//
void destroiIdoso(Idoso *idoso);


//  Retorna o nome do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: nome do idoso
//  pre-condicao: idoso existe
//  pos-condicao: idoso nao � modificado e nome do idoso dispon�vel

char *retornaNomeIdoso(Idoso *idoso);

//  Retona a lista de cuidadores do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: ponteiro para a estrutura ListCuidadores
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao � modificado e estrutura dos cuidadores dispon�vel

ListCuidadores *retornaListCuidadores(Idoso *idoso);

//  Retorna Lista de amigos do idoso
//  inputs: ponteiro para estrutura Idoso
//  output: ponteiro para estrutura ListAmigos
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao � alterado e lista de amigos dispon�vel

ListAmigos *retornaListAmigosIdoso(Idoso *idoso);

//  Imprime Usuario
//  inputs: ponteiro para Usuario
//  output: nenhum
//  pre-condicao: Usuario precisa existir
//  pos-condicao: Usuario nao eh alterado

void imprimeUsuario(Usuario* usuario);







/*Retorna Lista de musicas do Usuario
 * inputs: ponteiro para struct Usuario
 * output: ponteiro para struct ListMusic
 * pre-condicao: Usuario precisa existir
 * pos-condicao: Usuario nao eh alterado
 */
//ListMusica *retornaPlaylistUsuario(Usuario *usuario);



#endif
