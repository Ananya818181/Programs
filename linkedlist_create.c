#include<stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head;

void create(int n);
void traverse();

void create(int n) {
    struct node *newNode, *temp;
    int data, i;

    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Unable to allocate memory\n");
        exit(0);
    } else {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;

        for (i = 2; i <= n; i++) {
            newNode = (struct node*)malloc(sizeof(struct node));
            if (newNode == NULL) {
                printf("Unable to allocate memory\n");
                break;
            } else {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newNode->data = data;
                newNode->next = NULL;
                temp->next = newNode;
                temp = newNode;
            }
        }
    }
}

void traverse() {
    struct node *temp;
    temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("The linked list elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    int n;
    printf("Enter the number of nodes to be inserted: ");
    scanf("%d", &n);
    create(n);
    traverse();
    return 0;
}