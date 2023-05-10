#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *link;
};


void create_list(struct node **);
void add_node(struct node **, int);
void create_node(struct node **, int);
void reverse_list(struct node **);
void display_list(struct node *);


int main() {

    struct node *head = NULL;

    create_list(&head);
    display_list(head);
    reverse_list(&head);
    display_list(head);

    return 0;

}


void create_list(struct node **h) {

    int d;

    while (1) {

        printf("Enter data: "); scanf("%i", &d);

        if (d == -1) {
            break;
        }
        else {
            add_node(&*h, d);
        }

    }

}


void add_node(struct node **h, int d) {

    struct node *temp = *h;

    if(*h == NULL) {
        create_node(&*h, d);
    }
    else {
        while (temp->link != NULL) {
            temp = temp->link;
        }
        create_node(&temp->link, d);
    }

}


void create_node(struct node **node, int d) {
    *node = (struct node *) malloc(sizeof(struct node));
    (*node)->data = d;
    (*node)->link = NULL;
}


void reverse_list(struct node **h) {

    struct node *curr = *h;
    struct node *prev = NULL;
    struct node *next = NULL;

    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }

    *h = prev;

}


void display_list(struct node *temp) {

    printf("\nLinked List: ");
    while(temp != NULL) {
        printf("%i ", temp->data);
        temp = temp->link;
    }

}