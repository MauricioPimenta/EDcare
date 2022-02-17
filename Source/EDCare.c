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

void verificaIdoso(ListIdoso* listaidoso, ListCuidador* listacuidador);

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


            verificaIdoso(listaIdoso, listaCuidador);
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

	void verificaIdoso(ListIdoso* listaidoso, ListCuidador* listacuidador){  //funcao que 
    CelIdoso* p;
    for(p = listaidoso->prim; p != NULL; p = p->prox){
        if(retornaQueda(p->idoso) == 1){  //queda prevalece, por isso está no primeiro if()
            //fazer aparecer no arquivo o seguinte: "queda, acionou Cuidador1"
            Cuidador* cuidadorQuedaProximo = RetornaCuidadorMaisPerto(p->idoso, listacuidador);
            char* arquivo = strcat(strdup(retornaNomeIdoso(p->idoso)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "queda, acionou %s\n", retornaNomeCuidador(cuidadorQuedaProximo));

            fclose(arq);

            if(retornaTemperatura(p->idoso) >= 38){//se tiver queda e febre alta no mesmo dia, mesmo priorizando acao da queda, qtd de dias de febre deve ser zerada
                setNumFebresBaixas(p->idoso, 0);
            }
            else if(retornaTemperatura(p->idoso) > 37 && retornaTemperatura(p->idoso) < 38){//situacao parecida com a de cima
                increaseNumFebresBaixas(p->idoso);
            }

        }
        else if(retornaTemperatura(p->idoso) >= 38){  //depois verifica se idoso tem febre alta
            //fazer aparecer no arquivo o seguinte: "febre alta, acionou Cuidador1"
            Cuidador* CuidadorFebreAlta = RetornaCuidadorMaisPerto(p->idoso, listacuidador);
            char* arquivo = strcat(strdup(retornaNomeIdoso(p->idoso)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "febre alta, acionou %s\n", retornaNomeCuidador(CuidadorFebreAlta));

            fclose(arq);

            setNumFebresBaixas(p->idoso, 0);
        }
        else if(retornaTemperatura(p->idoso) > 37 && retornaTemperatura(p->idoso) < 38){  //depois se o idoso tem febre baixa
            increaseNumFebresBaixas(p->idoso);
            //fazer aparecer no arquivo o seguinte: "febre baixa, acionou amigo Maria"
            if(retornaNumFebresBaixas(p->idoso) < 4){
                Idoso* amigoProximo = RetornaAmigoMaisPerto(p->idoso, retornaListAmigosIdoso(p->idoso));
                char* arquivo = strcat(strdup(retornaNomeIdoso(p->idoso)), "-saida.txt");

                FILE* arq = fopen(arquivo, "a");
                fprintf(arq, "febre baixa, acionou amigo %s\n", retornaNomeIdoso(amigoProximo));

                fclose(arq);
            }

            if(retornaNumFebresBaixas(p->idoso) >= 4){
                setNumFebresBaixas(p->idoso, 0);
                //fazer aparecer no arquivo o seguinte: "febre baixa pela quarta vez, acionou Cuidador1"

                Cuidador* cuidadorQuatroFebresBaixas = RetornaCuidadorMaisPerto(p->idoso, listacuidador);
                char* arquivo = strcat(strdup(retornaNomeIdoso(p->idoso)), "-saida.txt");

                FILE* arq = fopen(arquivo, "a");
                fprintf(arq, "febre baixa pela quarta vez, acionou %s\n", retornaNomeCuidador(cuidadorQuatroFebresBaixas));

                fclose(arq);
            }
        }
        else{  //se esta tudo ok
            //fazer aparecer no arquivo o seguinte: "tudo ok"
            char* arquivo = strcat(strdup(retornaNomeIdoso(p->idoso)), "-saida.txt");

            FILE* arq = fopen(arquivo, "a");
            fprintf(arq, "tudo ok\n");

            fclose(arq);
        }
    }
}
	
//========================================================
	
	Idoso* RetornaAmigoMaisPerto(Idoso* idoso, ListAmigos* listaAmigo){
    float latIdoso = retornaLatitudeIdoso(idoso);
    float longiIdoso = retornaLongitudeIdoso(idoso);

    float latAmigo, longiAmigo;
    float distancia, menor;

    CelIdoso* p;
    for(p = listaAmigo->prim; p != NULL; p = p->prox){
        latAmigo = retornaLatitudeIdoso(p->idoso);
        longiAmigo = retornaLongitudeIdoso(p->idoso);

        distancia = calculaDistancia(latIdoso, longiIdoso, latAmigo, longiAmigo);
        if(p == listaAmigo->prim){  //só para inicializar o valor da distancia com base no primeiro amigo
            menor = distancia;
        }
        if(distancia < menor){
            menor = distancia;
        }
    }

    for(p = listaAmigo->prim; p != NULL; p = p->prox){ //for para "capturar" o amigo cuja distancia do idoso é a menor
        latAmigo = retornaLatitudeIdoso(p->idoso);
        longiAmigo = retornaLongitudeIdoso(p->idoso);

        distancia = calculaDistancia(latIdoso, longiIdoso, latAmigo, longiAmigo);
        if(distancia == menor){
            Idoso* amigoPerto = retornaIdosoCelula(p);
            return amigoPerto;
        }
    }
}
	
//========================================================
	
	
	Cuidador* RetornaCuidadorMaisPerto(Idoso* idoso, ListCuidador* listacuidador){
    float latIdoso = retornaLatitudeIdoso(idoso);
    float longiIdoso = retornaLongitudeIdoso(idoso);

    float latCuidador, longiCuidador;
    float distancia, menor;

    CelCuidador* p;
    for(p = listacuidador->prim; p != NULL; p = p->prox){
        latCuidador = retornaLatitudeCuidador(p->cuidador);
        longiCuidador = retornaLongitudeCuidador(p->cuidador);

        distancia = calculaDistancia(latIdoso, longiIdoso, latCuidador, longiCuidador);
        if(p == listacuidador->prim){  //só para inicializar o valor da distancia com base no primeiro cuidador
            menor = distancia;
        }
        if(distancia < menor){
            menor = distancia;
        }
    }

    for(p = listacuidador->prim; p != NULL; p = p->prox){ //for para "capturar" o cuidador cuja distancia do idoso é a menor
        latCuidador = retornaLatitudeCuidador(p->cuidador);
        longiCuidador = retornaLongitudeCuidador(p->cuidador);

        distancia = calculaDistancia(latIdoso, longiIdoso, latCuidador, longiCuidador);
        if(distancia == menor){
            Cuidador* cuidadorPerto = retornaCuidadorDaCelula(p);
            return cuidadorPerto;
        }
    }
}
	
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//SÓ USEI ESSAS 4 LINHAS PARA FAZER O QUE O TRABALHO PEDE
	
	ListIdoso *listaIdosos = inicializaListIdoso ( "apoio.txt" );
	ListCuidador *listaCuidadores = preencheListCuidador("cuidadores.txt");
	LeLinhaCuidadorNoIdoso("cuidadores.txt", listaIdosos, listaCuidadores);
	funcaoEDCare(listaIdosos, listaCuidadores);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
}
