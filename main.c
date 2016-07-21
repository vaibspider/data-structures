#include "list.h"
#include <stdio.h>
#include <stdlib.h>
/* What is the best way to get the input from a user for this linked list program?*/
/* How to use function name other than main() as an entry point into this program?*/
int main(int argc, char **argv) {
	list *l;
	l = (list *) malloc(sizeof(list));
	if(l == NULL) {
		printf("list malloc error!");
		return 1;
	}
	int input, ret, status, index;
	char str[MAX];
	llinit(l);
	do {
		printf("1.Insert\t\
			2.Append\t\
			3.Remove\t\
			4.Reverse\n\
			");
		scanf("%d", &input);
		switch(input) {
			case 1:
				if(llisfull(l) == FALSE) {
					printf("\nIndex: ");
					scanf("%d", &index);
					printf("String: ");
					scanf("%s", str);
					ret = llinsert(l, index, str);
					status = llprint(l);
				}
				else {
					printf("\nThe list is full!\n");
				}
				break;
			case 2:
				if(llisfull(l) == FALSE) {
					printf("String: ");
					scanf("%s", str);
					ret = llappend(l, str);
					status = llprint(l);
				}
				else {
					printf("\nThe list is full!\n");
				}
				break;
			case 3:
				if(llisempty(l) == FALSE) {
					printf("\nIndex: ");
					scanf("%d", &index);
					ret = llremove(l, index);
					status = llprint(l);
				}
				else {
					printf("\nThe list is already empty!\n");
				}
				break;
			case 4:
				ret = llreverse(l);
				status = llprint(l);
				break;
			case 5:
				return 0;
				break;
			default:
				break;
		}
	} while(1);
	return 0;
}
