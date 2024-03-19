#include <stdio.h>
#include "graph.h"


int main(){
    Graph *graph = create_graph();

    insert_vertex(graph, create_node(1));
    insert_vertex(graph, create_node(2));
    insert_vertex(graph, create_node(3));
    insert_vertex(graph, create_node(4));
    insert_vertex(graph, create_node(5));

    insert_edge(graph, 1, 2);
    insert_edge(graph, 2, 3);
    insert_edge(graph, 3, 4);
    insert_edge(graph, 4, 5);
    insert_edge(graph, 5, 3);
    insert_edge(graph, 5, 2);
    insert_edge(graph, 2, 1);
    insert_edge(graph, 1, 3);


    // 출력
    for(int i=1; i<=graph->n; i++){
        GraphNode *gn = graph->vertex_list[i];
        Edge *tmp_edge = gn->edge_list;
        
        printf("%d : ", gn->vertex);

        while(tmp_edge!=NULL){
            printf("%d ", tmp_edge->vertex);
            tmp_edge = tmp_edge->next;
        }

        printf("\n");
    }

    return 0;
}