#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void display_list(struct node *temp) {

    printf("\nLinked List: ");

    if (temp == NULL) {
        printf("Empty list.");
    }
    else {
        while (temp != NULL) {
            printf("%i ", temp->data);
            temp = temp->link;
        }
    }

}

struct node *create_node(int d) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = d;
    node->link = NULL;
    return node;
}

void insert_tail(struct node **h, int d) {

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

void insert_head(struct node **h, int d) {

    struct node *new = create_node(d);

    if (*h == NULL) {
        *h = new;
    }
    else {
        new->link = *h;
        *h = new;
    }

}

int list_length(struct node *temp) {

    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->link;
    }

    return count;

}

void insert_at_position(struct node **h, int p, int d) {

    struct node *new = create_node(d);
    struct node *temp = *h;

    if (p == 1) {
        insert_head(&*h, d);
    }
    else if (p == list_length(*h) + 1) {
        insert_tail(&*h, d);
    }
    else {
        while (p != 1) {
            temp = temp->link;
            p--;
        }
        new->link = temp->link;
        temp->link = new;
    }

}

int main() {

    int p, d;
    struct node *head = NULL;

    while (1) {

        printf("Enter position: "); scanf("%i", &p);

        if (p == 0) {
            break;
        }
        else if (p < 1 || p > list_length(head) + 1){ 
            printf("Invalid position\n");
            break;
        }
        
        printf("Enter data: "); scanf("%i", &d);
        insert_at_position(&head, p, d);

    }

    display_list(head);

    return 0;

}