#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
	
  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;

  opterr = 0;
  while ((c = getopt (argc, argv, "pbnmazws:")) != -1)
    switch (c)
      {
      case 'p':
		while ()
			FILE *wej[i] = fopen (optarg, "r");
        break;
      case 'b':
        break;
      case 'n':
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
  printf ("aflag = %d, bflag = %d, cvalue = %s\n",
          aflag, bflag, cvalue);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
  return 0;
}