#include "priority-queue.h"

int main(){
    PriorityQueue *pq = create_queue();

    enqueue(pq, create_node(1,1));
    enqueue(pq, create_node(2,2));
    enqueue(pq, create_node(3,3));
    enqueue(pq, create_node(4,4));
    enqueue(pq, create_node(5,5));
    enqueue(pq, create_node(6,6));
    enqueue(pq, create_node(7,7));

    for(int i=1; i<=pq->size; i++){
        
    }

    return 0;
}