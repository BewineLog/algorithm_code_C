//단순 삽입정렬 by 보초법, 이진 검색, memmove

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ary(int a[],int n){
    int i;
    for(i = 0; i < n ; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void print_ary_sentry(int a[],int n){
    int i;
    for(i = 1 ; i < n + 1; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insertion_sort_by_sentry(int a[], int n){ //보초법 사용
    int i,j;
    
    for(i = 2 ; i < n + 1; i++){
        a[0] = a[i];
        for(j = i; j > 1 && a[j-1] > a[0]; j--){
            a[j] = a[j-1];
        }
        a[j] = a[0];
    }
    
}

int binary_search(int a[], int key,int end){
    int pl = 0;
    int pr = end - 1;
    int pc = (pl+pr)/2;
    int pd;
    
    while(pl <= pr){
        if(a[pc] == key)
            break;
        else if(a[pc] > key)
            pr = pc - 1;
        else
            pl = pc + 1;
        
        pc = (pl+pr)/2;
    }
    pd = (pl <= pr) ? pc+1 : pr+1 ;
    return pd;
}

void insertion_sort_by_binarySearch(int a[],int n){
    int i,j;

    for(i = 1; i < n ; i ++){
        int tmp = a[i];
        int pd = binary_search(a,tmp,i);
        
        /*
         for(j = i; j > position ; j --){
            a[j] = a[j-1];
        }
         */
        memmove(a+pd+1,a+pd,(i-pd) * sizeof(int));
        a[pd] = tmp;
    }
}

int main(int argc, const char * argv[]) {
    int i;
    int nx;
    int *x;
    
    printf("input array size:");
    scanf("%d",&nx);
    
    //보초법일 때 사용하는 메인 함수
/*
    x = calloc(nx + 1,sizeof(int));
    if(x == NULL){
        printf("calloc error\n");
        exit(1);
    }
    
    printf("<<input array elements>>\n");
    for(i = 1 ; i < nx + 1 ; i ++){
        printf("x[%d]:",i);
        scanf(" %d",&x[i]);
    }
    print_ary_sentry(x, nx);
    insertion_sort_by_sentry(x,nx);
    print_ary_sentry(x,nx);
*/
    
    
    x = calloc(nx,sizeof(int));
    if(x == NULL){
        printf("calloc error\n");
        exit(1);
    }
    
    printf("<<input array elements>>\n");
    for(i = 0 ; i < nx ; i ++){
        printf("x[%d]:",i);
        scanf(" %d",&x[i]);
    }
    
    print_ary(x,nx);
    insertion_sort_by_binarySearch(x, nx);
    print_ary(x,nx);
    
    
    free(x);
    return 0;
}
