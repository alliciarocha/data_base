#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "patient.h"
#include "exam.h"

typedef struct priority_queue_node PriorityQueueNode;
typedef struct priority_queue PriorityQueue;


PriorityQueue *pq_create();

void pq_enqueue(PriorityQueue *pq, Exam *e);

Exam *pq_dequeue(PriorityQueue *pq);


void pq_free(struct priority_queue *pq);
void pq_print(struct priority_queue *pq);
void pq_test();


#endif