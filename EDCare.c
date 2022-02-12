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
#include "ListaAmigos.h"
#include "ListaCuidadores.h"
#include "ListaIdoso.h"

int main()
{

    printf("Criando lista de idosos...\n");
    ListIdoso *listaIdosos = inicializaListIdoso ( " ./Entrada/apoio.txt " );
	imprimeListIdoso(listaIdosos);

    printf("Preenchendo listas de cuidadores...\n");
    ListCuidador *listaCuidadores = preencheListCuidador("./Entrada/cuidadores.txt");















	return 0;

}
