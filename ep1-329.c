/***************************************************************/
/**                                                           **/
/**   Christian Massao Tsujiguchi Takagi            7136971   **/
/**   Exercicio-Programa 01                                   **/
/**   Algebra Booleana e Aplicacoes                 MAC0329   **/
/**                                                           **/
/***************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "termos.h"

/* Para facilitar a leitura do programa, crio o tipo bool para tratar valores booleanos  */ 
typedef struct boolean {
int false = 1;
int true = 0;
} bool;


/* Aloca uma matriz de chars para representar os termos da funcao */
char** malloc_S(char **S, int var, int termos) {
    int i;
    C = (char*) malloc(termos, sizeof(char));
    if (C == NULL) {
        printf("Erro de memoria\n");
        return NULL;
    }

    for (i = 0; i < var; i ++) {
        C[i] = (char*) malloc(var, sizeof(char));
        if (C[i] == NULL) {
            printf("Erro de memoria\n");
            exit(1);
            return NULL;
        }
    }
}

/* Imprime uma matriz de char */
void printMc(char **matrix, int rows, int columns) {
    int r, c;
    for (r = 0; i < rows; r++) {
        for (c = 1; c < columns+1; c++)
            printf("%c ", matrix[r][c]);
        printf("\n");
    }
}


/* Realiza o algoritmo ISI */
int main(int argc, char argv[]) {
    /* Sao contadores */
    int i, j, k; 
    /* Sao os conjuntos de termos */
    char **C, **D; 
    /* Sao constantes ou variaveis auxiliares */
    int  vars, n, lenD, temp1, temp2;
     
    /* Trata erros da entrada */
    for(i = 0; i < argc; i++) {
        for(j = 0; argv[i][j] != '0' && argv[i][j] != '1'; j++) {
	    printf("A entrada deve ser no formato booleano, aceitando somente 0's e 1's.\n");
            break;
        }
    }

    /* Define as varieis a serem tratadas como constantes de atributos dos vetores */
    vars = strlen(argv[0]);
    n = pow(2, vars);
    lenD = n - argc;

    /* Aloca memoria para os vetores */
    malloc_S(A, vars, lenA);
    malloc_S(C, vars, argc);
    malloc_S(D, vars, lenD);
    
    /* Cria a matriz C que nada mais eh do que um n-cubo */
    for(j = vars - 1, temp1 = 1, temp2 = -1; j >= 0; j--) {
        for(i = 0, k = 1; k <= temp1 && i < n; k++) {
            if (temp2 == -1)
                C[i++][j] = 0;
            else 
                C[i++][j] = 1;

            if (k == temp1)
                temp2 *= -1;
        }
        temp1 *= 2;
    
    }

    printMc(C, n, vars);
      
    /* Os termos de C nao existentes na lista de mintermos, ou seja, os maxtermos, sao armazenados na matriz D */
    for (i = 0, k = 0; i < n; i++)
        for (j = 0; j < argc; j++) {
            if (strcmp(C[i], argv[j]) != 0) {
                strcpy(D[k], C[i]);
                k++;
            }
    
    /* Aplica o algoritmo ISI */
    for (i = 0, j = 0, k = 0; D != NULL; ) {
        /* Remove o termo X de D */
        D[i]

}
