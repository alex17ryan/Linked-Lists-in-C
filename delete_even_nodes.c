#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *link;
};


void create_list(struct node **);
void add_node_at_last(struct node **, int);
struct node *create_node(int);
void display_list(struct node *);
struct node *delete_even(struct node *);
struct node *delete_node(struct node *, struct node *);


int main() {

    struct node *head = NULL;

    create_list(&head);

    printf("Linked list: ");
    display_list(head);

    head = delete_even(head);

    printf("Odd linked list: ");
    display_list(head);
    
    return 0;

}


void create_list(struct node **h) {

    int d;

    while (1) {

        printf("Enter data: "); scanf("%i", &d);

        if (d == -1)
            break;
        else
            add_node_at_last(&*h, d);

    }

    printf("\n");

}


void add_node_at_last(struct node **h, int d) {

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


struct node *create_node(int d) {
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = d;
    new->link = NULL;
    return new;
}


void display_list(struct node *h) {

    struct node *temp = h;

    if (h == NULL) {
        printf("The list is empty.");
    }
    else {
        while (temp != NULL) {
            printf("%i ", temp->data);
            temp = temp->link;
        }
    }

    printf("\n");

}


struct node *delete_even(struct node *h) {

    struct node *temp = h;

    if (temp->link == NULL) {
        return NULL;
    }
    else {
        delete_even(temp->link);
        if(temp->link->data % 2 == 0) {
            temp = delete_node(temp, temp->link);
        }
        return h;
    }

}


struct node *delete_node(struct node *prev, struct node *curr) {
    prev->link = curr->link;
    curr->link = NULL;
    free(curr);
    return prev;
}
