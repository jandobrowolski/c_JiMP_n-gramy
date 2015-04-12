#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "IO.h"

#define MAXDLUGWYRAZU 25



void alokujwszystko ()
{
	ngram = malloc(sizeof(*ngram));
	ngram->dlugosc = 2;
	ngram->size = 32;
	ngram->iloscwyrazow=0;
	ngram->znak = (char**)malloc ( sizeof(char*) * ngram->size );
	for(int i=0; i<ngram->size; i++)
	{
		ngram->znak[i] = (char*) malloc (sizeof(char) * MAXDLUGWYRAZU);
	}
	
	wyniki = malloc(sizeof(*wyniki));
	wyniki->limit = 1024;
	wyniki->iloscwyrazow = 0;
	wyniki->wskaznik = (char**) malloc ( sizeof(char*) * wyniki->limit );
	for(int i=0; i<ngram->size; i++)
	{
		wyniki->wskaznik[i] = (char*) malloc (sizeof(char) * MAXDLUGWYRAZU);
	}
}


void dorzuc (char *wyraz)
{
	if (ngram->iloscwyrazow >= ngram->size)
	{
		ngram->znak = (char**) realloc ( ngram->znak, sizeof(char*) * ngram->size * 2);
		for(int i=ngram->size; i<(ngram->size *2); i++)
		{
			ngram->znak[i] = (char*) malloc (sizeof(char) * MAXDLUGWYRAZU);
		}
		ngram->size *=2;
	}
	ngram->znak[ngram->iloscwyrazow] = wyraz;
	ngram->iloscwyrazow++;
}

/*

int wczytaj(argc, **argv, *ngram)
{
	FILE *in = fopen(argv[1], "r");
	
	
}
-czyta pliki wej?ciowe, ka?dy kolejny wyraz wrzuca do ngram


int zapisz(argc, **argv, *ngram)
{
	
}
-zapisuje tekst wynikowy do pliku


int zapiszbaze(argc, **argv, *ngram)
{
	
}
-zapisuje u?yt? baz? danych do pliku*/