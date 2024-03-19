#include "graph.h"

Graph* create_graph(){
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->n = 0;
    g->vertex_list = (GraphNode**)malloc(sizeof(GraphNode*)*(MAX_NODE+1));

    return g;
}

GraphNode* create_node(int vertex){
    GraphNode *gnode = (GraphNode*)malloc(sizeof(GraphNode));
    gnode->vertex = vertex;
    gnode->edge_list = NULL;
    return gnode;
}


void insert_vertex(Graph *g, GraphNode *gnode){
    if(g->n == MAX_NODE) printf("OVERFLOW\n");
    else
    {
        g->n++;
        g->vertex_list[gnode->vertex] = gnode;
    }
}

void insert_edge(Graph *g, int src, int dest){
    Edge *new_edge = (Edge*)malloc(sizeof(Edge));

    new_edge->vertex = dest;
    new_edge->next = g->vertex_list[src]->edge_list;
    g->vertex_list[src]->edge_list = new_edge;
}