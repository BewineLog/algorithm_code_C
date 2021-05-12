//
//  Deque.c
//  new_one
//
//  Created by 이정한 on 2021/05/11.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Deque.h"


//Q_F : 1 , Q_R = 2
//q->front : for Q_F , q->rear : for Q_R

int Initialize(IntQueue* q, int max){
    q->num = q->front = q->rear = 0;
    
    if((q->que = calloc(max,sizeof(int))) == NULL){
        return -1;
    }
    q->max = max;
    return 0;
}

int Enque(IntQueue *q, int x, int sw){
   if(q->num >= q->max)
       return -1;
    
    switch(sw){
        case 1://Q_F
            q->que[q->front++] = x;
            q->num++;
            
            if(q->front >= q->max)
                q->front = 0;
            
            break;
            
        case 2: //Q_R
            if(--q->rear < 0 )
                q->rear = q->max -1;
            q->que[q->rear] = x;
            q->num ++;
            
            break;
            
    }
    return 0;
}

int Deque(IntQueue *q, int *x , int sw){
    if(q->num <=0)
        return -1;
    
    switch(sw){
        case 1:
            if( --q->front < 0)
                q->front = q->max -1;
            *x = q->que[q->front];
            q->num --;
            
            break;
            
        case 2:
            *x = q->que[q->rear++];
            q->num --;
            
            if(q->rear > q->max -1)
                q->rear = 0;
            
            break;
            
    }
    return 0;
}

int Peek(const IntQueue *q, int *x, int sw){
    if(sw == 1)
        *x = q->que[q->front -1];
    else if(sw == 2 )
        *x = q->que[q->rear];
    
    return 0;
}

void Clear(IntQueue *q,int sw){
    switch(sw){
        case 1:
            q-> front = 0;
            break;
            
        case 2:
            q->rear = 0;
            break;
    }
}

int Size(const IntQueue *q){
    return q->num;
}

int Capacity(const IntQueue *q){
    return q->max;
}

int isEmpty(IntQueue *q, int sw){
    return (q->num <= 0) ? 1 : 0;
}

int isFull(IntQueue *q, int sw){
    return (q->num >= q->max) ? 1 : 0;
}

int Print(IntQueue *q, int sw){
    int i;
    
    switch(sw){
        case 1:
            for(i = 0; i < q-> front; i++){
                printf("%d ",q->que[i]);
            }
            putchar('\n');
            break;
            
        case 2:
            for(i =  q->max -1; i >= q->rear ; i--){
                printf("%d ",q->que[i]);
            }
            putchar('\n');
            break;
            
    }
    return 0;
}

int Search(IntQueue *q, int x , int sw){
    int i;
    
    switch(sw){
        case 1:
            for(i = 0; i < q-> front; i++){
                if(q->que[(i+q->front) % q->max] == x)
                    return i;
            }
            break;
            
        case 2:
            for(i =  q->max -1; i > q->rear ; i--){
                if(q->que[i] == x)
                    return i;
            }
            break;
            
    }
    return -1;
}

void Terminate(IntQueue *q){
    if(q->que != NULL)
        free(q->que);
    
    q->num = q->front=q->rear = 0;
}
