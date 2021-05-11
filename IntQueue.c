//
//  IntQueue.c
//  C-Language
//
//  Created by 이정한 on 2021/05/10.
//
#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

int Initialize(IntQueue* q, int max){
    q->num = q->front = q->rear = 0;
    
    if((q->que = calloc(max,sizeof(int))) == NULL){
        return -1;
    }
    q -> max = max;
    
    return 0;
}

int Enque(IntQueue *q, int x){
    if(isFull(q))
        return -1;
    else{
        q->que[q->rear++] = x;
        q->num++;
        if(q->rear >= q->max)
            q->rear = 0;
    }
    
    return 0;
}

int Deque(IntQueue *q, int *x){
    if(isEmpty(q))
        return -1;
    
    q->num--;
    *x = q->que[q->front++];
    
    if(q->front >= q->max)
        q->front = 0;
    
    return 0;
}

int Peek(const IntQueue *q, int *x){ //Queue에서 Peek는 맨 앞에 값을 보는 용도.
    if(isEmpty(q))
        return -1;
    *x = q->que[q->front];
    return 0;
}

void Clear(IntQueue *q){
    q->num = q->front= q->rear = 0;
}

int Size(const IntQueue *q){
    return q->num;
}

int Capacity(const IntQueue *q){
    return q->max;
}

int isEmpty(IntQueue *q){
    return q->num <=0;
}

int isFull(IntQueue *q){
    return q->num >= q->max;
}

int Print(IntQueue *q){
    int i;
    
    for( i = 0; i < q->num; i++){
        printf("%d ",q->que[(i+q->front) % q->max]);
    }
    putchar('\n');
    return 0;
}

int Search(IntQueue *q, int x){
    int i;
    int idx;
    for(i = 0 ; i < q -> num; i++){
        idx = (i+q->front) % q->max;
        if(q->que[idx] == x)
            return idx;
        
    }
    return -1;
}

void Terminate(IntQueue *q){
    if(q->que != NULL)
        free(q->que);
    q->max = q->num = q->front = q->rear = 0;
}
