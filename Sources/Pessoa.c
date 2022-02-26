/*
 * INCLUSAO DE BIBLIOTECAS
 */

// BIBLIOTECAS PADRÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// BIBLIOTECAS DO USUÁRIO
#include "Pessoa.h"
//#include "ListaCuidadores.h"

// Constantes da inicialização de pessoa
#define LAT_INIT 0
#define LONG_INIT 0
#define TEMP_INIT 0
#define LAT_INIT 0

#define ERRO_signal -1

/*
 * Definição da Estrutura do TAD Pessoa
 */
struct pessoa{
	char *nome; // Nome e principal identificador do pessoa

	// Listas de amigos e cuidadores
	ListPessoa *amigos;
	ListPessoa *cuidadores;

	// Atributos para guardar as informações do pessoa
	float latitude;
	float longitude;
	float temperatura;
	bool queda;
	int numFebresBaixas;

	// Arquivos de entrada e saida para leitura dos dados e 
	// escrita do log de ações realizadas
	char *strFileIn;
	char *strFileOut;
	FILE *fileIn;
	FILE *fileOut;
};

//  Cria estrutura pessoa
//  inputs: nome do pessoa
//  output: ponteiro para a estrutura Pessoa
//  pre-condicao: não existe
//  pos-condicao: ponteiro da estrutura alocado pronto para uso
Pessoa* criaPessoa(char *nome){

	// Retorna nada se o nome não for válido
	if (nome == NULL){
		return NULL;
	}
	
	// Reserva espaço na memória e armazena o nome
	Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa));
	pessoa->nome = strdup(nome);

	// Define nome de arquivo de entrada
	pessoa->strFileIn = strcat(nome, ".txt");
//	pessoa->strFileOut = strcat(nome, "-saida.txt");

	// Cria as listas de amigos e Cuidadores
	pessoa->amigos = CriaListPessoa();
	pessoa->cuidadores = novaListaCuidador();

	// Inicializa os atributos do Pessoa com valores padrão (zero)
	pessoa->latitude = LAT_INIT;
	pessoa->longitude = LONG_INIT;
	pessoa->temperatura = TEMP_INIT;
	pessoa->queda = false;
	pessoa->numFebresBaixas = 0;

  return pessoa;
}

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
char *getNomePessoa(Pessoa *pessoa){
	
	// Se pessoa não existir, retorna nada
	if (pessoa == NULL){
		return NULL;
	}
	// Se existir, retorna o nome do pessoa
	else
		return pessoa->nome;
}

//  Retorna Lista de amigos do pessoa
//  inputs: ponteiro para estrutura Pessoa
//  output: ponteiro para estrutura ListPessoa
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é alterado e lista de amigos disponível
//
ListPessoa *getListAmigosPessoa(Pessoa *pessoa){

	// Se pessoa não existir, retorna nada
	if (pessoa == NULL){
		return NULL;
	}
	else
		return pessoa->amigos;
}

//  Retona a lista de cuidadores do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: ponteiro para uma Lista de Cuidadores
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e estrutura dos cuidadores disponível
ListPessoa *getListCuidadores(Pessoa *pessoa){

	// Se pessoa não existir, retorna nada
	if (pessoa == NULL){
		return NULL;
	}
	else
  		return pessoa->cuidadores;
}

//  Retona a latitude do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: numero real type float
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e latitude disponível
float getLatitudePessoa(Pessoa *pessoa){

	// Se pessoa não existir, retorna sinal de erro (-1)
	if (pessoa == NULL){
		return ERRO_signal;
	}
	else
		return pessoa->latitude;
}

//  Retona a longitude do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: numero real type float
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e longitude disponível
//
float getLongitudePessoa(Pessoa *pessoa){

	// Se pessoa não existir, retorna sinal de erro (-1)
	if (pessoa == NULL){
		return ERRO_signal;
	}
	else
		return pessoa->longitude;
}

