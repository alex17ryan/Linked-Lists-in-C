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

void search_data(struct node *temp, int d) {

    if (temp == NULL) {
        printf("List is empty.");
    }
    else {
        while (temp != NULL) {
            if (temp->data == d) {
                printf("Data found.");
                return;
            }
            temp = temp->link;
        }
        printf("Data not found.");
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

void search_position(struct node *temp, int *p) {

    if (*p < 1 || *p > list_length(temp)) {
        printf("Invalid position.");
    }
    else {
        while (*p != 1) {
            temp = temp->link;
            (*p)--;
        }
        *p = temp->data;
        printf("Data found: %i", *p);
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

    printf("\nEnter data to search for: "); scanf("%i", &d);
    search_data(head, d);

    printf("\nEnter position to search at: "); scanf("%i", &d);
    search_position(head, &d);

    return 0;

}