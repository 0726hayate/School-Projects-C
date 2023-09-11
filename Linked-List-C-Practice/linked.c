#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a doubly-linked list node
typedef struct Node_struct {
    char data[15];             // Data stored in the node (a string with a max length of 15 characters)
    struct Node_struct* next;  // Pointer to the next node in the list
    struct Node_struct* prev;  // Pointer to the previous node in the list
} Node;

// Declare global pointers to keep track of the start and end of the list
Node* start = NULL;
Node* end = NULL;

// Function prototypes
void menu(void);
void printList();
int isEmpty();
void setData(Node* node, char* value);
void insert(Node* newPtr);
char* delete(char* value);
void printListReverse();
void readData();
void writeData();
void emptyList();

// Main function
int main(void) {
    Node* newPtr = NULL;
    char item[15];

    // Create the starting/ending node
    start = (Node*)malloc(sizeof(Node));
    setData(start, "#");  // Initialize with a special character
    end = start;
    puts("An empty ordered Doubly-LinkedList created.");
    puts("********************************************");

    // Display the menu
    menu();
    printf("%s", "? ");
    unsigned int choice; // User's choice
    scanf("%u", &choice);
    fflush(stdin);

    while (choice != 8) {
        switch (choice) {
        case 1:
            // Insert an element into the list
            printf("Enter a name (Maximum 14 characters):");
            fgets(item, 15, stdin);
            item[strlen(item) - 1] = '\0';  // Remove newline character
            newPtr = (Node*)malloc(sizeof(Node));
            setData(newPtr, item);
            insert(newPtr);
            printList();
            break;
        case 2:
            // Delete an element from the list
            if (!isEmpty()) {
                printf("Enter the character to be deleted:");
                fgets(item, 15, stdin);
                item[strlen(item) - 1] = '\0';  // Remove newline character
                char* found = delete(item);
                if (strcmp(found, "") != 0) {
                    printf("%s deleted\n", item);
                    printList();
                }
                else {
                    printf("%s not found.\n\n", item);
                }
            }
            else {
                puts("List is empty\n");
            }
            break;
        case 3:
            // Print the list from the beginning
            if (isEmpty()) {
                puts("List is empty\n");
            }
            else {
                printList();
            }
            break;
        case 4:
            // Print the list from the end
            if (isEmpty()) {
                puts("List is empty\n");
            }
            else {
                printListReverse();
            }
            break;
        case 5:
            // Read data from an input file and insert it into the list
            readData();
            break;
        case 6:
            // Write the list to an output file
            if (isEmpty()) {
                puts("List is empty\n");
            }
            else {
                writeData();
            }
            break;
        case 7:
            // Empty the list
            if (isEmpty()) {
                puts("List is empty\n");
            }
            else {
                emptyList();
            }
            break;
        default:
            puts("Invalid choice\n");
            break;
        }
        menu();
        printf("%s", "? ");
        scanf("%u", &choice);
        fflush(stdin);
    }
    puts("End of run.");
}

// Display the menu options
void menu(void) {
    puts("Enter your choice:\n"
         "   1 to insert an element into the list.\n"
         "   2 to delete an element from the list.\n"
         "   3 to print the list from the beginning.\n"
         "   4 to print the list from the end.\n"
         "   5 Read some words from input file and insert them to the list.\n"
         "   6 Write the list into the output file.\n"
         "   7 Empty the list.\n"
         "   8 to end.");
}

// Print the list
void printList() {
    Node* curr = start->next;
    puts("The list is:");
    printf("NULL <-->");
    
    while (curr != NULL) {
        printf("%s <--> ", curr->data);
        curr = curr->next;
    }
    puts("NULL\n");
}

// Check if the list is empty
int isEmpty() {
    return start->next == NULL;
}

// Set data in a node
void setData(Node* node, char* value) {
    strcpy(node->data, value);
    node->next = NULL;
    node->prev = NULL;
}

// Insert a new node into the list in its correct location
void insert(Node* newPtr) {
    Node* prevPtr = start;
    Node* curr = start->next;

    while (curr != NULL && strcmp(newPtr->data, curr->data) > 0) {
        prevPtr = curr;
        curr = curr->next;
    }
    newPtr->prev = prevPtr;
    prevPtr->next = newPtr;
    newPtr->next = curr;

    if (curr != NULL) {
        curr->prev = newPtr;
    }
    else {
        end = newPtr;
    }
}

// Delete a node with a specific value from the list
char* delete(char* value) {
    Node* prevPtr = start;
    Node* curr = start->next;

    while (curr != NULL && strcmp(value, curr->data) != 0) {
        prevPtr = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        Node* temp = curr;
        if (curr->next != NULL) {
            curr->next->prev = prevPtr;
        }
        else {
            end = prevPtr;
        }
        prevPtr->next = curr->next;
        free(temp);
        return value;
    }
    else {
        return "";
    }
}

// Print the list in reverse order
void printListReverse() {
    Node* curr = end;
    puts("The list in reverse order is:");
    printf("NULL<-->");
    
    while (curr != start) {
        printf("%s <-->", curr->data);
        curr = curr->prev;
    }
    puts("NULL\n");
}

// Read data from an input file and insert it into the list
void readData() {
    FILE* in;
    if ((in = fopen("input.txt", "r")) == NULL) {
        puts("Input file not found.");
        return;
    }
    char str[15];
    Node* Ptr = NULL;
    
    while (!feof(in)) {
        fscanf(in, "%14s\n", str);
        Ptr = (Node*)malloc(sizeof(Node));
        setData(Ptr, str);
        insert(Ptr);
    }
    fclose(in);
}

// Write the list to an output file
    void writeData() {
        FILE* out;
        if ((out = fopen("output.txt", "w")) == NULL) {
            puts("Output file not found");
            return;
        }
        if (isEmpty()) {
            fprintf(out, "List is empty\n");
        }
        else {
            Node* curr = start->next;
            while (curr != NULL) {
                fprintf(out, "%s\n", curr->data);
                curr = curr->next;
            }
        }
        puts("List is stored in the output file");
        fclose(out);
    }

    // Empty the list by freeing memory
    void emptyList() {
        while (start->next != NULL) {
            Node* curr = start;
            start = start->next;
            free(curr);
        }
        end = start;
    }
