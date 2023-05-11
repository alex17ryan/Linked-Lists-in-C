#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void display_list(struct node *temp) {
    if (temp == NULL) {
        printf("List is empty.");
    }
    else {
        printf("\nLinked List: ");
        while (temp != NULL) {
            printf("%i ", temp->data);
            temp = temp->link;
        }
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

void delete_tail(struct node **h) {

    struct node *temp = *h;

    if (*h == NULL) {
        return;
    }
    else if ((*h)->link == NULL) {
        free(*h);
        *h = NULL;
    }
    else {
        while (temp->link->link != NULL) {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }

}

void delete_head(struct node **h) {

    if (*h == NULL) {
        return;
    }
    else {
        struct node *head = (*h)->link;
        free(*h);
        *h = head;
    }

}

void delete_at_position(struct node **h, int p) {
    
    struct node *temp = *h;

    if (p < 1 || p > list_length(*h)) {
        printf("Invalid position.");
        exit(1);
    }
    else if (p == 1){
        delete_head(&*h);
    }
    else if (p == list_length(*h)) {
        delete_tail(&*h);
    }
    else {
        while (p != 2) {
            temp = temp->link;
            p--;
        }
        struct node *deleted = temp->link;
        temp->link = temp->link->link;
        free(deleted);
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
    struct node *list = NULL;

    printf("Enter the number of nodes: "); scanf("%i", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: "); scanf("%i", &d);
        add_node(&list, d);
    }

    delete_head(&list);
    delete_tail(&list);

    printf("Enter the position: "); scanf("%i", &d);
    delete_at_position(&list, d);

    display_list(list);

    return 0;

}