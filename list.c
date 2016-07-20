#include "list.h"
node *llcreateNode(void) { // This is a private function that should be accessible only through linked list methods. In C++, it is supported.
	node *new;
	new = (node *) malloc(sizeof(node));
	new->next = NULL;
	return new;
}

void llinit(list *l) {
	l->head = l->tail = NULL;
	l->len = 0;
}

void insert(list *l, int index, char *str) {
	if(l != NULL) {
		if(index >= 0 && index <= l->len) {
			node *new = llcreateNode();
			strcpy(new->str, str);
			if((l->head != NULL && l->tail != NULL) || (l->head == NULL && l->tail == NULL)) {
				if(index == 0) {
					new->next = l->head;
					l->head = new;
					l->len++;
				}
				else if(index < l->len){
					node *p = l->head;
					for(i = 0; i < index - 1; i++) {
						p = p->next;
					}
					new->next = p->next;
					p->next = new;
				}
				else {
					l->tail->next = new;
					l->tail = new;
					l->len++;
				}
			}
		}
	}
}
