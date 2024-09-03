#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include "priority_queue.h"
#include "exam.h"

struct priority_queue_node {
    Exam *info; 
    PriorityQueueNode *next;
};


struct priority_queue {
    PriorityQueueNode *front; 
};


PriorityQueue *pq_create() {
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->front = NULL;
    return pq;
}

void pq_enqueue(PriorityQueue*pq, Exam *e) {
    PriorityQueueNode *node = (PriorityQueueNode *)malloc(sizeof(PriorityQueueNode));
    node->info = e;
    node->next = NULL;

    int priority = get_exam_priority(e);
    PriorityQueueNode *current = pq->front;
    
    if (pq->front == NULL) {
        // node->next = pq->front;
        pq->front = node;
    }else { 
        if (get_exam_priority(pq->front->info) < priority){
            node->next = pq->front;
            pq->front = node;

        } else {
            //printf("\nelse flag");
            while (current->next != NULL && get_exam_priority(current->next->info) >= priority) {
            // current->next->info->priority >= priority) {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }   
}

Exam *pq_dequeue(struct priority_queue *pq) {
    if(pq->front == NULL)
        return NULL;

    struct priority_queue_node *temp = pq->front;
    Exam *e = temp->info;

    pq->front = pq->front->next;
    free(temp);

    return e;
}

void pq_free(struct priority_queue *pq) {
    struct priority_queue_node *p = pq->front;
    while (p != NULL) {
        struct priority_queue_node *t = p->next;
        free(p);
        p = t;
    }
    free(pq);
}

void pq_print(struct priority_queue *pq) {
    struct priority_queue_node *p = pq->front;
    while (p != NULL) {
        printf("\nPrioridade: %d\n", get_exam_priority(p->info));

        // Imprima outros campos, se necessário
        p = p->next;
    }
}

void pq_test(){
    // Exam* create_exam(int id, int patient_id, int rx_id, char *condition_ia, int priority, int tempo_fila_prioridade){
    // id counters
    int patient_id_counter = 1;
    int exam_id_counter = 1;

    // Instante de tempo para teste
    int time = 1;

    PriorityQueue *ExamPriorityQueue = pq_create();

    char* condition = "Muito sono";

    Exam *new_aexam;

    // Instanciamentos de exames com nivel de gravidade diferentes.
    new_aexam = create_exam(exam_id_counter++, 1, (1), "doente", 5, 10);

    pq_enqueue(ExamPriorityQueue,new_aexam);

    new_aexam = create_exam(exam_id_counter++, 2, (1), "doente", 2, 10);

    pq_enqueue(ExamPriorityQueue,new_aexam);

    new_aexam = create_exam(exam_id_counter++, 3, (1), "doente", 3, 10);

    pq_enqueue(ExamPriorityQueue,new_aexam);

    new_aexam = create_exam(exam_id_counter++, 4, (1), "doente", 1, 10);

    pq_enqueue(ExamPriorityQueue,new_aexam);

    new_aexam = create_exam(exam_id_counter++, 5, (1), "doente", 4, 10);

    pq_enqueue(ExamPriorityQueue,new_aexam);

    new_aexam = create_exam(exam_id_counter++, 6, (1), "doente", 5, 10);

    pq_enqueue(ExamPriorityQueue,new_aexam);

    new_aexam = create_exam(exam_id_counter++, 7, (1), "doente", 3, 10);

    pq_enqueue(ExamPriorityQueue,new_aexam);

    new_aexam = create_exam(exam_id_counter++, 8, (1), "doente", 5, 10);

    pq_enqueue(ExamPriorityQueue,new_aexam);

    new_aexam = create_exam(exam_id_counter++, 9, (1), "doente", 4, 10);

    pq_enqueue(ExamPriorityQueue,new_aexam);

    new_aexam = create_exam(exam_id_counter++, 10, (1), "doente", 1, 10);

    pq_enqueue(ExamPriorityQueue,new_aexam);

    pq_print(ExamPriorityQueue); // Checagem na tela se a função enfileirou corretamente.
}