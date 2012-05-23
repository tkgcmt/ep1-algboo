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
/*#include "termos.h"*/

typedef struct t {
char *body;
int index;
} TERMO;

/* Cria uma celula e insere no final da lista */
TERMO new_t(char *body, int index) {
    TERMO *p;
    p = (TERMO*) malloc (1, sizeof(TERMO));
    if (p == NULL) {
        printf ("Erro de memoria - malloc retornou NULL");
        exit (0);
        return (NULL);
    }
    p.body = body;
    p.index = index;
    
    return p;
}

/* Remove uma celula da lista e devolve a celula removida*/
TERMO rm_t(TERMO *head, TERMO *item) {
    TERMO *p;
    for (p = head; p->next != item || p->next != NULL; p = p->next);
    if (p->next == NULL) {
        printf("Termo nao encontrado ou invalido");
        return NULL;
    }
    p->next = p->next->next;
    free(item);
    for (p = p->next; p->next != NULL; p = p->next)
        p.index--;

    return item;
}


/* Aloca uma matriz de chars para representar os termos da funcao */
char** mallocS (char **S, int var, int termos) {
    int i;
    S = (char*) malloc (termos, sizeof(char));
    if ( == NULL) {
        printf ("Erro de memoria\n");
        return NULL;
    }

    for (i = 0; i < var; i ++) {
        S[i] = (char*) malloc (var, sizeof(char));
        if (S[i] == NULL) {
            printf ("Erro de memoria\n");
            exit (1);
            return NULL;
        }
    }
}

/* Cria uma lista ligada para representar o conjunto dos termos */
void new_lst (TERMO head, int size, *char[]) {
	int i;
	TERMO *p;
	
	for (i = 0, p = head; i < size; i++, p = p->next)
		p = new_t (char[i], i);
}

/* Copia a celula, do tipo TERMO, A em B */
void cpy_t (TERMO A, TERMO B) {
	strcpy(B.body = A.body);
	B.index = A.index;
	B.next = A.index;
}

/* Imprime uma matriz de char */
void printS (char **matrix, int rows, int columns) {
    int r, c;
    for (r = 0; i < rows; r++) {
        for (c = 1; c < columns+1; c++)
            printf ("%c ", matrix[r][c]);
        printf ("\n");
    }
}

/* Imprime as strings de uma lista TERMO*/
void printb (TERMO head, int len) {
    TERMO *p;
    int i;

    for (p = head; p->next != NULL; p = p->next) {
        for (i = 0; i < len; i++)
            printf ("%c", p->body[i]);
        printf("\n");
    }
}


int main (int argc, char argv[]) {
    /* Sao contadores */
    int i, j, k; 
    /* Sao os conjuntos de termos */
    char **C, **maxtermos;
    /* Sao constantes ou variaveis auxiliares */
    int  vars, n, lenD, temp1, temp2;
    /* Sao cabecas das estruturas ligadas */
	TERMO D, X;
	/* Sao ponteiros auxiliares */
	TERMO *p;
	
    /* Trata erros da entrada */
    for (i = 0; i < argc; i++) {
        for (j = 0; argv[i][j] != '0' && argv[i][j] != '1'; j++) {
	    printf ("A entrada deve ser no formato booleano, aceitando somente 0's e 1's.\n");
            break;
        }
    }
    
    printf("Mintermos");
	printS (argv, argc, vars);

    /* Define as varieis a serem tratadas como constantes de atributos dos vetores */
    vars = strlen (argv[0]);
    n = pow (2, vars);
    lenD = n - argc;

    /* Aloca memoria para os vetores */
    mallocS (C, vars, argc);
    mallocS (D, vars, lenD);
    
    /* Cria o n-cubo */
    for (j = vars - 1, temp1 = 1, temp2 = -1; j >= 0; j--) {
        for (i = 0, k = 1; k <= temp1 && i < n; k++) {
            if (temp2 == -1)
                C[i++][j] = 0;
            else 
                C[i++][j] = 1;

            if (k == temp1)
                temp2 *= -1;
        }
        temp1 *= 2;
    }

    printf("C:");
    printS(C, n, vars);
	
	
    /* Cria a lista de estruturas ligadas que representa o conjunto D */
	new_lst (D, lenD, maxtermos)
	

    /* Os termos de C nao existentes na lista de mintermos, ou seja, os maxtermos, sao armazenados na lista D */
    for (i = 0, p = D; i < n; i++)
        for (j = 0; j < argc; j++)
            if (strcmp(C[i], argv[j]) != 0) {
                strcpy(p->body, C[i]);
                p = p->next;
            }

    printf("D:");
    printb (D, lenD);
    
    
    /* Aplica o algoritmo ISI */
    /*for (i = 0, j = 0, k = 0; D != NULL; ) {
        /* Remove o primeiro termo de D - o termo X */
		cpy_t(D, X);
		rm_t(D);
	*/	
}
