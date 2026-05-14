#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;

    int value = queue[front];
    front++;

    return value;
}

void bfs(int start, int vertices)
{
    int i;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear)
    {
        int current = dequeue();

        printf("%d ", current);

        for (i = 0; i < vertices; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int vertices, edges;
    int i, u, v;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph and visited array
    for (i = 0; i < vertices; i++)
    {
        visited[i] = 0;

        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1; // Undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start, vertices);

    return 0;
}