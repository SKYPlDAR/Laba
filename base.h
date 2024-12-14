#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[20];
    float price;
    char brend[20];
    int kolvo;
} t;

void read_t(t **tov, int *n, const char *fil_n);
void print_t(t *tov, int n);
void add_t(t **tov, int *n);
void del_t(t *tov, int *n);
void edit_t(t *tov, int n);
void poisk_t(t *tov, int n);
void save_t(t *tov, int *n, const char *fil_n);

#endif