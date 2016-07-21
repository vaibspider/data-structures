#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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

int llisempty(list *l) {
	if(l->len == 0) {
		return YES;
	}
	return NO;
}

int llisfull(list *l) {
	if(malloc(sizeof(node)) == NULL) {
		return YES;
	}
	return NO;
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
					if(l->tail == NULL) {
						l->tail = new;
					}
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
				return SUCCESS;
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
	int ret = llinsert(l, l->len, str);// ret: return
	return ret;
}

int llremove(list *l, int index) {
	if(l != NULL) {
		if(index >= 0 && index < l->len) {
			if(l->head != NULL && l->tail != NULL) {
				if(index == 0) {
					node *p = l->head;
					l->head = p->next;
					p->next = NULL;
					if(l->head == NULL) {
						l->tail = NULL;
					}
					free(p);
				}
				else if(index < l->len - 1) {
					node *p;
					for(int i = 0; i < index - 1; i++) {
						p = p->next;
					}
					node *q = p->next;
					p->next = q->next;
					q->next = NULL;
					free(q);
				}
				else { /*same as 'index == l->len - 1'*/
					node *p;
					while(p->next != l->tail) {
						p = p->next;
					}
					p->next = NULL;
					free(l->tail);
					l->tail = p;
				}
				l->len--;
				return SUCCESS;
			}
			else if(l->head == NULL && l->tail == NULL && l->len == 0) {
				return EMPTY_LIST;
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

int llreverse(list *l) {
	if(l != NULL) {
		if(l->head != NULL && l->tail != NULL) {
			node *p, *q, *r;
			p = l->head;
			q = p->next;
			if(q != NULL) {
				r = q->next;
				while(r != NULL) {
					q->next = p;
					p = q;
					q = r;
					r = r->next;
				}
				q->next = p;
				p = q;
				q = r;//here q will surely be null
				
				node *tmp;
				l->head->next = NULL;
				tmp = l->head;
				l->head = l->tail;
				l->tail = tmp;
				return SUCCESS;
			}
			else {
				return SUCCESS;
			}
		}
		else {
			return EMPTY_LIST;
		}
	}
	else {
		return INVALID_LIST;
	}
}

int llprint(list *l) {
	if(l != NULL) {
		if(l->head != NULL && l->tail != NULL ) {
			node *p = l->head;
			int i, len = l->len;
			for(i = 0; i < len; i++) {
				if(p != l->head) {
					printf("->");
				}
				printf("[ %s ]", p->str);
				p = p->next;
			}
			return SUCCESS;
		}
		else if(l->head == NULL && l->tail == NULL){
			printf("[  ]\n");
			return EMPTY_LIST;
		}
		else {
			return INCONSISTENT_LIST;
		}
	}
	else {
		return INVALID_LIST;
	}
}
