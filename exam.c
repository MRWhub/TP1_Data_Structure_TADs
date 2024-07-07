#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "exam.h"

struct exam{
    int id;
    int patient_id;
    int rx_id;
    struct tm *time;


};


Exam *create_exam(int id, int patient_id, int rx_id, struct tm *time) {
    /** \brief This function creates an exam object // Esta fun��o cria um objeto de exame
     *
     * \param id - Unique exam identification // Identifica��o �nica do exame
     * \param patient_id - ID of the patient associated with the exam // ID do paciente associado ao exame
     * \param rx_id - ID of the machine used for the exam // ID da m�quina usada para o exame
     * \param time - Pointer to a tm structure with the exam time // Ponteiro para uma estrutura tm com o hor�rio do exame
     * \return The created exam object // O objeto de exame criado
     *
     * \details This function allocates memory for a new exam and initializes its fields with the given values.
     *          The tm structure passed as a parameter is copied to the new exam structure.
     *          If memory allocation fails, the function prints an error message and returns NULL.
     * \details Esta fun��o aloca mem�ria para um novo exame e inicializa seus campos com os valores fornecidos.
     *          A estrutura tm passada como par�metro � copiada para a nova estrutura de exame.
     *          Se a aloca��o de mem�ria falhar, a fun��o imprime uma mensagem de erro e retorna NULL.
     *
     * \warning If memory allocation fails, the function prints an error message and returns NULL.
     *          Se a aloca��o de mem�ria falhar, a fun��o imprime uma mensagem de erro e retorna NULL.
     */

    /* Checks if the time pointer is NULL // Verifica se o ponteiro de time � nulo */
    if (!time) {
        fprintf(stderr, "Error: Exam's time cannot be NULL\n");
        return NULL;
    }

    /* Allocates memory for exam structure and checks whether the allocation was successful
    // Aloca mem�ria para estrutura de exame e verifica se a aloca��o foi bem-sucedida */
    Exam *new_exam = (Exam*)malloc(sizeof(Exam));
    if (!new_exam) {
        fprintf(stderr, "Failed to allocate memory for exam's structure\n");
        return NULL;
    }

    /* Allocates memory for exam's time and checks whether the allocation was successful
    // Aloca mem�ria para o hor�rio do exame e verifica se a aloca��o foi bem-sucedida */
    new_exam->time = (struct tm*)malloc(sizeof(struct tm));
    if (!new_exam->time) {
        fprintf(stderr, "Failed to allocate memory for time structure\n");
        free(new_exam);
        return NULL;
    }

    /* Assign the exam's id, patient_id, and rx_id // Atribui o id, patient_id e rx_id do exame */
    new_exam->id = id;
    new_exam->patient_id = patient_id;
    new_exam->rx_id = rx_id;

    /* Copy the tm structure // Copia a estrutura tm */
    memcpy(new_exam->time, time, sizeof(struct tm));

    return new_exam;
}

void destroy_exam(Exam *old_exam) {
    /** \brief Free the allocated memory for the exam's structure // Libera a mem�ria alocada para a estrutura do exame
     *
     * \param old_exam - Pointer to the exam structure to be freed // Ponteiro para a estrutura do exame a ser liberada
     *
     * \details This function frees the memory allocated for the exam's time and the exam structure itself.
     * \details Esta fun��o libera a mem�ria alocada para o hor�rio do exame e a pr�pria estrutura do exame.
     *
     * \warning This function does not return any value. If the exam pointer is NULL, it simply returns without doing anything.
     *          Esta fun��o n�o retorna nenhum valor. Se o ponteiro do exame for NULL, simplesmente retorna sem fazer nada.
     */

    /* Checks if the exam pointer is NULL // Verifica se o ponteiro do exame � nulo */
    if (!old_exam) {
        fprintf(stderr, "\nNULL POINTER!!\n");
        return;
    }

    /* Free exam's time if allocated // Libera o hor�rio do exame, se alocado */
    if (old_exam->time) {
        free(old_exam->time);
        old_exam->time = NULL; // Set to NULL after freeing // Define como NULL ap�s liberar
    }

    /* Free the exam structure itself // Libera a pr�pria estrutura do exame */
    free(old_exam);
    printf("Memory Allocation Freed!(Exam)\n");
}

