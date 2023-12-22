//librerie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct per implementare abr
typedef struct _node {
    int key ; /* Chiave */
    struct _node * left ; /* Sottoalbero sinistro */
    struct _node * right ; /* Sottoalbero destro */
}tree_node;
typedef tree_node * ptree_node;

//funzioni che useremo
void insert(ptree_node * root, int val);
int secondo_massimo(ptree_node root);

//principale
int main(){

    //variabili
    ptree_node root = NULL;
    int n, val;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        scanf("%d", &val);
        insert(&root, val);
    }
    printf("%d\n", secondo_massimo(root));


}
//implemento funzioni
void insert(ptree_node * root, int val){

    if(* root == NULL){
        * root = malloc(sizeof(tree_node));
        (* root)->left = NULL;
        (* root)->right = NULL;
        (* root)->key = val;
    }
    else{
        if((* root)->key > val){
            insert(&((* root)->left), val);
        }
        else if((* root)->key <= val){
            insert(&((* root)->right), val);
        }
    }

}
int secondo_massimo(ptree_node root){

    ptree_node pre = NULL;
    ptree_node scorri = root;
    while(scorri->right != NULL){
        pre = scorri;
        scorri = scorri->right;
    }
    if(scorri->left != NULL){
        scorri = scorri->left;
        while(scorri->right != NULL){
            scorri = scorri->right;
        }
        return scorri->key;
    }


    return pre->key;


}