#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//funzioni di supporto
int order(const void *x, const void *y){
    int a = *(int *)x;
    int b = *(int *)y;
    return a - b;
}

//funzioni che useremo
void sottoinsiemi(int perm[], int a[], int sol[], int j, int n, int *max, int ff[]);
void elabora(int perm[], int a[], int sol[], int n, int *max, int ff[]);

//principale
int main(){

    int n;
    int j = -1;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int ) * n);
    int *perm = (int *)malloc(sizeof(int ) * n);
    int *sol = (int *)malloc(sizeof(int ) * n);
    int *ff = (int *)malloc(sizeof(int ) * n);

    for(int i = 0; i<n; i++){
        scanf("%d", &a[i]);
        sol[i] = -1;
        perm[i] = -1;
    }
    int max = INT_MIN;
    sottoinsiemi(perm, a, sol, j, n, &max, ff);
    if(n > 1){
        printf("%d\n", max);
        for(int i = 0; i<n; i++){
            if(ff[i] != 0){
                printf("%d ", ff[i] + 1);
            }
        }
    }
    else{
        printf("%d\n", max + 1);
        printf("%d ", max + 1);
    }

    free(a);
    free(perm);
    free(sol);
    free(ff);
}
//implemento funzioni
void sottoinsiemi(int perm[], int a[], int sol[], int j, int n, int *max, int ff[]){

    if(j == n - 1)elabora(perm, a, sol, n, max, ff);
    else{
        perm[j+1] = 1;
        sottoinsiemi(perm, a, sol, j + 1, n, max, ff);
        perm[j+1] = 0;
        sottoinsiemi(perm, a, sol, j + 1, n, max, ff);
    }
}
void elabora(int perm[], int a[], int sol[], int n, int *max, int ff[]){

    int i = 0;
    int j = 1;
    int k = 0;
    while(i < n - 1){
        while(j < n && perm[i] == perm[j]){
            j++;
        }
        sol[k] = j - i - 1;
        k++;
        i = j;
        j = i + 1;
    }
    int temp_max = 0;
    int m = 0;
    qsort(sol, k, sizeof(int), order);
    for(int l = 0; l<k; l++){
        if(sol[l] != -1){
            temp_max += a[sol[l]];
        }
    }
    if(temp_max > *max){
        *max = temp_max;
        for(int l = 0; l<k; l++){
            if(sol[l] != -1){
                ff[m] = sol[l];
                m++;
                sol[l] = -1;
            }
        }
    }
}