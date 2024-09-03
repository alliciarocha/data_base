#ifndef PATIENT_H
#define PATIENT_H
#include <time.h>

typedef struct patient Patient;

Patient *create_patient(int id, char *nome, int hora_chegada, int tempo_de_espera);
int get_patient_id(Patient *patient);
const char *get_patient_name(Patient *patient);
void print_patient(Patient *patient);
void destroy_patient(Patient *patient);
void database_patient(Patient *patient);

#endif