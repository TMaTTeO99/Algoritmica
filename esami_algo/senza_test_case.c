//libreire
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//definizioni globali
#define MAX_LEN 20

//struct per memorizzare abr
typedef struct per{

    char nome[MAX_LEN];
    int id;
    struct per *left;
    struct per *right;

}Per;
typedef Per * ptPer;

//struct per memorizzare lista
typedef struct tabella{

    char vittima[MAX_LEN];
    struct tabella *next;

}Tabella;
typedef Tabella * ptTabella;

//funzioni che useremo
void insert(ptPer * root, char *nome, int id);
int search(ptPer root, char * nome);
void insert_lista(ptTabella *testa, char *vittima);
void stampa(ptTabella testa);

//principale
int main(){

    //variabili
    int m, n;
    int id;
    ptPer root = NULL;//variabilie abr
    char *nome = (char *)malloc(sizeof(char) * MAX_LEN);//vet per inserire nome personaggi

    //inserisco numero di personaggi
    scanf("%d", &m);

    //ciclo per inserire input un abr
    for(int i = 0; i<m; i++){
        scanf("%s", nome);
        scanf("%d", &id);
        insert(&root, nome, id);
        free(nome);
        nome = (char *)malloc(sizeof(char) * MAX_LEN);
    }

    //vet per salvare la vittima
    char *vittima = (char *)malloc(sizeof(char) * MAX_LEN);

    //alloco tabella
    ptTabella *t_hash = (ptTabella * )malloc(sizeof(ptTabella) * m);

    //inizializzo tabella
    for(int i = 0; i<m; i++){
        t_hash[i] = NULL;
    }

    //inserisco numero di vittime
    scanf("%d", &n);

    //ciclo per inserire input
    for(int i = 0; i<n; i++){
        scanf("%s", nome);
        scanf("%s", vittima);
        int k = search(root, nome);
        insert_lista(&t_hash[k], vittima);
        free(nome);
        free(vittima);
        nome = (char *)malloc(sizeof(char) * MAX_LEN);
        vittima = (char *)malloc(sizeof(char) * MAX_LEN);
    }
    scanf("%s", nome);
    stampa(t_hash[search(root, nome)]);
}
//implemento funzioni
void insert(ptPer * root, char *nome, int id){

    if(* root == NULL){
        * root = malloc(sizeof(Per));
        (* root)->id = id;
        strcpy((* root)->nome, nome);
        (* root)->left = NULL;
        (* root)->right = NULL;
    }
    else{
        if(strcmp((* root)->nome, nome) > 0){
            insert(&((* root)->left), nome, id);
        }
        else if(strcmp((* root)->nome, nome) < 0){
            insert(&((* root)->right), nome, id);
        }
    }
}
int search(ptPer root, char * nome){

    ptPer scorri = root;
    while(scorri != NULL && strcmp(scorri->nome, nome) != 0){
        if(strcmp(scorri->nome, nome) < 0){
            scorri = scorri->right;
        }
        else if(strcmp(scorri->nome, nome) > 0){
            scorri = scorri->left;
        }
    }
    /*if(scorri == NULL){

    }*/
    return  scorri->id;
}
void insert_lista(ptTabella *testa, char *vittima){

    ptTabella nodo = malloc(sizeof(Tabella));
    if(nodo != NULL){
        strcpy(nodo->vittima, vittima);
        nodo->next = *testa;
        *testa = nodo;
    }
    else{
        printf("Memoria esaurita.\n");
    }


}
void stampa(ptTabella testa){

    ptTabella t = testa;
    while(t != NULL){
        printf("%s\n", t->vittima);
        t = t->next;
    }

}