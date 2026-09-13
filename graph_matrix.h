#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

typedef struct matrix_graph {
    int *mat;
    int v;
    int e;
} MatrixGraph;

typedef MatrixGraph *MatrixGraphPtr;

MatrixGraphPtr CreateMatrixGraph(int v);
void AddMatrixEdge(MatrixGraphPtr graph, int from, int to, int weight);

#endif
