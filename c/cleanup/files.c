#include <stdio.h>
#include <stdlib.h>

#define TMP "/tmp/test-tmp.file"

void wait()
{
  int c;
	while ((c = getchar()) != EOF) {
   	if (c == 's')
   		break;
	}
}

void __free_buf(char **buf)
{
  printf("freeing buffer;\n");
  free(*buf);
}

void __free_file(FILE **fd)
{
	printf("closing file;\n");
  fclose(*fd);

  printf("remove the file;\n");
  remove(TMP);
}

int main(int argc, char **argv)
{
  char *buf __attribute__ ((__cleanup__(__free_buf))) = (char*) malloc(40 * sizeof(char));
  FILE *fp __attribute__ ((__cleanup__(__free_file)));

  fp = fopen(TMP, "w+");
  if (fp) fprintf(fp, "%s", "ATestlinewithnospacesandother");

  fflush(fp);
  fseek(fp, 0L, SEEK_SET);
  fscanf(fp, "%s", buf);
  printf("%s\n", buf);

  wait();

  return 0;
}
