#ifndef HEAP_H
#define HEAP_H
#include "graph_ortho.h"


struct element{
    int dist;
    int serial;
};
typedef struct element Element;

typedef struct heap *HeapPtr;
struct heap{
    int size;
    int capacity;
    int *hash;
    Element *elements;
};
typedef struct heap Heap;

HeapPtr CreateHeap(int capacity);
void PercolateUp(HeapPtr H , int position);
void PercolateDown(HeapPtr H , int position);
void BuildHeap(HeapPtr H ,int source);
void DecreaseDist(HeapPtr H, int serial, int weight, int dist);
Element PopHeap(HeapPtr H);

#endif