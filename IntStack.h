//
//  IntStack.h
//  C-Language
//
//  Created by 이정한 on 2021/05/10.
//

#ifndef IntStack_h
#define IntStack_h

typedef struct{
    int max;
    int ptr;
    int *stk;
}IntStack;

int Initialize(IntStack *s, int max); // data 초기화

int Push(IntStack *s, int x);//데이터 입력

int Pop(IntStack *s, int *x);//데이터 삭제

int Peek(IntStack *s, int *x);//스택에서 데이터를 피크

void Clear(IntStack * s);//스택 비우기

int Capacity(const IntStack *s);// 스택 최대 용량

int Size(const IntStack *s);// 스택 데이터 갯수

int isEmpty(const IntStack *s);//스택 비어있나 확인

int isFull(const IntStack *s);//스택이 꽉 차 있나 확인

int Search(const IntStack *s, int x); //스택에서 값 검색

void Print(const IntStack *s);//스택 모든 데이터 출력

void Terminate(IntStack *s);//스택 종료

#endif /* IntStack_h */
