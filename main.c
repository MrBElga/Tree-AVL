#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main()
{
	Tree* raiz,*busca;
    init(&raiz);
    int rotacao = 0,nivel=0;
    
    
    // Insere elementos na árvore AVL
    insereAVL(&raiz, 10, &rotacao);
    insereAVL(&raiz, 5, &rotacao);
    insereAVL(&raiz, 15, &rotacao);
    insereAVL(&raiz, 3, &rotacao);
    insereAVL(&raiz, 7, &rotacao);
    insereAVL(&raiz, 12, &rotacao);
    insereAVL(&raiz, 18, &rotacao);


    // Exibe a árvore AVL
    printf("Arvore AVL:\n");
    exibe(raiz, 0);

    // Exibe a altura da árvore AVL
    printf("\nAltura da arvore AVL: %d\n", getAlt(raiz));

    // Realiza algumas operações de busca e exibe os resultados
 
    nivel = CalculaNivel(raiz, 5, 0);
    printf("\nNivel do no com valor 5: %d\n", nivel);
	busca = buscaNoR(raiz, 5);
    if (busca != NULL) {
        printf("No com valor 5 encontrado!\n");
    } else {
        printf("No com valor 5 nao encontrado.\n");
    }

    // Deleta a árvore AVL
    deletTree(&raiz);

    return 0;
}
