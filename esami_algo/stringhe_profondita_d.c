//librerie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//definizoni gloabeli
#define MAX_LEN 1001

//struct per salvare l abr
typedef struct abr{

    char s[MAX_LEN];
    int val;
    struct abr *left;
    struct abr *right;

}ABR;
typedef ABR *ptABR;

//funzioni di supporto
int order(const void *x, const void *y){
    char *a = *(char **)x;
    char *b = *(char **)y;
    return strcmp(a, b);
}

//funzioni che useremo
void insert(ptABR *root, int val, char *vet);
void trova(ptABR root, int d, char **array, int *index, int prof);

//principale
int main(){

    //variabili
    ptABR root = NULL;
    int n, d;
    int val;
    char *vet = (char *)malloc(sizeof(char) * MAX_LEN);
    scanf("%d %d", &n, &d);

    for(int i = 0; i<n; i++){
        scanf("%d", &val);
        scanf("%s", vet);
        insert(&root, val, vet);
        free(vet);
        vet = (char *)malloc(sizeof(char) * MAX_LEN);
    }
    char **array = (char **)malloc(sizeof(char*) * n);
    for(int i = 0; i<n; i++){
        array[i] = (char *)malloc(sizeof(char) * MAX_LEN);
    }
    int prof = 0;
    int index = 0;
    trova(root, d, array, &index, prof);
    qsort( array, index, sizeof(char *), order);
    printf("%d\n", index);
    for(int i = 0; i<index; i++){
        printf("%s\n", array[i]);
    }
}
//funzioni implementate
void insert(ptABR *root, int val, char *vet){

    if(*root == NULL){
        *root = malloc(sizeof(ABR));
        strcpy((*root)->s, vet);
        (*root)->val = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else{
        if((*root)->val >= val){
            insert(&((*root)->left), val, vet);
        }
        else{
            insert(&((*root)->right), val, vet);
        }
    }
}
void trova(ptABR root, int d, char **array, int *index, int prof){

    if(root != NULL){
        if(prof == d){
            strcpy(array[*index], root->s);
            *index += 1;
            return;
        }
        else{
            trova(root->left, d, array, index, prof + 1);
            trova(root->right, d, array, index, prof + 1);
        }
    }

}