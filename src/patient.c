#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include <time.h>

// Estrutura do paciente
struct patient{
	int id;
	char *nome;
	int hora_chegada;
};

Patient *create_patient(int id, char *nome, int hora_chegada,int tempo_de_espera) {

  if (!nome) {
    printf("Erro: o ponteiro nome não aponta para nenhum endereço de memória corretamente\n");
    exit(1);
  }
  
  Patient *patient = malloc(sizeof(struct patient));
  if (!patient) {
    printf("Erro ao alocar memória\n");
    exit(1);
  }

  // Atribui o ID do paciente
  patient->id = id;

  // Atribui 0 ao tempo de espera
  patient->hora_chegada = hora_chegada;

  // Aloca memória para o nome do paciente e verifica se a memória foi alocada corretamente
  patient->nome = (char *)malloc(sizeof(char) * strlen(nome) + 1);
  
  if (!patient->nome) {
    printf("Erro ao alocar memória\n");
    destroy_patient(patient); 
    exit(1); 
  }

  // Copia o nome do paciente para a atribuição do nome do paciente
  strcpy(patient->nome, nome); 
  
  // Atribui a hora_chegada do paciente
  patient->hora_chegada = hora_chegada;

  //salva dados do paciente em db_patient.txt
  database_patient(patient);

  return patient;
}



// Função para retornar ID do paciente
int get_patient_id(Patient *patient) {
  if (!patient) {
    printf("Erro: o ponteiro é NULL\n");
    exit(1);
  }
  
  return patient->id;
}



// Função para retornar o nome do paciente
const char *get_patient_name(Patient *patient) {
  if (!patient) {
    printf("Erro: o ponteiro é NULL\n");
    exit(1); 
  }
  return patient->nome; 
}



// Imprime as informações do paciente criado
void print_patient(Patient *patient)
{
   printf("Paciente criado:\n");
   printf("ID: %d\n", get_patient_id(patient));
   printf("Nome: %s\n", get_patient_name(patient));
}



// Função para destruir alocação do paciente
void destroy_patient(Patient *patient) {
  if (!patient) {
    free(patient);
    free(patient->nome);
  }
}


// Função para criar e preencher os arquivos(pacientes)
void database_patient(Patient *patient) {
    FILE *arquivo;

    // Abre o arquivo no modo de escrita, criando-o se não existir
    arquivo = fopen("db_patient.txt", "a");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    // Escreve cada informação em uma linha
    fprintf(arquivo, "ID do paciente:      %d\n", patient->id);
    fprintf(arquivo, "Nome do paciente:    %s\n", patient->nome);
    fprintf(arquivo, "Horário de check in: %d\n", patient->hora_chegada);
    fprintf(arquivo, "\n");
    fclose(arquivo);
    
}