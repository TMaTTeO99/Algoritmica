//librerie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct per creare l abr

typedef struct abr{

    char nome[150];
    int val;
    struct abr *l;
    struct abr *r;
    struct abr *d;

}ABR;
typedef ABR * ptABR;

//funzioni di supporto
void visit(ptABR root, int *max){

    if(root != NULL){
        visit(root->l, max);
        if(root->val >= *max)*max = root->val;
        visit(root->r, max);
    }

}


//funzioni che useremo
void insert(ptABR *root, char *nome, int val);
int search(ptABR *root,  char *trova);

//principale
int main(){

    //variabili
    ptABR root = NULL;
    int n, val;
    char *nome = (char *)malloc(sizeof(char) * 100);
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%s", nome);
        scanf("%d", &val);
        insert(&root, nome, val);
        free(nome);
        nome = (char *)malloc(sizeof(char) * 150);
    }
    char * trova = (char * )malloc(sizeof(char) * 150);
    scanf("%s", trova);

    printf("%d\n", search(&root,  trova));

}
//funzioni implementate
void insert(ptABR *root, char *nome, int val){

    ptABR nodo = malloc(sizeof(ABR));
    nodo->val = val;
    strcpy(nodo->nome, nome);
    nodo->d = NULL;
    nodo->l = NULL;
    nodo->r = NULL;
    ptABR y = NULL;
    ptABR scorri = *root;

    while(scorri != NULL){
        y = (scorri);
        if((strcmp(scorri->nome, nodo->nome) > 0)){
            scorri = scorri->l;
        }
        else if((strcmp(scorri->nome, nodo->nome) < 0)){
            scorri = scorri->r;
        }
    }
    nodo->d = y;
    if(y == NULL){
        *root = nodo;
    }
    else{
        if((strcmp(y->nome, nodo->nome) > 0)){
            y->l = nodo;
        }
        else if((strcmp(y->nome, nodo->nome) < 0)){
            y->r = nodo;
        }
    }
}
int search(ptABR * root,  char *trova){

    ptABR scorri = * root;
    while(scorri != NULL && strcmp(scorri->nome, trova) != 0){
        if((strcmp(scorri->nome, trova) > 0)){
            scorri = scorri->l;
        }
        else if((strcmp(scorri->nome, trova) < 0)){
            scorri = scorri->r;
        }
    }


    scorri->d = NULL;
    int max = 0;
    visit(scorri, &max);

    return max;
}