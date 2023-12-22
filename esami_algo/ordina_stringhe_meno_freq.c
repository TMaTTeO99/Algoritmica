//librerie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define MAX_LEN 101

typedef struct vet{
    char s[101];
    int fre;
}VET;

int order(const void *x, const void *y){

    VET *a = (VET *)x;
    VET *b = (VET *)y;
    return strcmp(a->s, b->s);
}
int order_due(const void *x, const void *y){

    VET *a = (VET *)x;
    VET *b = (VET *)y;
    if(a->fre >= b->fre){
        return  a->fre - b->fre;
    }
    return a->fre - b->fre;
}
int order_tre(const void *x, const void *y){

    VET *a = (VET *)x;
    VET *b = (VET *)y;
    if(strlen(a->s) >= strlen(b->s)){
        if(strlen(a->s) == strlen(b->s)){
            return strcmp(a->s, b->s);
        }
        else{
            return strlen(a->s) - strlen(b->s);
        }
    }
    return  strlen(a->s) - strlen(b->s);

}
int main(){

    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    VET *array = (VET *)malloc(sizeof(VET) * n);
    for(int i = 0; i<n; i++){
        scanf("%s", array[i].s);
        array[i].fre = 1;
    }
    qsort(array, n, sizeof(VET), order);

    int s = 0;
    while(s <= n-1){
        int j = s+1;
        while(j < n && strcmp(array[s].s, array[j].s) == 0){
            array[s].fre += 1;
            array[j].fre = INT_MAX;
            j++;
        }
        s = j;
    }
    qsort(array, n, sizeof(VET), order_due);
    qsort(array, k, sizeof(VET), order_tre);
    for(int m = 0; m<k; m++){
        printf("%s\n", array[m].s);
    }
}