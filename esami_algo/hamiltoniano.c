#include<stdio.h>
#include<stdlib.h>

typedef struct grafo{

    int v;
    int n_archi;
    int * lista;

}Grafo;

void scambia(Grafo *x, Grafo *y){

    Grafo temp = *x;
    *x = *y;
    *y = temp;

    //exit(0);
}


void permutazioni(Grafo g[], int k, int n);
void elabora(Grafo g[], int n);

int main(){

    int n;
    scanf("%d", &n);

    Grafo *g = (Grafo *)malloc(sizeof(Grafo) * n);

    for(int i = 0; i<n; i++){
        scanf("%d", &g[i].n_archi);
        g[i].v = i;
        g[i].lista = (int *)malloc(sizeof(int ) * g[i].n_archi);
        for(int j = 0; j<g[i].n_archi; j++){
            scanf("%d", &g[i].lista[j]);
        }
    }
    int k = 0;
    permutazioni(g, k, n);

}
void permutazioni(Grafo g[], int k, int n){

    if(k == n-1)elabora(g, n);
    else{
        for(int j = k; j<n; j++){
            scambia(&g[j], &g[k]);
            permutazioni( g, k + 1, n);
            scambia(&g[j], &g[k]);
        }
    }
}
void elabora(Grafo g[], int n){

    int i = 0;
    int j = 0;

    while(i < n-1){
        j = 0;
        while(j < g[i].n_archi && g[i+1].v != g[i].lista[j]){
            j++;
        }
        if(j < g[i].n_archi){
            i++;
        }
        else{
            return;
        }
    }
    for(int p = 0; p<n; p++){
        printf(" %d ", g[p].v);
    }
    puts("");

    exit(0);
}