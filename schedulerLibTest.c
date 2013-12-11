#include "testUtils.h"
#include "schedulerLib.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(Queue a, Queue b)
{
	int result;
	result = a.elementSize==b.elementSize && a.noOfElements == b.noOfElements
				&& a.front==b.front && a.rear == b.rear;
	if(!result)	return 0;
	return 0 == memcmp(a.elements,b.elements,a.elementSize*a.noOfElements);
}

void test_create_creates_queue_of_intType(){
	Queue *queuePtr;
	int result;
	process *pr;
	process job1 = {1,10,1000};
	
	queuePtr = create(sizeof(process),4);
	result = enqueue(queuePtr,&job1);
	pr = (process*)queuePtr->elements;
	// printf("%d\n",(process*)queuePtr->elements);
	printf("\n\n%d",pr->jobId);	
}
// void test_Enqueue_FloatElement_into_queue_through_rearEnd(){
// 	// float inputElement = 9.223f;
// 	// float input2 = 7.989f;
// 	// Queue *queuePtr;
// 	// int result;
// 	// float floatArray[4] = {9.223f,7.989f,0.0,0.0};
// 	// Queue expectedQueue = {floatArray,sizeof(float),0,1,4};
// 	// queuePtr = create(sizeof(float),4);
// 	// enqueue(queuePtr,&inputElement);
// 	result = enqueue(queuePtr,&input2);
// 	ASSERT(areEqual(expectedQueue,*queuePtr));
// }