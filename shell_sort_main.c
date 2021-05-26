//
//  main.c
//  shell_sort
//
//  Created by 이정한 on 2021/05/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(type,x,y) do {type t = x; x = y; y = t;} while(0)


/*(n/2, n/4, ~~ 1- 정렬)*/
void shell_sort(int a[],int n){
    int i,j,h;
    
    for(h = n/2; h >= 1; h /= 2){
        for(i = h; i < n ; i ++){
            int tmp = a[i];
            
            for(j = i - h ; j >= 0 && a[j] > tmp; j -= h){
                a[j + h] = a[j];
            }
            a[j+h] = tmp; //위 싸이클이 돈다면, a[j] < tmp 인 부분에서 종료, ->
        }//for i
        
    }//for h
}

/*증분값을 수열 등을 활용하여 배수가 되지 않게 만든다 -> 더욱 효율적인 셸 정렬*/
void shell_sort_adv(int a[],int n){
    int i,j,h;
    
    for(h = 1 ; h < n/9; h = 3*h+1)
        ;
    
    for(;h > 0; h /= 3){
        for(i = h; i < n ; i ++){
            int tmp = a[i];
                
            for(j = i - h; j >= 0 && a[j] > tmp; j -= h){
                a[j+h] = a[j];
            }
            a[j+h] = tmp;
        }
    }
}

void print_ary(int a[],int n){
    int i;
    
    for(i = 0 ; i < n ; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}


int main(void){
    int nx;
    int i;
    int* x;
    
    printf("input array size:");
    scanf("%d",&nx);
    
    x = calloc(nx,sizeof(int));
    if(x == NULL){
        printf("calloc error\n");
        exit(1);
    }
    
    printf("\nInput array element\n");
    for(i = 0 ; i < nx; i++){
        printf("x[%d]: ",i);
        scanf(" %d",&x[i]);
    }
    
    print_ary(x,nx);
    shell_sort_adv(x,nx);
    print_ary(x,nx);
    
    free(x);
    return(0);
}
