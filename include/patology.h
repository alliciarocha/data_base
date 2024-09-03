#ifndef PATOLOGY_H
#define PATOLOGY_H

typedef struct patology Patology;

char *gerar_disease();
Patology *create_pathology();
const char *get_disease_name(Patology *pathology);
int get_priority_disease(Patology *pre_diagnostico);
void destroy_patology(Patology *pathology);

#endif