#include <malloc.h>
#include <stdlib.h>

typedef struct t {
char *body;
int index;
struct t *next;
} TERMO;


char **callocS (char **S, int rows, int columns);
void printS (char **matrix, int rows);
void printb (TERMO *head, int len);
void new_lst (TERMO *head, int size, char **body);
void cpy_t (TERMO *A, TERMO *B);
TERMO *new_t (char *body, int index);
void rm_t (TERMO *head, int index);
