// Display list in reverse order.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void reverse_display(struct node *h) {
    if (h == NULL) {
        return;
    }
    else {
        reverse_display(h->link);
        printf("%i ", h->data);
    }
}

void display_list(struct node *temp) {
    while (temp != NULL) {
        printf("%i ", temp->data);
        temp = temp->link;
    }
}

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

int main() {

    int i, n, d;
    struct node *head = NULL;

    printf("Enter the number of nodes: "); scanf("%i", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: "); scanf("%i", &d);
        add_node(&head, d);
    }

    printf("\nOriginal List: ");
    display_list(head);

    printf("\nReversed List: ");
    reverse_display(head);

    return 0;

}