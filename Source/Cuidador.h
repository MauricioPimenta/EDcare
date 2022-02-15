#ifndef CUIDADOR_H
#define CUIDADOR_H

typedef struct cuidador Cuidador;

//  Funcao que cria a estrutura cuidador
//  inputs: nome do cuidador
//  output: ponteiro para a estrutura Cuidador
//  pre-condicao: nome existe
//  pos-condicao: ponteiro de retorno existe e esta alocado
Cuidador* criaCuidador(char* nome);

//  Funcao que libera memoria alocada para o cuidador
//  inputs: ponteiro para a estrutura cuidador
//  output: nenhum
//  pre-condicao: Cuidador existe
//  pos-condicao: toda a memoria alocada para cuidador foi liberada
void destroiCuidador(Cuidador* cuidador);


/*****************************************************
 *
 * FUNCOES GET - RETORNAM UM ATRIBUTO DO CUIDADOR
 * 
 *****************************************************/
//  Funcao que retorna o nome do cuidador
//  inputs: ponteiro para a estrutura cuidador
//  output: String - ponteiro para char
//  pre-condicao: cuidador existe
//  pos-condicao: cuidador nao e modificado
char* getNomeCuidador(Cuidador* cuidador);

//  Funcao que retorna a latitude do cuidador
//  inputs: ponteiro para a estrutura cuidador
//  output: inteiro com dados da latitude
//  pre-condicao: cuidador existe
//  pos-condicao: cuidador nao e modificado
int getLatitudeCuidador(Cuidador* cuidador);

//  Funcao que retorna a longitude do cuidador
//  inputs: ponteiro para a estrutura cuidador
//  output: inteiro com dados da longitude
//  pre-condicao: cuidador existe
//  pos-condicao: cuidador nao e modificado
int getLongitudeCuidador(Cuidador* cuidador);



/*****************************************************
 *
 * FUNCOES SET - MODIFICAM UM ATRIBUTO DO CUIDADOR
 * 
 *****************************************************/

/*
 * Modifca a Latitude do Cuidador
 */
void setLatitudeCuidador(Cuidador* c, float lat);

/*
 * Modifca a Longitude do Cuidador
 */
void setLongitudeCuidador(Cuidador* c, float l);



/*****************************************************************************
 * 
 * OUTRAS FUNÇÕES
 * 
 *****************************************************************************/
//  Imprime cuidador
//  inputs: ponteiro para cuidador
//  output: nenhum
//  pre-condicao: cuidador existe
//  pos-condicao: cuidador nao e alterado
void imprimeCuidador(Cuidador* cuidador);

#endif

