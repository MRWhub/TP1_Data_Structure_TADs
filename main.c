#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "exam.h"
#include "patient.h"
#include "sleep.h"

int main() {
    struct tm birthdate = {0};
    birthdate.tm_year = 90;
    birthdate.tm_mon = 5;
    birthdate.tm_mday = 15;


    Patient *patient = create_patient(1, "João Silva", &birthdate);

    printf("Paciente criado!!\n");
    printf("ID: %d\n", get_patient_id(patient));
    printf("Nome: %s\n", get_patient_name(patient));
    printf("Data de Nascimento: %s\n",asctime(get_patient_birthdate(patient)));

    time_t current_time;
    struct tm *exam_time;

    current_time = time(NULL);
    exam_time = localtime(&current_time);

    Exam *new_exam = create_exam(101, get_patient_id(patient), 1, exam_time);

    printf("\nExame Criado!!\n");
    printf("Exam ID: %d\n", get_exam_id(new_exam));
    printf("ID do Paciente: %d\n", get_exam_patient_id(new_exam));
    printf("ID da Máquina: %d\n", get_exam_rx_id(new_exam));
    printf("Data e Hora do Exame: %s\n", asctime(get_exam_time(new_exam)));

    destroy_exam(new_exam);
    destroy_patient(patient);

    stopping(5);



    return 0;
}
