#include "func.h"

typedef struct Que{
	int head;
	int tail;
	int *vect;
}Que;

int find(Graph *graph){
	int i, j;
	printf("Enter vertex from: ");
	scanf("%d", &i);
	printf("Enter vertex to: ");
        scanf("%d", &j);

	Que *o =(Que*)malloc(sizeof(Que));
	o->vect = (int *)malloc(sizeof(int) * 10);
	o->vect[0] = i;
	o->head = 0;
	o->tail = 1;

	int mas[10];
	int p;
	for(p = 0; p <= 10; p++)
	mas[p] = 21474836;
	mas[i] = 0;

	for(p = 0; p < graph->L ; p++){
			i = o->vect[o->head];
			Node *ptr = graph->array[i].head;
			++o->head;

			while (ptr != NULL){
				int m = ptr->dest;
				if(mas[m] > (ptr->h + mas[i])){
					o->vect[o->tail] = m;
					++o->tail;
					mas[m] = mas[i] + ptr->h;
				}
				ptr = ptr->next;
			}
	}
	printf("Min way: %d\n", mas[j]);
	free(o->vect);
	free(o);

	return 1;
}
