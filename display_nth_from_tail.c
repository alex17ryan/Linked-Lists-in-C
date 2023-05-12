#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *create_node(int d) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = d;
    node->link = NULL;
    return node;
}

void add_node(struct node **h, int d) {

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

void display_nth_tail(struct node *h, int *n) {
    if (h == NULL) {
        return;
    }
    else {
        display_nth_tail(h->link, &*n);
        (*n)--;
        if (*n == 0) {
            printf("%i", h->data);
        }
    }
}

int main() {

    int i, n, d;
    struct node *head = NULL;

    printf("Enter the number of nodes: "); scanf("%i", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: "); scanf("%i", &d);
        add_node(&head, d);
    }

    printf("Enter the position starting from tail: "); scanf("%i", &n);

    display_nth_tail(head, &n);

    return 0;

}