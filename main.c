#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

struct options
{
  int numberNonEmpty; //-b
  int markEndl;       // -e -v
  int numberAll;      // -n
  int tab;            //-t -v отображает табы как ^|
  int printNonPrintable;
}flag;

void print(char *filename)
{
  FILE *f = fopen(filename, "rt");

  if (f != NULL)
  {
    int c = fgetc(f);
    while (c != EOF)
    {
      putc(c, stdout);
      c = fgetc(f);
    }
    fclose(f);
  }
  else{
    // printf("cat: %s: No such file or directory", filename);
  }
}

int main(int argc, char **argv){

  int rez = 0;
  struct options flag;
  
  while ((rez = getopt(argc, argv, "bevEnstT")) != -1)
  {
    switch (rez)
    {
    case 'b':
    flag.numberNonEmpty = 1;
    printf("%d", flag.numberNonEmpty);
      break;
    case 'e':
    flag.markEndl =1;
      break;
    case 'v':
    flag.markEndl =1;
      break;
    case 'n':
    flag.numberAll = 1;
      break;
    case 't':
    flag.tab =1 ;
      break;
    case 'T':
    flag.tab =1 ;
      break;
    default:
      break;
    }
  }
  
  for (int i = 1; i < argc; i++)
  {
    print(argv[i],flag);
  }
  return 0;
}
