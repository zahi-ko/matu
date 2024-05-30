#include <stdio.h>
#include <stdlib.h>

/**
 * 深度优先搜索遍历邻接矩阵表示的图
 * @param v 当前遍历的顶点
 * @param n 图的顶点数
 * @param visited 记录顶点是否被访问的数组
 * @param matrix 邻接矩阵
 * @param out 存储遍历结果的数组
 * @param index 存储遍历结果数组的索引
 */
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

/**
 * 解决问题A的函数
 * @param n 图的顶点数
 * @param m 图的边数
 * @param e 存储边的数组
 * @param out 存储遍历结果的数组
 */
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

/**
 * 邻接链表的结点结构
 */
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

/**
 * 深度优先搜索遍历邻接链表表示的图
 * @param v 当前遍历的顶点
 * @param adjList 邻接链表数组
 * @param visited 记录顶点是否被访问的数组
 * @param out 存储遍历结果的数组
 * @param index 存储遍历结果数组的索引
 */
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

/**
 * 向邻接链表中添加结点
 * @param head 链表头指针的指针
 * @param vertex 结点的值
 */
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

/**
 * 解决问题B的函数
 * @param n 图的顶点数
 * @param m 图的边数
 * @param e 存储边的数组
 * @param out 存储遍历结果的数组
 */
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