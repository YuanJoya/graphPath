#include <stdio.h>
#include <stdlib.h>
#include "graph_ortho.h"
#include "heap.h"
#define INF 0x3f3f3f3f

HeapPtr CreateHeap(int capacity){
    HeapPtr H=(HeapPtr)malloc(sizeof(Heap));

    H->capacity=capacity;
    H->size=capacity;

    H->hash=(int*)malloc((capacity+1)*sizeof(int));
    H->elements=(Element*)malloc((capacity+1)*sizeof(Element));

    for(int i=0;i<=capacity;i++){
        H->hash[i]=i;
        H->elements[i].dist=INF;
        H->elements[i].serial=i;
    }

    return H;
}

void PercolateUp(HeapPtr H , int position){
    Element now=H->elements[position];
    int ptr=position;

    while(ptr>1&&H->elements[ptr/2].dist>now.dist){

        H->elements[ptr]=H->elements[ptr/2];
        H->hash[H->elements[ptr].serial]=ptr;

        ptr=ptr/2;
    }

    H->elements[ptr]=now;
    H->hash[now.serial]=ptr;
}

void PercolateDown(HeapPtr H , int position){
    Element now=H->elements[position];
    int ptr=position;

    while(2*ptr<=H->size){
        int min_position=2*ptr;

        if(2*ptr+1<=H->size&&H->elements[2*ptr+1].dist<H->elements[2*ptr].dist){
            min_position=2*ptr+1;
        }

        if(H->elements[min_position].dist>now.dist) break;

        H->elements[ptr]=H->elements[min_position];
        H->hash[H->elements[min_position].serial]=ptr;

        ptr=min_position;
    }

    H->elements[ptr]=now;
    H->hash[now.serial]=ptr;
}

void BuildHeap(HeapPtr H , int source){
    H->elements[source].dist=0;
    PercolateUp(H,source);
}

void DecreaseDist(HeapPtr H, int serial , int weight, int dist){
    if(H->hash[serial]>0 && dist+weight<H->elements[H->hash[serial]].dist){
        H->elements[H->hash[serial]].dist=weight+dist;
        PercolateUp(H,H->hash[serial]);
    }
}

Element PopHeap(HeapPtr H){
    if(H->size==1){
        H->size--;
        H->hash[H->elements[1].serial]=0;
        return H->elements[1];                   //边界处理
    }

    Element top=H->elements[1];
    H->elements[1]=H->elements[H->size];
 
    H->size--;                                  //先修改size的值
    H->hash[top.serial]=0;

    PercolateDown(H,1);
    return top;
}