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
void printS (char *matrix[], int rows) {
    int r;
    for (r = 0; r < rows; r++) {
        printf ("%s\n", matrix[r]);
    }
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


/* Cria uma lista ligada para representar o conjunto dos termos */
void new_lst (TERMO *head, int size, char **body) {
	int i;
	TERMO *p;

	for (i = 0, p = head; i < size; i++, p = p->next)
		p->next = new_t (body[i], i);
}


/* Verifica se um termo pertence a um intervalo fazendo as devidas ligacoes na lista de intervalos. Devolve a ultima celula da lista. */
/* TERMO *chk_t (TERMO *maxt, TERMO *last) {
    TERMO *p, *buff;
    
    for (
*/


/* Remove uma celula da lista e libera a celula removida. Devolve a celula de mesmo indice de item */
TERMO *rm_t (TERMO *head, TERMO *item) {
    TERMO *p, *buff;

    for (p = head; p->next != NULL && p->next != item; p = p->next);

    buff = p->next;
    p->next = p->next->next;
    free(buff->body);
    free(buff); 

    buff = p;

    for (; p->next != NULL; p = p->next)
        p->index--;

    return buff;
}


/* Verifica se a celula last esta contida em um intervalo da lista - se estiver, remove last da lista e devolve a última célula da lista */
TERMO *vrf (TERMO *last, TERMO *head, int vars) {
    TERMO *p, *buff;
    int i;
    
    for (p = head; p->next != NULL; p = p->next) {
        i = 0; 
        while (i < vars) {
            if (p->next->body[i] != 'x') 
                if (last->body[i] != p->next->body[i])
                    break;
            i++;
        }
        if (i == vars) {
            if (p->next == last)
                return last;
            else
                buff = rm_t(p, last);
                break;
        }
    }            
    return buff;
}
