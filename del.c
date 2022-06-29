#include "func.h"

int delVert(Graph* graph){ 
    int src;
    printf("Enter vertex for del: ");
    scanf("%d", &src);

    int i, j;

    for (i=0; i < graph->L; i++){
        Node *del = NULL;
        del = graph->array[i].head;  
        for (j=0; j < graph->array[i].c; j++){ 
            if (src == i){  
                graph->array[i].head = NULL;
                graph->array[i].c = 0;
                --graph->V;
                --graph->L;
                break;
            }

            if(j+1 == graph->array[i].c){
                if (src == del->dest){ 
                    graph->array[i].head = NULL; 
                    --graph->array[i].c;
                    --graph->L;
                    break;
                }else
                    break;
            }

            if (src == del->dest){ 
                if(del->next != NULL)
                *del = *del->next;
                else{
                    graph->array[i].head = NULL;
                    --graph->V;
                }
                --graph->array[i].c;
                --graph->L;
                break;
            }

            if(del->next->dest == src){ 
                --graph->array[i].c;
                if(del->next->next != NULL)
                *del->next = *del->next->next;
                else{
		            free(del->next);
                    del->next = NULL;
		            }
                break;
            }

            del = del->next;
        }
    }

    printf("Vertex %d was deleted\n", src);
    return 1;
}

