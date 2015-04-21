#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXDLUGWYRAZU 100

struct {
char **znak;
int dlugosc;
int size;
int iloscwyrazow;
} *ngram;

struct {
char **wskaznik;
int limit;
int limitakapitow;
int iloscwyrazow;
} *wyniki;


void free_all();
void alokujwszystko ();
void dorzuc (char *wyraz);
int wczytaj (char *value);
int zapisz (char *zflag);
int zapiszbaze (char *wflag);