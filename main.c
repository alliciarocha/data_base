#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "exam.h"
#include "patient.h"
#include "queue.h"
#include "machine.h"
#include "patology.h"
#include "priority_queue.h"

#define PROBABILIDADE_CHEGADA 20
#define NUMERO_ITERACOES 7200
#define QUANT_MAQUINAS 5 
#define TEMPO_MAQUINA 10

int main() {
    // Cria lista de pacientes
    Queue *patient_queue = q_create();
    
    // Cria máquinas de raio-X
    Patient *xr_machine[QUANT_MAQUINAS] = {NULL};

    // Tempo restante para cada máquina
    int tempo_xr_machine[QUANT_MAQUINAS] = {0};

    int tempo = 0;
    int patient_id = 0;
    int total_pacientes = 0;
    int exam_id = 0;
    srand(time(NULL));

    for (int i = 0; i < NUMERO_ITERACOES; i++) {
        tempo++;
        // printf("\nTempo: %d\n", tempo);

        // Gera um número aleatório entre 1 e 100
        int numeroAleatorio = rand() % 100 + 1;

        // Verifica se o número aleatório está dentro da faixa da probabilidade
        if (numeroAleatorio < PROBABILIDADE_CHEGADA) {
            printf("\nNovo paciente chegou!\n");
            // Cria novo paciente
            Patient *new_patient = create_patient(patient_id, "João", tempo, 0);
            
            // Adiciona paciente no arquivo db_patient.txt
            database_patient(new_patient);

            // Adiciona paciente na fila dos pacientes 
            q_enqueue(patient_queue, TIPO_PATIENT, new_patient);

            // Imprime informações do novo paciente
            print_patient(new_patient);
            
            // Conta total de pacientes 
            total_pacientes++;
            patient_id++;
        }

        // Verifica o estado das máquinas e atualiza o tempo restante
        for (int j = 0; j < QUANT_MAQUINAS; j++) {
            if (xr_machine[j] != NULL) {
                tempo_xr_machine[j]--;
                if (tempo_xr_machine[j] <= 0) {
                    // O exame foi concluído e a máquina está livre
                    printf("Máquina %d liberada\n", j);
                    xr_machine[j] = NULL;
                }
            }
        }

        // Verifica se há pacientes na fila e máquinas livres
        for (int j = 0; j < QUANT_MAQUINAS; j++) {
            if (xr_machine[j] == NULL && !q_is_empty(patient_queue)) {
                // Retiro paciente da fila para colocar em alguma máquina
                Patient *p = (Patient*)q_dequeue(patient_queue);

                // Coloco paciente em uma máquina livre
                xr_machine[j] = p;
                // Atualizo o tempo da máquina
                tempo_xr_machine[j] = TEMPO_MAQUINA;
            }
        }

        // Processo de exame de raio-X
        for (int k = 0; k < QUANT_MAQUINAS; k++) {
            if (xr_machine[k] != NULL && tempo_xr_machine[k] == 0) {
                // Paciente entrou na máquina e exame está concluído
                Patient *p = (Patient*)xr_machine[k];

                // Criar exame para o paciente
                // Gerar patologia por meio de IA
                Patology *pre_diagnostico = create_pathology();
                Exam *e = create_exam(exam_id, get_patient_id(p), k, "Normal", get_priority_disease(pre_diagnostico), tempo);
                database_exam(e);
                exam_id++;

                // A máquina será liberada após o exame
                xr_machine[k] = NULL;
                tempo_xr_machine[k] = 0;
            }
        }
    }
    
    printf("\nNúmero total de pacientes que visitaram o hospital: %d\n", total_pacientes);
    return 0;
}
