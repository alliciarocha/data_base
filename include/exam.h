#ifndef EXAM_H
#define EXAM_H
#include <time.h>

typedef struct exam Exam;

Exam* create_exam(int id, int patient_id, int rx_id, char *condition_ia, int priority, int tempo_fila_prioridade);
void destroy_exam(Exam *exam);
int get_exam_id(Exam *exam);
int get_exam_patient_id(Exam *exam);
int get_exam_rx_id(Exam *exam);
char *get_exam_condition_ia(Exam *exam);
int get_exam_priority(Exam *exam);
int get_exam_time(Exam *exam);
void print_exam(Exam *exam);
void database_exam(Exam *exam);

#endif