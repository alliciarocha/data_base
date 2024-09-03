#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "patient.h"
#include "exam.h"

//TAD do exame
struct exam{
	int id;
	int rx_id;
	int patient_id;
  int priority;
  int tempo_fila_prioridade;
	char *condition_ia;
};


// função para criar exame
Exam* create_exam(int id, int patient_id, int rx_id, char *condition_ia, int priority, int tempo_fila_prioridade){

  // aloca memória para a estrutura Exam
  Exam* exam = (Exam*)malloc(sizeof(struct exam)); 
  // Verifica se a memória foi alocada corretamente
  if (!exam){
    printf("Erro ao alocar memória!\n");
    exit(1); // Abortar programa caso a memória não foi alocada corretamente
  }
  
  exam->id = id;
  exam->patient_id = patient_id;
  exam->rx_id = rx_id;
  
  exam->condition_ia = (char *)malloc(sizeof(char) * strlen(condition_ia) + 1);
  if (!exam->condition_ia) {
    printf("Erro ao alocar memória\n");
    destroy_exam(exam);
    return NULL;
  }
  strcpy(exam->condition_ia, condition_ia);
  
  exam->priority = priority;
  exam->tempo_fila_prioridade = tempo_fila_prioridade;

  database_exam(exam);

  return exam;
}



// função para desalocar memória da struct exam
void destroy_exam(Exam *exam){
  if (exam)
    free(exam);
}



// função para retornar ID do exame
int get_exam_id(Exam *exam){
  if (!exam) {
    printf("Erro: o ponteiro é NULL\n");
    exit(1);
  }
  return exam->id;
}



// função para retornar ID do paciente do exame
int get_exam_patient_id(Exam *exam){
  if (!exam) {
    printf("Erro: o ponteiro é NULL\n");
    return -1; 
  }
  return exam->patient_id;
}



// função para retornar ID do aparelho do exame
int get_exam_rx_id(Exam *exam){
  if (!exam) {
    printf("Erro: o ponteiro é NULL\n");
    return -1; 
  }
  return exam->rx_id; 
}



// função para retornar a condição diagnosticada pela IA
char *get_exam_condition_ia(Exam *exam){
  if (!exam){
    printf("Erro: o ponteiro é NULL\n");
    return NULL;
  }
  return exam->condition_ia;
}



// função para retornar o nível de prioridade do exame
int get_exam_priority(Exam *exam){
  if (exam == NULL){
    printf("Erro: o ponteiro é NULL\n");
  }
  return exam->priority;
}



// estrutura para retornar data e hora do exame
int get_exam_time(Exam *exam){
  if (exam == NULL) {
    printf("Erro: o ponteiro é NULL\n");
    return 0;
  }
  return exam->tempo_fila_prioridade; 
}



// Imprime as informações do exame criado
void print_exam(Exam *exam)
{
   printf("Exame criado:\n");
   printf("ID do exame: %d\n", get_exam_id(exam));
   printf("ID da máquina: %d\n", get_exam_rx_id(exam));
   printf("Pré diagnóstico: %s\n", get_exam_condition_ia(exam));
   printf("Gravidade: %d", get_exam_priority(exam));
}



// Função para criar e preencher os arquivos(exames))
void database_exam(Exam *exam) {
    FILE *arquivo;

    // Abre o arquivo no modo de escrita, criando-o se não existir
    arquivo = fopen("db_exam.txt", "a");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    // Escreve cada informação em uma linha
    fprintf(arquivo, "ID do exame:     %d\n", exam->id);
    fprintf(arquivo, "ID da máquina:   %d\n", exam->rx_id);
    fprintf(arquivo, "ID do paciente:  %d\n", exam->patient_id);
    fprintf(arquivo, "Diagnóstico IA:  %s\n", exam->condition_ia);
    fprintf(arquivo, "Tempo de espera: %d\n", exam->tempo_fila_prioridade);
    fprintf(arquivo, "\n");
    fclose(arquivo);
}