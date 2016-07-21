#define MAX 16

#define INVALID_LIST 1
#define INVALID_INDEX 2
#define INCONSISTENT_LIST 3
#define NULL_STRING 4
#define MALLOC_ERROR 5
#define EMPTY_LIST 6
#define FALSE 1
#define TRUE 0
#define SUCCESS 0

typedef struct node {
	char str[MAX];
	struct node *next;
} node;

typedef struct linked_list {
	node *head, *tail;
	int len;
} list;

void llinit(list *l);
int llisempty(list *l);
int llisfull(list *l);
int llinsert(list *l, int index, char *str);
int llappend(list *l, char *str);
int llremove(list *l, int index);
list *llreverse(list *l);
int llprint(list *l);
