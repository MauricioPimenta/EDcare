/*----------------------------------------------------------------------------------------------
 * EDCare.c
 * Projeto de um Sistema simplificado de controle de saúde de 
 * idosos utilizando TADs (Tipos Abstratos de Dados) em C.
 * 
 * 
 * 
 * 
 * Autores: Maurício Bittencourt Pimenta e Douglas Stein
 * Data: 02/2022
 ---------------------------------------------------------------------------------------------*/

/* 
 * Bibliotecas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Idoso.h"
#include "Cuidador.h"

#include "ListaCuidadores.h"
#include "ListaIdoso.h"

/*
 *  CABECALHO DE FUNCOES DO PROGRAMA
*/
void InsereMedidasCuidador(Cuidador* cuidador, int linhaArquivo, char* arquivo);


/*
 * FUNÇÃO PRINCIPAL DO PROGRAMA
 */
int main()
{
	// SETUP - Le arquivos de entrada e armazena Idosos, cria suas dependências, etc
	//		 - Inicializa os cuidadores cadastrados e define as dependências entre
	//			idosos e cuidadores.

    printf("Criando lista de idosos...\n");
    ListIdoso *listaIdosos = inicializaListIdoso ( "./Entradas/apoio.txt" );
	imprimeListIdoso(listaIdosos);

    printf("Preenchendo listas de cuidadores...\n");
	ListCuidador *listaCuidadores = preencheListCuidador("./Entradas/cuidadores.txt");

	imprimeListCuidador(listaCuidadores);


	// RUN  - Le arquivos de entrada de cada um dos Idosos e Cuidadores.
	//		- Le a linha 'n' de cada arquivo por vez e depois realiza as operações
	//		  necessárias










	return 0;

}

void InsereMedidasCuidador(Cuidador* cuidador, int linhaArquivo, char* arquivo){

    // FILE *fp = fopen(arquivo, "r");

    // if(fp == NULL){
    //     printf("Erro no arquivo de medidas de %s\n.", retornaNomeCuidador(cuidador));
    // }

    // if(linhaArquivo == 1){
    //     char linha[100];
    //     fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
    //     char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

    //     int k = 0;  //auxilia na inserção das medidas nos campos corretos através das condicoes
    //     while(medida != NULL){
    //         k = k + 1;
    //         if(k == 1){
    //             cuidador->Latitude = atof(medida);
    //         }
    //         else{
    //             cuidador->Longitude = atof(medida);
    //         }

    //         medida = strtok(NULL, ";");
    //     }
    // }
    // else{
    //     char linha[100];
    //     int i;
    //     for(i = 0; i < linhaArquivo - 1; i++){
    //         fscanf(fp, "%[^\n]\n", linha);  //le até a ultima linha antes da linha de interesse
    //     }

    //     fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
    //     char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

    //     int k = 0;  //auxilia na inserção das medidas nos campos corretos através das condicoes
    //     while(medida != NULL){
    //         k = k + 1;
    //         if(k == 1){
    //             cuidador->Latitude = atof(medida);
    //         }
    //         else{
    //             cuidador->Longitude = atof(medida);
    //         }

    //         medida = strtok(NULL, ";");
    //     }
    // }

    // fclose(fp);
}