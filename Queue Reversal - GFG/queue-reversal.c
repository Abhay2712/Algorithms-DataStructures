// { Driver Code Starts
//Initial Template for C

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}
 
// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}
 
// Function to remove an item from queue.
// It changes front and size
void dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return ;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
}
 
// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get size of queue
int size(struct Queue* queue)
{
    return queue->size;
}
 


 // } Driver Code Ends
//User function Template for C

/* 
//A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
struct Queue* createQueue(unsigned capacity);

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue);
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue);
 
// Function to add an item to the queue.
void enqueue(struct Queue* queue, int item);
 
// Function to remove an item from queue.
void dequeue(struct Queue* queue);
 
// Function to get front of queue
int front(struct Queue* queue);

// Function to get size of queue
int size(struct Queue* queue);
*/

//Function to reverse the queue.
struct Queue* rev(struct Queue* Q)
{
    if(isEmpty(Q)) {
        return -1;
    }
    
    int data = front(Q);
    dequeue(Q);
    
    rev(Q);
    
    enqueue(Q, data);
}

// { Driver Code Starts.

int main() {
	
	int t;
	scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        struct Queue* q = createQueue(n);
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            enqueue(q,x);
        }
        struct Queue* ans = rev(q);
        while(!isEmpty(ans))
        {
            printf("%d ",front(ans));
            dequeue(ans);
        }
        printf("\n");
        	    
    }
	return 0;
}
  // } Driver Code Ends