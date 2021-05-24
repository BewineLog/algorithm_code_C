#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(type,x,y) do {type t = x; x = y; y = t;} while(0)

void selection_sort(int a[],int n){
    int i,j;
    int min;
    
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(a[j] < a[min])
                min = j; //정렬되지않은 맨 앞과 비교해서 남은 요소값중 최소값이 있는 index를 찾는 것.
        }
        swap(int,a[i],a[min]);
    }
} //선택정렬

void selection_sort_details(int a[],int n){
    int i,j,k;
    int min;// 최소값 저장
    for(i = 0; i < n ; i++){
        min = i;
        for(j = i+1 ; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        
        for(k = 0; k < n ; k++){
           /* if(k == i)
                printf("%2c",'*');
            else if( k == min )
                printf("%2c",'+');
            else
                printf("  ");*/
            printf((k == i) ? " *" : k == min ? " +" : "  ");
        }
        printf("\n");
        
        for(k = 0; k < n ; k++){
            printf("%2d",a[k]);
        }
        printf("\n");
        
        swap(int,a[i],a[min]);
        
    }
    
}

void insertion_sort(int a[],int n){
    int i,j;
    
    for(i = 1; i < n; i++){  //선택 정렬은 두번째 값부터 비교
        int tmp = a[i];
        
        for(j = i; j > 0 && a[j-1] > tmp ; j--){ //j > 0, 선택한 값 앞의 값이 선택한 값보다 크면                                            한칸식 민다.
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
    
}//삽입정렬

void insertion_sort_details(int a[], int n){
    int i,j,k;
    
    for(i = 1; i < n; i++){
        //print array
        for(k = 0; k < n; k++){
            printf("%2d",a[k]);
        }
        printf("\n");
        
        
        //insertion
        int tmp = a[i];
        for(j = i; j > 0 && a[j-1] > tmp; j --){
            a[j] = a[j-1];
        }
        a[j] = tmp;
        
        for(k = 0; k < n; k++){
            if(i == j){ // not swap
                /*if(k == i)
                    printf("%2c",'+');
                else
                    printf("  ");*/
                printf( k == i ? " +" : "  ");
            }else{ //swap
               /* if(k == j)
                    printf("%2c",'^');
                else if(k == i)
                    printf("%2s","-+");
                else if( k >= j && k <= i)
                    printf("--");
                else
                    printf("  ");*/
                printf(k == j ? " ^" : k == i ? "-+" : k >= j && k <=i ? "--" : "  ");
            }
        }//for k
        printf("\n");
    }//for i
}

void print_ary(int a[],int n){
    int i;
    
    for(i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(int argc, char** argv){
    int i;
    int nx;
    int *x;
    
    //printf("Selection sort\n\n");
    printf("input array size:");
    scanf("%d",&nx);
    
    x = calloc(nx,sizeof(int));
    if(x==NULL){
        printf("calloc error\n");
        exit(1);
    }
    
    puts("input array elements");
    for(i = 0; i <nx; i++){
        printf("x[%d]:",i);
        scanf(" %d",&x[i]);
    }
    
    print_ary(x,nx);
//    selection_sort(x,nx);
    selection_sort_details(x,nx);
//    insertion_sort_details(x, nx);
    print_ary(x,nx);
    
    free(x);
    return 0;
}
