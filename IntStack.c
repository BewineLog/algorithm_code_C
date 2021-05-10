//
//  IntStack.c
//  C-Language
//
//  Created by 이정한 on 2021/05/10.
//

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack *s, int max){
    s->ptr = 0;
    
    if((s->stk = calloc(max,sizeof(int))) == NULL){
        s->max = 0;
        return -1;
    }
    
    s->max = max;
    return 0;
    
}

int Push(IntStack *s, int x){//데이터 입력
    if(s->ptr >= s->max){ //stack last idx : s->max -1
        return -1;
    }
    
    s->stk[s->ptr++] = x;
    return 0;

}

int Pop(IntStack *s, int *x){//데이터 삭제
    if(s->ptr <= 0){
        return -1;
    }
    *x = s->stk[--s->ptr];
    return 0;
}

int Peek(IntStack *s, int *x){//스택에서 데이터를 피크
    if(s->ptr <= 0){
        return -1;
    }
    *x = s->stk[s->ptr-1];
    return 0;
}

void Clear(IntStack * s){//스택 비우기
    s->ptr = 0;
}

int Capacity(const IntStack *s){// 스택 최대 용량
    return s->max;
}

int Size(const IntStack *s){// 스택 데이터 갯수
    return (s->ptr);
}

int isEmpty(const IntStack *s){//스택 비어있나 확인
    return s->ptr <= 0;
}

int isFull(const IntStack *s){//스택이 꽉 차 있나 확인
    return s->ptr >= s->max;
}

int Search(const IntStack *s, int x){ //스택에서 값 검색
    int i;
    for(i = s->ptr -1 ; i >= 0 ; i --){
        if(s->stk[i] == x){
            return i;
        }
    }
    return -1;
}

void Print(const IntStack *s){
    int i;
    for(i = 0 ; i < s->ptr; i++){
        printf("%d ",s->stk[i]);
    }
    printf("\n");
}//스택 모든 데이터 출력

void Terminate(IntStack *s){//스택 종료
    if(s->stk != NULL)
        free(s->stk);
    s->max = 0;
    s->ptr = 0;
}
