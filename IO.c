#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include IO.h

#define MAXDLUGWYRAZU 25

struct {
char **znak;
int dlugosc = 2;
int size = 32;
int iloscwyrazow;
} *ngram;

struct {
char **wskaznik;
int limit = 1024;
int iloscwyrazow = 1;
} *wyniki;

void dorzuc (int wyraz)
{
	if (ngram->iloscwyrazow >= ngram->size)
	{
		ngram->znak = (char**) realloc ( ngram->znak, sizeof(*char) * ngram->size * 2);
		for(int i=ngram->size; i<(ngram->size *2); i++)
		{
			ngram->znak[i] = (char*) malloc (sizeof(char) * MAXDLUGWYRAZU);
		}
	}
	ngram->znak[iloscwyrazow] = wyraz;
}



int wczytaj(argc, **argv, *ngram)
{
	
}
-czyta pliki wej?ciowe, ka?dy kolejny wyraz wrzuca do ngram


int zapisz(argc, **argv, *ngram)
{
	
}
-zapisuje tekst wynikowy do pliku


int zapiszbaze(argc, **argv, *ngram)
{
	
}
-zapisuje u?yt? baz? danych do pliku