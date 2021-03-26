#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_arg.h"

int count_word(const char *str)
{
    int i = 0;
    int nb_word = 0;
    while (str[i] != '\0')
        {
            while (str[i] == ' ' && str[i] != '\0')
                i++ ;
            if(str[i] != '\0')
                nb_word++ ;
            while (str[i] != ' ' && str[i] != '\0')
                i++ ;
        }
    return(nb_word);
}
                                                                                                                                                                                  
char *alloc_word(int *start, int *end, const char *str)
{                                                                                                                             
    char *new_word;                                                                                                                                                     
    while(str[*start] != '\0' && str[*start] == ' ')                                                                                                                                 
        (*start)++;                                                                                                                                                                  
    if (str[*start] == '\0')                                                                                                                                                         
        return NULL;                                                                                                                                                                 
    *end = *start;                                                                                                                                                                   
    while(str[*end] != '\0' && str[*end] != ' ')                                                                                                                                     
                (*end)++;                                                                                                                                                            
    new_word = malloc(sizeof(char) * ((*end) - (*start) + 1));                                                                                                                             
    return new_word;                                                                                                                                                                 
} 

char **my_str_to_word_array(const char *str)
{
    char **tab;
    int start = 0;
    int end = 0;
    int x = 0;
    int y = 0;

    tab = malloc( sizeof ( char* ) * ( count_word(str) + 1) );

    while(str[start] != '\0')
         {
            if ((tab[x] = alloc_word(&start, &end, str)) == NULL)                                                                                                            
                 return tab; 
            /*effacer entre les deux commentaires */
            while (start < end)
                {
                    tab[x][y] = str[start];
                    y++;
                    start++;
                 }
            tab[x][y] ='\0'; /* caractere de fin de ligne*/
            x++;
            y = 0; /*pour passer à la ligne suivante*/
         }
    tab[x] = NULL;
    return tab;
}

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