//
//  IntQueue.h
//  C-Language
//
//  Created by 이정한 on 2021/05/10.
//

#ifndef IntQueue_h
#define IntQueue_h

#include <stdio.h>

typedef struct{
    int max;
    int num; //현재 요소의 갯수
    int front;
    int rear;
    int *que;
}IntQueue;

int Initialize(IntQueue* q, int max);

int Enque(IntQueue *q, int x);

int Deque(IntQueue *q, int *x);

int Peek(const IntQueue *q, int *x);

void Clear(IntQueue *q);

int Size(const IntQueue *q);

int Capacity(const IntQueue *q);

int isEmpty(IntQueue *q);

int isFull(IntQueue *q);

int Print(IntQueue *q);

int Search(IntQueue *q, int x);

void Terminate(IntQueue *q);

#endif /* IntQueue_h */
