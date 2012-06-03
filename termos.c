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
TERMO *new_t (char body[MAX]) {
    TERMO *p;
    p = (TERMO*) malloc (1 * sizeof(TERMO));
    if (p == NULL) {
        printf ("Erro de memoria - malloc retornou NULL");
        exit (0);
        return (NULL);
    }
    strcpy (p->body, body);
    p->next = NULL;

    return p;
}


/* Cria uma lista ligada para representar o conjunto dos termos */
void new_lst (TERMO *head, int size, char *body[]) {
	int i;
	TERMO *p;

	for (i = 0, p = head; i < size; i++, p = p->next)
		p->next = new_t (body[i]);
}


/* Verifica se um termo pertence a um intervalo fazendo as devidas ligacoes na lista de intervalos. Devolve a ultima celula da lista. */
TERMO *chk_t (TERMO *head, char maxt[], TERMO *last, int vars) {
    TERMO *p, *buff, *ab;
    int i, j, stop, remove = 0;
    char *interval;

    ab = last;
    for (p = head->next; p != NULL; p = p->next) {
        stop = 0;
        buff = p;
        remove = 0;

        for (i = 0; i < vars; i++) {
            if (p->body[i] == 'x') {
                interval = (char*) calloc (vars, sizeof(char));
                interval[i] = compl(maxt[i]);
                
                /* Copia os termos restantes */
                for (j = i + 1; j < vars; j++) {
                    if (p->body[j] == compl(maxt[j])) {
                        stop++;
                        break;
                    }
                    else
                        interval[j] = p->body[j];
                }

                if (stop != 0) {
                    free (interval);
                    break;
                }

                for (j = i - 1; j >= 0; j--) {
                    if (p->body[j] == compl(maxt[j])) {
                        stop++;
                        break;
                    }
                    else
                        interval[j] = p->body[j];
                }

                if (stop != 0) {
                    free( interval);
                    break;
                }

                
                /* Cria a celula com o novo intervalo filho. Marca que o intervalo pai deve ser removido ao final */
                ab->next = new_t(interval);
                ab = ab->next;
                remove = 1;
            }

            
            else if (p->body[i] != maxt[i])
                break;
        }
        if (remove == 1)
            rm_t (head, buff);
        printf("chk:\n");
        printb (head, vars);

        if (p == last)
            break;
    }
    
    return ab;
}


/* Remove uma celula da lista e libera a celula removida. Devolve a celula imediatamente seguinte a ceula removida */
TERMO *rm_t (TERMO *head, TERMO *item) {
    TERMO *p, *buff;

    for (p = head; p->next != NULL && p->next!= item; p = p->next);

    buff = p->next;
    p->next = p->next->next;
    free(buff); 

    return p;
}


/* Verifica, de tras para frente, se a ultima celula esta contida em um intervalo da lista. Se estiver, remove-a com rm_t() */
TERMO *vrf (TERMO *last, TERMO *head, int vars) {
    TERMO *p, *buff;
    int i;
    buff = last;
    for (p = head->next; p->next != NULL && p != buff; p = p->next) {
        for (i = 0; i < vars; i++) {
            if (p->body[i] != buff->body[i])
                if (p->body[i] != 'x')
                    break;
        }
        if (i == vars) {
            buff = rm_t (head, buff);
            p = head;
        }
    }
    return buff;
}
