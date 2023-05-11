// insert nodes at the end, at the start, and in the middle.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

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

void insert_middle(struct node **h, int d) {

    struct node *new = create_node(d);
    struct node *big_boy = (*h)->link;
    struct node *little_girl = *h;

    if (*h == NULL) {
        *h = new;
    }
    else {
        while(big_boy != NULL && big_boy->link != NULL) {
            big_boy = big_boy->link->link;
            little_girl = little_girl->link;
        }
        new->link = little_girl->link;
        little_girl->link = new;
    }

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

int main() {

    int i, n, d;
    struct node *list = NULL;

    printf("Enter the number of nodes to insert at last: "); scanf("%i", &n);
    for (i = 0; i < n; i++) {
        printf("Enter data: "); scanf("%i", &d);
        insert_tail(&list, d);
    }

    printf("Enter the number of nodes to insert at start: "); scanf("%i", &n);
    for (i = 0; i < n; i++) {
        printf("Enter data: "); scanf("%i", &d);
        insert_head(&list, d);
    }

    printf("Enter data to insert at the middle: "); scanf("%i", &d);
    insert_middle(&list, d);
    
    printf("\nLinked List: ");
    display_list(list);

    return 0;

}