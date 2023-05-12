#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int list_length(struct node *temp) {

    int length = 0;

    while (temp != NULL) {
        length++;
        temp = temp->link;
    }

    return length;

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

int *list_to_array(struct node *temp) {

    int len = list_length(temp);
    int *arr = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        arr[i] = temp->data;
        temp = temp->link;
    }

    return arr;

}

int main() {
    
    int n, i, d;
    struct node *head = NULL;

    printf("Enter the number of nodes: "); scanf("%i", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: "); scanf("%i", &d);
        add_node(&head, d);
    }

    for (i = 0; i < n; i++) {
        printf("%i ", list_to_array(head)[i]);
    }

    return 0;

}