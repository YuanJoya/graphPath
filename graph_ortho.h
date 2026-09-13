#ifndef GRAPH_ORTHO_H
#define GRAPH_ORTHO_H

typedef struct ortho_arc *OrthoArcPtr;
struct ortho_arc{
    int tail;
    int head;
    int weight;
    OrthoArcPtr tailLink;
    OrthoArcPtr headLink;
};
typedef struct ortho_arc OrthoArc;


typedef struct ortho_graph *OrthoGraphPtr;
struct ortho_graph{
    OrthoArcPtr *firstOut;
    OrthoArcPtr *firstIn;
    int v;
    int e;
};
typedef struct ortho_graph OrthoGraph;

OrthoGraphPtr CreateOrthoGraph(int v);
void AddOrthoArc(OrthoGraphPtr G , int tail, int head, int weight);

#endif