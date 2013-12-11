#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  #define MAXJOBS 100

  struct job {
        char name[100];
        int jobid, priority, order;
  };

  struct pQueue {
        struct job node[MAXJOBS];
        int front, rear;
  };

  int jobCount = 0;

  /* enqeue operation */
  void enqueue(struct pQueue *pq, struct job myJob) {
        struct job temp;
        int i, j;

        if (pq->front == MAXJOBS - 1) {
                printf("Enqueue operation failed - PQ is full\n");
                return;
        } else if (pq->front == -1) {
                pq->front = 0;
        }
        pq->rear++;
        pq->node[pq->rear] = myJob;
        for (i = pq->front; i < pq->rear; i++) {
                for (j = i + 1; j <= pq->rear; j++) {
                        /* place the node with high priority at the front */
                        if (pq->node[i].priority < pq->node[j].priority) {
                                temp = pq->node[i];
                                pq->node[i] = pq->node[j];
                                pq->node[j] = temp;
                        } else  if (pq->node[i].priority ==
                                        pq->node[j].priority) {
                                /*
                                 * if both elements have same priority, then the
                                 * element with lesser order is processed first
                                 */
                                if (pq->node[i].order > pq->node[j].order) {
                                        temp = pq->node[i];
                                        pq->node[i] = pq->node[j];
                                        pq->node[j] = temp;
                                }
                        }
                }
        }
        return;
  }

  /* dequeue operation */
  void dequeue(struct pQueue *pq) {
        if (pq->front == -1) {
                printf("Priority Queue underflow\n");
                return;
        }

        if (pq->front == pq->rear) {
                pq->front = pq->rear = -1;
        } else {
                printf("Dequeued Data:\n");
                printf("Job Name : %s\n", pq->node[pq->front].name);
                printf("Job ID   : %d\n", pq->node[pq->front].jobid);
                printf("Priority : %d\n", pq->node[pq->front].priority);
                printf("Order    : %d\n", pq->node[pq->front].order);
                pq->front++;
        }
        return;
  }

  /* dump the contents of the queue */
  void dumpQueue(struct pQueue *pq) {
        int i;
        if (pq->front == -1) {
                printf("Priority Queue Underflow\n");
                return;
        }

        printf("Job Name    JobID  Priority  Order\n");
        printf("-------------------------------------\n");
        for (i = pq->front; i <= pq->rear; i++) {
                printf("%8s%5d%9d%5d\n", pq->node[i].name, pq->node[i].jobid,
                        pq->node[i].priority, pq->node[i].order);
        }
        return;
  }

  int main() {
        struct pQueue pq;
        struct job myJob;
        int i, ch, order = 0;

        memset(&pq, 0, sizeof (struct pQueue));
        pq.front = pq.rear = -1;
        while (1) {
                printf("1. Add new Job(Enqueue)\t");
                printf("2. Dequeue\n3. Dump Queue\t");
                printf("4. Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                getchar();
                                printf("Enter the job name:");
                                fgets(myJob.name, 100, stdin);
                                myJob.name[strlen(myJob.name) - 1] = '\0';
                                printf("Job ID: ");
                                scanf("%d", &myJob.jobid);
                                printf("Priority: ");
                                scanf("%d", &myJob.priority);
                                myJob.order = order++;
                                enqueue(&pq, myJob);
                                break;

                        case 2:
                                dequeue(&pq);
                                break;

                        case 3:
                                dumpQueue(&pq);
                                break;

                        case 4:
                                exit(0);
                        default:

                                printf("U have entered wrong option!!\n");

                                break;
                }
        }
        return 0;
  }