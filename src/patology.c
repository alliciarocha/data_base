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

struct patology{
    char *nome_patologia;
    int prioridade;
};

Patology *create_pathology(){
  Patology *pre_diagnostico = (Patology *)malloc(sizeof(Patology));

  char *disease = gerar_disease();

  if (!pre_diagnostico) {
    printf("Erro ao alocar memória\n");
    exit(1);
  }
 
  pre_diagnostico->nome_patologia = (char *)malloc(sizeof(char) * strlen(disease) + 1);
  
  if (strcmp(disease, "Saúde normal") == 0){
    int gravidade = 1;
    pre_diagnostico->prioridade = gravidade;
    strcpy(pre_diagnostico->nome_patologia, disease);
  }
  else if (strcmp(disease, "Bronquite") == 0){
    int gravidade = 2;
    pre_diagnostico->prioridade = gravidade;
    strcpy(pre_diagnostico->nome_patologia, disease);
  }
  else if (strcmp(disease, "Pneumonia") == 0){
    int gravidade = 3;
    pre_diagnostico->prioridade = gravidade;
    strcpy(pre_diagnostico->nome_patologia, disease);
  }
  else if (strcmp(disease, "COVID") == 0){
    int gravidade = 4;
    pre_diagnostico->prioridade = gravidade;
    strcpy(pre_diagnostico->nome_patologia, disease);
  }
  else if (strcmp(disease, "Embolia pulmonar") == 0){
    int gravidade = 4;
    pre_diagnostico->prioridade = gravidade;
    strcpy(pre_diagnostico->nome_patologia, disease);
  }
  else if (strcmp(disease, "Derrame pleural") == 0){
    int gravidade = 4;
    pre_diagnostico->prioridade = gravidade;
    strcpy(pre_diagnostico->nome_patologia, disease);
  }
  else if (strcmp(disease, "Fibrose pulmonar") == 0){
    int gravidade = 5;
    pre_diagnostico->prioridade = gravidade;
    strcpy(pre_diagnostico->nome_patologia, disease);
  }
  else if (strcmp(disease, "Tuberculose") == 0){
    int gravidade = 5;
    pre_diagnostico->prioridade = gravidade;
    strcpy(pre_diagnostico->nome_patologia, disease);
  }
  else if (strcmp(disease, "Câncer de pulmão") == 0){
    int gravidade = 6;
    pre_diagnostico->prioridade = gravidade;
    strcpy(pre_diagnostico->nome_patologia, disease);
  }

  return pre_diagnostico;
}

const char *get_disease_name(Patology *pathology) {
  if (!pathology) {
    printf("Erro: o ponteiro é NULL\n");
    exit(1); 
  }
  return pathology->nome_patologia; 
}

int get_priority_disease(Patology *pathology){
  return pathology->prioridade;
}

// função para gerar doença
char *gerar_disease() {
  srand(time(NULL));

  char *diseases[] = {
    "Saúde normal",
    "Bronquite",
    "Pneumonia",
    "COVID",
    "Embolia pulmonar",
    "Derrame pleural",
    "Fibrose pulmonar",
    "Tuberculose",
    "Câncer de pulmão"
  };

  static const double probabilidades[] = {0.3, 0.5, 0.6, 0.7, 0.75, 0.80, 0.85, 0.9, 1};
  double prob_aleatoria = (double)rand() / RAND_MAX;

  for (int i = 0; i < 9; i++) {
    if (prob_aleatoria <= probabilidades[i]) {
      return diseases[i];
    }
  }
  return diseases[0]; // Caso alguma condição não seja atendida
}

void destroy_patology(Patology *pathology) {
  if (!pathology) {
    free(pathology->nome_patologia);
    free(pathology);
  }
}