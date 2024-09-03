# Simulação de Realização de Exames de Raio-X
Este trabalho prático de programação visa simular o processo de exames de raio-X de tórax e diagnóstico em um hospital, com foco na organização das filas em diferentes etapas. Pacientes chegam ao hospital e são atendidos conforme a disponibilidade dos equipamentos. Uma IA sugere diagnósticos preliminares, e os exames são encaminhados para laudo médico.

## Principais arquivos
### `Patient`
#### Estrutura `Patient`
| Variáveis | Tipo |Função |
| :---:        |     :---:      | :---: |
| id  | int | Armazena a Identificação Única (id) do paciente  |
| nome   | char* | Armazena o nome do paciente     |
| hora_chegada     | int      | Armazena o tempo de chegada do paciente      |

#### Funções do `Patient` 
| Funções | Descrição | Parâmetros | Retorna |
|:---:|:---:|:---:|:---:|
| create_patient | Cria um novo paciente | int id , char *nome, int hora_chegada e int tempo_de_espera| Patient* |
| get_patient_id | Retorna o id do paciente | Patient *patient | int |
| get_patient_name | Retorna o nome do paciente | Patient *patient | const char*  |
| print_patient | Imprime na tela as informações do paciente | Patient *patient | void |
| destroy_patient | Destroí o registro de um paciente | Patient *patient | void |
| database_patient | Registra no db.patient.txt as informações do paciente | Patient *patient | void |

### `Exam`
#### Estrutura `Exam`
| Variáveis | Tipo |Função |
| :---:        |     :---:      | :---: |
| id  | int | Armazena o id do exame  |
| rx_id   | int | Armazena o id da máquina de raio-X     |
| patient_id    | int | Armazena o id do paciente      |
| priority   | int | Armazena a gravidade da doença do paciente |
| tempo_fila_prioridade | int | Armazena o tempo na fila de prioridade |
| condition_IA    | char* | Armazena o pré-diagnóstico do paciente|

#### Funções do `Exam` 
| Funções | Descrição | Parâmetros | Retorna |
|:---:|:---:|:---:|:---:|
| create_exam | Cria um novo exame | int id, int patient_id, int rx_id, char *condition_ia, int priority, int tempo_fila_prioridade| Exam* |
| destroy_exam | Destroí o registro do exame | Exam *exam | void |
|  get_exam_id | Retorna o id do exame | Exam *exam | int |
|  get_exam_patient_id | Retorna o id do paciente | Exam *exam | int |
|  get_exam_rx_id | Retorna o id da máquina de raio-X | Exam *exam | int |
|  get_exam_condition_ia | Retorna o pré-diagnóstico do paciente | Exam *exam | char* |
|  get_exam_priority | Retorna a gravidade do exame | Exam *exam | int |
|  get_exam_time | Retorna o tempo em que foi feito o exame| Exam *exam | int |
|  print_exam | Imprime na tela as informações do exame | Exam *exam | void |
|  database_exam | Registra no db.exam.txt as informações do exame | Exam *exam | void |

### `Queue`
#### Estrutura `Queue`
| Variáveis | Tipo |Função |
| :---:        |     :---:      | :---: |
| front   | QueueNode* | Ponteiro que aponta para o primeiro elemento da fila  |
| rear | QueueNode* | Ponteiro que aponta para o último elemento da fila    |

#### Estrutura `QueueNode`
| Variáveis | Tipo |Função |
| :---:        |     :---:      | :---: |
| info   | Exam* | Ponteiro que aponta para algum exame  |
| next | QueueNode* | Ponteiro que o próximo nó da fila  |

#### Funções do `Queue`
A queue foi implementada para ser genérica.
| Funções | Descrição | Parâmetros | Retorna |
|:---:|:---:|:---:|:---:|
| q_create | Cria uma fila | void | Queue* |
| q_is_empty | Verifica se a fila está vazia | Queue *q | int |
| q_enqueue | Adiciona um novo paciente na fila | Queue *q,  StructType type, void *p | void |
| q_dequeue | Remove um paciente na fila | Queue *q | void |
| q_free | Liberar memória alocada para criar fila | Queue *q | void |
| q_print| Conta o número de máquinas livres | Queue *q | void |

## Como executar:
- 1º Baixe e descompacte o código;
- 2º No terminal linux, execute: make.
  
## Criadores:
- Allicia Rocha
- Vitor Ramos
