#include <stdio.h>
#include <stdlib.h>

#define N 5 // Size of the circular queue

int queue[N];   // Array to store queue elements
int front = -1; // Front pointer
int rear = -1;  // Rear pointer

// Function to insert an element into the circular queue
void enqueue(int x)
{
    // If queue is empty
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    // If queue is full
    else if ((rear + 1) % N == front)
    {
        printf("Queue is full");
    }
    // Normal insertion
    else
    {
        rear = (rear + 1) % N; // Move rear circularly
        queue[rear] = x;
    }
}

// Function to delete an element from the circular queue
void dequeue()
{
    // If queue is empty
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
    }
    // If only one element is present
    else if (front == rear)
    {
        printf("Dequeued element : %d", queue[front]);
        front = rear = -1; // Queue becomes empty
    }
    // If more than one element is present
    else
    {
        printf("Dequeued element : %d", queue[front]);
        front = (front + 1) % N; // Move front circularly
    }
}

// Function to display all elements of the queue
void display()
{
    int i = front;

    // If queue is empty
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue is ");
        // Traverse from front to rear circularly
        while (i != rear)
        {
            printf("%d\t", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d", queue[rear]); // Print last element
    }
}

// Function to check queue status
void checkstatus()
{
    // Underflow condition
    if (front == -1 && rear == -1)
    {
        printf("Underflow");
    }
    // Overflow condition
    else if ((rear + 1) % N == front)
    {
        printf("Overflow");
    }
    // Normal condition
    else
    {
        printf("Queue is neither full nor empty");
    }
}

int main()
{
    int ch, x;

    // Infinite loop for menu-driven program
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Check status\n5.Exit");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to Enqueue : ");
            scanf("%d", &x);
            enqueue(x);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            checkstatus();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice! try again");
        }
    }
}
