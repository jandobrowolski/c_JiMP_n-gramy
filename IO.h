#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXDLUGWYRAZU 25

struct {
char **znak;
int dlugosc;
int size;
int iloscwyrazow;
} *ngram;

struct {
char **wskaznik;
int limit;
int iloscwyrazow;
} *wyniki;

void alokujwszystko ();
void dorzuc (char *wyraz);/*
int wczytaj (argc, **argv, *ngram);
int zapisz (argc, **argv, *ngram);
int zapiszbaze (argc, **argv, *ngram);*/