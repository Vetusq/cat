#include <stdio.h>

void print(char *filename)
{
    FILE *f = fopen(name, "rt");

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
}

int main(int argc, char **argv) {
  for (int i = 1; i < argc; i++) { 
    print(argv[i]);        
  }
  return 0; 
}
