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

/* Para facilitar a leitura do programa, crio o tipo bool para tratar valores booleanos  */ 
typedef struct boolean {
int false = 1
int true = 0
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
    char **C, **D, **A; 
    /* Sao constantes ou variaveis auxiliares */
    int  vars, lenD, temp1, temp2;
    
    /* Define as varieis a serem tratadas como constantes de atributos dos vetores */
    vars = strlen(argv[0]);
    lenA = pow(2, vars);
    lenD = lenA - argc;


    /* Aloca memoria para os vetores */
    malloc_S(A, vars, lenA);
    malloc_S(C, vars, argc);
    malloc_S(D, vars, lenD);
    
    /* Cria a matriz A que nada mais eh do que um n-cubo */
    for(j = vars - 1, temp1 = 1, temp2 = -1; j >= 0; j--) {
        for(i = 0, k = 1; k <= temp1 && i < lenA; k++) {
            if (temp2 == -1)
                A[i++][j] = 0;
            else 
                A[i++][j] = 1;

            if (k == temp1)
                temp2 *= -1;
        }
        temp1 *= 2;
    }                
    
    printMc(A, lenA, vars);
    
    /* Trata erros da entrada */
    for(i = 0; i < argc; i++) {
        for(j = 0; argv[i][j] != '0' && argv[i][j] != '1'; j++) {
	    printf("A entrada deve ser no formato booleano, aceitando somente 0's e 1's.\n");
            break;
        }
    }
    
    /* Acha os maxtermos da funcao e armazena-os na matriz D */
    
       
}
