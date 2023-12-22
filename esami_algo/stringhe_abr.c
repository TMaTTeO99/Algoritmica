#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 101

//struct per memorizzare l abr
typedef struct abr{

    char key[MAX_LEN];
    struct abr *left;
    struct abr *right;

}ABR;
typedef ABR * ptABR;

//funzioni che useremo
void insert(ptABR * root, char *vet_temp);
char * prefix(ptABR root);
int prefisso(char *minimo, char *root_key);

int main(){

    //variabili
    ptABR root = NULL;
    int n;
    char *vet_temp = (char *)malloc(sizeof(char) * MAX_LEN);

    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%s", vet_temp);
        insert(&root, vet_temp);
        free(vet_temp);
        vet_temp = (char *)malloc(sizeof(char) * MAX_LEN);
    }
    prefix(root);
}
void insert(ptABR * root, char *vet_temp){

    if(* root == NULL){

        * root = malloc(sizeof(ABR));
        strcpy((* root)->key, vet_temp);
        (* root)->left = NULL;
        (* root)->right = NULL;

    }
    else{
        if(strcmp((* root)->key, vet_temp) < 0){
            insert(&((* root)->right), vet_temp);
        }
        else if(strcmp((* root)->key, vet_temp) > 0){
            insert(&((* root)->left), vet_temp);
        }
    }
}
char * prefix(ptABR root){

    if(root == NULL)return NULL;

    char *minimo = root->key;

    if(root->left != NULL){
        minimo = prefix(root->left);
    }
    if(prefisso(minimo, root->key) == 1){
        printf("%s\n", root->key);
    }
    prefix(root->right);
    return minimo;
}
int prefisso(char *minimo, char *root_key){

    int len_minimo = strlen(minimo);
    int len_root_key = strlen(root_key);
    if(len_minimo <= len_root_key){
        if(strncmp(minimo, root_key, len_minimo) == 0)return 1;
    }
    return 0;
}