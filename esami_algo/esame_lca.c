//librerie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//struct per memorizzare abr
typedef struct n{
    int key;
    struct n * left;
    struct n * right;
}node;
typedef node * ptnode;

//funzioni che useremo
void insert(ptnode * root, int val);
int lca(node * root , int x, int y);

//principale
int main(){

    //variabili
    ptnode root = NULL;
    int n;//numero di nodi da inserire nell abr
    int val, x, y;//variabile per inserire i valori
    scanf("%d", &n);//inserisco n

    //ciclo per inserire input
    for(int i = 0; i<n; i++){
        scanf("%d", &val);
        insert(&root, val);
    }
    scanf("%d", &x);
    scanf("%d", &y);
    printf("%d\n", lca(root , x, y));

}
//funzioni che useremo
void insert(ptnode * root, int val){

    if(* root == NULL){
        * root = malloc(sizeof(node));
        (* root)->key = val;
        (* root)->left = NULL;
        (* root)->right = NULL;
    }
    else{
        if((* root)->key > val){
            insert(&((* root)->left), val);
        }
        else{
            insert(&((* root)->right), val);
        }
    }
}
int lca(node * root , int x, int y){


    if((* root).key > x && (* root).key > y){
        lca((* root).left , x, y);
    }
    else if((* root).key < x && (* root).key < y){
        lca((* root).right , x, y);
    }
    else{
        return (* root).key;
    }

}