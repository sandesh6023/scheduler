typedef struct{
	void *elements;
	int elementSize;
	int front;
	int rear;
	int noOfElements;
}Queue;

typedef char String[256];

typedef struct 
{
	int priority;
	int jobId;
	int time;
}process;


Queue* create(int typeSize, int noOfElements);
int enqueue(Queue *queue , void *inputElement);
void* dequeue(Queue *queue);