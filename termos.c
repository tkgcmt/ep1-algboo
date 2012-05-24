#include <stdlib.h>
#include <malloc.h>
#include "termos.h"

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

    return p;
}

/* Remove uma celula da lista e devolve a celula removida*/
TERMO *rm_t(TERMO *head, TERMO *item) {
    TERMO *p;
    for (p = head; p->next != item || p->next != NULL; p = p->next);
    if (p->next == NULL) {
        printf("Termo nao encontrado ou invalido");
        return NULL;
    }
    p->next = p->next->next;
    free(item);
    for (p = p->next; p->next != NULL; p = p->next)
        p->index--;

    return item;
}
