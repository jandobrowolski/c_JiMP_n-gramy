#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "IO.h"



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
	wyniki->limitakapitow = 1024;
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
	strcpy (ngram->znak[ngram->iloscwyrazow], wyraz);
	ngram->iloscwyrazow++;
}


int wczytaj(char *value)
{
	char *result = malloc(strlen("data/")+strlen(value)+1);
    strcpy(result, "data/");
    strcat(result, value);
	FILE *in = fopen(result, "r");
	if(in==NULL)
		return 1;
	char tmp;
	char *wyraz = malloc(sizeof(char)*MAXDLUGWYRAZU);
	int j=0;
	while((tmp=getc(in))!=EOF)
	{
		if(tmp>32&&tmp<126)
		{
			wyraz[j]=tmp;
			j++;
		}
		else if(j!=0)
		{
			dorzuc(wyraz);
			for(int i=0; i<MAXDLUGWYRAZU; i++)
				wyraz[i]='\0';
			j=0;
		}
	}
	if(j!=0)
	{
		dorzuc(wyraz);
		free(wyraz);
	}
	fclose(in);
	return 0;
}


int zapisz(char *zflag)
{
	char *result = malloc(strlen("generated/")+strlen(zflag)+1);
    strcpy(result, "generated/");
    strcat(result, zflag);
	FILE *out = fopen(result, "w");
	if((wyniki->iloscwyrazow / wyniki->limitakapitow) >=10)
		for(int i=0; i<wyniki->iloscwyrazow; i++)
		{
			fprintf(out, "%s ", wyniki->wskaznik[i]);
			if(i%(wyniki->iloscwyrazow / wyniki->limitakapitow) == wyniki->iloscwyrazow / wyniki->limitakapitow - 1)
				fprintf(out, "\n");
		}
	else
		for(int i=0; i<wyniki->iloscwyrazow; i++)
		{
			fprintf(out, "%s ", wyniki->wskaznik[i]);
			if(i%10 == 9)
				fprintf(out, "\n");
		}
	fclose(out);
}


int zapiszbaze(char *wflag)
{
	FILE *out = fopen(wflag, "w");
	for(int i=0; i<ngram->iloscwyrazow; i++)
	{
		fprintf(out, "%s ", ngram->znak[i]);
	}
	fclose(out);
}