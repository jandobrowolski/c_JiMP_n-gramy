#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "IO.h"

int generuj (int argc, char **argv)
{
	int ktorywyraz;
	int wyszukane[10000];		//wyszukuje maksymalnie 10000 ngramów z tym samym prefiksem
	int j;
	srand( time( NULL ) );
	ktorywyraz = rand()%ngram->iloscwyrazow;		//losowanie pierwszego wyrazu
	wyniki->wskaznik[0] = ngram->znak[ktorywyraz];

	
	while (wyniki->iloscwyrazow < wyniki->limit && ktorywyraz < ngram->iloscwyrazow)
	{
		j=0;
		
		for (int i=0; i<ngram->iloscwyrazow && j<10000 ; i++)		//szuka wszystkich ngramów z prefiksem jak poprzednio wylosowany ngram
		{
			if(strcmp( ngram->znak[i], ngram->znak[ktorywyraz]) == 0)
			{
				wyszukane[j] = i;
				j++;
			}
		}
		
		if(j!=0)
		{
			
			ktorywyraz = wyszukane[rand()%j];
			for(int i=1; i<ngram->dlugosc; i++)
			{
				wyniki->iloscwyrazow++;
				wyniki->wskaznik[wyniki->iloscwyrazow] = ngram->znak[ktorywyraz+i];
			}
			ktorywyraz+=ngram->dlugosc-1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
	
}