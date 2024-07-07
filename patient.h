#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED
#include <time.h>

typedef struct patient Patient;

Patient *create_patient(int id, const char *name, struct tm *birthdate);

void destroy_patient(Patient *patient);

int get_patient_id(Patient *patient);

char *get_patient_name(Patient *patient);

struct tm *get_patient_birthdate(Patient *patient);

#endif // PATIENT_H_INCLUDED
