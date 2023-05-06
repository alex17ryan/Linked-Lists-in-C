#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_list(struct node *);
struct node *create_node(int);
struct node *add_node_at_end(struct node *, int);
void display_list(struct node *);

int main() {

    struct node *head = NULL;

    head = create_list(head);
    display_list(head);

    return 0;

}

struct node *create_list(struct node *h) {

    int d;

    while (1) {

        printf("Enter data: "); scanf("%i", &d);

        if (d == -1)
            break;
        else
            h = add_node_at_end(h, d);

    }

    return h;

}

struct node *add_node_at_end(struct node *h, int d) {

    struct node *temp = h;
    
    if (h == NULL) {
        h = create_node(d);
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = create_node(d);
    }

    return h;

}

struct node *create_node(int d) {
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = d;
    new->next = NULL;
    return new;
}

void display_list(struct node *h) {
    
    struct node *temp = h;

    while(temp != NULL) {
        printf("%i ", temp->data);
        temp = temp->next;
    }

}
