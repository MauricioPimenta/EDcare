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
#include "Idoso.h"
#include "ListaCuidadores.h"
#include "ListaIdoso.h"

// Constantes da inicialização de idoso
#define LAT_INIT 0
#define LONG_INIT 0
#define TEMP_INIT 0
#define LAT_INIT 0

#define ERRO_signal -1

/*
 * Definição da Estrutura do TAD Idoso
 */
struct idoso{
	char *nome; // Nome e principal identificador do idoso

	// Listas de amigos e cuidadores
	ListAmigos *amigos;
	ListCuidador *cuidadores;

	// Atributos para guardar as informações do idoso
	float latitude;
	float longitude;
	float temperatura;
	bool queda;
	int numFebresBaixas;

	// Arquivos de entrada e saida para leitura dos dados e ações realizadas
	char *strFileIn;
	char *strFileOut;
	FILE *fileIn;
	FILE *fileOut;
};

//  Cria estrutura idoso
//  inputs: nome do idoso
//  output: ponteiro para a estrutura Idoso
//  pre-condicao: não existe
//  pos-condicao: ponteiro da estrutura alocado pronto para uso
Idoso* criaIdoso(char *nome){

	// Retorna nada se o nome não for válido
	if (nome == NULL){
		return NULL;
	}
	
	// Reserva espaço na memória e armazena o nome
	Idoso* idoso = (Idoso*)malloc(sizeof(Idoso));
	idoso->nome = strdup(nome);

	// Define nome de arquivo de entrada
//	idoso->strFileIn = strcat(nome, ".txt");
//	idoso->strFileOut = strcat(nome, "-saida.txt");

	// Cria as listas de amigos e Cuidadores
	idoso->amigos = CriaListAmigos();
	idoso->cuidadores = novaListaCuidador();

	// Inicializa os atributos do Idoso com valores padrão (zero)
	idoso->latitude = LAT_INIT;
	idoso->longitude = LONG_INIT;
	idoso->temperatura = TEMP_INIT;
	idoso->queda = false;
	idoso->numFebresBaixas = 0;

  return idoso;
}

/*****************************************************
 *
 * FUNCOES GET - RETORNAM UM ATRIBUTO DO IDOSO
 * 
 *****************************************************/

//  Retorna o nome do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: nome do idoso
//  pre-condicao: idoso existe
//  pos-condicao: idoso nao é modificado e nome do idoso disponível
char *getNomeIdoso(Idoso *idoso){
	
	// Se idoso não existir, retorna nada
	if (idoso == NULL){
		return NULL;
	}
	// Se existir, retorna o nome do idoso
	else
		return idoso->nome;
}

//  Retorna Lista de amigos do idoso
//  inputs: ponteiro para estrutura Idoso
//  output: ponteiro para estrutura ListAmigos
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é alterado e lista de amigos disponível
//
ListAmigos *getListAmigosIdoso(Idoso *idoso){

	// Se idoso não existir, retorna nada
	if (idoso == NULL){
		return NULL;
	}
	else
		return idoso->amigos;
}

//  Retona a lista de cuidadores do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: ponteiro para uma Lista de Cuidadores
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e estrutura dos cuidadores disponível
ListCuidador *getListCuidadores(Idoso *idoso){

	// Se idoso não existir, retorna nada
	if (idoso == NULL){
		return NULL;
	}
	else
  		return idoso->cuidadores;
}

//  Retona a latitude do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: numero real type float
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e latitude disponível
float getLatitudeIdoso(Idoso *idoso){

	// Se idoso não existir, retorna sinal de erro (-1)
	if (idoso == NULL){
		return ERRO_signal;
	}
	else
		return idoso->latitude;
}

//  Retona a longitude do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: numero real type float
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e longitude disponível
//
float getLongitudeIdoso(Idoso *idoso){

	// Se idoso não existir, retorna sinal de erro (-1)
	if (idoso == NULL){
		return ERRO_signal;
	}
	else
		return idoso->longitude;
}

//  Retona a temperatura do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: temperatura, um numero real type float
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e temperatura disponível
//
float getTemperaturaIdoso(Idoso* idoso){

	// Se idoso não existir, retorna sinal de erro (-1)
	if (idoso == NULL){
		return ERRO_signal;
	}
	else
		return idoso->temperatura;
}



//  Retona informacao de queda do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: boolean que indica se idoso sofreu queda
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e 'informacao de queda' disponível
//
bool getQuedaIdoso(Idoso* idoso){

	// Se idoso não existir, retorna sinal de erro (-1)
	if (idoso == NULL){
		return ERRO_signal;
	}
	else
		return idoso->queda;
}

//  Retona a quantidade de febres baixas do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: inteiro com a quantidade de febres baixas
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e quantidade de febres disponível
//
int getNumFebresBaixas(Idoso* idoso){

	// Se idoso não existir, retorna sinal de erro (-1)
	if (idoso == NULL){
		return ERRO_signal;
	}
	else
		return idoso->numFebresBaixas;
}

//  Retona o nome do arquivo de entradas (infos) do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: string com o nome do arquivo
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e nome do arquivo disponível
//
char* getNomeArquivoEntradaIdoso(Idoso* idoso){
	if(idoso == NULL)
		return NULL;
	else
		return idoso->strFileIn;
}

