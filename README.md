# data_structure

## list에서 head node가 따로 필요한 이유
- 삭제 작업을 진행할 때 node->next의 null 여부에 따라서 이어가는게 삭제 연산이 수월하다. 
따라서 특별한 경우가 아니라면 head node를 두자. 