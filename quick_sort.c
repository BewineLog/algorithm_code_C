//
//  quick_sort.c
//  quick sort
//
//  Created by 이정한 on 2021/05/27.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmp_stack.h"

#define swap(type,x,y) do { type t = x; x = y; y = t;} while(0)
#define MIN 9


void print_ary(int a[],int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insertion_sort(int a[], int n){
    int i, j;
    
    for(i = 1; i < n ; i++){
        int tmp = a[i];
        for(j = i-1; j >= 0 && a[j] > tmp ;j--){
            a[j+1] = a[j];
        }
        a[j+1] = tmp;
    }
}

void partition(int a[],int n){
    int pl = 0;
    int pr = n-1;
    int pivot = a[n/2];
    int i;
    
    do{
        while(a[pl] < pivot) pl ++;
        while(a[pr] > pivot) pr --; // pl은 요소 값이 피벗보다 클 때 , pr은 피벗 보다 값이 작을 때 idx로 설정된다.
        
        if(pl <= pr){
            swap(int,a[pl],a[pr]);
            pl++;
            pr--;
        }
        
    }while(pl <= pr);
    
    
    printf("Pivot value: %d\n",pivot);
    printf("infront of pivot group\n");
    for(i = 0; i <=pl-1; i++)
        printf("%d ",a[i]);
    printf("\n");
    
    if(pl > pr + 1){
        printf("same with pivot group\n");
        for(i = pr + 1 ; i < pl; i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    
    printf("behind of pivot group\n");
    for(i = pr+1; i <n; i++)
        printf("%d ",a[i]);
    printf("\n");
    
}


/*재귀적으로 구성한 퀵 정렬 함수*/
void quick(int a[],int left, int right){
    int pl = left;
    int pr = right;
    int pivot = a[(pl+pr)/2];
    
    do{
        while(a[pl] < pivot) pl++;
        while(a[pr] > pivot) pr--;
        
        if(pl <= pr){
            swap(int,a[pl],a[pr]);
            pl++;
            pr--;
        }
    }while(pl <= pr);
    
    if(left < pr) quick(a,left,pr);
    if(right > pl) quick(a,pl,right);
    
}

/*요소의 갯수가 적을 경우, 단순 삽입 정렬로 돌아 갈 수 있도록 설정한 함수*/
void quick_replace_insertion(int a[],int left, int right){
    int pl = left;
    int pr = right;
    int pivot = a[(pl+pr)/2];
    
    if((right - left + 1) < MIN){
        printf("단순 삽입 정렬로 대체합니다\n");
        insertion_sort(a,(right-left+1));
        print_ary(a,right-left+1);
        exit(1);
    }
    
    do{
        while(a[pl] < pivot) pl++;
        while(a[pr] > pivot) pr--;
        
        if(pl <= pr){
            swap(int,a[pl],a[pr]);
            pl++;
            pr--;
        }
    }while(pl <= pr);
    
    if(left < pr) quick(a,left,pr);
    if(right > pl) quick(a,pl,right);
    
}


void quick_details(int a[],int left, int right){
    int pl = left;
    int pr = right;
    int pivot = a[(pl+pr)/2];
    int i;
    
    printf("a[%d]~a[%d]:{",left,right);
    for(i = left; i <= right-1;i++){
        printf("%d, ",a[i]);
    }
    printf("%d}\n",a[right]);
    
    do{
        while(a[pl] < pivot) pl++;
        while(a[pr] > pivot) pr--;
        
        if(pl <= pr){
            swap(int,a[pl],a[pr]);
            pl++;
            pr--;
        }
    }while(pl <= pr);
    
    if(left < pr) quick_details(a,left,pr);
    if(right > pl) quick_details(a,pl,right);
    
}

void quick_not_recur(int a[],int left,int right){
    IntStack lstack;
    IntStack rstack;
    int l,r;
    
    Initialize(&lstack, right-left + 1);
    Initialize(&rstack, right-left + 1);
    
    Push(&lstack,left);
    Push(&rstack,right);
    
    while(!Is_Empty(&lstack)){
        int pl = (Pop(&lstack,&l),l);
        int pr = (Pop(&rstack,&r),r);
        int pivot = a[(pl+pr)/2];
        
        do{
            while(a[pl] < pivot) pl ++;
            while(a[pr] > pivot) pr --;
            
            if(pl <= pr){
                swap(int,a[pl],a[pr]);
                pl++;
                pr--;
            }
            
        }while(pl <= pr);
        
        if(l < pr ){
            Push(&lstack,l);
            Push(&rstack,pr);
        }
        if(r > pl){
            Push(&lstack,pl);
            Push(&rstack,r);
        }
    }//while_empty
    Terminate(&lstack);
    Terminate(&rstack);
}

/*재귀적으로 요소의 갯수가 적은 그룹을 먼저 나누는 함수*/
void quick_by_cnt(int a[], int left, int right){
    int pl = left;
    int pr = right;
    int pivot = a[(left+right)/2];
    
    do{
        while(a[pl] < pivot) pl++;
        while(a[pr] > pivot) pr--;
        
        if(pl <= pr){
            swap(int,a[pl],a[pr]);
            pl++;
            pr--;
        }
        
    }while(pl <= pr);
    
    if(pr - left > right - pl){
        swap(int,pl,left);
        swap(int,pr,right);
    } //항상 요소의 갯수가 작은 그룹의 인덱스를 left ~ pr로 고정
    
    if(left < pr) quick_by_cnt(a, left, pr);
    if(right >pl) quick_by_cnt(a,pl,right);
    
    
}
 
/* 비 재귀적으로 요소의 갯수가 적은 그룹부터 돌아가는 함수*/
void quick_not_recur_by_cnt(int a[],int left, int right){
    IntStack lstack,rstack;
    int pl, pr,pivot;
    
    Initialize(&lstack,right-left+1);
    Initialize(&rstack,right-left+1);
    
    Push(&lstack,left);
    Push(&rstack,right);
    
    while(!Is_Empty(&lstack)){
        do{
            pl = (Pop(&lstack,&left), left);
            pr = (Pop(&rstack,&right), right);
            pivot = a[(pl+pr)/2];
        
            while(a[pl] < pivot) pl ++;
            while(a[pr] > pivot) pr --;
        
            if(pl <= pr){
                swap(int,a[pl],a[pr]);
                pl++;
                pr--;
            }
        
        }while(pl <= pr);
        
        if(pr - left > right - pl){
            swap(int, pl , left);
            swap(int, pr, right);
        } //작은 그룹의 인덱스를 left ~ pr 로 고정
        
        if(pl < right){
            Push(&lstack,pl);
            Push(&rstack,right);
        }
        if(left < pr){
            Push(&lstack,left);
            Push(&rstack,pr);
        }
            
        
    }
    Terminate(&lstack);
    Terminate(&rstack);
}
int main(void){
    int nx;
    int *x;
    int i;
    
    printf("Input array size: ");
    scanf("%d",&nx);
    
    x = calloc(nx,sizeof(int));
    if(x == NULL){
        printf("calloc error\n");
        exit(1);
    }
    
    printf("Input array element\n");
    for(i = 0; i < nx; i++){
        printf("x[%d]: ",i);
        scanf(" %d",&x[i]);
    }
    
    print_ary(x,nx);
//    quick(x,0,nx-1);
//    quick_details(x,0,nx-1);
//    quick_not_recur(x,0,nx-1);
//    quick_by_cnt(x,0,nx-1);
//    quick_not_recur_by_cnt(x, 0, nx-1);
    quick_replace_insertion(x, 0, nx-1);
    print_ary(x,nx);
    
    
    free(x);
    return 0;
}
