#include "graph.h"

Graph* create_graph(){
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->n = 0;
    //g->vertex_list = (GraphNode**)malloc(sizeof(GraphNode*)*(MAX_NODE+1));
    g->vertex_list = (GraphNode**)calloc(sizeof(GraphNode*), MAX_NODE+1);

    return g;
}

GraphNode* create_node(int vertex){
    GraphNode *gnode = (GraphNode*)malloc(sizeof(GraphNode));
    gnode->vertex = vertex;
    gnode->edge_list = (Edge*)calloc(sizeof(Edge), 1);
    // gnode->edge_list = (Edge*)malloc(sizeof(Edge));
    // gnode->edge_list->next = NULL;
    return gnode;
}


void insert_vertex(Graph *g, GraphNode *gnode){
    if(g->n == MAX_NODE) printf("OVERFLOW\n");

    // check duplication
    if(g->vertex_list[gnode->vertex] != NULL){
        perror("VERTEX EXIST\n");
    }
    // insert
    else{
        g->n++;
        g->vertex_list[gnode->vertex] = gnode;
    }
}

void insert_edge(Graph *g, int src, int dest){
    Edge *new_edge = (Edge*)malloc(sizeof(Edge));

    // check duplication
    Edge *edge_tmp = g->vertex_list[src]->edge_list;
    while (edge_tmp->next != NULL)
    {
        edge_tmp = edge_tmp->next;
        if (edge_tmp->vertex == dest)
        {
            perror("EDGE EXISTS\n");
            return;
        }
    }

    //insert
    new_edge->vertex = dest;
    new_edge->next = g->vertex_list[src]->edge_list->next;
    g->vertex_list[src]->edge_list->next = new_edge;
}

void delete_vertex(Graph *g, int target_vertex){

    // vertex의 edge 삭제
    Edge *tmp_edge1 = g->vertex_list[target_vertex]->edge_list;
    Edge *tmp_edge2;
    while(tmp_edge1->next != NULL){
        tmp_edge2 = tmp_edge1;
        tmp_edge1 = tmp_edge1->next;
        free(tmp_edge2);
    }
    // vertex 삭제 
    free(g->vertex_list[target_vertex]);
    g->vertex_list[target_vertex] = NULL;

    // target_vertex가 dest인 edge 삭제
    for(int i=1; i<=MAX_NODE; i++){
        if(g->vertex_list[i] == NULL) continue;

        GraphNode *gnode = g->vertex_list[i];
        Edge *edge_node = gnode->edge_list;
        Edge *tmp_next_edge;
        
        while(edge_node->next != NULL){
            if(edge_node->next->vertex == target_vertex){
                tmp_next_edge = edge_node->next->next;
                free(edge_node->next);
                edge_node->next = tmp_next_edge;
                break;
            }
            edge_node = edge_node->next;
        }
    }
}

void delete_edge(Graph *g, int src, int dest){

    Edge* tmp_edge = g->vertex_list[src]->edge_list;
    Edge* tmp_edge_next;

    while (tmp_edge->next != NULL)
    {
        if (tmp_edge->next->vertex == dest)
        {
            tmp_edge_next = tmp_edge->next->next;
            free(tmp_edge->next);
            tmp_edge->next = tmp_edge_next;
            break;
        }
        tmp_edge = tmp_edge->next;
    }
}

void traversal(Graph *g){
    for(int i=1; i<MAX_NODE; i++){
        if(g->vertex_list[i] == NULL) continue;
        Edge* tmp_edge = g->vertex_list[i]->edge_list;

        printf("VERTEX[%d] : ", i);


        while(tmp_edge->next != NULL){
            tmp_edge = tmp_edge->next;
            printf("%d ", tmp_edge->vertex); 
        }

        printf("\n");
    }
}