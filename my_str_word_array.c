#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_str_word_array.h"

/*
int     is_sep(char c)
{
  return (c == ' ' || c == '\0' || c == '\t') ? 0 : -1 ;
}

int     my_count_word(const char *str)
{
  int   count;
  int   word;
 
  if (str == NULL)
    return (0);
  word = 0;
  count = 0;
  while (str[count] != '\0')
    {
      if (is_sep(str[count]) && is_sep(str[count + 1]) == 0)
        ++word;
      ++count;
    }
  return (word);
}
*/
int count_word(const char *str) /*compter le nombre de mots*/
{
    int i =0;
    int nb_word = 0;
    while (str[i]!= '\0')
        {
            while (str[i] == ' ' && str[i]!= '\0')
                i++;
            if(str[i]!= '\0')
                nb_word++;
            while (str[i] != ' ' && str[i]!= '\0')
                i++;
        }
    return(nb_word);
}
/*pour simplifier notre code, on crée une autre fonction*/
                                                                                                                                                                                  
char *alloc_word(int *start, int *end, const char *str){                                                                                                                             
    char *new_word;                                                                                                                                                     
    while(str[*start] != '\0' && str[*start] == ' ')                                                                                                                                 
        (*start)++;                                                                                                                                                                  
    if (str[*start] == '\0')                                                                                                                                                         
        return NULL;                                                                                                                                                                 
    *end = *start;                                                                                                                                                                   
    while(str[*end] != '\0' && str[*end] != ' ')                                                                                                                                     
                (*end)++;                                                                                                                                                            
    new_word = malloc(sizeof(char)*((*end)-(*start)+1));                                                                                                                             
    return new_word;                                                                                                                                                                 
} 

char    **my_str_to_word_array(const char *str)
{
    char **tab; /*tableau de chaine de caractere*/
    int start = 0;/*start = debut du mot*/
    int end = 0;/*start = debut du mot, end je le place debut du mot également, j'incremente end, je fais la difference entre start et end et j'allouela taille correspondant à la !\
= start et end; je dis que start = end et je recommence*/
    int x = 0;
    int y = 0;

    tab= malloc(sizeof(char*)*(count_word(str)+1));

    while(str[start] != '\0')
         {
            if ((tab[x] = alloc_word(&start, &end, str)) == NULL)                                                                                                            
                 return tab; 
            /*effacer entre les deux commentaires */
            while (start < end)
                {
                    tab[x][y]= str[start];
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


/*
int main (int ac, char **av) {

    //printf("%s\n", av[1]);
    char *phrase = "abdou diop etna\n";

    char **tab= my_str_to_word_array(phrase);
    printf("affiche phrase %s", phrase);
    for(int i = 0 ; tab[i] != NULL; i++)
        printf("tab[%d] = %s\n",i, tab[i]);
    return 0;
}*/