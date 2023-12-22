#include<stdio.h>
#include<stdlib.h>

typedef struct abr{

    int key;
    int colore;
    struct abr *left;
    struct abr *right;

}Abr;
typedef Abr * ptAbr;

typedef struct ritorno{

    int key;
    int n;

}Ritorno;

typedef struct n_colori{

    int b;
    int r;

}N_COL;


enum colore{rosso = 0, blu = 1};
void insert(ptAbr *root, int val, int colore);
N_COL ros(ptAbr root, Ritorno vet[], int *j);
int main(){

    ptAbr root = NULL;
    int val;
    int colore;
    for(int i = 0; i<10; i++){
        scanf("%d", &val);
        scanf("%d", &colore);
        insert(&root, val, colore);
    }
    Ritorno *vet = (Ritorno *)malloc(sizeof(Ritorno) * 5);
    int j = 0;
    ros(root, vet, &j);
    int k = 0;
    int index = 0;
    for(int i = 0; i<10; i++){
        if(vet[i].n > k){
            k = vet[i].n;
            index = i;
        }
    }
    printf("%d\n", vet[index].key);

}
void insert(ptAbr *root, int val, int colore){

    if(*root == NULL){
        *root = malloc(sizeof(Abr));
        (*root)->key = val;
        (*root)->colore = colore;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else{
        if((*root)->key > val){
            insert(&((*root)->left), val, colore);
        }
        else if((*root)->key > val){
            insert(&((*root)->left), val, colore);
        }
    }

}
N_COL ros(ptAbr root, Ritorno vet[], int *j){

    if(root != NULL){
        if(root->left == NULL && root->right == NULL){
            if(root->colore == rosso){
                N_COL x;
                x.r = 1;
                x.b = 0;
                return x;
            }
            else{
                N_COL x;
                x.r = 0;
                x.b = 1;
                return x;
            }
        }
        N_COL s = ros(root->left, vet, j);
        N_COL d = ros(root->right, vet, j);

        N_COL x;
        x.b = s.b + d.b;
        x.r = s.r + d.r;

        if(x.b == 0){
            vet[*j].n = x.r;
            vet[*j].key = root->key;
            *j += 1;
        }

        if(root->colore == blu)x.b += 1;
        else x.r += 1;
        return x;
    }


}