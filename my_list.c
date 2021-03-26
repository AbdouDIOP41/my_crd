#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_list.h"

ListeData alloueCellule(Data elem)
{
	ListeData tmp;
    tmp = (CelluleData *) malloc(sizeof(CelluleData));
	if(tmp == NULL){
        printf("MALLOC FAILED\n");
		return NULL;
    }
	tmp->d.key = elem.key;
	tmp->d.value = elem.value;
	tmp->next = NULL;
	return tmp;
}

ListeData insertionEnTrie(ListeData* liste, Data elem)
{
    ListeData tmp;
    ListeData index;

    tmp = alloueCellule(elem);
    index = *liste;

    if(tmp == NULL)
        return tmp;

    if(*liste == NULL){
        //printf("pas assez d'element\n");
        *liste = tmp;
    }
    /*
    if((*liste)->d.key == elem.key){
        (*liste)->d.value = elem.value;
        *liste = tmp;
    }*/

    else if ((*liste)->d.key > elem.key){
        tmp->next =*liste;
        *liste=tmp;
        //return *liste;
    }
    else {
        while(index->next != NULL && index->next->d.key <= elem.key)
            index = index->next;
        
        if(index->d.key == elem.key){
            index->d.value = elem.value;
            index = tmp;
        }
        else {
            tmp->next = index->next;
            index->next = tmp;
        }
    }
    return tmp;
}

int search(ListeData liste, int x){
    if (liste == NULL)
        return -1;
    if(liste->d.key == x )
        return liste->d.value;
    return search(liste->next, x);
}

int my_delete_nodes(ListeData *liste, int data_ref)
{
    
    ListeData tmp;
    tmp = *liste;
    int data_value = -1;
    if (tmp == NULL)
    {
        return -1;
    }
        
    while (tmp != NULL && tmp->d.key == data_ref)
    {
        data_value = tmp->d.value;
        *liste = tmp->next;
        tmp = tmp->next;
        //return data_value;
        
    }
    while (tmp->next != NULL)
    {
       while (tmp->next != NULL && tmp->next->d.key == data_ref){
           data_value = tmp->d.value;
           tmp->next = tmp->next->next;
       }
       while (tmp->next != NULL)
           tmp = tmp->next;
	}

    return data_value;
}

void afficherListe(ListeData liste)
{
	ListeData tmp = liste;
	if (tmp == NULL){
		printf("liste vide\n");
	}
	while (tmp != NULL){
		printf("%d, %d\n", tmp->d.key, tmp->d.value );
		tmp = tmp->next;
	}
}
