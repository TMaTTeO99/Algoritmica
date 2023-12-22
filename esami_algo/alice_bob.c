//librerie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//definizioni globali
#define MAX_LEN 200
//struct per creare la tabella hash con liste di trabbocco
typedef struct tab_hash{

    int valore;
    char oggetto[MAX_LEN];
    struct tab_hash *next;

}Tab_hash;
typedef Tab_hash * ptTab_hash;

//funzioni che useremo

unsigned int hash(char *oggetto, int n);
void insert(ptTab_hash * testa, char *oggetto, int val);
void serach(ptTab_hash * testa, char *oggetto, int val);
void insert_non_oder(ptTab_hash * testa, char *oggetto, int val);
void serach_2(ptTab_hash * testa, char *oggetto, int val);

//principale
int main(){

    //variabili
    int n, val;
    unsigned int casella = 0;
    //inserisco numero di oggetti totali
    scanf("%d", &n);
    ptTab_hash *tabella = (ptTab_hash * )malloc(sizeof(ptTab_hash) * (2 * n));
    for(int i = 0; i< 2 * n; i++){
        tabella[i] = NULL;
    }
    char *oggetto = (char *)malloc(sizeof(char ) * MAX_LEN);
    for(int i = 0; i<n; i++){
        scanf("%s", oggetto);
        scanf("%d", &val);
        casella = hash(oggetto, n);
        serach(&tabella[casella], oggetto, val);
        free(oggetto);
        oggetto = (char *)malloc(sizeof(char ) * MAX_LEN);
    }
    ptTab_hash finale = NULL;
    for(int i = 0; i<2*n; i++){
        ptTab_hash t = tabella[i];
        while(t != NULL){
            serach_2(&finale, t->oggetto, t->valore);
            t = t->next;
        }
    }
    ptTab_hash q = finale;
    int l = 0;
    while(l < 15 && q != NULL){
        printf("%s\n", q->oggetto);
        l++;
        q = q->next;
    }
}
//implemento funzioni
unsigned int hash(char *oggetto, int n){

    int i = 0;
    unsigned int sum = 0;
    while(oggetto[i] != '\0'){
        sum += oggetto[i];
        i++;
    }
    return sum % (2 * n);
}
void serach(ptTab_hash *testa, char *oggetto, int val){

    if(*testa != NULL){
        ptTab_hash temp = *testa;
        while(temp != NULL && (strcmp(temp->oggetto, oggetto) != 0)){
            temp = temp->next;
        }
        if(temp == NULL){
            insert_non_oder(testa, oggetto, val);
            //insert(testa, oggetto, val);
            return;
        }
        else{
            if(temp->valore < val){
                temp->valore = val;
            }
        }
    }
    else{
        insert_non_oder(testa, oggetto, val);
        //insert(testa, oggetto, val);
    }
}
void insert(ptTab_hash * testa, char *oggetto, int val){

    if(* testa == NULL){
        ptTab_hash nodo = malloc(sizeof(Tab_hash));
        if(nodo != NULL){
            nodo->valore = val;
            strcpy(nodo->oggetto, oggetto);
            nodo->next = *testa;
            *testa = nodo;
        }
        else{
            printf("Memoria esaurita.\n");
        }
    }
    else if((* testa)->valore <= val){
        if((* testa)->valore == val){
            int x = strcmp((* testa)->oggetto, oggetto);
            if(x >= 0){
                ptTab_hash nodo = malloc(sizeof(Tab_hash));
                if(nodo != NULL){
                    nodo->valore = val;
                    strcpy(nodo->oggetto, oggetto);
                    nodo->next = *testa;
                    *testa = nodo;
                }
                else{
                    printf("Memoria esaurita.\n");
                }
            }
            else{
                insert(&((* testa)->next), oggetto, val);
            }
        }
        else{
            ptTab_hash nodo = malloc(sizeof(Tab_hash));
            if(nodo != NULL){
                nodo->valore = val;
                strcpy(nodo->oggetto, oggetto);
                nodo->next = *testa;
                *testa = nodo;
            }
            else{
                printf("Memoria esaurita.\n");
            }
        }
    }
    else{
        insert(&((* testa)->next), oggetto, val);
    }
}
void insert_non_oder(ptTab_hash * testa, char *oggetto, int val){

    ptTab_hash nodo = malloc(sizeof(Tab_hash));
    if(nodo != NULL){
        nodo->valore = val;
        strcpy(nodo->oggetto, oggetto);
        nodo->next = *testa;
        *testa = nodo;
    }
    else{
        printf("Memoria esaurita.\n");
    }
}
void serach_2(ptTab_hash * testa, char *oggetto, int val){

    if(*testa != NULL){
        ptTab_hash temp = *testa;
        while(temp != NULL && (strcmp(temp->oggetto, oggetto) != 0)){
            temp = temp->next;
        }
        if(temp == NULL){
            insert(testa, oggetto, val);
            return;
        }
        else{
            if(temp->valore < val){
                temp->valore = val;
            }
        }
    }
    else{
        insert(testa, oggetto, val);
    }
}