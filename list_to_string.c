#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node *link;
};

struct node *create_node(char d) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = d;
    node->link = NULL;
    return node;
}

void add_node(struct node **h, char d) {

    struct node *temp = *h;

    if (*h == NULL) {
        *h = create_node(d);
    }
    else {
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = create_node(d);
    }

}

char *list_to_string(struct node *temp) {

    static char string[20];

    while (temp != NULL) {
        string[strlen(string)] = temp->data;
        temp = temp->link;
    }

    return string;

}

int main() {

    int i, n;
    char d;
    struct node *head = NULL;

    printf("Enter the number of nodes: "); scanf("%i", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: "); scanf(" %c", &d);
        add_node(&head, d);
    }
    
    printf("\n%s", list_to_string(head));

    return 0;

}