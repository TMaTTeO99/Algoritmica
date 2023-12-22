//librerie
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//struct per memorizzare tabella hash
typedef struct hash{

    int key;
    int freq;

}Hash;

//funzioni di supporto
int funzione_hash(int key, int n){

    return key % n;

}
//funzioni che useremo
int search(Hash tabella[], int casella, int key);

//principale
int main(){

    //variabili
    int n, k;
    //inserisco dim di array e k
    scanf("%d %d", &n, &k);
    int casella = 0;
    Hash tabella[n];
    int array[n];

    //inserisco input
    for(int i = 0; i<n; i++){
        scanf("%d", &array[i]);
        tabella[i].key = INT_MAX;
        tabella[i].freq = 1;
    }
    for(int i = 0; i<n; i++){
        casella = funzione_hash(array[i], n);
        if(!search(tabella, casella, array[i])){
            tabella[casella].key = array[i];
            //tabella[casella].freq += 1;
        }
        else{
            tabella[casella].freq += 1;
        }
    }
    for(int i = 0; i<n; i++){
        if(tabella[funzione_hash(array[i], n)].freq >= k){
            printf("%d ", array[i]);
        }
    }
    printf("\n");


}
//implemento funzioni
int search(Hash tabella[], int casella, int key){
    if(tabella[casella].key == INT_MAX){
        return 0;
    }
    return 1;
}

