#include <stdio.h>
#include "graph.h"


int main(){
    Graph *graph = create_graph();


    insert_vertex(graph, create_node(1));
    insert_vertex(graph, create_node(2));
    insert_vertex(graph, create_node(3));
    insert_vertex(graph, create_node(4));
    insert_vertex(graph, create_node(5));
    insert_vertex(graph, create_node(10));

    insert_edge(graph, 1, 2);
    insert_edge(graph, 2, 3);
    insert_edge(graph, 3, 4);
    insert_edge(graph, 4, 5);
    insert_edge(graph, 5, 3);
    insert_edge(graph, 5, 2);
    insert_edge(graph, 2, 1);
    insert_edge(graph, 1, 3);
    insert_edge(graph, 10, 5);
    insert_edge(graph, 10, 1);

    // 출력
    traversal(graph);

    // 삭제 후 출력
    printf("vertex 10 delete\n");
    delete_vertex(graph, 10);
    traversal(graph);

    printf("vertex 3 delete\n");
    delete_vertex(graph, 3);
    traversal(graph);
    
    printf("edge (4->5) delete\n");
    delete_edge(graph, 4, 5);
    traversal(graph);
    
    return 0;
}