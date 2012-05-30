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

    
int main (int argc, char *argv[]) {
    /* Sao contadores */
    int i, j, k;
    /* Sao os conjuntos de termos */
    char **C = NULL, **maxtermos = NULL, **interval = NULL, **f0 = NULL, **ab1 = NULL;
    /* Sao constantes ou variaveis auxiliares */
    int  vars, n, lenD, mint, temp1, temp2;
    /* Sao cabecas das estruturas ligadas */
	TERMO *D = NULL, *X = NULL, *MAX = NULL, *AB1 = NULL;
	/* Sao ponteiros auxiliares */
	TERMO *d = NULL, *x = NULL, *buff = NULL;

    /* Define as varieis a serem tratadas como constantes */
    vars = strlen (argv[1]);
    mint = argc - 1;
    n = pow (2, vars);
    lenD = n - mint;
    D = (TERMO*) malloc (sizeof(TERMO));
    X = (TERMO*) malloc (sizeof(TERMO));
    if (X == NULL || D == NULL) {
        printf("Erro de memoria");
        exit(1);
    }
    interval = callocS(interval, 2, vars);
    
    /* debug */   
    f0 = callocS (f0, 3, 3);
    ab1 = callocS (ab1, 4, 3);
    MAX = (TERMO*) malloc (sizeof(TERMO));
    AB1 = (TERMO*) malloc (sizeof(TERMO));
    strcpy (f0[0], "010");
    strcpy (f0[1], "111");
    strcpy (f0[2], "011");
    strcpy (ab1[0], "x0x");
    strcpy (ab1[1], "xx0");
    strcpy (ab1[2], "00x");
    strcpy (ab1[3], "0x0");    
    new_lst (MAX, 3, f0);
    new_lst (AB1, 4, ab1);
    

    /* Imprime as variáveis inicializadas */
    printf("\nArgumentos: \n");
    printS (argv, argc);
    printf("\nvars=%d, mint=%d, n=%d, lenD=%d\n", vars, mint, n, lenD);


    /* Cria o n-cubo */
    C = callocS (C, n, vars);
    for (j = vars -1, temp1 = 1, temp2 = -1; j >= 0; j--) {
        for (i = 0; i < n;){
            for(k = 0; k < temp1;) {

                if (temp2 == -1) {
                    C[i][j] = '0';
                    i++;
                }

                else {
                    C[i][j] = '1';
                    i++;
                }
                k++;
                if (k == temp1)
                    temp2 *= -1;
            }

        }

        temp1 *= 2;
    }
    printf("C (Hipercubo):\n");
    printS(C, n);    


    /* Cria o maxtermo */ 
    maxtermos = callocS (maxtermos, lenD, vars);

    /* Os termos de C nao existentes na lista de mintermos, ou seja, os maxtermos, serao armazenados na lista D */
    for (i = 0, k = 0; i < n; i++) {
        j = 1;
        while (j < mint && strcmp (C[i], argv[j]) != 0)
            j++;

        if (strcmp (C[i], argv[j]) != 0) {
            maxtermos[k] = strcpy (maxtermos[k], C[i]);
            k++;
        }
    }
    printS(maxtermos, lenD);


    /* Cria a lista de estruturas ligadas que representa o conjunto D */
	new_lst (D, lenD, maxtermos);
    printb(D, lenD);


    /* Preenche o interval[0] com x's */
    for (i = 0; i < vars; i++)
        interval[0][i] = 'x';
    printS(interval, 2);

    /* Realiza efetivamente o algoritmo ISI */    
    temp2 = 0;
    X->next = new_t (interval[0], temp2);
    temp2++;
    d = D->next; x = X->next;
    printf("controle\n");


/*
    while (D->next != NULL) {
        for (d = D->next; d->next != NULL; d = d->next) {
            for (x = X->next; x->next != NULL; x = x->next) {
                for (j = 0; j < vars; j++) {
                    buff = x;
                    
                    if (compl(d->body[j]) == x->body[j]) {
                        strcpy(interval[1], interval[0]);
                        break;
                    }

                    else if (x->body[j] == 'x')
                        interval[1][j] = compl(d->body[j]);

                    else
                        interval[1][j] = d->body[j];
                }
            x->next = new_t(interval[1], temp2);
            temp2++;
            }
        }
    }
*/  
    printf ("MAX:\n");
    printb (MAX, 3);
    printf ("AB1: \n");
    printb (AB1, 3);
    
    for (x = AB1->next; x->next != NULL; x = x->next);
    x = vrf (x, AB1, vars);

    printf ("\nx: %s\n", x->body);
    printf ("AB1: \n");
    printb (AB1, 4);
    
    x = vrf (x, AB1, vars);

    printf ("\nx: %s\n", x->body);
    printf ("AB1: \n");
    printb (AB1, 4);
    
    d = x;

    x = vrf (x, AB1, vars);

    printf ("\nx: %s\n", x->body);
    printf ("AB1: \n");
    printb (AB1, 4);
    
    x = rm_t (AB1, x);
    printf ("\nx: %s\n", x->body);
    printf ("AB1: \n");
    printb (AB1, 4);

    
	return 1;
}
