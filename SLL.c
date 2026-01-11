// Singly Linked List implementation in C

/*
Develop a menu driven C program to perform operations on a
Singly Linked List (SLL) of student data.

Student data fields:
USN
Name
Programme
Semester
Phone Number

Operations to be performed:
1. Create a Singly Linked List of N students using front insertion.
2. Display the contents of the SLL and count the number of nodes.
3. Perform insertion and deletion at the end of the Singly Linked List.
4. Perform insertion and deletion at the front of the Singly Linked List
   (demonstration of stack operations).
5. Exit.
*/

#include <stdio.h>
#include <stdlib.h>

/* Structure definition */
struct student
{
    char usn[20];
    char name[30];
    char prog[20];
    char phno[15];
    int sem;
    struct student *next;
};

struct student *head = NULL;

/* Create a new node */
struct student *create()
{
    struct student *newNode;
    newNode = (struct student *)malloc(sizeof(struct student));

    printf("\nEnter USN: ");
    scanf("%s", newNode->usn);

    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Programme: ");
    scanf("%s", newNode->prog);

    printf("Enter Semester: ");
    scanf("%d", &newNode->sem);

    printf("Enter Phone Number: ");
    scanf("%s", newNode->phno);

    newNode->next = NULL;
    return newNode;
}

/* Create list using front insertion */
void create_list(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        struct student *newNode = create();
        newNode->next = head;
        head = newNode;
    }
}

/* Display list and count nodes */
void display()
{
    struct student *temp = head;
    int count = 0;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nStudent Details:\n");
    printf("-------------------------\n");

    while (temp != NULL)
    {
        printf("USN       : %s\n", temp->usn);
        printf("Name      : %s\n", temp->name);
        printf("Programme : %s\n", temp->prog);
        printf("Semester  : %d\n", temp->sem);
        printf("Phone No  : %s\n", temp->phno);
        printf("-------------------------\n");

        count++;
        temp = temp->next;
    }

    printf("Total number of students: %d\n", count);
}

/* Insert node at end */
void insert_end()
{
    struct student *newNode = create();
    struct student *temp;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Delete node from end */
void delete_end()
{
    struct student *temp = head;

    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Deleted last student.\n");
        return;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    printf("Deleted last student.\n");
}

/* Insert node at front */
void insert_front()
{
    struct student *newNode = create();
    newNode->next = head;
    head = newNode;
}

/* Delete node from front */
void delete_front()
{
    struct student *temp;

    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
    printf("Deleted first student.\n");
}

/* Main function */
int main()
{
    int choice, n;

    while (1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create list using front insertion\n");
        printf("2. Display list and count\n");
        printf("3. Insert at end\n");
        printf("4. Delete from end\n");
        printf("5. Insert at front\n");
        printf("6. Delete from front\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of students: ");
            scanf("%d", &n);
            create_list(n);
            break;

        case 2:
            display();
            break;

        case 3:
            insert_end();
            break;

        case 4:
            delete_end();
            break;

        case 5:
            insert_front();
            break;

        case 6:
            delete_front();
            break;

        case 7:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
