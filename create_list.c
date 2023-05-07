#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display_list(struct node *h) {

    struct node *temp = h;

    if (h == NULL) {
        printf("The list is empty.");
    }
    else {
        while (temp != NULL) {
            printf("%i ", temp->data);
            temp = temp->next;
        }
    }

}

struct node *create_node(int d) {
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = d;
    new->next = NULL;
    return new;
}

void add_node_at_last(struct node **h, int d) {

    struct node *temp = *h;

    if (*h == NULL) {
        *h = create_node(d);
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = create_node(d);
    }

}

void create_list(struct node **h) {

    int d;

    while (1) {

        printf("Enter data: "); scanf("%i", &d);

        if (d == -1) {
            break;
        }
        else {
            add_node_at_last(&*h, d);
        }

    }

}

int main() {

    struct node *head = NULL;

    create_list(&head);
    display_list(head);

    return 0;
    
}
