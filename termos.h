#include <malloc.h>
#include <stdlib.h>

typedef struct t {
char *body;
int index;
} TERMO;

int new_t(char *content, int index);
int rm_t(int index);
