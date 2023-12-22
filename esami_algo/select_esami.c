//librerie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//definizioni globali
#define MAX_LEN 100

//struct per memorizzare esami dello studente
typedef struct esami{

    char *nome;
    int cfu;
    int difficolta;

}Esami;

//funzioni che useremo
int order(const void *x, const void *y);
int compare_due(const void *x, const void *y);

//principale
int main(){

    //variabili
    int k, n;
    Esami *array;

    //inserisco il numero di vreediti da raggiumgere
    scanf("%d", &k);
    //inserisco il nuemro di esami disponibili
    scanf("%d", &n);

    //alloco memoria al vettore per salvare lgi esami
    array = (Esami * )malloc(sizeof(Esami) * n);
    for(int i = 0; i<n; i++){
        array[i].nome = (char *)malloc(sizeof(array) * MAX_LEN);
        scanf("%s", array[i].nome);
        scanf("%d", &array[i].cfu);
        scanf("%d", &array[i].difficolta);
    }
    qsort(array, n, sizeof(Esami), order);

    //siccome la traccia dice che gli esami selezionati vanno stampati in ordine lessicografico
    //uso un altro array di ptr per ordinarli e stamparli
    char **vet = (char **)malloc(sizeof(char *) * n);
    for(int i = 0; i<n; i++){
        vet[i] = (char *)malloc(sizeof(char) * MAX_LEN);
    }
    int j = 0;
    int s = 0;
    while(j < n && k > 0){
        if((k - array[j].cfu) >= 0){
            strcpy(vet[s], array[j].nome);
            k -= array[j].cfu;
            s++;
        }
        j++;
    }
    qsort(vet, s, sizeof(char *), compare_due);
    for(int i = 0; i<s; i++){
        printf("%s\n", vet[i]);
    }
    free(array);
    for(int i = 0; i<n; i++){
        free(vet[i]);
    }
}
//implemento funzioni
int order(const void *x, const void *y){

    Esami *a = (Esami *)x;
    Esami *b = (Esami *)y;

    if((a)->cfu == (b)->cfu){
        if((a)->difficolta == (b)->difficolta){
            return strcmp((a)->nome, (b)->nome);
        }
        else{
            return (a)->difficolta - (b)->difficolta;
        }
    }
    else{
        return (b)->cfu - (a)->cfu;
    }

}
int compare_due(const void *x, const void *y){

    char ** a = (char **)x;
    char ** b = (char **)y;
    return strcmp(*a, *b);
}