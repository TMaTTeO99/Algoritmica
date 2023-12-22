//librerie
#include<stdio.h>
#include<stdlib.h>

//struct per definire abr
typedef struct abr{

    int key;
    struct abr *left;
    struct abr *right;

}ABR;
typedef ABR * ptABR;

//funzzioni che useremo
void insert(ptABR * root, int val);
void mediana(ptABR root, int rango_mediana, int *counter);

//principale
int main(){

    //variabili
    ptABR root = NULL;//riferimento alla radice
    int n;//numero di elementi dell abr
    int val;
    scanf("%d", &n);//inserisco numero di elementi

    //inserisco input
    for(int i = 0; i<n; i++){
        scanf("%d", &val);
        insert(&root, val);
    }
    int counter = 0;
    int rango_mediana = 0;
    if(n % 2 == 0){
        rango_mediana = n / 2 + 1;
    }
    else{
        counter = -1;
        rango_mediana = n / 2;
    }

    mediana(root, rango_mediana, &counter);
}
//funzioni implementate
void insert(ptABR * root, int val){

    if(*root == NULL){

        * root = malloc(sizeof(ABR));
        (* root)->key = val;
        (* root)->right = NULL;
        (* root)->left = NULL;
    }
    else{
        if((* root)->key > val){
            insert(&((* root)->left), val);
        }
        else if((* root)->key < val){
            insert(&((* root)->right), val);
        }
    }
}
void mediana(ptABR root, int rango_mediana, int *counter){

    if(root != NULL){
        mediana(root->left, rango_mediana, counter);
        *counter += 1;
        if(*counter == rango_mediana){
            printf("%d\n", root->key);
            return;
        }
        mediana(root->right, rango_mediana, counter);
    }

}