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
#include <string.h>
#include "termos.h"


/* Aloca uma matriz de chars para representar os termos da funcao */
char **callocS (char **S, int var, int termos) {
    int i;
    S = (char**) calloc (termos, sizeof(char*));
    if (S == NULL) {
        printf ("Erro de memoria\n");
        exit(1);
    }

    for (i = 0; i < termos; i ++) {
        S[i] = (char*) calloc (var, sizeof(char));
        if (S[i] == NULL) {
            printf ("Erro de memoria\n");
            exit (1);
        }
    }
    return S;
}

/* Cria uma lista ligada para representar o conjunto dos termos */
void new_lst (TERMO *head, int size, char **body) {
	int i;
	TERMO *p;

	for (i = 0, p = head; i < size; i++, p = p->next)
		p->next = new_t (body[i], i);
}

/* Copia a celula, do tipo TERMO, A em B */
void cpy_t (TERMO *A, TERMO *B) {
	strcpy(B->body, A->body);
	B->index = A->index;
	B->next = A->next;
}

/* Imprime uma matriz de char */
void printS (char **matrix, int rows) {
    int r;
    for (r = 0; r < rows; r++) {
        printf ("%s\n", matrix[r]);
    }
}

/* Imprime as strings de uma lista TERMO*/
void printb (TERMO *head, int len) {
    TERMO *p;
    int i;

    for (p = head; p->next != NULL; p = p->next) {
        for (i = 0; i < len; i++)
            printf ("%c", p->body[i]);
        printf ("\n");
    }
}

int main (int argc, char *argv[]) {
    /* Sao contadores */
    int i, j, k;
    /* Sao os conjuntos de termos */
    char **C = NULL, **maxtermos = NULL;
    /* Sao constantes ou variaveis auxiliares */
    int  vars, n, lenD, mint, temp1, temp2;
    /* Sao cabecas das estruturas ligadas */
	TERMO *D = NULL, *X = NULL;
	/* Sao ponteiros auxiliares */
	TERMO *p = NULL;


    /* Define as varieis a serem tratadas como constantes de atributos dos vetores */
    vars = strlen (argv[1]);
    mint = argc -1;
    n = pow (2, vars);
    lenD = n - argc;
    D = (TERMO*) malloc (sizeof(TERMO));
    X = (TERMO*) malloc (sizeof(TERMO));
    if (X == NULL || D == NULL) {
        printf("Erro de memoria");
        exit(1);
    }
    printS (argv, argc);
    printf ("\n");

    printf ("vars: %d\nn: %d\nlenD: %d\nmint: %d\n", vars, n, lenD, mint);
    printf ("\n");

    /* Trata erros da entrada 
    for (i = 1; i < mint; i++) {
        for (j = 0; vars; j++) {
	        if(argv[i][j] != '0' ||  argv[i][j] != '1')
            printf ("A entrada deve ser no formato booleano, aceitando somente 0's e 1's.\n");
                exit(-1);
        }
    }*/

    printf("Mintermos\n");
	printS (argv, mint);
    printf ("\n");


    /* Aloca memoria para os vetores */
    callocS (C, mint, vars);
    
    printf ("mallocou C\n");
    printS (C, mint);

    /* Cria o n-cubo */
    for (j = vars -1, temp1 = 1, temp2 = -1; j >= 0; j--) {
        for (i = 0, k = 1; k <= temp1 && i < n; k++) {
            printf("i = %d  j = %d  k = %d  temp1 = %d  temp2 = %d\n", i, j, k, temp1, temp2);
            if (temp2 == -1) {
                C[i][j] = 0;
                i++;
            }

            else {
                C[i][j] = 1;
                i++;
            }

            if (k == temp1)
                temp2 *= -1;
        }
        temp1 *= 2;
        printf("i = %d  j = %d  k = %d  temp1 = %d  temp2 = %d\n", i, j, k, temp1, temp2); 
    }

    printf("\nC:\n");
    printS(C, n);


    /* Os termos de C nao existentes na lista de mintermos, ou seja, os maxtermos, serao armazenados na lista D */
    for (i = 0, k = 0; i < n; i++) {
        for (j = 0; j < mint; j++) {
            if (strcmp(C[i], argv[j]) != 0) {
                strcpy(maxtermos[k], C[i]);
                k++;
            }
        }
    }

    /* Cria a lista de estruturas ligadas que representa o conjunto D */
	new_lst (D, lenD, maxtermos);


    printf("\nD:\n");
    printb (D, lenD);


    /* Aplica o algoritmo ISI */
    /*for (i = 0, j = 0, k = 0; D != NULL; ) { */
        /* Remove o primeiro termo de D - o termo X */
	/*  cpy_t(D, X);
		rm_t(D, X);
	*/
	return 1;
}
