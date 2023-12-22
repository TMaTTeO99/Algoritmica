//librerie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//struct per memorizzare tabella hash
typedef struct hash{

    int n;
    struct hash *next;

}Hash;
typedef Hash * ptHash;


//funzioni di supporto
unsigned int hash_due(int val, int n){
    return ((val % 137) % (2 * n));
}
unsigned int hash_uno(int val, int n){
    return ((val % 109) % (2 * n));
}
int len_lista(ptHash testa){

    ptHash t = testa;
    int l = 0;
    while(t != NULL){
        l += 1;
        t = t->next;
    }
    return l;
}
//funzioni che useremo
void insert(ptHash *testa, int val);
int cerca(ptHash testa, int k);

//principale
int main(){

    //variabili
    int n, k, val;
    //inserisco n e k
    scanf("%d %d", &n, &k);

    int flag = -1;
    //alloco dimensione alla tabella
    ptHash *tabella = (ptHash *)malloc(sizeof(ptHash) * (2*n));

    //annullo tutte le liste della tabella
    for(int i = 0; i<2*n; i++){
        tabella[i] = NULL;
    }
    //inserisco elementi
    for(int i = 0; i<n; i++){
        scanf("%d", &val);
        if(i == 0){
            if(val == k)flag = 1;
            insert(&tabella[hash_uno(val, n)], val);
        }
        else{
            int a = len_lista(tabella[hash_uno(val, n)]);
            int b = len_lista(tabella[hash_due(val, n)]);

            if(a >= b){
                if(a == b){
                    if(val == k)flag = 1;
                    insert(&tabella[hash_uno(val, n)], val);
                }
                else{
                    if(val == k)flag = 2;
                    insert(&tabella[hash_due(val, n)], val);
                }
            }
            else{
                if(val == k)flag = 1;
                insert(&tabella[hash_uno(val, n)], val);
            }
        }
    }
    int s = 0;
    if(flag == 1)s = hash_uno(k, n);
    else s = hash_due(k, n);

    printf("%d", cerca(tabella[s], k));


}
//implemento funzioni
void insert(ptHash *testa, int val){

    ptHash nodo = malloc(sizeof(Hash));
    if(nodo != NULL){
        nodo->n = val;
        nodo->next = *testa;
        *testa = nodo;
    }
    else{
        printf("Memoria esaurita.\n");
    }
}
int cerca(ptHash testa, int k){

    ptHash t = testa;
    int x = 0;
    int flag = 0;
    while(t != NULL){
        if(t->n == k)flag = 1;
        x += 1;
        t = t->next;
    }
    if(flag == 0)return 0;

    return x;
}