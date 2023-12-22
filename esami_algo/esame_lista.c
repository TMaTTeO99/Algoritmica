//librerie
#include<stdio.h>
#include<stdlib.h>

//struct per creare una coda
typedef struct lista{

    int key;
    struct lista *next;

}Lista;
typedef Lista * ptLista;



//funzioni di supporto
void termina(ptLista *testa, int x, int n){
    return;
}
void insert_testa(ptLista *testa, int x){

    ptLista nodo = malloc(sizeof(Lista));
    if(nodo != NULL){

        nodo->key= x;
        nodo->next = *testa;
        *testa = nodo;

    }
    else{
        printf("Memoria esaurita.\n");
    }
}
void elimina(ptLista *testa){

    ptLista t = *testa;
    ptLista pre = NULL;
    while(t->next != NULL){
        pre = t;
        t = t->next;
    }
    pre->next = NULL;
    free(t);
}
//funzioni che useremo
void insert(ptLista * testa, int x, int n);
void stampa(ptLista * testa, int x, int n);

//principale
int main(){

    //variabili

    int n;//variabile per memorizzare il numero di elementi massimi da inserire nella coda
    int e = 0;
    int x;
    ptLista testa = NULL;
    void (*array[])(ptLista *, int , int) = {termina, insert, stampa};
    //inserisco limite della coda
    scanf("%d", &n);

    //inserisco scelta
    scanf("%d", &e);

    while(e != 0){
        if(e != 2){
            scanf("%d", &x);
        }
        (*array[e])(&testa, x, n);
        scanf("%d", &e);
    }

}
//implemento funzioni
void insert(ptLista * testa, int x, int n){

    ptLista scorri = *testa;
    ptLista pre = NULL;
    int n_nodi = 0;
    while(scorri != NULL && scorri->key != x){
        pre = scorri;
        scorri = scorri->next;
        n_nodi++;
    }
    if(scorri == NULL){
        insert_testa(testa, x);
        n_nodi++;
        if(n_nodi > n){
            elimina(testa);//funzione per eliminare elemento dalla coda
        }
    }
    else{
        if(scorri->next != NULL){
            if(pre != NULL){
                ptLista temp = scorri;
                pre->next = scorri->next;
                int s = temp->key;
                free(temp);
                insert_testa(testa, s);
            }
        }
        else{
            if(n > 1){
                ptLista temp = scorri;
                pre->next = NULL;
                int s = temp->key;
                free(temp);
                insert_testa(testa, s);
            }
        }
    }


}
void stampa(ptLista * testa, int x, int n){

    ptLista t = *testa;
    while(t != NULL){
        printf("%d ", t->key);
        t = t->next;
    }
    printf("$\n");

}