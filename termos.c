#include <stdlib.h>
#include <string.h>
#include "termos.h"

/* Aloca uma matriz de chars para representar os termos da funcao */
char **callocS (char **S, int rows, int columns) {
    int i;
    S = (char**) calloc (rows, sizeof(char*));
    if (S == NULL) {
        printf ("Erro de memoria\n");
        exit(1);
    }

    for (i = 0; i < rows; i ++) {
        S[i] = (char*) calloc (columns, sizeof(char));
        if (S[i] == NULL) {
            printf ("Erro de memoria\n");
            exit (1);
        }
    }
    return S;
}

/* Imprime uma matriz de char */
void printS (char **matrix, int rows) {
    int r;
    for (r = 0; r < rows; r++) {
        printf ("%s\n", matrix[r]);
    }
}



/* Cria uma celula e insere no final da lista */
TERMO *new_t(char *body, int index) {
    TERMO *p;
    p = (TERMO*) malloc (1 * sizeof(TERMO));
    if (p == NULL) {
        printf ("Erro de memoria - malloc retornou NULL");
        exit (0);
        return (NULL);
    }
    p->body = body;
    p->index = index;
    p->next = NULL;

    return p;
}

/* Remove uma celula da lista e devolve a celula removida*/
void rm_t(TERMO *head, int index) {
    TERMO *p, *buff;
    int i;

    for (i = 0, p = head; i < index; i++, p = p->next);
    if (p->next == NULL) {
        printf("Termo nao encontrado ou invalido");
        return;
    }
    buff = p->next;
    p->next = p->next->next;
    free(buff);
    for (; p->next != NULL; p = p->next)
        p->index--;
}

/* Imprime as strings de uma lista TERMO*/
void printb (TERMO *head, int len) {
    TERMO *p;
    int i;

    for (p = head->next; p != NULL; p = p->next) {
        for (i = 0; i < len; i++)
            printf ("%c", p->body[i]);
        printf ("\n");
    }
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


