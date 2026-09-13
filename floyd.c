#include <stdio.h>
#include <stdlib.h>
#include "graph_matrix.h"

#define INF 0x3f3f3f3f

#define M(graph,i,j) ((graph)->mat[(i) * ((graph)->v + 1) + (j)])
#define D(i,j) dist[(i) * (n + 1) + (j)]

void Floyd(MatrixGraphPtr graph){
    int n = graph->v;
    int *dist = (int *)malloc((n + 1) * (n + 1) * sizeof(int));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            D(i, j) = M(graph, i, j);
        }
    }


    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(D(i, j) > D(i, k) + D(k, j)){
                    D(i, j) = D(i, k) + D(j, k);
                    D(j, i) = D(i, k) + D(j, k);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < n; j++){
            if(D(i, j) < INF){
                printf("%d ", D(i, j));
            }
            else{
                printf("INF ");
            }
        }
        if(D(i, n) < INF){
            printf("%d\n", D(i, n));
        }
        else{
            printf("INF\n");
        }
    }
}
