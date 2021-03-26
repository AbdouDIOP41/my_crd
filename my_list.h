#ifndef __MY_LIST__
#define __MY_LIST__

typedef struct {
	int key;
	int value;
} Data;

typedef struct celluleData{
	Data d;
	struct celluleData *next;
} CelluleData, *ListeData;

ListeData alloueCellule(Data elem);
ListeData insertionEnTrie(ListeData* liste, Data elem);
int my_delete_nodes(ListeData *liste, const int data_ref);
int search(ListeData liste, int x);
void afficherListe(ListeData liste);

#endif