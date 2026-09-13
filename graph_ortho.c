#include <stdio.h>
#include <stdlib.h>
#include "graph_ortho.h"

OrthoGraphPtr CreateOrthoGraph(int v){
    OrthoGraphPtr G=(OrthoGraphPtr)malloc(sizeof(OrthoGraph));
    G->v=v;
    G->e=0;
    G->firstIn=(OrthoArcPtr*)malloc((v+1)*sizeof(OrthoArcPtr));
    G->firstOut=(OrthoArcPtr*)malloc((v+1)*sizeof(OrthoArcPtr));

    for(int i=0;i<=v;i++){
        G->firstIn[i]=NULL;
        G->firstOut[i]=NULL;
    }

    return G;
}

void AddOrthoArc(OrthoGraphPtr G , int tail , int head , int weight){

        OrthoArcPtr arc=(OrthoArcPtr)malloc(sizeof(OrthoArc));

        arc->weight=weight;
        arc->tail=tail;
        arc->head=head;

        arc->tailLink=G->firstOut[tail];
        G->firstOut[tail]=arc;

        arc->headLink=G->firstIn[head];
        G->firstIn[head]=arc;
        
        G->e++;
}

