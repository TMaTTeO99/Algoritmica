#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct per definire abr
typedef struct abr{

    int key;
    int color;
    struct abr *left;
    struct abr *right;

}ABR;
typedef ABR * prABR;

//enum per definire i colori
enum colori {rosso = 0, bianco = 1};

//funzioni di supporto
int modulo(int sx, int dx){
    if(sx - dx < 0){
        return - (sx - dx);
    }
    return sx - dx;
}
int max_fun(int sx, int dx){
    if(sx >= dx){
        return sx;
    }
    return dx;
}

//funzioni che useremo
void insert(prABR * root, int val, int color);
int altezza_rossa(prABR root);

//principale
int main(){

    //variabili
    prABR root = NULL;
    int n, val, color;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        scanf("%d", &val);
        scanf("%d", &color);
        insert(&root, val, color);
    }
    altezza_rossa(root);
    printf("TRUE\n");
}
//implemento funzioni
void insert(prABR * root, int val, int color){

    if(*root == NULL){

        *root = malloc(sizeof(ABR));
        (*root)->key = val;
        (*root)->color = color;
        (*root)->right = NULL;
        (*root)->left = NULL;
    }
    else{
        if((*root)->key > val){
            insert(&((* root)->left), val, color);
        }
        else if((*root)->key < val){
            insert(&((* root)->right), val, color);
        }
    }
}
int altezza_rossa(prABR root){

    if(root == NULL)return 0;
    if(root->left == NULL && root->right == NULL){
        if(root->color == rosso){
            return 1;
        }
        else{
            return 0;
        }
    }
    int sx = altezza_rossa(root->left);
    int dx = altezza_rossa(root->right);
    int dif = modulo(sx, dx);
    if(dif > 1){
        printf("FALSE\n");
        exit(0);
    }
    int max = max_fun(sx, dx);
    if(root->color == rosso){
        max += 1;
    }
    return max;
}