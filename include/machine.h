#ifndef MACHINE_H
#define MACHINE_H
#include <time.h>
#include "exam.h"

typedef struct maquina Maquina;

Maquina* criar_maquinas(int num_maquinas);
int get_rxMachine_id(Maquina *maquina);
Maquina *encontrar_maquina_livre(Maquina  *cabeca);
void atribuir_paciente(Maquina *maquina, Exam *exam, int *indic_maquina_free);
void atualizar_tempo(Maquina *cabeca);
int contar_maquinas_livres(Maquina *cabeca);
void print_info_maquina(Maquina *cabeca);

#endif