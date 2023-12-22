//librerie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//definizioni globali
#define MAX_LEN 101

//struct per memorizzare le partite
typedef struct partite{

    char nome[MAX_LEN];
    int diff;
    int gol_fatti;
    int gol_subiti;
    int punti;
    struct partite *next;

}Partite;
typedef Partite * ptPartite;

//struct per memorizzare la lista in un array di struct per poter ordinare con qsort
typedef struct order{

    char nome[MAX_LEN];
    int diff;
    int gol_fatti;
    int gol_subiti;
    int punti;

}Order;

//funzioni che useremo
void insert(ptPartite *testa, char *squadra, int fatti, int subiti);
int ordina(const void *x, const void *y);

//principale
int main(){

    //variabili
    int n;
    ptPartite testa = NULL;
    scanf("%d", &n);
    char *s1 = (char *)malloc(sizeof(char)* MAX_LEN);
    char *s2 = (char *)malloc(sizeof(char)* MAX_LEN);
    int fatti_s1, fatti_s2;

    for(int i = 0; i<n; i++){
        scanf("%s", s1);
        scanf("%d", &fatti_s1);
        scanf("%s", s2);
        scanf("%d", &fatti_s2);
        insert(&testa, s1, fatti_s1, fatti_s2);
        insert(&testa, s2, fatti_s2, fatti_s1);
        free(s1);
        free(s2);
        s1 = (char *)malloc(sizeof(char)* MAX_LEN);
        s2 = (char *)malloc(sizeof(char)* MAX_LEN);
    }
    ptPartite t = testa;
    int n_squadre = 0;
    while(t != NULL){
        //printf("nome %s gol_f: %d gol_s : %d pt %d differenza_reti %d\n", t->nome, t->gol_fatti, t->gol_subiti, t->punti, t->diff);
        n_squadre++;
        t = t->next;
    }
    Order *part = (Order * )malloc(sizeof(Order) * n_squadre);
    t = testa;
    int j = 0;
    while(t != NULL){
        part[j].diff = t->diff;
        part[j].gol_subiti = t->gol_subiti;
        part[j].gol_fatti = t->gol_fatti;
        part[j].punti = t->punti;
        strcpy(part[j].nome, t->nome);
        j++;
        ptPartite tt = t;
        t = t->next;
        free(tt);
    }
    qsort(part, j, sizeof(Order), ordina);
    for(int i = 0; i<j; i++){
        printf("%s\n", part[i].nome);
    }
}
//funzioni implementate
void insert(ptPartite *testa, char *squadra, int fatti, int subiti){

    if(*testa == NULL){
        ptPartite nodo = malloc(sizeof(Partite));
        nodo->gol_fatti = fatti;
        nodo->gol_subiti = subiti;
        strcpy(nodo->nome, squadra);
        if(fatti >= subiti){
            if(fatti == subiti){
                nodo->punti = 1;
            }
            else{
                nodo->punti = 3;
            }
        }
        nodo->diff = nodo->gol_fatti - nodo->gol_subiti;
        //nodo->diff = fatti - subiti;
        nodo->next = *testa;
        *testa = nodo;
    }
    else if(strcmp((*testa)->nome, squadra) >= 0){
        if(strcmp((*testa)->nome, squadra) == 0){
            if(fatti >= subiti){
                if(fatti == subiti){
                    (*testa)->punti += 1;
                }
                else{
                    (*testa)->punti += 3;
                }
            }
            (*testa)->gol_fatti += fatti;
            (*testa)->gol_subiti += subiti;
            (*testa)->diff = (*testa)->gol_fatti - (*testa)->gol_subiti;
        }
        else{
            ptPartite nodo = malloc(sizeof(Partite));
            nodo->gol_fatti = fatti;
            nodo->gol_subiti = subiti;
            strcpy(nodo->nome, squadra);
            if(fatti >= subiti){
                if(fatti == subiti){
                    nodo->punti = 1;
                }
                else{
                    nodo->punti = 3;
                }
            }
            nodo->diff = fatti - subiti;
            nodo->next = *testa;
            *testa = nodo;
        }
    }
    else{
        insert(&((*testa)->next), squadra, fatti, subiti);
    }
}
int ordina(const void *x, const void *y){

    Order *a = (Order *)x;
    Order *b = (Order *)y;
    if(a->punti > b->punti){
        return a->punti - b->punti;
    }
    else if(a->punti < b->punti){
        return b->punti - a->punti;
    }
    else{
        if(a->diff > b->diff){
            return b->diff - a->diff;
        }
        else if(a->diff < b->diff){
            return b->diff - a->diff;
        }
        else{
            if(a->gol_fatti > b->gol_fatti){
                return a->gol_fatti - b->gol_fatti;
            }
            else if(a->gol_fatti < b->gol_fatti){
                return b->gol_fatti - a->gol_fatti;
            }
            else{
                return strcmp(a->nome, b->nome);
            }
        }
    }
}