int get_exam_id(Exam *exam) {
    /** \brief This function gets and returns exam's ID // Esta fun��o obt�m e retorna o ID do exame
     *
     * \param exam - Pointer to exam's structure // Ponteiro para a estrutura do exame
     * \return The exam's ID // O ID do exame
     *
     * \details This function checks if the exam pointer is NULL. If it is, it prints an error message to stderr and returns 1. Otherwise, it returns the exam's ID.
     * \details Esta fun��o verifica se o ponteiro do exame � NULL. Se for, imprime uma mensagem de erro em stderr e retorna 1. Caso contr�rio, retorna o ID do exame.
     *

     */

    /* Checks if the exam pointer is NULL // Verifica se o ponteiro do exame � nulo */
    if (!exam) {
        fprintf(stderr, "Error: NULL exam pointer\n");
        return 1;
    }

    return exam->id;
}

int get_exam_patient_id(Exam *exam) {
    /** \brief This function gets and returns the patient's ID associated with the exam // Esta fun��o obt�m e retorna o ID do paciente associado ao exame
     *
     * \param exam - Pointer to exam's structure // Ponteiro para a estrutura do exame
     * \return The patient's ID associated with the exam // O ID do paciente associado ao exame
     *
     * \details This function checks if the exam pointer is NULL. If it is, it prints an error message to stderr and returns 1. Otherwise, it returns the patient's ID associated with the exam.
     * \details Esta fun��o verifica se o ponteiro do exame � NULL. Se for, imprime uma mensagem de erro em stderr e retorna 1. Caso contr�rio, retorna o ID do paciente associado ao exame.
     *
     *
     */

    /* Checks if the exam pointer is NULL // Verifica se o ponteiro do exame � nulo */
    if (!exam) {
        fprintf(stderr, "Error: NULL exam pointer\n");
        return 1;
    }

    return exam->patient_id;
}

int get_exam_rx_id(Exam *exam) {
    /** \brief This function gets and returns the machine's ID used for the exam // Esta fun��o obt�m e retorna o ID da m�quina usada para o exame
     *
     * \param exam - Pointer to exam's structure // Ponteiro para a estrutura do exame
     * \return The machine's ID used for the exam // O ID da m�quina usada para o exame
     *
     * \details This function checks if the exam pointer is NULL. If it is, it prints an error message to stderr and returns 1. Otherwise, it returns the machine's ID used for the exam.
     * \details Esta fun��o verifica se o ponteiro do exame � NULL. Se for, imprime uma mensagem de erro em stderr e retorna 1. Caso contr�rio, retorna o ID da m�quina usada para o exame.
     *
     *
     */

    /* Checks if the exam pointer is NULL // Verifica se o ponteiro do exame � nulo */
    if (!exam) {
        fprintf(stderr, "Error: NULL exam pointer\n");
        return 1;
    }

    return exam->rx_id;
}

struct tm *get_exam_time(Exam *exam) {
    /** \brief This function gets and returns the exam's time // Esta fun��o obt�m e retorna o hor�rio do exame
     *
     * \param exam - Pointer to exam's structure // Ponteiro para a estrutura do exame
     * \return Pointer to const struct tm representing the exam's time // Ponteiro para const struct tm representando o hor�rio do exame
     *
     * \details This function checks if the exam pointer is NULL. If it is, it prints an error message to stderr and returns NULL. Otherwise, it returns a pointer to the exam's time.
     * \details Esta fun��o verifica se o ponteiro do exame � NULL. Se for, imprime uma mensagem de erro em stderr e retorna NULL. Caso contr�rio, retorna um ponteiro para o hor�rio do exame.
     *
     *
     */

    /* Checks if the exam pointer is NULL // Verifica se o ponteiro do exame � nulo */
    if (!exam) {
        fprintf(stderr, "Error: NULL exam pointer\n");
        return NULL;
    }

    return exam->time;
}
