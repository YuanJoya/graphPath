#ifndef GRAPH_EDGE
#define GRAPH_EDGE

typedef struct edge *EdgePtr; 
struct edge{
    int from;
    int to;
    int weight;
};
typedef struct edge Edge;

typedef struct edge_graph *EdgeGraphPtr;
struct edge_graph{
    int v;
    int e;
    EdgePtr edge;
};
typedef struct edge_graph EdgeGraph;

EdgeGraphPtr CreatGraph(int v, int e);

#endif