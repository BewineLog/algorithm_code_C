//
//  Deque.h -> Deck, Double Ended Queue
//  new_one
//
//  Created by 이정한 on 2021/05/11.
//

#ifndef Deque_h
#define Deque_h

#include <stdio.h>

#define Q_F 1  // Queue start from Front
#define Q_R 2 // Queue start from Rear

typedef struct{
    int max;
    int num;
    int front; //for Q_F
    int rear; //for Q_B
    int *que;
}IntQueue;

int Initialize(IntQueue* q, int max);

int Enque(IntQueue *q, int x, int sw);

int Deque(IntQueue *q, int *x , int sw);

int Peek(const IntQueue *q, int *x, int sw);

void Clear(IntQueue *q,int sw);

int Size(const IntQueue *q);

int Capacity(const IntQueue *q);

int isEmpty(IntQueue *q, int sw);

int isFull(IntQueue *q, int sw);

int Print(IntQueue *q, int sw);

int Search(IntQueue *q, int x , int sw);

void Terminate(IntQueue *q);
#endif /* Deque_h */
