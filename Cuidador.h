#ifndef CUIDADOR_H
#define CUIDADOR_H

typedef struct cuidador Cuidador;

#include "listaMedidas.h"


//  Função que cria a estrutura cuidador
//  inputs: nome do cuidador
//  output: ponteiro para a estrutura Cuidador
//  pre-condicao: nenhuma
//  pos-condicao: ponteiro de retorno existe e está alocado
Cuidador* criaCuidador(char* nome);

//  Função que libera memória alocada para o cuidador
//  inputs: ponteiro para a estrutura cuidador
//  output: nenhum
//  pre-condicao: Cuidador existe
//  pos-condicao: toda a memória alocada para cuidador foi liberada
void destroiCuidador(Cuidador* cuidador);

//  Função que retorna o nome do cuidador
//  inputs: ponteiro para a estrutura cuidador
//  output: ponteiro para char
//  pre-condicao: cuidador existe
//  pos-condicao: cuidador nao é modificado
char* retornaNomeCuidador(Cuidador* cuidador);

//  Função que retorna a lista de medidas do cuidador
//  inputs: ponteiro para a estrutura cuidador
//  output: ponteiro para ListMedidas
//  pre-condicao: cuidador existe
//  pos-condicao: cuidador nao é modificado
ListMedidas* retornaListMedidas(Cuidador* cuidador);

//  Imprime cuidador
//  inputs: ponteiro para cuidador
//  output: nenhum
//  pre-condicao: cuidador existe
//  pos-condicao: cuidador nao é alterado
void imprimeCuidador(Cuidador* cuidador);

#endif
