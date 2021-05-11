//
//  Stack.c
//  new_one
//
//  Created by 이정한 on 2021/05/11.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"

int Initialize(IntStack* s, int max){
    
    if((s->stk = calloc(max,sizeof(int))) == NULL){
        return -1;
    }
    s->max = max;
    s->ptr_a = 0;
    s->ptr_b = max -1;
    
    return 0;
}

int Push(IntStack* s, int sw,int x){
    if(s->ptr_a >= s->ptr_b)
        return -1;
    
    switch(sw){
        case StackA :
            s->stk[s->ptr_a++] = x;
            break;
        case StackB :
            s->stk[s->ptr_b--] = x;
            break;
    }
    return 0;
}

int Pop(IntStack* s, int sw, int *x){
    
    switch(sw){
        case StackA :
            if(s->ptr_a <= 0)
                return -1;
            *x = s->stk[--s->ptr_a];
            break;
            
        case StackB :
            if(s->ptr_b >= s->max -1)
                return -1;
            *x = s->stk[++s->ptr_b];
            break;
    }
    return 0;
}

int Peek(IntStack* s, int sw, int *x){
    if(s->ptr_a <=0 || s->ptr_b >= s->max)
        return -1;
    
    switch(sw){
        case StackA :
            *x = s->stk[s->ptr_a-1];
            break;
            
        case StackB :
            *x = s->stk[s->ptr_b+1];
            break;
    }
    return 0;
}

void Clear(IntStack *s, int sw){
    switch(sw){
        case StackA :
            s->ptr_a = 0;
            break;
            
        case StackB :
            s->ptr_b = 0;
            break;
    }
}

int Capacity(IntStack *s){
    return s->max;
}

int Size(IntStack *s, int sw){
    return (sw == 1) ? s->ptr_a : s->max - s->ptr_b -1;
}

int isEmpty(IntStack *s,int sw){
    return (sw == 1) ? (s->ptr_a<=0) : (s->ptr_b >=s->max);
}

int isFull(IntStack *s,int sw){
    return s->ptr_a >= s->ptr_b;
}

int Search(IntStack *s,int sw,int x){
    int i;
    
    if(isEmpty(s,sw))
        return -1;
    
    switch(sw){
        case StackA :
            for(i = 0 ; i < s->ptr_a; i++){
                if(s->stk[i] == x)
                    return i;
            }
            break;
        case StackB :
            for(i = s->max -1; i >= s->ptr_b ; i --){
                if(s->stk[i] == x)
                    return i;
            }
            break;
    }
    
    return -1;
    
}

void Print(IntStack *s,int sw){
    int i;
    
    switch(sw){
        case StackA :
            printf("#StackA Print\n");
            for( i = 0; i < s->ptr_a; i++){
                printf("%d ",s->stk[i]);
            }
            putchar('\n');
            
            break;
            
        case StackB :
            printf("#StackB Print\n");
            for(i = s->max -1; i > s->ptr_b ; i--){
                printf("%d ",s->stk[i]);
            }
            putchar('\n');
            
            break;
    }
}

void Terminate(IntStack *s){
    if(s->stk != NULL)
        free (s->stk);
    s->max = s->ptr_a = s->ptr_b = 0;
}

