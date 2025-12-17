#include <stdio.h>

#define V 5
#define MAXQ 100

void addEdge(int adj[V][V], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void displayAdjacencyMatrix(int adj[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

void dfsRec(int adj[V][V], int visited[V], int s, int res[V], int *idx) {
    visited[s] = 1;
    res[(*idx)++] = s;

    for (int i = 0; i < V; i++) {
        if (adj[s][i] && !visited[i])
            dfsRec(adj, visited, i, res, idx);
    }
}

void dfs(int adj[V][V]) {
    int visited[V] = {0};
    int res[V];
    int idx = 0;

    dfsRec(adj, visited, 0, res, &idx);

    printf("DFS Traversal: ");
    for (int i = 0; i < idx; i++)
        printf("%d ", res[i]);
    printf("\n");
}

void bfs(int adj[V][V]) {
    int visited[V] = {0};
    int res[V];
    int q[MAXQ];
    int front = 0, rear = 0;
    int resSize = 0;
    int src = 0;

    visited[src] = 1;
    q[rear++] = src;

    while (front < rear) {
        int curr = q[front++];
        res[resSize++] = curr;

        for (int i = 0; i < V; i++) {
            if (adj[curr][i] && !visited[i]) {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }

    printf("BFS Traversal: ");
    for (int i = 0; i < resSize; i++)
        printf("%d ", res[i]);
    printf("\n");
}

int main() {
    int adj[V][V] = {0};

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 0);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);

    displayAdjacencyMatrix(adj);

    dfs(adj);
    bfs(adj);

    return 0;
}
