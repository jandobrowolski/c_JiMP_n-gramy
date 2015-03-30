#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "IO.h"

int main()
{
	int generuj (*ngram, *wyniki)
	{
		int ktorywyraz;
		srand( time( NULL ) );
		ktorywyraz = rand()%iloscwyrazow;
		wyniki->wskaznik[0] = ngram->znak[ktorywyraz];
		int wyszukane[] = 0;
		int i;
		int j;
		
		while (wyniki->iloscwyrazow < wyniki->limit)
		{
			j=0;
			for (i=0; i<iloscwyrazow; i++)
			{
				if(ngram->znak[i] == ngram->znak[ktorywyraz])
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
}