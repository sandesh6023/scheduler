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


int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void test_create_creates_queue_of_intType(){
	Queue *queuePtr;
	int result;
	process *pr;
	process job1 = {1,10,50};
	process job2 = {2,5,30};
	process job3 = {3,7,10};

	queuePtr = create(sizeof(process),3);
	enqueue(queuePtr,&job2);
		pr = (process*)queuePtr->elements;
		printf("jobid===>%d,==>priority %d==>time %d\n",pr->jobId,pr->priority,pr->time);	
	enqueue(queuePtr,&job3);
		pr = (process*)(queuePtr->elements+sizeof(process));
		printf("jobid===>%d,==>priority %d==>time %d\n",pr->jobId,pr->priority,pr->time);	
	result = enqueue(queuePtr,&job1);
		pr = (process*)(queuePtr->elements+(2*sizeof(process)));
		printf("jobid===>%d,==>priority %d==>time %d\n",pr->jobId,pr->priority,pr->time);	
	
	qsort(queuePtr->elements,3,sizeof(process),cmpfunc);
						
						printf("After sort \n\n");	

// sorted based on priority
	pr = (process*)queuePtr->elements;
	printf("jobid===>%d,==>priority %d==>time %d\n",pr->jobId,pr->priority,pr->time);	

	pr = (process*)(queuePtr->elements+sizeof(process));
	printf("jobid===>%d,==>priority %d==>time %d\n",pr->jobId,pr->priority,pr->time);	

	pr = (process*)(queuePtr->elements+(2*sizeof(process)));
	printf("jobid===>%d,==>priority %d==>time %d\n",pr->jobId,pr->priority,pr->time);	

}
