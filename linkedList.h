struct linkedList {
    char *word;
    int counter;
    struct linkedList *next;
};

typedef struct linkedList *node; 

node createNode();

node addNode(node *head, char *word);

node search(node head, char *word);

void printNode(node Node);

void printList(node *head);

void sortList(node head);