#include <stdio.h>
#include <stdlib.h>
#include "bellman.h"
#include "graph_edge.h"
#define INF 0x3f3f3f3f

int BellmanFord(EdgeGraphPtr G, int source, int dist[]){
    int v=G->v;
    int e=G->e;

    for(int i=0;i<=v;i++){
        dist[i]=INF;
    }

    dist[source]=0;

    for(int i=0;i<v-1;i++){
        for(int j=0;j<e;j++){
            if(dist[G->edge[j].from]!=INF&&dist[G->edge[j].to]>dist[G->edge[j].from]+G->edge[j].weight){
                dist[G->edge[j].to]=dist[G->edge[j].from]+G->edge[j].weight;
            }
        }
    }

    for(int i=0;i<e;i++){
        if(dist[G->edge[i].from]!=INF&&dist[G->edge[i].to]>dist[G->edge[i].from]+G->edge[i].weight){
            return 0;
        }
    }
    return 1;
}