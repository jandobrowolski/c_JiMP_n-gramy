#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include "generator.h"
#include "IO.h"

int main (int argc, char **argv)			//obsługa flag i wywołanie funkcji
{
	alokujwszystko();
	char *cvalue = NULL;
	int index;
	int c;
	char *zflag = "gen_wyniki.txt";
	char *wflag = "gen_wyniki.txt";
	int sflag = 0;
	while ((c=getopt(argc, argv, "p:b:n:m:a:z:w:s")) != -1)
	switch (c)
	{
		case 'p':					//czytaj pliki
			index = optind-1;
            while(index < argc){
                if(argv[index][0] == '-'){         //czy następny wyraz to nie flaga
                    break;
                }		
				if(wczytaj(argv[index])==1)
				{
					printf("błąd: nie można odczytać pliku");
					return 1;
				}
				index++;
            }
			optind = index - 1;
            break;
		case 'b':					//czytaj bazy
			index = optind-1;
            while(index < argc){
                if(argv[index][0] == '-'){         //czy następny wyraz to nie flaga
                    break;
                }	
				if(wczytaj(argv[index])==1)
				{
					printf("błąd: nie można odczytać pliku");
					return 1;
				}
				index++;
            }
			optind = index - 1;
			break;
		case 'n':					//definiuj dlugosc ngramu
			index = optind-1;
			ngram->dlugosc=atoi(argv[index]);
			break;
		case 'm':					//maksymalna ilość słów w tekście
			index = optind-1;
			wyniki->limit=atoi(argv[index]);
			break;
		case 'a':					//maksymalna ilość akapitów
			index = optind-1;
			wyniki->limitakapitow=atoi(argv[index]);
			break;
		case 'z':					//zmiana domyślnej nazwy pliku wynikowego
			index = optind-1;
			zflag=argv[index];
			break;
		case 'w':					//umożliwia zapis bazy danych
			index = optind-1;
			wflag=argv[index];
			break;
		case 's':					//zmiana trybu programu do statystyki NIE DZIALA!
			sflag=1;
			break;
		case '?':
			if (optopt == 'p'||optopt == 'b'||optopt == 'n'||optopt == 'm'||optopt == 'a'||optopt == 'z'||optopt == 'w')
				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
			else if (isprint (optopt))
				fprintf (stderr, "Unknown option `-%c'.\n", optopt);
			else
				fprintf (stderr,"Unknown option character `\\x%x'.\n",optopt);
		default:
			abort ();
	}
	
	generuj(argc, argv);			//tutaj cała magia
	if(zapisz(zflag)==1)
	{
		printf("błąd: nie można zapisac pliku");
		return 1;
	}
	if(wflag!="gen_wyniki.txt")
		if(zapiszbaze(wflag)==1)
		{
			printf("błąd: nie można zapisac bazy");
			return 1;
		}
	free_all();
	printf("Tekst wygenerowano pomyslnie\n");
	return 0;
	
}