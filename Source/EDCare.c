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

void funcaoEDCare(ListIdoso* listaIdoso, ListCuidador* listaCuidador);

/*
 * FUNÇÃO PRINCIPAL DO PROGRAMA
 */
int main(){
	
	float calculaDistancia(float lat1, float long1, float lat2, float long2){
        float resultado = sqrt(pow(fabs(lat1 - lat2), 2) + pow(fabs(long1 - long2), 2));
        return resultado;
    }
	
//=======================================================================================================
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

//=======================================================================================================
	
	void funcaoEDCare(ListIdoso* listaIdoso, ListCuidador* listaCuidador){

        int numLinhas;

        //a linha abaixo conta quantas linhas os arquivos tem, pegando como referencia um arquivo de cuidador, visto que todos tem o mesmo tamanho
        char* nomeCuid = strdup(retornaNomeCuidador(retornaCuidadorDaCelula(retornaPrimeiroCuidador(listaCuidador))));
        numLinhas = ContadorDeLinhasArquivo(strcat(nomeCuid, ".txt"));
        printf("%i linhas\n\n", numLinhas);

        free(nomeCuid);  //liberando a memoria do char* duplicado

        int linha;
        for(linha = 1; linha <= numLinhas; linha++){
            //fazer as operacoes principais dentro deste for(), pois nele o acesso aos dados fica automatizado por linhas

            insereLinhaDeMedidaIdoso(listaIdoso, linha);
            insereLinhaDeMedidaCuidador(listaCuidador, linha);


            // FAZER OPERACOES AQUI <----------------------------------------------------------
        }
    }
	
	
//===============================================================================================================================================
//===============================================================================================================================================
//FUNCOES DOS TADS LISTAIDOSO E LISTACUIDADOR (usei na função q ta aqui na EDCare.c, a funcao "funcaoEDCare")
	
	void insereLinhaDeMedidaIdoso(ListIdoso* lista, int linha){
    CelIdoso* p;
    for(p = lista->prim; p != NULL; p = p->prox){
        Idoso* idoso = retornaIdosoCelula(p);
        char* nomeIdoso = strdup(retornaNomeIdoso(idoso));

        char* arquivo = strcat(nomeIdoso, ".txt");
        InsereMedidasIdoso(idoso, linha, arquivo);

        free(nomeIdoso);
    }
}
   
//=========================================================
	
	void insereLinhaDeMedidaCuidador(ListCuidador* lista, int linha){
    CelCuidador* p;
    for(p = lista->prim; p != NULL; p = p->prox){
        Cuidador* cuidador = retornaCuidadorDaCelula(p);
        char* nomeCuidador = strdup(retornaNomeCuidador(cuidador));

        char* arquivo = strcat(nomeCuidador, ".txt");
        InsereMedidasCuidador(cuidador, linha, arquivo);

        free(nomeCuidador);
    }
}
	
//========================================================

	
	

}
