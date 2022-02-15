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
 * CONSTANTES E DEFINICOES
 */
#define FILE_IN_IDOSOS	"../Entradas/apoio.txt"
#define FILE_IN_CUIDADORES	"../Entradas/cuidadores.txt"


/*
 *  CABECALHO DE FUNCOES DO PROGRAMA
*/
void InsereMedidasCuidador(Cuidador* cuidador, int linhaArquivo, char* arquivo);
void LeLinhaCuidadorNoIdoso(char* arquivo, ListIdoso* listaIdoso, ListCuidador* listaCuidador);
void InsereMedidasIdoso(Idoso* idoso, int linhaArquivo, char* arquivo);



/*
 * FUNÇÃO PRINCIPAL DO PROGRAMA
 */
int main()
{
	// SETUP - 	Le arquivos de entrada e armazena Idosos, cria suas dependências, etc
	//		 - 	Inicializa os cuidadores cadastrados e define as dependências entre
	//			idosos e cuidadores.

    printf("Criando lista de idosos...\n");

	// Cria a lista de Idosos do programa
	// e a Inicializa.
	ListIdoso* idososCadastrados = CriaListaIdoso();	

	/*
	* Lê o arquivo de idosos e insere os idosos na lista
	*/
		FILE *fp = fopen(FILE_IN_IDOSOS, "r");	// Abre arquivo de entrada dos idosos
		char conteudo[10000];

		// Verifica se o arquivo abriu corretamente
		if (fp == NULL){
			printf("Nao foi possivel abrir o arquivo. %s.\n", FILE_IN_IDOSOS);
			
			// Exit Status -1 = Arquivo de entrada não encontrado
			return -1;	
		}

		// Pega informações somente da primeira linha
		fscanf(fp, "%[^\n]\n", conteudo);

		char* nome = strtok(conteudo, ";");

		while( nome != NULL ) {
				// Cria o idoso e armazena na lista de idosos do programa
				Idoso* idoso = criaIdoso(nome);
				insereIdoso(idososCadastrados, idoso);

				nome = strtok(NULL, ";");
		}


	/*
	 * Lê o restante do arquivo e armazena as relações de amizades dos idosos
	 */
		// Agora trabalhando com as informações(linhas) restantes
		fscanf(fp, "%[^EOF]", conteudo);
		char idoso[10000], amigo[10000];
		
		
		nome = strtok(conteudo, "\n");
		//pegando o primeiro nome da linha
		while (nome != NULL)
		{	
			int i,j;
			// Pegando o primeiro nome da linha até encontrar o ';'
			for (i = 0; nome[i] != ';'; i++){ 
				idoso[i] = nome[i];
			}
			// Adiciona '\0' no final para identificar término da string
			idoso[i] = '\0';
			i++;

			for (j = 0; nome[i] != '\0'; i++, j++){ //pegando o segundo nome da linha
				amigo[j] = nome[i];
			}
			amigo[j] = '\0';

			insereAmizade(idososCadastrados, idoso, amigo);
			nome = strtok(NULL, "\n");
		}

		fclose(fp);

	imprimeListIdoso(idososCadastrados);

    printf("Preenchendo listas de cuidadores...\n");
	//ListCuidador *listaCuidadores = preencheListCuidador("./Entradas/cuidadores.txt");

	//imprimeListCuidador(listaCuidadores);


	// RUN  - Le arquivos de entrada de cada um dos Idosos e Cuidadores.
	//		- Le a linha 'n' de cada arquivo por vez e depois realiza as operações
	//		  necessárias










	return 0;

}

ListIdoso* inicializaListIdoso(char* arquivo);

  

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




void LeLinhaCuidadorNoIdoso(char* arquivo, ListIdoso* listaIdoso, ListCuidador* listaCuidador){
    // FILE* fp = fopen(arquivo, "r");

    // if(fp == NULL){
    //     printf("Arquivo invalido.\n");
    // }

    // char conteudo[10000];
    // fscanf(fp, "%[^\n]\n", conteudo);  //fazendo isso para ignorar a primeira linha

    // fscanf(fp, "%[^EOF]", conteudo);  //lendo da segunda linha ate o final

    // char* nomes = strtok(conteudo, "\n");
    // char nomeIdoso[10000], nomeCuidador[10000];

    // int i, j;

    // while(nomes != NULL){
    //     for(i = 0; nomes[i] != ';'; i++){  //for para pegar o nome do idoso na linha
    //     nomeIdoso[i] = nomes[i];
    //     }
    //     nomeIdoso[i] = '\0';  //nome do idoso com terminador

	// 	i++;
    //     //parei aqui----------------------------------------------------------------------------------------- erro abaixo, nesta função
    //     for(j = 0; nomes[i] != '\n'; i++, j++){  //for() indo do nome do primeiro cuidador depois do idoso até o final da linha
    //         if(nomes[i] == ';'){  //se acaba o nome do cuidador, entra no if()
    //             nomeCuidador[j] = '\0';  //no lugar do ";" coloca '\0' pra terminar o nome do cuidador corretamente


    //             Idoso* idoso = buscaIdoso(listaIdoso, nomeIdoso);
    //             Cuidador* cuidador = buscaCuidador(listaCuidador, nomeCuidador);

    //             insereNovoCuidador(idoso->cuidadores, cuidador);

    //             j = 0;  //zerando j para preencher um novo nome de cuidador
    //         }
    //         else{
    //             nomeCuidador[j] = nomes[i];
    //         }
    //     }
    //     if(nomes[i] == '\n'){  //só entra aqui se for o ultimo cuidador, para colocar '\0' e inserir o respectivo cuidador no respectivo idoso
    //         nomeCuidador[j] = '\0';

    //         Idoso* idoso = buscaIdoso(listaIdoso, nomeIdoso);
    //         Cuidador* cuidador = buscaCuidador(listaCuidador, nomeCuidador);

    //         insereNovoCuidador(idoso->cuidadores, cuidador);
    //     }

    //     nomes = strtok(NULL, "\n");
    // }
}




void InsereMedidasIdoso(Idoso* idoso, int linhaArquivo, char* arquivo){

    // FILE *fp = fopen(arquivo, "r");

    // if(fp == NULL){
    //     printf("Erro no arquivo de medidas de %s.\n", retornaNomeIdoso(idoso));
    // }

    // if(linhaArquivo == 1){
    //     char linha[100];
    //     fscanf(fp, "%[^\n]\n", linha);  //le a linha de interesse
    //     char* medida = strtok(linha, ";");  //separa as medidas da linha pelo separador ";"

    //     int k = 0;  //auxilia na inserção das medidas nos campos corretos através das condicoes
    //     while(medida != NULL){
    //         k++;
    //         if(k == 1){
    //             idoso->temperatura = atof(medida);
    //         }
    //         else if(k == 2){
    //             idoso->latitude = atof(medida);
    //         }
    //         else if(k == 3){
    //             idoso->longitude = atof(medida);
    //         }
    //         else{
    //             idoso->queda = atoi(medida);
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
    //         k++;
    //         if(k == 1){
    //             idoso->temperatura = atof(medida);
    //         }
    //         else if(k == 2){
    //             idoso->latitude = atof(medida);
    //         }
    //         else if(k == 3){
    //             idoso->longitude = atof(medida);
    //         }
    //         else{
    //             idoso->queda = atoi(medida);
    //         }

    //         medida = strtok(NULL, ";");
    //     }
    // }

    // fclose(fp);
}



