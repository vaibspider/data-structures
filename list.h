#define MAX 16

#define INVALID_LIST 1
#define INVALID_INDEX 2
#define INCONSISTENT_LIST 3
#define NULL_STRING 4
#define MALLOC_ERROR 5

typedef struct node {
	char str[MAX];
	struct node *next;
} node;

typedef struct linked_list {
	node *head, *tail;
	int len;
} list;

void llinit(list *l);
int llempty(list *l);
int llfull(list *l);
int llinsert(list *l, int index, char *str);
char *llremove(list *l, int index, char *str);
void llappend(list *l, char *str);
list *llreverse(list *l);
