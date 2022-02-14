#ifndef IDOSO_H_
#define IDOSO_H_

//typedef struct celCuidador CelCuidador;
//typedef struct listCuidador ListCuidador;
typedef struct idoso Idoso;

//#include "ListaAmigos.h"
#include "ListaCuidadores.h"
#include "ListaIdoso.h"




//  Cria estrutura idoso
//  inputs: nome do idoso
//  output: ponteiro para a estrutura Idoso
//  pre-condicao: não existe
//  pos-condicao: ponteiro da estrutura alocado pronto para uso

Idoso *criaIdoso(char *nome);

//  Libera memória alocada para o idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: nenhum
//  pre-condicao: idoso existe
//  pos-condicao: a memória alocada para a estrutura Idoso foi liberada
//
void destroiIdoso(Idoso *idoso);


//  Retorna o nome do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: nome do idoso
//  pre-condicao: idoso existe
//  pos-condicao: idoso nao é modificado e nome do idoso disponível

char *retornaNomeIdoso(Idoso *idoso);



//  Retorna Lista de amigos do idoso
//  inputs: ponteiro para estrutura Idoso
//  output: ponteiro para estrutura ListAmigos
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é alterado e lista de amigos disponível

ListAmigos *retornaListAmigosIdoso(Idoso *idoso);

void InsereMedidasIdoso(Idoso* idoso, int linhaArquivo, char* arquivo);

void LeLinhaCuidadorNoIdoso(char* arquivo, ListIdoso* listaIdoso, ListCuidador* listaCuidador);

void InsereCuidadorNoIdoso(Idoso* idoso, Cuidador* cuidador);

//int ContadorDeTokensLinha(char* linha);


//  Imprime idoso
//  inputs: ponteiro para Usuario
//  output: nenhum
//  pre-condicao: Usuario precisa existir
//  pos-condicao: Usuario nao eh alterado
void imprimeIdoso(Idoso* usuario);





#endif
