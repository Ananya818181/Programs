#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node* insertAtBeginning(struct node* start, int newData) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Unable to allocate memory\n");
        return start;  
    }
    newNode->data = newData;
    newNode->next = start; 
    return newNode;         
}
struct node* insertAtEnd(struct node* start, int newData) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = start;
    if (newNode == NULL) {
        printf("Unable to allocate memory\n");
        return start; 
    }
    newNode->data = newData;
    newNode->next = NULL;

    if (start == NULL) {
        return newNode; 
    }
    while (temp->next != NULL) { 
        temp = temp->next;
    }
    temp->next = newNode;  
    return start;         
}
struct node* insertBetween(struct node* start, int newData, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = start;
    int i;
    if (newNode == NULL) {
        printf("Unable to allocate memory\n");
        return start;  
    }
    newNode->data = newData;
    if (position == 1) {
        newNode->next = start;
        return newNode; 
    }
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("The position is out of range\n");
        return start;
    }
    newNode->next = temp->next;
    temp->next = newNode;  
    return start;         
}
void display(struct node* start) {
    struct node* temp = start;
    int count = 0;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
        count++;
    }
    printf("The number of nodes are %d\n", count);
}
int main() {
    struct node* start = NULL;
    int choice, data, position;
    while (1) {
        printf("\nChoice:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                start = insertAtBeginning(start, data); 
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                start = insertAtEnd(start, data);  
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert the data: ");
                scanf("%d", &position);
                start = insertBetween(start, data, position);  
                break;
            case 4:
                display(start); 
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