//  Retona a temperatura do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: temperatura, um numero real type float
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e temperatura disponível
//
float getTemperaturaPessoa(Pessoa* pessoa){

	// Se pessoa não existir, retorna sinal de erro (-1)
	if (pessoa == NULL){
		return ERRO_signal;
	}
	else
		return pessoa->temperatura;
}



//  Retona informacao de queda do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: boolean que indica se pessoa sofreu queda
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e 'informacao de queda' disponível
//
bool getQuedaPessoa(Pessoa* pessoa){

	// Se pessoa não existir, retorna sinal de erro (-1)
	if (pessoa == NULL){
		return ERRO_signal;
	}
	else
		return pessoa->queda;
}

//  Retona a quantidade de febres baixas do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: inteiro com a quantidade de febres baixas
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e quantidade de febres disponível
//
int getNumFebresBaixas(Pessoa* pessoa){

	// Se pessoa não existir, retorna sinal de erro (-1)
	if (pessoa == NULL){
		return ERRO_signal;
	}
	else
		return pessoa->numFebresBaixas;
}

//  Retona o nome do arquivo de entradas (infos) do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: string com o nome do arquivo
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e nome do arquivo disponível
//
char* getNomeArquivoEntradaPessoa(Pessoa* pessoa){
	if(pessoa == NULL)
		return NULL;
	else
		return pessoa->strFileIn;
}

//  Retona o nome do arquivo de saidas (log) do pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output: string com o nome do arquivo
//  pre-condicao: pessoa precisa existir
//  pos-condicao: pessoa nao é modificado e nome do arquivo disponível
//
char* getNomeArquivoSaidaPessoa(Pessoa* pessoa){
	if(pessoa == NULL)
		return NULL;
	else
		return pessoa->strFileOut;

}


/*****************************************************
 *
 * FUNCOES SET - MODIFICAM UM ATRIBUTO DO IDOSO
 * 
 ****************************************************/

//  Modifica a Latitude do Pessoa
//  inputs: 
//		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
//		- float lat = latitude do pessoa, do tipo float
//
//  output: nada
//  pre-condicao: pessoa precisa existir e latituda positiva
//  pos-condicao: latitude do pessoa modificada
//
void setLatitudePessoa(Pessoa *pessoa, float lat){

	// Se pessoa existir e lat não for negativo, modifica a latitude
	if (pessoa != NULL && lat >= 0)
		pessoa->latitude = lat;
}



//  Modifica a Longitude do Pessoa
//  inputs: 
//		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
//		- float longit = longitude do pessoa, do tipo float
//
//  output: nada
//  pre-condicao: pessoa precisa existir e longitude não negativa
//  pos-condicao: logitude do pessoa modificada
//
void setLongitudePessoa(Pessoa *pessoa, float longit){

	// Se pessoa existir e longit não for negativo, modifica a latitude
	if (pessoa != NULL && longit >= 0)
		pessoa->longitude = longit;
}


//  Modifica a Temperatura do Pessoa
//  inputs: 
//		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
//		- float temp = temperatura do pessoa, do tipo float
//
//  output: nada
//  pre-condicao: pessoa precisa existir e temperatura positiva
//  pos-condicao: temperatura do pessoa modificada
//
void setTemperaturaPessoa(Pessoa* pessoa, float temp){

	if (pessoa != NULL && temp >= 0)
		pessoa->temperatura = temp;
}

//  Define o valor de queda do Pessoa
//  inputs: 
//		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
//		- bool queda = true ou false, indica se houve queda
//
//  output: nada
//  pre-condicao: pessoa precisa existir
//  pos-condicao: queda do pessoa modificada
//
void setQuedaPessoa(Pessoa* pessoa, bool queda){

	if (pessoa != NULL)
		pessoa->queda = queda;
}

