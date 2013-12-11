#include "schedulerLib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Queue* create(int typeSize, int noOfElements)
{
	Queue *queue = malloc(sizeof(Queue));
	queue->elements = calloc(noOfElements,typeSize);
	queue->noOfElements = noOfElements;
	queue->elementSize = typeSize;
	queue->front = 0;
	queue->rear = -1;
	return queue;	
}

int enqueue(Queue *queue, void *inputElement){
	
	if(queue->rear == queue->noOfElements-1) return 0;
	queue->rear = queue->rear + 1;
	memcpy(queue->elements+(queue->rear*queue->elementSize),inputElement,queue->elementSize);
	return 1;
}

void* dequeue(Queue *queue){
	void* removedElement;
	if(queue->rear == -1) return NULL;
	removedElement = queue->elements + (queue->front * queue->elementSize);
	queue->front = queue->front + 1;	
		return removedElement; 
}