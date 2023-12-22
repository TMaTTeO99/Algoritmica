//librerie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//definizioni globali
#define MAX_LEN 1001

//struct per memorizzare abr
typedef struct abr{

    char s[MAX_LEN];
    struct abr *left;
    struct abr *right;

}Abr;
typedef Abr * ptAbr;

//funzioni di supporto
char * check(char * sx, char *dx, int *len){
    int len_sx = strlen(sx);
    int len_dx = strlen(dx);
    int x = 0;
    if(len_sx >= len_dx)x = len_dx;
    else x = len_sx;

    int i = 0;
    while(i < x && sx[i] == dx[i]){
        i++;
    }
    char *temp = (char *)malloc(sizeof(char) * i);
    strncpy(temp, sx, i);
    *len = i;
    return temp;
}

//funzioni che useremo
void insert(ptAbr * root, char *vet);
int search(ptAbr root, char *vet);
char *len_prefix(ptAbr scorri, int *len);

//principale
int main(){

    //variabili
    int n;
    ptAbr root = NULL;
    char *vet = (char * )malloc(sizeof(char) * MAX_LEN);
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%s", vet);
        insert(&root, vet);
        free(vet);
        vet = (char * )malloc(sizeof(char) * MAX_LEN);
    }
    scanf("%s", vet);
    printf("%d\n",  search(root, vet));


}
//implemento funzioni
void insert(ptAbr * root, char *vet){

    if(* root == NULL){
        * root = malloc(sizeof(Abr));
        strcpy((* root)->s, vet);
        (* root)->right = NULL;
        (* root)->left = NULL;
    }
    else{
        if(strcmp((* root)->s, vet) >= 0){
            insert(&((* root)->left), vet);
        }
        else{
            insert(&((* root)->right), vet);
        }
    }
}
int search(ptAbr root, char *vet){

    ptAbr scorri = root;
    while(scorri != NULL && strcmp(scorri->s, vet) != 0){
        if(strcmp(scorri->s, vet) >= 0){
            scorri = scorri->left;
        }
        else{
            scorri = scorri->right;
        }
    }
    if(scorri == NULL)return -1;
    int len = 0;
    if(scorri->left != NULL || scorri->right != NULL){
        len_prefix(scorri, &len);
    }
    else{
        len = strlen(scorri->s);
    }
    return len;

}
char * len_prefix(ptAbr scorri, int *len){

    if(scorri == NULL)return NULL;
    if(scorri->left == NULL && scorri->right == NULL){
        return scorri->s;
    }
    char *sx = len_prefix(scorri->left, len);
    char *dx = len_prefix(scorri->right, len);

    if(sx == NULL && dx != NULL){
        return check(dx, scorri->s, len);
    }
    else if(sx != NULL && dx == NULL){
        return check(sx, scorri->s, len);
    }
    return check(dx, sx, len);

}