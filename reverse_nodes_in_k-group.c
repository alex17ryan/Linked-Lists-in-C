#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *link;
};


void create_list(struct node **);
void add_node_at_last(struct node **, int);
struct node *create_node(int);
struct node *reverse_groups(struct node *, int);
void display_list(struct node *);


int main() {

    struct node *head1 = NULL;
    struct node *head2 = NULL;

    int k;

    printf("Enter number of nodes in each group: "); scanf("%i", &k);

    create_list(&head1);

    printf("Linked list: ");
    display_list(head1);
    
    head2 = reverse_groups(head1, k);

    printf("Reversed linked list: ");
    display_list(head2);

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


struct node *reverse_groups(struct node *h, int k) {

    struct node *curr = h;
    struct node *prev = NULL;
    struct node *next = NULL;

    int count = 0;

    while (curr != NULL && count < k) {
        count++;
        curr = curr->link;
    }

    if (count == k) {

        curr = h;
        count = 0;

        while (curr != NULL && count < k) {
            next = curr->link;
            curr->link = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != NULL) {
            h->link = reverse_groups(next, k);
        }

        return prev;

    }

    return h;

}
