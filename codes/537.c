/**
 * 使用深度优先搜索算法遍历图的邻接矩阵和邻接表表示。
 *
 * @param n 图的顶点数
 * @param m 图的边数
 * @param e 图的边集合
 * @param outA 使用邻接矩阵表示遍历结果
 * @param outB 使用邻接表表示遍历结果
 */

#include <stdio.h>
#include <stdlib.h>

void dfsMatrix(int v, int n, int visited[], int **matrix, int out[], int *index)
{
    visited[v] = 1;
    out[(*index)++] = v;
    for (int i = 0; i < n; i++)
    {
        if (matrix[v][i] > 0 && !visited[i])
        {
            dfsMatrix(i, n, visited, matrix, out, index);
        }
    }
}

void solveA(int n, int m, int e[][2], int out[])
{
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)calloc(n, sizeof(int));
    }
    for (int i = 0; i < m; i++)
    {
        matrix[e[i][0]][e[i][1]] = 1;
        matrix[e[i][1]][e[i][0]] = 1;
    }

    int *visited = (int *)calloc(n, sizeof(int));
    int index = 0;
    dfsMatrix(0, n, visited, matrix, out, &index);

    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    free(visited);
}

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

void dfsList(int v, Node **adjList, int visited[], int out[], int *index)
{
    visited[v] = 1;
    out[(*index)++] = v;
    Node *current = adjList[v];
    while (current != NULL)
    {
        if (!visited[current->vertex])
        {
            dfsList(current->vertex, adjList, visited, out, index);
        }
        current = current->next;
    }
}
void addNode(Node **head, int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}
void solveB(int n, int m, int e[][2], int out[])
{
    Node **adjList = (Node **)calloc(n, sizeof(Node *));
    for (int i = 0; i < m; i++)
    {
        addNode(&adjList[e[i][0]], e[i][1]);
        addNode(&adjList[e[i][1]], e[i][0]);
    }

    int *visited = (int *)calloc(n, sizeof(int));
    int index = 0;
    dfsList(0, adjList, visited, out, &index);

    for (int i = 0; i < n; i++)
    {
        Node *cur = adjList[i];
        while (cur)
        {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(adjList);
    free(visited);
}
int main()
{
    int n = 5, m = 10;
    int e[10][2] = {{2, 4}, {3, 0}, {0, 2}, {3, 1}, {4, 1}, {0, 1}, {3, 4}, {2, 3}, {1, 2}, {0, 4}};
    int outA[5] = {0}, outB[5] = {0};

    solveA(n, m, e, outA);
    solveB(n, m, e, outB);

    printf("solveA: out={");
    for (int i = 0; i < n; i++)
    {
        printf("%d", outA[i]);
        if (i < n - 1)
        {
            printf(",");
        }
    }
    printf("}\n");

    printf("solveB: out={");
    for (int i = 0; i < n; i++)
    {
        printf("%d", outB[i]);
        if (i < n - 1)
        {
            printf(",");
        }
    }
    printf("}\n");

    return 0;
}