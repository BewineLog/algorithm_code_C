//
//  Stack.h
//  new_one
//
//  Created by 이정한 on 2021/05/11.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>

#define StackA 1
#define StackB 2

typedef struct{
    int max;
    int ptr_a;
    int ptr_b;
    int *stk;
}IntStack;

int Initialize(IntStack* s, int max);

int Push(IntStack* s,int sw, int x);

int Pop(IntStack* s,int sw, int *x);

int Peek(IntStack* s,int sw, int *x);

void Clear(IntStack *s, int sw);

int Capacity(IntStack *s);

int Size(IntStack *s,int sw);

int isEmpty(IntStack *s,int sw);

int isFull(IntStack *s,int sw);

int Search(IntStack *s,int sw,int x);

void Print(IntStack *s, int sw);

void Terminate(IntStack *s);

#endif /* Stack_h */
