#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "machine.h"
#include "patient.h"
#include "exam.h"
#include "patology.h"
#include "functions.h"

//TAD da máquina
struct maquina{
	int rx_id;
	int tempo_restante;
    int estado; 
	Maquina *proxima;
	Exam *paciente_atendido;
	Exam *paciente_em_atendimento;
};

struct exam{
	int id;
	int rx_id;
	int patient_id;
    int priority;
    int tempo_fila_prioridade;
	char *condition_ia;
};

struct patology{
    char *nome_patologia;
    int prioridade;
};

// Função para criar as maquinas
Maquina* criar_maquinas(int num_maquinas)
{

    Maquina  *cabeca = NULL; // Inicializa a cabeça da lista como NULL

    Maquina  *nova, *atual = NULL;
    for (int i = 0; i < num_maquinas; i++) {
        nova = (Maquina  *)malloc(sizeof(Maquina));
        nova->rx_id = i;
        nova->estado = 0; // Inicialmente livre
        nova->tempo_restante = 0;
        nova->paciente_atendido = NULL;
        nova->paciente_em_atendimento = NULL;
        nova->proxima = NULL;

        if (cabeca == NULL) {
            cabeca = nova; // A primeira máquina se torna a cabeça da lista
        } else {
            atual->proxima = nova; // As máquinas subsequentes são adicionadas ao final da lista
        }
        atual = nova; // Atualizamos o ponteiro 'atual' para apontar para a nova máquina
    }
    return cabeca;
}



// Função para retornar ID da maquina
int get_rxMachine_id(Maquina *maquina) {
  if (!maquina) {
    printf("Erro: o ponteiro é NULL\n");
    exit(1);
  }
  return maquina->rx_id;
}


// Função para encontrar uma máquina livre
Maquina *encontrar_maquina_livre(Maquina  *cabeca) {
    Maquina  *atual = cabeca;
    while (atual != NULL) {
        if (atual->estado == 0) {
            return atual;
        }
        atual = atual->proxima;
    }
    return NULL;
}



// Função para atribuir um paciente a uma máquina
void atribuir_paciente(Maquina *maquina, Exam *exam, int *indic_maquina_free){

    Maquina *maquina_livre = encontrar_maquina_livre(maquina);
    if (maquina_livre != NULL){
        maquina_livre->estado = 1;
        maquina_livre->tempo_restante = 1;
        maquina_livre->paciente_em_atendimento = exam;

        printf("Paciente %d alocado na máquina %d",get_exam_patient_id(exam),get_rxMachine_id(maquina_livre));
        *indic_maquina_free = 1;
    }
    else{
        printf("\nTodas as máquinas estão ocupadas! Aguarde na fila de espera!");
        *indic_maquina_free = 0;
    }
}



// Função para atualizar o tempo
void atualizar_tempo(Maquina *cabeca) {

    Maquina *atual = cabeca;
    while(atual != NULL){

        atual->tempo_restante--;
        if (atual->tempo_restante == 0){
            printf("\nMáquina %d liberada",atual->rx_id);

            // gerar condição 
            Patology *condition_ia = create_pathology();

            char *nome_condition_ia = get_disease_name(condition_ia);
            atual->paciente_em_atendimento->condition_ia = (char *)malloc(sizeof(char) * strlen(nome_condition_ia) + 1);
            atual->paciente_em_atendimento->condition_ia = (char *)malloc(sizeof(char) * (strlen(nome_condition_ia) + 1));
            
            strcpy(atual->paciente_em_atendimento->condition_ia, nome_condition_ia);
            atual->paciente_em_atendimento->priority = get_priority_disease(condition_ia);
            destroy_patology(condition_ia);
            
            atual->paciente_atendido = atual->paciente_em_atendimento;
            atual->paciente_em_atendimento = NULL;
            atual->estado = 0;
        }
       atual = atual->proxima;
    }  
}



// função para contar máquinas livres
int contar_maquinas_livres(Maquina *cabeca){
    
    int num_maquinas_free = 0;
    Maquina  *atual = cabeca;

    while (atual != NULL) {
        if (atual->estado == 0) {
            num_maquinas_free++;
        }
        atual = atual->proxima;
     }
    return num_maquinas_free;
}



void print_info_maquina(Maquina *cabeca){
    Maquina *atual = cabeca;
    while (atual != NULL){
        if (atual->paciente_atendido != NULL){
            printf("%s", get_exam_condition_ia(atual->paciente_atendido));
        }
        atual = atual->proxima;
    }
}