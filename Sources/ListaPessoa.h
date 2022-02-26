#ifndef LISTAPESSOA_H_
#define LISTAPESSOA_H_

typedef struct node Node;
typedef struct listPessoa ListPessoa;

#include "ListaCuidadores.h"
#include "Pessoa.h"
#include "Cuidador.h"


ListPessoa* CriaListaPessoa(void);

/*****************************************************
 *
 * FUNCOES GET - RETORNAM UM ATRIBUTO DO IDOSO
 * 
 *****************************************************/
//  Função que retorna a primeira célula da lista
//  inputs: ponteiro para ListaPessoa
//  output: ponteiro para Node
//  pre-condicao: lista de pessoas existe
//  pos-condicao: lista de pessoas nao é modificada
Node *getPrimeiro(ListPessoa* lista);

//  Função que retorna a última célula da lista
//  inputs: ponteiro para ListaPessoa
//  output: ponteiro para Node
//  pre-condicao: lista de pessoas existe
//  pos-condicao: lista de pessoas nao é modificada
Node *getUltimo(ListPessoa* lista);

//  Função que retorna a próxima célula em relação à célula de input
//  inputs: ponteiro para Node
//  output: ponteiro para Node
//  pre-condicao: lista de pessoas existe
//  pos-condicao: lista de pessoas nao é modificada
Node *getProximo(Node* p);

//  Função que retorna o pessoa de dada célula
//  inputs: ponteiro para celula de pessoa
//  output: ponteiro para pessoa
//  pre-condicao: celula existe
//  pos-condicao: celula nao é modificada
Pessoa *getPessoaCelula(Node* p);



/*****************************************************
 *
 * FUNCOES SET - MODIFICAM UM ATRIBUTO DO IDOSO
 * 
 *****************************************************/
//  Insere dois pessoas como amigo um do outro(amizade reciproca) em suas próprias listas de amigos
//  inputs: ponteiro para ListPessoa e dois ponteiros para char
//  output: nenhum
//  pre-condicao: lista de pessoas existe e pessoas existem
//  pos-condicao: lista de pessoas não é modificada e as listas de amigos de cada pessoa sao modificadas
void novaAmizade(ListPessoa *listPessoa, char* amigo1, char* amigo2);

//  Insere o pessoa no final da lista de amigos
//  inputs: ponteiro para ListPessoa e para pessoa
//  output: nenhum
//  pre-condicao: lista de amigos existe e usuario existe
//  pos-condicao: lista de amigos continua existindo, agora com um novo pessoa
void insereAmigoNaLista(ListPessoa *lista, Pessoa *amigo);

//  Função que insere um pessoa no final de uma lista
//  inputs: ponteiro para a estrutura ListPessoa e o ponteiro para o pessoa
//  output: nenhum
//  pre-condicao: lista de pessoa e pessoa existem
//  pos-condicao: lista continua existindo, agora com pessoa inseridos
void inserePessoa(ListPessoa* lista, Pessoa *usuario);




/*****************************************************************************
 * 
 * OUTRAS FUNÇÕES
 * 
 *****************************************************************************/
//ListPessoa* CriaListaPessoa(void);

ListPessoa* CriaListPessoa(void);

//  Inicializa a lista de pessoa
//  inputs: string com o nome do arquivo com os dados
//  output: ponteiro para a estrutura ListPessoa
//  pre-condicao: nenhuma
//  pos-condicao: ponteiro de retorno existe e está alocado
ListPessoa* inicializaListPessoa(char* arquivo);

//  Função que libera a memória alocada da lista
//  inputs: ponteiro para a estrutura ListPessoa
//  output: nenhum
//  pre-condicao: ListPessoa existe
//  pos-condicao: toda a memória alocada para ListPessoa foi liberada
void destroiListPessoa(ListPessoa* lista);

//  Função que retira um pessoa de uma lista
//  inputs: ponteiro para estrutura listPessoa e string do nome do pessoa
//  output: nenhum
//  pre-condicao: lista de pessoa existe
//  pos-condicao: lista continua existindo, agora com pessoa em questao retirado
void retiraPessoa(ListPessoa* lista, char *nome);

//  Função que retorna o pessoa desejado através do nome, supondo que não haja pessoas de mesmo nome
//  inputs: ponteiro para ListaPessoa e para char
//  output: ponteiro para pessoa
//  pre-condicao: lista de pessoas existe
//  pos-condicao: lista de pessoas nao é modificada
Pessoa *buscaPessoa(ListPessoa *lista, char *nome);



//  Função que imprime os pessoas de uma lista
//  inputs: ponteiro para lista de pessoas
//  output: nenhum
//  pre-condicao: lista de pessoas existe
//  pos-condicao: lista de pessoas nao é alterada
void imprimeListPessoa(ListPessoa* lista);

//  Imprime lista de amigos
//  inputs: ponteiro para ListPessoa
//  output: nenhum
//  pre-condicao: lista de amigos existe
//  pos-condicao: lista de amigos nao é alterada
void imprimeListPessoa(ListPessoa *listPessoa);


void insereLinhaDeMedidaPessoa(ListPessoa* lista, int linha);

void verificaPessoa(ListPessoa* listapessoa, ListCuidador* listacuidador);

Pessoa* RetornaPessoaMaisPerto(Pessoa* pessoa, ListPessoa* listaPessoa);

//Cuidador* RetornaCuidadorMaisPerto(Pessoa* pessoa, ListCuidador* listacuidador);

#endif
