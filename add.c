#include "func.h"

Node* neww(int dest){
        Node* node = (Node*)malloc(sizeof(Node));
        node->dest = dest;
        node->next = NULL;
        return node;
}

int addEdge(Graph* graph){
        int src, dest, h;
        printf("Enter first vertex: ");
        scanf("%d", &src);
        printf("Enter second vertex: ");
        scanf("%d", &dest);
        printf("Enter ves : ");
        scanf("%d", &h);

        Node* check = NULL;
        Node *newNode = neww(dest);
        ++graph->V; 
        ++graph->L;
        graph->array = (AdjList*)realloc(graph->array, sizeof(Node) * graph->L); 
        graph->array[graph->L-1].head = NULL;
        newNode->h = h;

        if (graph->array[src].head == NULL){ 
                newNode->next = NULL;
                graph->array[src].c = 1;
                graph->array[src].head = newNode;
        }
        else { 
                --graph->V;
                check = graph->array[src].head;
                while (check->next != NULL) {
                        check = check->next;
                }
                check->next = newNode;
                ++graph->array[src].c;
        }

        return 1;
}

