//librerie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//definizioni globali
#define MAX_LEN 110

//struct per memorizzare una lista ordinata
typedef struct lista{

    char s[MAX_LEN];
    struct lista * next;

}Lista;
typedef Lista * ptLista;

//funzioni che useremo
void pre_su(char *input, char *p, char *s, ptLista * testa);
void insert(ptLista * testa, char *input);

//principale
int main(){

    //variabili
    ptLista testa = NULL;//testa della lista
    char *p = (char *)malloc(sizeof(char ) * MAX_LEN);
    char *s = (char *)malloc(sizeof(char ) * MAX_LEN);
    int n;
    char *input = (char *)malloc(sizeof(char ) * MAX_LEN);

    scanf("%s", p);
    scanf("%s", s);

    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%s", input);
        pre_su(input, p, s, &testa);
        free(input);
        input = (char *)malloc(sizeof(char ) * MAX_LEN);
    }
    free(input);
    free(p);
    free(s);
    ptLista t = testa;
    while(t != NULL){
        printf("%s\n", t->s);
        t = t->next;
    }
}
//funzioni implementate
void pre_su(char *input, char *p, char *s, ptLista * testa){

    int len_p = strlen(p);
    int len_s = strlen(s);
    int len_input = strlen(input);
    if(strncmp(input, p, len_p) == 0)insert(testa, input);

    if(len_s < len_input){
        if(strcmp(input +  (len_input - len_s ) , s) == 0)insert(testa, input);
    }
}
void insert(ptLista * testa, char *input){

    if(* testa == NULL){
        ptLista nodo = malloc(sizeof(Lista));
        strcpy(nodo->s, input);
        nodo->next = *testa;
        *testa = nodo;
    }
    else if(strcmp((* testa)->s, input) >= 0){
        if(strcmp((* testa)->s, input) != 0){
            ptLista nodo = malloc(sizeof(Lista));
            strcpy(nodo->s, input);
            nodo->next = *testa;
            *testa = nodo;
        }
    }
    else{
        insert(&((* testa)->next), input);
    }
}

