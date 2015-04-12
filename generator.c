#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "IO.h"

int generuj (int argc, char **argv)
{
	alokujwszystko();
	
	for(int i=1; i<argc; i++)
	{
		dorzuc(argv[i]);
	}
	int ktorywyraz;
	int wyszukane[1000];
	int j;
	srand( time( NULL ) );
	ktorywyraz = rand()%ngram->iloscwyrazow;
	wyniki->wskaznik[0] = ngram->znak[ktorywyraz];

	
	while (wyniki->iloscwyrazow < wyniki->limit && ktorywyraz < ngram->iloscwyrazow)
	{
		j=0;
		
		for (int i=0; i<ngram->iloscwyrazow && j<1000 ; i++)
		{
			if(strcmp( ngram->znak[i], ngram->znak[ktorywyraz]) == 0)
			{
				wyszukane[j] = i;
				j++;
			}
		}
		
		if(j!=0)
		{
			ktorywyraz = wyszukane[rand()%j] + 1;
			wyniki->wskaznik[wyniki->iloscwyrazow] = ngram->znak[ktorywyraz];
			wyniki->iloscwyrazow++;
		}
		else
		{
			return 0;
		}
	}
	return 0;
	
}