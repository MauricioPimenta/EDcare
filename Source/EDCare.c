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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Idoso.h"
#include "Cuidador.h"

#include "ListaCuidadores.h"
#include "ListaIdoso.h"

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













	return 0;

}
