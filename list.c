#include "list.h"

node *llcreateNode(void) { // This is a private function that should be accessible only through linked list methods. In C++, it is supported.
	node *new;
	new = (node *) malloc(sizeof(node));
	if(new == NULL) {
		return NULL;
	}
	new->next = NULL;
	return new;
}

void llinit(list *l) {
	l->head = l->tail = NULL;
	l->len = 0;
}

int llempty(list *l) {
	if(l->len == 0) {
		return 1;
	}
	return 0;
}

int llfull(list *l) {
	if(malloc(sizeof(node)) == NULL) {
		return 1;
	}
	return 0;
}

int llinsert(list *l, int index, char *str) {
	if(l != NULL) {
		if(index >= 0 && index <= l->len) {
			node *new = llcreateNode();
			if(new == NULL) {
				return MALLOC_ERROR;
			}
			if(str != NULL) {
				strcpy(new->str, str);
			}
			else {
				free(new);
				return NULL_STRING;
			}
			if((l->head != NULL && l->tail != NULL) || (l->head == NULL && l->tail == NULL && l->len == 0)) {
				if(index == 0) {
					new->next = l->head;
					l->head = new;
				}
				else if(index < l->len){
					int i;
					node *p = l->head;
					for(i = 0; i < index - 1; i++) {
						p = p->next;
					}
					new->next = p->next;
					p->next = new;
				}
				else { /* same as 'index == l->len'*/
					l->tail->next = new;
					l->tail = new;
				}
				l->len++;
				return 0;
			}
			else {
				free(new);
				return INCONSISTENT_LIST;
			}
		}
		else {
			return INVALID_INDEX;
		}
	}
	else {
		return INVALID_LIST;
	}
}

int llappend(list *l, char *str) {
	ret = llinsert(l, l->len, str);// ret: return
	return ret
}

int llremove(list *l, int index) {
	if(l != NULL) {
		if(index >= 0 && index <= l->len) {
			if((l->head != NULL && l->tail != NULL) || (l->head == NULL && l->tail == NULL && l->len == 0)) {
				if(index == 0) {
					node *p = l->head;
					l->head = p->next;
					p->next = NULL;
					free(p);
				}
				else if(index < l->len) {
					for(int i = 0; i < index - 1; i++) {
						p = p->next;
					}
					node *q = p->next;
					p->next = q->next;
					q->next = NULL;
					free(q);
				}
				else { /*same as 'index == l->len'*/
					while(p->next != l->tail) {
						p = p->next;
					}
					p->next = NULL;
					free(l->tail);
					l->tail = p;
				}
				l->len--;
				return 0;
			}
			else {
				return INCONSISTENT_LIST;
			}
		}
		else {
			return INVALID_INDEX;
		}
	}
	else {
		return INVALID_LIST;
	}
}
