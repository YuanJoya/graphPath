#include <stdio.h>
#include <stdlib.h>
#include "graph_matrix.h"

#define M(graph,i,j) ((graph)->mat[(i) * ((graph)->v + 1) + (j)])
#define INF 0x3f3f3f3f

MatrixGraphPtr CreateMatrixGraph(int v){
    MatrixGraphPtr graph = (MatrixGraphPtr)malloc(sizeof(MatrixGraph));
    graph->v = v;
    graph->e = 0;
    graph->mat = (int*)malloc((v + 1) * (v + 1) * sizeof(int));

    for(int i = 0; i < (v + 1) * (v + 1); i++){
        graph->mat[i] = INF;
    }

    for(int i = 1; i <= graph->v; i++){
        M(graph, i, i) = 0;
    }

    return graph;
}

void AddMatrixEdge(MatrixGraphPtr graph, int from, int to, int weight){
    if(weight < M(graph, from, to)){
        M(graph, from, to) = weight;
        M(graph, to, from) = weight;
    }
    graph->e++;
}
