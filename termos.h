#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define compl(a) (a != '0' ? (a == '1' ? '0' : 'x') : '1')

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
TERMO *rm_t (TERMO *head, TERMO *item);
TERMO *vrf (TERMO *in, TERMO *head, int vars);
