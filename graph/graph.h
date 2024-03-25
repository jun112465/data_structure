#include <stdlib.h>
#include <stdio.h>
#define MAX_NODE 20

typedef struct edge{
    int vertex;
    struct edge *next;
}Edge;

typedef struct graph_node{
    int vertex;
    // 인접 노드에 대한 연결리스트
    Edge *edge_list;
}GraphNode;

typedef struct graph{
    int n;
    GraphNode** vertex_list;
}Graph;

GraphNode* create_node(int vertex);
Graph* create_graph();
void insert_vertex(Graph *g, GraphNode *node);
void insert_edge(Graph *g, int src, int dest);
void delete_vertex(Graph *g, int target_vertex);
void delete_edge(Graph *g, int src, int dest);
void traversal(Graph *g);

