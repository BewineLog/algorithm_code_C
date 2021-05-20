#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define swap(type,x,y) do {type t = x; x = y; y = t;} while(0)


void bubble_sort(int a[], int n){
    int i ,j;
    
    for(i = n-1; i > 0; i--){
        int cnt = 0;
        for(j = 0; j <i; j++){
            if(a[j] > a[j+1]){
                swap(int,a[j],a[j+1]);
                cnt++;
            }
        }
        if(cnt == 0)
            break;
    }
}

void bubble_sort_details(int a[],int n){
    int i,j,m;
    
    for(i = n-1; i > 0; i--){
        for(j = 0; j < i; j ++){
            for(m = 0 ; m < n; m++){
                printf("%3d%c",a[m],m != j ? ' ' : a[j]>a[j+1]? '+': '-' );
            }//for m
            printf("\n");
            if(a[j] > a[j+1]){
                swap(int,a[j],a[j+1]);
                
            }//if swap
        }//for j
    }//for i
    
}

void bubble_sort_v3(int a[],int n){
    int last = 0;
    int j;
    int k =0;
    int ccnt = 0 , scnt = 0;
    
    while(k < n-1){
        for(j = n-1; j > k; j--){
            ccnt++;
            if(a[j] < a[j-1]){
                swap(int,a[j],a[j-1]);
                last = j;
                scnt++;
            }
        }
        printf("last: %d\n",last);
        k = last;
    }
    
    printf("comparison cnt:%d , swap cnt: %d \n",ccnt,scnt);
}

void bubble_sort_v3_details(int a[],int n){
    int last = 0, k = 0;
    int i,j;

    
    while(k < n-1){
        for(i = n-1 ; i > k ; i --){
            for(j = 0; j < n; j ++){
                printf("%c%3d", j!=i ? ' ' : a[i] < a[i-1] ? '+' : '-',a[j]);
            }//for j
            printf("\n");
            
            if(a[i] < a[i-1]){
                swap(int,a[i],a[i-1]);
                last = i;
            }
        }//for i
        k = last;
    }//while
    
    
}

void biddirection_bubble_sort(int a[],int n){
    int left = 0;
    int right = n-1;
    int last = 0;
    int i;
    int ccnt = 0 , scnt = 0; // comparsion,swap count
    
    while(left < right){
        for(i = right; i > left; i--){
            ccnt++;
            if(a[i] < a[i-1]){
                swap(int,a[i],a[i-1]);
                last = i;
                scnt++;
            }
        }//홀수 번째 pass
        left = last;
        
        for(i = left; i < right;i++){
            ccnt++;
            if(a[i] > a[i+1]){
                swap(int,a[i],a[i+1]);
                last = i;
                scnt++;
            }
            
        }//짝수 번째 pass
        right = last;
    }//while
    
    printf("comparison count: %d, swap count: %d\n",ccnt,scnt);
}

int main(void){
    int* x;
    int nx;
    int i;
    
    printf("input array size:");
    scanf("%d",&nx);
    
    x = calloc(nx,sizeof(int));
    if(x == NULL){
        printf("calloc error\n");
        exit(1);
    }
    
    for(i = 0; i < nx; i++){
        printf("x[%d]:",i);
        scanf(" %d",&x[i]);
    }

    biddirection_bubble_sort(x,nx);
    //bubble_sort_v3(x,nx);
    
    for(i = 0; i < nx; i++){
        printf("%d ",x[i]);
    }
    printf("\n");
    
    free(x);
    return 0;
    
}
