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

#define compl(a) (a != '0' ? (a == '1' ? '0' : 'X') : '1')

/* Verifica se a celula in esta contida em um  intervalo da lista - se estiver, remove in da lista*/
int vrf (TERMO *in, TERMO *head, int vars) {
    TERMO *p;
    int i, 
    control = 0;

    for (p = head->next; p != in; p = p->next) {
        for (i = 0; i < vars; i++) {
            if (compl(in->body[i]) == p->body[i])
                return 0;
            else if (in->body[i] == 'x' &&  p->body[i] != 'x') {
                control++;
            }
            else if( in->body[i] != 'x' &&  p->body[i] == 'x') { 
                control++;
            }

        }
    }
    if (control == vars) {
        return 0;
    }
    
    rm_t (head, in->index);
    return 1;
}
    
int main (int argc, char *argv[]) {
    /* Sao contadores */
    int i, j, k;
    /* Sao os conjuntos de termos */
    char **C = NULL, **maxtermos = NULL;
    /* Sao constantes ou variaveis auxiliares */
    int  vars, n, lenD, mint, temp1, temp2;
    /* Sao cabecas das estruturas ligadas */
	TERMO *D = NULL, *X = NULL;
	/* Sao ponteiros auxiliares */
	TERMO *d = NULL, *x = NULL;
    

    /* Define as varieis a serem tratadas como constantes de atributos dos vetores */
    vars = strlen (argv[1]);
    mint = argc -1;
    n = pow (2, vars);
    lenD = n - mint;
    D = (TERMO*) malloc (sizeof(TERMO));
    X = (TERMO*) malloc (sizeof(TERMO));
    if (X == NULL || D == NULL) {
        printf("Erro de memoria");
        exit(1);
    }
    printS (argv, argc);
    printf ("\n");

    printf ("vars: %d\nn: %d\nlenD: %d\nmint: %d\n", vars, n, lenD, mint);
    printf ("\n");

    /* Cria o n-cubo */
    C = callocS (C, n, vars);
    for (j = vars -1, temp1 = 1, temp2 = -1; j >= 0; j--) {
        printf("for j\n");

        for (i = 0; i < n;){
            printf("for i\n");

            for(k = 0; k < temp1;) {
                if (temp2 == -1) {
                    printf("if -1\n");
                    C[i][j] = '0';
                    i++;
                }

                else {
                    printf("if 1\n");
                    C[i][j] = '1';
                    i++;
                }
                printf("k = %d\n", k);
                k++;
                if (k == temp1)
                    temp2 *= -1;
            }

        printf("i = %d  j = %d  k = %d  temp1 = %d  temp2 = %d\n", i, j, k, temp1, temp2);

        }

    temp1 *= 2;

    printf("i = %d  j = %d   temp1 = %d  temp2 = %d\n\n", i, j, temp1, temp2);

    }

    printf("\nC:\n");
    printS(C, n);
    
    /* Cria o maxtermo */ 
    maxtermos = callocS (maxtermos, lenD, vars);
/*
    strcpy(maxtermos[0], "010");
    strcpy(maxtermos[1], "011");
    strcpy(maxtermos[2], "111");
   
    printf("Fmaxtermos\n");
    printS(maxtermos, lenD);
    */

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

    printf("\nMaxtermos\n");
    printS(maxtermos, lenD);

       
    /* Cria a lista de estruturas ligadas que representa o conjunto D */
	new_lst (D, lenD, maxtermos);
    

    printf("\nD:\n");
    printb (D, vars);
    
/*
    X->next = new_t ("xxx", 0);
    d = D->next; x = X->next;
    while (D->next != NULL) {
        for (j = 0; j < vars; j++) {
            x->next = new_t(NULL, x->index + 1);
            if (d->body[j] != compl(x->body[k])) {
                
                
                




/*
            if (x->body[i] == 'x') {
                x->next->body[j] = compl(d->body[j]);
                for (k = j + 1; k < vars; k++)
                    x->next->body[k] = d->body[k];
                for (k = j - 1; k < 0; k++)
                    x->next->body[k] = d->body[k];
                j = vars;
                printf("x->body = %s\n", x->body);
            }
            
            else if (x->body[j] == compl(d->body[j]) {
  */
              
	return 1;
}