//  Define o valor de queda do Pessoa
//  inputs: 
//		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
//		- int febres = quantidade de febres baixas
//
//  output: nada
//  pre-condicao: pessoa precisa existir e febres >= 0
//  pos-condicao: quantidade de febres do pessoa modificada
//
void setNumFebresBaixas(Pessoa* pessoa, int febres){

	if (pessoa != NULL && febres >= 0)
		pessoa->numFebresBaixas = febres;
}

/*  Incrementa o valor de queda do Pessoa
 *  Inputs: 
 *		- Pessoa* pessoa = ponteiro para a estrutura Pessoa
 * 
 *  pre-condicao: pessoa precisa existir
 *  pos-condicao: quantidade de febres baixas do pessoa incrementada em 1.
 */
void increaseNumFebresBaixas(Pessoa *pessoa){

	if (pessoa != NULL)
		pessoa->numFebresBaixas++;
}

//  Libera memória alocada para o pessoa
//  inputs: ponteiro para a estrutura Pessoa
//  output:  0	->	tudo certo
//			-1	->	pessoa não existe
//  pre-condicao: pessoa existe
//  pos-condicao: a memória alocada para a estrutura Pessoa foi liberada
//
int destroiPessoa(Pessoa *pessoa){

	// Se Pessoa não existe, retorna um código de erro
	if (pessoa == NULL){
		return -1;
	}
	// Se existir, libera a memoria
	else{ 
		free(pessoa->nome);
  		free(pessoa->cuidadores);
  		free(pessoa->amigos);
  		free(pessoa);
	}
	return 0;
}

//  Imprime pessoa
//  inputs: ponteiro para Usuario
//  output: nenhum
//  pre-condicao: Usuario precisa existir
//  pos-condicao: Usuario nao eh alterado
//
void imprimePessoa(Pessoa* pessoa){

	if (pessoa != NULL){
	printf("Nome: %s\n", pessoa->nome);
	imprimeListCuidador(pessoa->cuidadores);
	imprimeListPessoa(pessoa->amigos);
	printf("%f, %f, %f, %d", pessoa->temperatura, pessoa->latitude, pessoa->longitude, pessoa->queda);
	}
}


void InsereMedidasPessoa(Pessoa* pessoa, int linhaArquivo, char* arquivo){

    FILE *fp = fopen(arquivo, "r");

    if(fp == NULL){
        printf("Erro no arquivo de medidas de %s.\n", getNomePessoa(pessoa));
        return;
    }
    if(linhaArquivo == 1){
        char linha[1000];
        fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
        char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

        int k = 0;  //auxilia na inser��o das medidas nos campos corretos atrav�s das condicoes
        while(medida != NULL){
            k++;
            if(k == 1){
                pessoa->temperatura = atof(medida);
            }
            else if(k == 2){
                pessoa->latitude = atof(medida);
            }
            else if(k == 3){
                pessoa->longitude = atof(medida);
            }
            else{
                pessoa->queda = atoi(medida);
            }

            medida = strtok(NULL, ";");
        }
    }
    else{
        char linha[1000];
        int i;
        for(i = 0; i < linhaArquivo - 1; i++){
            fscanf(fp, "%[^\n]\n", linha);  //le at� a ultima linha antes da linha de interesse
        }

        fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
        char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

        int k = 0;  //auxilia na inser��o das medidas nos campos corretos atrav�s das condicoes
        while(medida != NULL){
            k++;
            if(k == 1){
                pessoa->temperatura = atof(medida);
            }
            else if(k == 2){
                pessoa->latitude = atof(medida);
            }
            else if(k == 3){
                pessoa->longitude = atof(medida);
            }
            else{
                pessoa->queda = atoi(medida);
            }

            medida = strtok(NULL, ";");
        }
    }

    fclose(fp);
}


float calculaDistancia(float lat1, float long1, float lat2, float long2){
        float resultado = sqrt(pow(fabs(lat1 - lat2), 2) + pow(fabs(long1 - long2), 2));
        return resultado;
    }