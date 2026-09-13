# graphPath

`graphPath` is a small C project for finding shortest paths in graphs. It includes three classic algorithms:

- Floyd–Warshall for all-pairs shortest paths
- Dijkstra for single-source shortest paths with non-negative edge weights
- Bellman–Ford for single-source shortest paths, including negative edge weights

## Build

Compile the project with GCC:

```bash
gcc -Wall -Wextra -std=c11 main.c graph_matrix.c floyd.c graph_ortho.c dijkstra.c heap.c graph_edge.c bellman.c -o app
```

## Run

The program reads a mode number from standard input:

- `1` — Floyd–Warshall. Then enter `vertices edges`, followed by `from to weight` for each edge.
- `2` — Dijkstra. Then enter `vertices edges source`, followed by the edges.
- `3` — Bellman–Ford. Then enter `vertices edges source`, followed by the edges.

Vertices are numbered from `1` to `V`. The program prints the shortest distances, or `INF` when a vertex cannot be reached. Bellman–Ford also reports `Negative cycle` when it detects one.
