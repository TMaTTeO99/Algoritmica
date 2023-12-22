//librerie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//definizioni globali
#define MAX_LEN 150

//struct per salvare abr
typedef struct abr{

    int key;
    char stringa[MAX_LEN];
    struct abr *left;
    struct abr *right;

}ABR;
typedef ABR * ptABR;

//funzioni di suprto
void minimum(char *str_sx, char *str_dx, char * root_stringa, char *minimo){

    if(str_sx != NULL && str_dx != NULL){
        if(strcmp(str_sx, str_dx) <= 0){
            if(strcmp(str_sx, root_stringa) <= 0){
                strcpy(minimo, str_sx);
                //return str_sx;
            }
            else{
                strcpy(minimo,root_stringa);
                //return root_stringa;
            }
        }
        else{
            if(strcmp(str_dx, root_stringa) <= 0){
                strcpy(minimo,str_dx);
                //return str_dx;
            }
            else{
                strcpy(minimo,root_stringa);
                //return root_stringa;
            }
        }
    }
    else if(str_sx != NULL && str_dx == NULL){
        if(strcmp(str_sx, root_stringa) >= 0){
            strcpy(minimo,root_stringa);
            //return  root_stringa;
        }
        else{
            strcpy(minimo,str_sx);
            //return str_sx;
        }
    }
    else if(str_sx == NULL && str_dx != NULL){
        if(strcmp(str_dx, root_stringa) >= 0){
            strcpy(minimo,root_stringa);
            //return  root_stringa;
        }
        else{
            strcpy(minimo,str_dx);
            //return str_dx;
        }
    }
}
//funzioni che useremo
void insert(ptABR * root, int key, char * vet);
char * minore(ptABR root, int k, char *minino);

//principale
int main(){

    //variabili
    ptABR root = NULL;
    int n;//numeo di nodi
    int key, k;

    char *vet = (char *)malloc(sizeof(char) * MAX_LEN);
    scanf("%d", &n);//inserisco numero nodi
    for(int i = 0; i<n; i++){
        scanf("%d", &key);
        scanf("%s", vet);
        insert(&root, key, vet);
        free(vet);
        vet = (char *)malloc(sizeof(char) * MAX_LEN);
    }
    char *minino = (char *)malloc(sizeof(char) * MAX_LEN);
    strcpy(minino, "vuoto");
    scanf("%d", &k);
    minore(root, k, minino);
    printf("%s\n", minino);
}
//implemento funzioni
void insert(ptABR * root, int key, char * vet){

    if(* root == NULL){
        * root = malloc(sizeof(ABR ));
        (* root)->left = NULL;
        (* root)->right = NULL;
        (* root)->key = key;
        strcpy((* root)->stringa, vet);
    }
    else{
        if((* root)->key > key){
            insert(&((* root)->left), key, vet);
        }
        else if((* root)->key < key){
            insert(&((* root)->right), key, vet);
        }
    }
}
char * minore(ptABR root, int k, char *minino){

    if(root == NULL)return NULL;
    if(root->key != k){

        if(root->left == NULL && root->right == NULL)return root->stringa;

        char *str_sx = minore(root->left, k, minino);
        char *str_dx = minore(root->right, k, minino);

        minimum(str_sx, str_dx, root->stringa, minino);
        return minino;
    }
    else{
        return NULL;
    }

}