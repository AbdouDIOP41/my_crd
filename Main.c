/*
** ETNA PROJECT, 2019 by diop_c
** FDI-DEVC / my_crd  
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_arg.h"
#include "my_list.h"
#include "my_print.h"
#include "convert.h"

int main()
{
    ListeData liste = NULL; 
    char *line;
    char **tab;
    int nb = 0;
    int key ;
    int retour;

    while ((line = my_readline()) != NULL){ 
        nb = count_word(line);
        tab= my_str_to_word_array(line);

        if (nb == 1 || nb == 2){

            if (!isNumber(tab[0]))
                my_putstr("error : its not a number");

            else {
                key = convert_char_to_int(tab[0]);

                if (nb  == 1){
                    retour = search(liste,key);
                    convert_int_to_char(retour);
                }
                else {
                    if(isNumber(tab[1])){
                        Data data;
                        data.key = key;
                        data.value = convert_char_to_int(tab[1]);
                        insertionEnTrie(&liste, data);
                       // printf("%d || %d\n", data.key, data.value);
                        
                        my_putstr(tab[0]);
                    }
                    else if (tab[1][0] == 'D'){
                        retour = my_delete_nodes(&liste, key);
                        convert_int_to_char(retour);
                    }
                    
                    else 
                        my_putstr("mauvais format");
                }

            }
        }
        else 
            my_putstr("mauvais format");

        my_putchar('\n'); 
    }
    printf("lsite est ");
    afficherListe(liste);
    return 0;
}