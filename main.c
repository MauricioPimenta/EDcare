#include <stdio.h>
#include "idoso.h"
#include "ListaIdoso.h"

int main(){

    printf("Criando lista de idosos...\n");
    ListIdoso *listaIdosos = inicializaListIdoso ( "C:/Users/dstei/Downloads/entradas2/apoio.txt" );

    imprimeListIdoso(listaIdosos);







    return 0;
}

