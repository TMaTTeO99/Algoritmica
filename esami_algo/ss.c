//librerie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//def globali
typedef struct tabella{

    char nome[101];
    char numero[21];
    struct tabella *next;

}Tabella;
typedef Tabella * ptTabella;

//funzioni di supporto
unsigned int hash(char *nome, int n){

    int i = 0;
    unsigned int x = 0;
    while(nome[i] != '\0'){
        x += nome[i];
        i++;
    }
    return x % (2*n);
}
void stampa(ptTabella lista){
    ptTabella t = lista;
    while(t != NULL){
        printf("%s %s\n", t->nome, t->numero);
        t = t->next;
    }
}
//funzioni che useremo
void insert(ptTabella * testa, char *nome, char *numero);

//principale
int main(){

    int n;
    unsigned int casella = 0;
    char *nome = (char *)malloc(sizeof(char) * 101);
    char *numero = (char *)malloc(sizeof(char) * 21);

    //inserisco numeri di elementi
    scanf("%d", &n);
    ptTabella *t_hash = (ptTabella *)malloc(sizeof(ptTabella) * (2*n));
    for(int i = 0; i<2*n; i++)
        t_hash[i] = NULL;

    for(int i = 0; i<n; i++){
        scanf("%s", nome);
        scanf("%s", numero);
        casella = hash(nome, n);
        insert(&t_hash[casella], nome, numero);
        free(nome);
        free(numero);
        nome = (char *)malloc(sizeof(char) * 101);
        numero = (char *)malloc(sizeof(char) * 21);
    }
    int k;
    scanf("%d", &k);

    stampa(t_hash[k]);


}
//implemento funzioni
void insert(ptTabella * testa, char *nome, char *numero){

    ptTabella nodo = malloc(sizeof(Tabella));
    strcpy(nodo->nome, nome);
    strcpy(nodo->numero, numero);
    nodo->next = NULL;
    ptTabella cor = *testa;
    ptTabella pre = NULL;
    while(cor != NULL && strcmp(nome, cor->nome) > 0){
        pre = cor;
        cor = cor->next;
    }
    if(pre == NULL){
        nodo->next = *testa;
        *testa = nodo;
    }
    else{
        nodo->next = cor;
        pre->next = nodo;
    }
}



