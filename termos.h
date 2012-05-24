#include <malloc.h>
#include <stdlib.h>

typedef struct t {
char *body;
int index;
struct t *next;
} TERMO;

TERMO *new_t(char *body, int index);
TERMO *rm_t(TERMO *head, TERMO *item);
