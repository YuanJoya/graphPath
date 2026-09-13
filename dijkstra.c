#include <stdio.h>
#include <stdlib.h>
#include "graph_ortho.h"
#include "heap.h"
#include "dijkstra.h"

#define INF 0x3f3f3f3f
void Dijkstra(OrthoGraphPtr G, int source, Element* result){
    HeapPtr H=CreateHeap(G->v);
    BuildHeap(H,source);

    for(int i=0;i<G->v+1;i++){
        result[i].serial=i;
        result[i].dist=INF;
    }

    while(H->size>0){
        Element temp=PopHeap(H);

        if(temp.dist==INF) break;
        
        result[temp.serial]=temp;

        OrthoArcPtr ptr=G->firstOut[temp.serial];

        while(ptr!=NULL){
            DecreaseDist(H, ptr->head, ptr->weight, temp.dist);
            ptr=ptr->tailLink;
        }
    }
}