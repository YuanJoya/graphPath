#include <stdio.h>
#include <stdlib.h>
#include "graph_edge.h"

EdgeGraphPtr CreatGraph(int v, int e){
    EdgeGraphPtr G=(EdgeGraphPtr)malloc(sizeof(EdgeGraph));
    G->v=v;
    G->e=e;
    G->edge=(EdgePtr)malloc(e*sizeof(Edge));

    for(int i=0;i<e;i++){

        int from;
        int to;
        int weight;
        scanf("%d %d %d", &from, &to, &weight);

        G->edge[i].from=from;
        G->edge[i].to=to;
        G->edge[i].weight=weight;
    }
    return G;
}