//  Retona o nome do arquivo de saidas (log) do idoso
//  inputs: ponteiro para a estrutura Idoso
//  output: string com o nome do arquivo
//  pre-condicao: idoso precisa existir
//  pos-condicao: idoso nao é modificado e nome do arquivo disponível
//
char* getNomeArquivoSaidaIdoso(Idoso* idoso){
	if(idoso == NULL)
		return NULL;
	else
		return idoso->strFileOut;

}


/*****************************************************
 *
 * FUNCOES SET - MODIFICAM UM ATRIBUTO DO IDOSO
 * 
 ****************************************************/

//  Modifica a Latitude do Idoso
//  inputs: 
//		- Idoso* idoso = ponteiro para a estrutura Idoso
//		- float lat = latitude do idoso, do tipo float
//
//  output: nada
//  pre-condicao: idoso precisa existir e latituda positiva
//  pos-condicao: latitude do idoso modificada
//
void setLatitudeIdoso(Idoso *idoso, float lat){

	// Se idoso existir e lat não for negativo, modifica a latitude
	if (idoso != NULL && lat >= 0)
		idoso->latitude = lat;
}



//  Modifica a Longitude do Idoso
//  inputs: 
//		- Idoso* idoso = ponteiro para a estrutura Idoso
//		- float longit = longitude do idoso, do tipo float
//
//  output: nada
//  pre-condicao: idoso precisa existir e longitude não negativa
//  pos-condicao: logitude do idoso modificada
//
void setLongitudeIdoso(Idoso *idoso, float longit){

	// Se idoso existir e longit não for negativo, modifica a latitude
	if (idoso != NULL && longit >= 0)
		idoso->longitude = longit;
}


//  Modifica a Temperatura do Idoso
//  inputs: 
//		- Idoso* idoso = ponteiro para a estrutura Idoso
//		- float temp = temperatura do idoso, do tipo float
//
//  output: nada
//  pre-condicao: idoso precisa existir e temperatura positiva
//  pos-condicao: temperatura do idoso modificada
//
void setTemperaturaIdoso(Idoso* idoso, float temp){

	if (idoso != NULL && temp >= 0)
		idoso->temperatura = temp;
}

//  Define o valor de queda do Idoso
//  inputs: 
//		- Idoso* idoso = ponteiro para a estrutura Idoso
//		- bool queda = true ou false, indica se houve queda
//
//  output: nada
//  pre-condicao: idoso precisa existir
//  pos-condicao: queda do idoso modificada
//
void setQuedaIdoso(Idoso* idoso, bool queda){

	if (idoso != NULL)
		idoso->queda = queda;
}

//  Define o valor de queda do Idoso
//  inputs: 
//		- Idoso* idoso = ponteiro para a estrutura Idoso
//		- int febres = quantidade de febres baixas
//
//  output: nada
//  pre-condicao: idoso precisa existir e febres >= 0
//  pos-condicao: quantidade de febres do idoso modificada
//
void setNumFebresBaixas(Idoso* idoso, int febres){

	if (idoso != NULL && febres >= 0)
		idoso->numFebresBaixas = febres;
}

/*  Incrementa o valor de queda do Idoso
 *  Inputs: 
 *		- Idoso* idoso = ponteiro para a estrutura Idoso
 * 
 *  pre-condicao: idoso precisa existir
 *  pos-condicao: quantidade de febres baixas do idoso incrementada em 1.
 */
void increaseNumFebresBaixas(Idoso *idoso){

	if (idoso != NULL)
		idoso->numFebresBaixas++;
}

//  Libera memória alocada para o idoso
//  inputs: ponteiro para a estrutura Idoso
//  output:  0	->	tudo certo
//			-1	->	idoso não existe
//  pre-condicao: idoso existe
//  pos-condicao: a memória alocada para a estrutura Idoso foi liberada
//
int destroiIdoso(Idoso *idoso){

	// Se Idoso não existe, retorna um código de erro
	if (idoso == NULL){
		return -1;
	}
	// Se existir, libera a memoria
	else{ 
		free(idoso->nome);
  		free(idoso->cuidadores);
  		free(idoso->amigos);
  		free(idoso);
	}
	return 0;
}

//  Imprime idoso
//  inputs: ponteiro para Usuario
//  output: nenhum
//  pre-condicao: Usuario precisa existir
//  pos-condicao: Usuario nao eh alterado
//
void imprimeIdoso(Idoso* idoso){

	if (idoso != NULL){
	printf("Nome: %s\n", idoso->nome);
	imprimeListCuidador(idoso->cuidadores);
	imprimeListAmigos(idoso->amigos);
	printf("%f, %f, %f, %d", idoso->temperatura, idoso->latitude, idoso->longitude, idoso->queda);
	}
}


void InsereMedidasIdoso(Idoso* idoso, int linhaArquivo, char* arquivo){

    FILE *fp = fopen(arquivo, "r");

    if(fp == NULL){
        printf("Erro no arquivo de medidas de %s.\n", getNomeIdoso(idoso));
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
                idoso->temperatura = atof(medida);
            }
            else if(k == 2){
                idoso->latitude = atof(medida);
            }
            else if(k == 3){
                idoso->longitude = atof(medida);
            }
            else{
                idoso->queda = atoi(medida);
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
                idoso->temperatura = atof(medida);
            }
            else if(k == 2){
                idoso->latitude = atof(medida);
            }
            else if(k == 3){
                idoso->longitude = atof(medida);
            }
            else{
                idoso->queda = atoi(medida);
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