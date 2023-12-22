//librerie
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//struct per i valori di ritorno
typedef struct rit{

    int sum;
    int min;

}Rit;

//truct per memorizzare abr
typedef struct albero{

    int key;
    Rit dati_left;
    Rit dati_right;
    struct albero *left;
    struct albero *right;


}Albero;
typedef Albero *ptAlbero;

//funzioni di supporto
int max(int x, int y){
    if(x >= y)return x;

    return y;
}
int min(int x, int y){
    if(x >= y)return y;

    return x;

}


//funzioni cher useremo
void insert(ptAlbero * root, int key);
Rit cammino_minimo(ptAlbero root);

//principale
int main(){

    //variabili
    ptAlbero root = NULL;//riferimento alla radice dell albero
    int n;
    int key;

    //inserisco numero di nodi dell abr
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &key);
        insert(&root, key);
    }
    if(n > 0){
        Rit x = cammino_minimo(root);
        printf("%d\n", x.min);
    }
    else{
        printf("%d\n", n);
    }

}
//funzioni implementate
void insert(ptAlbero * root, int key){

    if(* root == NULL){
        * root = malloc(sizeof(Albero));
        (* root)->key = key;
        (* root)->left = NULL;
        (* root)->right = NULL;
    }
    else{

        if((* root)->key > key){
            insert(&(((* root)->left)), key);
        }
        else if((* root)->key < key){
            insert(&(((* root)->right)), key);
        }
    }
}
Rit cammino_minimo(ptAlbero root){

    if(root == NULL){
        Rit r;
        r.sum = 0;
        r.min = INT_MAX;
        return r;
    }
    if(root->left == NULL && root->right == NULL){
        Rit r;
        r.sum = root->key;
        r.min = root->key;
        return r;
    }
    root->dati_left = cammino_minimo(root->left);
    root->dati_right = cammino_minimo(root->right);

    root->dati_left.sum += root->key;
    root->dati_right.sum += root->key;

    Rit r2;
    r2.sum = max(root->dati_left.sum, root->dati_right.sum);

    if(r2.sum == root->dati_left.sum){
        r2.min = min(root->dati_left.min, root->key);
    }
    else{
        r2.min = min(root->dati_right.min, root->key);
    }
    return r2;
}