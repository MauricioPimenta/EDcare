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
float calculaDistancia(float lat1, float long1, float lat2, float long2);

int ContadorDeLinhasArquivo(char* arquivo);

/*
 * FUNÇÃO PRINCIPAL DO PROGRAMA
 */
int main(){
	
	float calculaDistancia(float lat1, float long1, float lat2, float long2){
        float resultado = sqrt(pow(fabs(lat1 - lat2), 2) + pow(fabs(long1 - long2), 2));
        return resultado;
    }
	
	int ContadorDeLinhasArquivo(char* arquivo){
        FILE* fp = fopen(arquivo, "r");
        char conteudo[10000];
        int cont = 0;

        fscanf(fp, "%[^EOF]", conteudo);

        char* linhas = strtok(conteudo, "\n");

        while(linhas != NULL){
            linhas = strtok(NULL, "\n");
            cont++;
        }
        fclose(fp);

        return cont;
    }

   
}
