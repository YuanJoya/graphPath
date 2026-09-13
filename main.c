#include <stdio.h>
#include "graph_matrix.h"
#include "graph_ortho.h"
#include "floyd.h"
#include "dijkstra.h"
#include "bellman.h"

#define INF 0x3f3f3f3f
#define MODE_FLOYD 1
#define MODE_DIJKSTRA 2
#define MODE_BELLMAN 3

int main(){
    int mode;
    scanf("%d", &mode);

    switch(mode){
        case MODE_FLOYD:{
            int v, e;
            scanf("%d %d", &v, &e);

            MatrixGraphPtr graph = CreateMatrixGraph(v);

            for(int i = 0; i < e; i++){
                int from, to, weight;
                scanf("%d %d %d", &from, &to, &weight);
                AddMatrixEdge(graph, from, to, weight);
            }

            Floyd(graph);
            break;
        }

        case MODE_DIJKSTRA:{
            int v, e, source;
            scanf("%d %d %d", &v, &e, &source);

            OrthoGraphPtr graph = CreateOrthoGraph(v);
            Element result[v + 1];

            for(int i = 0; i < e; i++){
                int from, to, weight;
                scanf("%d %d %d", &from, &to, &weight);
                AddOrthoArc(graph, from, to, weight);
            }

            Dijkstra(graph, source, result);

            for(int i = 1; i <= v; i++){
                if(result[i].dist < INF){
                    printf("%d\n", result[i].dist);
                }
                else{
                    printf("INF\n");
                }
            }
            break;
        }

        case MODE_BELLMAN:{
            int v, e, source;
            scanf("%d %d %d", &v, &e, &source);

            EdgeGraphPtr graph = CreatGraph(v, e);
            int dist[v + 1];

            if(!BellmanFord(graph, source, dist)){
                printf("Negative cycle\n");
                break;
            }

            for(int i = 1; i <= v; i++){
                if(dist[i] < INF){
                    printf("%d\n", dist[i]);
                }
                else{
                    printf("INF\n");
                }
            }
            break;
        }

        default:
            printf("Invalid mode\n");
            break;
    }

    return 0;
}
