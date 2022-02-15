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
#define FILE_IN_IDOSOS	"./Entradas/apoio.txt"
#define FILE_IN_CUIDADORES	"./Entradas/cuidadores.txt"


/*
 *  CABECALHO DE FUNCOES DO PROGRAMA
*/
void InsereMedidasCuidador(Cuidador* cuidador, int linhaArquivo, char* arquivo);
void LeLinhaCuidadorNoIdoso(char* arquivo, ListIdoso* listaIdoso, ListCuidador* listaCuidador);
void InsereMedidasIdoso(Idoso* idoso, int linhaArquivo, char* arquivo);



/*
 * FUNÇÃO PRINCIPAL DO PROGRAMA
 * 
 * Exit Statuses:
 * Exit Status	 0	Saída Normal
 * Exit Status	-1	Arquivo de entrada dos idosos não encontrado
 * Exit Status	-2	Arquivo de entrada dos cuidadores não encontrado
 */
int main()
{
	/*********************************************************************************************************
	* SETUP - 	Le arquivos de entrada e armazena Idosos, cria suas dependências, cadastra amigos, etc
	*		 - 	Inicializa os cuidadores cadastrados e define as dependências entre
	*			idosos e cuidadores.
	*/

		/***************************************************************************************
		 * 
		 * Cadastro dos Idosos
		 * 
		 ***************************************************************************************/
			printf("Criando lista de idosos...\n");

			// Cria a lista de Idosos do programa
			// e a Inicializa.
			ListIdoso* idososCadastrados = CriaListaIdoso();	

			/*
			* Lê o arquivo de idosos e insere os idosos na lista
			*/
				FILE *f_idoso = fopen(FILE_IN_IDOSOS, "r");	// Abre arquivo de entrada dos idosos
				char conteudo[10000];

				// Verifica se o arquivo abriu corretamente
				if (f_idoso == NULL){
					printf("Nao foi possivel abrir o arquivo. %s.\n", FILE_IN_IDOSOS);

					// Libera memoria usada pela lista
					destroiListIdoso(idososCadastrados);

					// Exit Status -1 = Arquivo de entrada não encontrado
					return -1;	
				}

				// Pega informações somente da primeira linha
				fscanf(f_idoso, "%[^\n]\n", conteudo);

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
				fscanf(f_idoso, "%[^EOF]", conteudo);
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

					novaAmizade(idososCadastrados, idoso, amigo);
					nome = strtok(NULL, "\n");
				}

				fclose(f_idoso);

			imprimeListIdoso(idososCadastrados);

		/***************************************************************************************
		 * 
		 * Cadastro dos cuidadores
		 * 
		 ***************************************************************************************/

			printf("Preenchendo listas de cuidadores...\n");
			
			// Lista para armazenar os Cuidadores do Sistema
			ListCuidador *cuidadoresCadastrados = novaListaCuidador();

			/*
			* Lê o arquivo de cuidadores e insere-os na lista
			*/
				// Abre o arquivo para leitura
				FILE *f_cuidadores = fopen(FILE_IN_CUIDADORES, "r");
				//char conteudo2[10000];

				if (f_cuidadores == NULL){
					printf("Nao foi possivel abrir o arquivo. %s\n", FILE_IN_CUIDADORES);
					destroiListCuidador(cuidadoresCadastrados);
					// Exit Status -2 -> Arquivo de entrada dos cuidadores não encontrado
					return -2;
				}

				// Pega informacoes somente da primeira linha
				fscanf(f_cuidadores, "%[^\n]\n", conteudo);
				nome = strtok(conteudo, ";");

				//colocando os cuidadores na lista
				while( nome != NULL ) {
					Cuidador* c_temp = criaCuidador(nome);
					insereNovoCuidador(cuidadoresCadastrados, c_temp);

					nome = strtok(NULL, ";");
				}

			/*
			* Lê o restante do arquivo e armazena os cuidadores de cada idoso
			*/
				fscanf(f_cuidadores, "%[^EOF]", conteudo);  //lendo da segunda linha ate o final

				// Armazena a linha 
				char* nomes = strtok(conteudo, "\n");
				
				// Variaveis para armazenar os nomes
				char nomeIdoso[10000], nomeCuidador[10000];

				while(nomes != NULL){
					int i, j;
				    // armazena o nome do idoso na linha
					for(i = 0; nomes[i] != ';'; i++){  
				    	nomeIdoso[i] = nomes[i];
				    }

					// Adiciona terminador de string ao nome do idoso
				    nomeIdoso[i] = '\0';  
					
					// coloca o indice no proximo nome
					i++;

				    /* Le os nomes dos cuidadores e os acrescenta à lista do idoso */
					
					// for() indo do nome do primeiro cuidador depois do idoso até o final da linha
				    for(j = 0; nomes[i] != '\0'; i++){  
				        // se acaba o nome do cuidador, busca ele na lista de cuidadores cadastrados
						// e cadastra ele na lista de cuidadores do idoso
						if(nomes[i] == ';'){
							
							// no lugar do ";" coloca '\0' pra terminar o nome do cuidador corretamente
				            nomeCuidador[j] = '\0';
							
							// identifica o idoso e o cuidador já cadastrados
				            Idoso* idoso = buscaIdoso(idososCadastrados, nomeIdoso);
				            Cuidador* cuidador = buscaCuidador(cuidadoresCadastrados, nomeCuidador);

							// Insere o cuidador na lista de cuidadores do idoso
				            insereNovoCuidador(getListCuidadores(idoso), cuidador);

				            j = 0;  //zerando j para preencher um novo nome de cuidador
				        }
				        else{
				            nomeCuidador[j] = nomes[i];
							j++;
				        }
				    }
					//só entra aqui se for o ultimo cuidador, para colocar '\0' e inserir o respectivo cuidador no respectivo idoso
				    if(nomes[i] == '\0'){
				        // no lugar do "\n" coloca '\0' pra terminar o nome do cuidador corretamente
						nomeCuidador[j] = '\0';
						
						// identifica o idoso e o cuidador já cadastrados
						Idoso* idoso = buscaIdoso(idososCadastrados, nomeIdoso);
						Cuidador* cuidador = buscaCuidador(cuidadoresCadastrados, nomeCuidador);

						// Insere o cuidador na lista de cuidadores do idoso
						insereNovoCuidador(getListCuidadores(idoso), cuidador);
				    }

				    nomes = strtok(NULL, "\n");
				}

				fclose(f_cuidadores);

		// Imprime a lista de cuidadores cadastrados
		imprimeListCuidador(cuidadoresCadastrados);
		imprimeListIdoso(idososCadastrados);


	// RUN  - Le arquivos de entrada de cada um dos Idosos e Cuidadores.
	//		- Le a linha 'n' de cada arquivo por vez e depois realiza as operações
	//		  necessárias







	
	/***************************************************************************************
	 * 
	 * SAÍDA DO PROGRAMA
	 * 
	 ***************************************************************************************/

	// Libera a memória alocada de todas as estruturas criadas
	destroiListIdoso(idososCadastrados);
	destroiListCuidador(cuidadoresCadastrados);

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



