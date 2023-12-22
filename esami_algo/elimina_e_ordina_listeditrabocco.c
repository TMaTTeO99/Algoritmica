#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//definizioni globali
#define MAX_LEN 101

//struct per creare la tabella hash con liste di trabocco
typedef struct hash{

    int val;
    char vet[MAX_LEN];
    struct hash *next;

}Hash;
typedef Hash * ptHash;

//funzioni che useremo
int funz_hash(int val, int n);
void serch(ptHash *testa, int val, char *stringa);
void insert(ptHash * testa, int val, char *stringa);

//principale
int main(){

    //variabili
    int n;
    int val;
    int casella = 0 ;
    char *stringa = (char *)malloc(sizeof(char ) * MAX_LEN);
    scanf("%d", &n);
    ptHash *array = (ptHash * )malloc(sizeof(ptHash) * (2 * n));
    for(int i = 0; i<2*n; i++){
        array[i] = NULL;
    }
    for(int i = 0; i<n; i++){
        scanf("%d", &val);
        scanf("%s", stringa);
        casella = funz_hash(val, n);
        serch(&array[casella], val, stringa);
    }
    int k;
    scanf("%d", &k);
    ptHash temp = array[k];
    if(temp != NULL){
        while(temp != NULL){
            printf("%s\n", temp->vet);
            temp = temp->next;
        }
    }
    else{
        printf("vuota\n");
    }

}
//implemento funzioni
int funz_hash(int val, int n){
    return (val % 109) % (2 * n);
}
void serch(ptHash *testa, int val, char *stringa){

    ptHash temp = *testa;
    ptHash pre = NULL;
    while(temp != NULL && temp->val != val){
        pre = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        insert(testa, val, stringa);
    }
    else{
        if(pre != NULL){
            pre->next = temp->next;
            free(temp);
            insert(testa, val, stringa);
        }
        else if(pre == NULL){
            *testa = temp->next;
            free(temp);
            insert(testa, val, stringa);
        }
    }
}
void insert(ptHash * testa, int val, char *stringa){

    ptHash nodo = malloc(sizeof(Hash));
    nodo->val = val;
    strcpy(nodo->vet, stringa);
    nodo->next = NULL;

    ptHash cor = *testa;
    ptHash pre = NULL;

    while(cor != NULL && strcmp(cor->vet, stringa) < 0){
        pre = cor;
        cor = cor->next;
    }
    if(pre == NULL){
        nodo->next = *testa;
        *testa = nodo;
    }
    else{
        pre->next = nodo;
        nodo->next = cor;
    }

}