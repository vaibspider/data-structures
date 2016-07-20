#define MAX 16

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
void llinsert(list *l, int index, char *str);
char *llremove(list *l, int index, char *str);
void llappend(list *l, char *str);
list *llreverse(list *l);
