#ifndef CUIDADOR_H
#define CUIDADOR_H

typedef struct cuidador Cuidador;

#include "listaMedidas.h"


//  Fun��o que cria a estrutura cuidador
//  inputs: nome do cuidador
//  output: ponteiro para a estrutura Cuidador
//  pre-condicao: nenhuma
//  pos-condicao: ponteiro de retorno existe e est� alocado
Cuidador* criaCuidador(char* nome);

//  Fun��o que libera mem�ria alocada para o cuidador
//  inputs: ponteiro para a estrutura cuidador
//  output: nenhum
//  pre-condicao: Cuidador existe
//  pos-condicao: toda a mem�ria alocada para cuidador foi liberada
void destroiCuidador(Cuidador* cuidador);

//  Fun��o que retorna o nome do cuidador
//  inputs: ponteiro para a estrutura cuidador
//  output: ponteiro para char
//  pre-condicao: cuidador existe
//  pos-condicao: cuidador nao � modificado
char* retornaNomeCuidador(Cuidador* cuidador);

//  Fun��o que retorna a lista de medidas do cuidador
//  inputs: ponteiro para a estrutura cuidador
//  output: ponteiro para ListMedidas
//  pre-condicao: cuidador existe
//  pos-condicao: cuidador nao � modificado
ListMedidas* retornaListMedidas(Cuidador* cuidador);

//  Imprime cuidador
//  inputs: ponteiro para cuidador
//  output: nenhum
//  pre-condicao: cuidador existe
//  pos-condicao: cuidador nao � alterado
void imprimeCuidador(Cuidador* cuidador);

#endif
