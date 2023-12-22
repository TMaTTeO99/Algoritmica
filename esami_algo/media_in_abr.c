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

}ABR;
typedef ABR * ptABR;

//funzioni che useremo
void insert(ptABR * root, char *string);
int media(ptABR root, char *string);
float media_sottoabr(ptABR scorri);

//principale
int main(){

    //variabili
    ptABR root = NULL;
    int n;
    char *string = (char *)malloc(sizeof(char) * MAX_LEN);
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        scanf("%s", string);
        insert(&root, string);
        free(string);
        string = (char *)malloc(sizeof(char) * MAX_LEN);
    }
    scanf("%s", string);
    printf("%d\n", media(root, string));
}
//implemento funzioni
void insert(ptABR * root, char *string){

    if(* root == NULL){
        * root = malloc(sizeof(ABR));
        strcpy((* root)->s, string);
    }
    else{
        if(strcmp((* root)->s, string) >= 0){
            insert(&((* root)->left), string);
        }
        else{
            insert(&((* root)->right), string);
        }
    }
}
int media(ptABR root, char *string){

    ptABR scorri = root;
    float media = 0;
    int i = 0;
    while(scorri != NULL && strcmp(scorri->s, string) != 0){
        media += strlen(scorri->s);
        i++;
        if(strcmp(scorri->s, string) >= 0){
            scorri = scorri->left;
        }
        else{
            scorri = scorri->right;
        }
    }
    if(scorri == NULL)return 0;
    media += strlen(scorri->s);
    i++;
    media /= i;
    float media_due = 0;
    if(scorri->left != NULL || scorri->right != NULL){
        media_due = media_sottoabr(scorri);
    }
    if(media_due < media)return 1;
    if(media_due == media)return 0;
    return -1;
}
float media_sottoabr(ptABR scorri){

    if(scorri == NULL){
        return 0;
    }
    if(scorri->left == NULL && scorri->right == NULL){
        return strlen(scorri->s);
    }
    float msx = media_sottoabr(scorri->left);
    float mdx = media_sottoabr(scorri->right);
    if(msx == 0 && mdx != 0){
        return (mdx + strlen(scorri->s)) / 2;
    }
    else if(msx != 0 && mdx == 0){
        return (msx + strlen(scorri->s)) / 2;
    }
    else if(msx != 0 && mdx != 0){
        return (msx + mdx + strlen(scorri->s)) / 3;
    }
    return strlen(scorri->s);
}