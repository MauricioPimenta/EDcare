#ifndef LISTACUIDADORES_H_
#define LISTACUIDADORES_H_

#include "Cuidador.h"
#include "ListaIdoso.h"

typedef struct celCuidador CelCuidador;
typedef struct listCuidador ListCuidador;

//  Funcao que inicializa a lista de cuidadores
//  inputs: nenhum
//  output: ponteiro para a estrutura ListCuidador
//  pre-condicao: nenhuma
//  pos-condicao: ponteiro de retorno existe e esta alocado
ListCuidador* inicializaListaCuidador(void);

//  Libera memoria alocada para a lista de cuidadores
//  inputs: ponteiro para a estrutura ListCuidador
//  output: nenhum
//  pre-condicao: ListCuidador precisa existir
//  pos-condicao: toda a memoria alocada para ListCuidador foi liberada
void destroiListCuidador(ListCuidador *lista);


/*****************************************************
 *
 * FUNCOES GET - RETORNAM UM ATRIBUTO DO IDOSO
 * 
 */

//  Funcao que retorna o cuidador da celula
//  inputs: ponteiro para celula de cuidador
//  output: ponteiro para cuidador
//  pre-condicao: celula existe
//  pos-condicao: celula nao e modificada
Cuidador* getCuidadorDaCelula(CelCuidador* p);

//  Funcao que retorna a proxima celula
//  inputs: ponteiro para CelCuidador
//  output: ponteiro para CelCuidador
//  pre-condicao: lista de cuidador existe
//  pos-condicao: lista de cuidador nao e modificada
CelCuidador *getProximoCuidador(CelCuidador *p);

//  Funcao que retorna primeira celula
//  inputs: ponteiro para ListCuidador
//  output: ponteiro para CelCuidador
//  pre-condicao: lista de cuidadores precisa existir
//  pos-condicao: lista de cuidadores nao e modificada
CelCuidador *getPrimeiroCuidador(ListCuidador *lista);



/*****************************************************
 *
 * FUNCOES SET - INSEREM UM ATRIBUTO DO IDOSO
 * 
 */

//  Funcao que preenche a lista de cuidadores
//  inputs: string com o nome do arquivo com os nomes dos cuidadores
//  output: nenhum
//  pre-condicao: lista de cuidadores cujos nomes sao separados com ";", todos dispostos na primeira linha do arquivo de texto
//  pos-condicao: lista de cuidadores criada
ListCuidador *setListCuidador(char* arquivo);

//  Funcao que cria e insere o cuidador no final da lista
//  inputs: ponteiro para a estrutura ListCuidador e ponteiro para char
//  output: ponteiro para o cuidador criada
//  pre-condicao: lista de cuidador existe
//  pos-condicao: lista de cuidador continua existindo, agora com um novo cuidador
CelCuidador* setCuidador (ListCuidador* lista, char* nome);

//  Funcao que insere um cuidador que ja existe no inicio da lista
//  inputs: ponteiro para a estrutura ListCuidador e o ponteiro para Cuidador
//  output: nenhum
//  pre-condicao: lista de cuidadores e cuidador existem
//  pos-condicao: lista de cuidadores continua existindo, agora com um novo cuidador
void setNovoCuidador(ListCuidador* lista, Cuidador *cuidador);






//  Funcao que retira cuidador da lista de cuidadores
//  inputs: ponteiro para a estrutura ListCuidador e o ponteiro para CelCuidador
//  output: nenhum
//  pre-condicao: lista de cuidadores existe
//  pos-condicao: lista de cuidadores continua existindo, agora com cuidador desejado retirado
void retiraCuidadorDaLista(ListCuidador* lista, CelCuidador* cuidador);



//  Funaoo que retorna cuidador com o nome especificado
//  inputs: ponteiro para ListCuidador e ponteiro para char
//  output: ponteiro para cuidador
//  pre-condicao: lista de cuidador precisa existir
//  pos-condicao: lista de cuidador nao e modificada
Cuidador* buscaCuidador(ListCuidador* lista, char* nome);

//  Funaoo que retorna a celula que contem o cuidador com o nome especificado
//  inputs: ponteiro para ListCuidador e ponteiro para char
//  output: ponteiro para CelCuidador
//  pre-condicao: lista de cuidadores existe
//  pos-condicao: lista de cuidadores nao e modificada
CelCuidador* buscaCuidadorERetornaCelula(ListCuidador* lista, char* nome);

/* Funaoo que imprime lista de cuidadores
 * inputs: ponteiro para ListCuidador
 * output: nenhum
 * pre-condicao: lista de cuidadores existe
 * pos-condicao: lista de cuidadores nao e alterada
 */
void imprimeListCuidador(ListCuidador* lista);

#endif
