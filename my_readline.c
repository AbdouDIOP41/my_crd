/*
** This function allows you to read a line of less than 50 characters from the standard input.
** The function does not take any parameter and returns an allocated string, dont forget to free().
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_readline.h"

char *my_readline(void)
{
  size_t n = 0;
  char *ret = NULL;
  ssize_t result = getline(&ret, &n, stdin);

  if (result <= 0) {
    free(ret);
    return NULL;
  }
  if (ret[result - 1] == '\n') {
    ret[result - 1] = '\0';
  }
  return ret;
}


/*
int main(){
  char *line;
  int nb = 0;
  int i = 1;
  while ((line = my_readline()) != NULL){
    
    printf("ligne %d : %s\n", i, line);
    nb = my_count_word(line);
    printf("nombre de mot %d\n", nb);
   // printf("fin du mot\n");
    //printf("%d\n", i);
    i++;
  }

  return 0;
}*/