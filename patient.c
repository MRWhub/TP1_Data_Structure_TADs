#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "patient.h"

struct patient {
    int id;
    char *name;
    struct tm *birthdate;
};


Patient *create_patient(int id, const char *name, struct tm *birthdate){
    /** \brief This function builds a patient object // Esta função constrói um objeto paciente
     *
     * \param id - Unique patient identification // Identificação única do paciente
     * \param name - Pointer to patient name // Ponteiro para o nome do paciente
     * \param birthdate - TM object with patient's birthday // Objeto TM com o aniversário do paciente
     * \return The patient object created // O objeto paciente criado
     *
     * \details This function allocates memory for a new patient and initializes its fields with the given values.
     *          The TM structure passed as a parameter is copied to the new patient structure.
     *          If the name or birthdate pointers are NULL, the function prints an error message to stderr and returns NULL.
     *          If memory allocation fails, the function prints an error message to stderr and returns NULL.
     *
     * \details Esta função aloca memória para um novo paciente e inicializa seus campos com os valores fornecidos.
     *          A estrutura TM passada como parâmetro é copiada para a nova estrutura do paciente.
     *          Se os ponteiros para name ou birthdate forem NULL, a função imprime uma mensagem de erro em stderr e retorna NULL.
     *          Se a alocação de memória falhar, a função imprime uma mensagem de erro em stderr e retorna NULL.
     *
     * \warning If the name or birthdate pointers are NULL, the function prints an error message to stderr and returns NULL.
     *          Se os ponteiros para name ou birthdate forem NULL, a função imprime uma mensagem de erro em stderr e retorna NULL.
     *
     * \warning If memory allocation fails, the function prints an error message to stderr and returns NULL
     *          Se a alocação de memória falhar, a função imprime uma mensagem de erro em stderr e retorna NULL.
     */

     /* Checks if name or birthdate is NULL // Verifica se name ou birthdate é nulo */
     if (!name) {
        fprintf(stderr, "Error: Patient's name cannot be NULL");
        return NULL;
     } else if (!birthdate){
         fprintf(stderr, "Error: Patient's birth date cannot be NULL");
         return NULL;
     }

    /* Allocates memory for patient structure and checks whether the allocation was successful
    // Aloca memória para estrutura paciente e verifica se a alocação foi bem-sucedida */
    Patient *patient = (Patient *)malloc(sizeof(Patient));


    if(!patient){
        fprintf(stderr, "Failed to allocate memory for patient's structure");
        return NULL;
    }

    /* Assign the patient's id(Type INT) // Atribui o id(INT) do paciente */
    patient->id = id;

    /* Allocates memory for patient's name and checks whether the allocation was successful
    // Aloca memória para o nome do paciente e verifica se a alocação foi bem-sucedida */
    patient->name = (char *) malloc(sizeof(char) * strlen(name) + 1);

    if(!patient->name) {
        fprintf(stderr, "Failed to allocate memory for name");
        destroy_patient(patient);
        return NULL;
    }

    /* Copy the name // Copia o nome */
    strcpy(patient->name, name);

    /* Allocates memory for patient's birthdate and checks whether the allocation was successful
    // Aloca memória para a data de nascimento do paciente e verifica se a alocação foi bem-sucedida */
    patient->birthdate = (struct tm *) malloc(sizeof(struct tm));

    if (!patient->birthdate){
        fprintf(stderr, "Failed to allocate memory for birthdate");
        destroy_patient(patient);
        return NULL;
    }

    /* Copy the tm structure // Copia a estrutura tm */
    memcpy(patient->birthdate, birthdate, sizeof(struct tm));

    return patient;
}

void destroy_patient(Patient *patient){
    /** \brief Free the allocated memory for the patient's structure // Libera memória alocada para a estrutura do paciente
     *
     * \param patient - Pointer to patient's structure for free // Ponteiro para estrutura do paciente a ser liberada
     *
     * \details This function checks if the patient pointer is NULL. If not, it frees the memory allocated for the patient's name and birthdate, if they were allocated, and then frees the patient structure itself.
     * \details Esta função verifica se o ponteiro do paciente é NULL. Se não for, libera a memória alocada para o nome e data de nascimento do paciente, se estiverem alocados, e então libera a própria estrutura do paciente.
     *
     * \warning This function does not return any value. If the patient pointer is NULL, it simply returns without doing anything.
     *          Esta função não retorna nenhum valor. Se o ponteiro do paciente for NULL, simplesmente retorna sem fazer nada.
     */

    /* Checks if the patient pointer is NULL // Verifica se o ponteiro do paciente é nulo */
    if (!patient){
        fprintf(stderr,"\nNULL POINTER!!");
        return;
    }

    /* Free patient's name if allocated // Libera o nome do paciente, se alocado */
    if (patient->name) {
        free(patient->name);
        patient->name = NULL; // Set to NULL after freeing // Define como NULL após liberar
    }

    /* Free patient's birthdate if allocated // Libera a data de nascimento do paciente, se alocada */
    if (patient->birthdate) {
        free(patient->birthdate);
        patient->birthdate = NULL; // Set to NULL after freeing // Define como NULL após liberar
    }

    /* Free the patient structure itself // Libera a estrutura do paciente */
    free(patient);
    printf("Memory Allocation Freed!(Patient)\n");
}

int get_patient_id(Patient *patient) {
    /** \brief This function gets and returns patient's ID // Esta função obtém e retorna o ID do paciente
     *
     * \param patient - Pointer to patient's structure // Ponteiro para a estrutura do paciente
     * \return The patient's ID // O ID do paciente
     *
     * \details This function checks if the patient pointer is NULL. If it is, it prints an error message to stderr and returns 1. Otherwise, it returns the patient's ID.
     * \details Esta função verifica se o ponteiro do paciente é NULL. Se for, imprime uma mensagem de erro em stderr e retorna 1. Caso contrário, retorna o ID do paciente.
     *
     *
     */

     /* Checks if the patient pointer is NULL // Verifica se o ponteiro do paciente é nulo */
     if (!patient){
        fprintf(stderr, "Error: NULL patient pointer");
        return 1;
     }

    return patient->id;
}

char *get_patient_name(Patient *patient){
    /** \brief This function gets and returns patient's name // Esta função obtém e retorna o nome do paciente
     *
     * \param patient - Pointer to patient's structure // Ponteiro para a estrutura do paciente
     * \return The patient's name // O nome do paciente
     *
     * \details This function checks if the patient pointer is NULL. If it is, it prints an error message to stderr and returns NULL. Otherwise, it returns the patient's name.
     * \details Esta função verifica se o ponteiro do paciente é NULL. Se for, imprime uma mensagem de erro em stderr e retorna NULL. Caso contrário, retorna o nome do paciente.
     *
     *
     */

     /* Checks if the patient pointer is NULL // Verifica se o ponteiro do paciente é nulo */
     if (!patient){
        fprintf(stderr, "Error: NULL patient pointer");
        return NULL;
     }

    return patient->name;
}

struct tm *get_patient_birthdate(Patient *patient){
    /** \brief This function gets and returns patient's birthdate // Esta função obtém e retorna a data de nascimento do paciente
     *
     * \param patient - Pointer to patient's structure // Ponteiro para a estrutura do paciente
     * \return Pointer to const struct tm representing the patient's birthdate // Ponteiro para const struct tm representando a data de nascimento do paciente
     *
     * \details This function checks if the patient pointer is NULL. If it is, it prints an error message to stderr and returns NULL. Otherwise, it returns a pointer to the patient's birthdate.
     * \details Esta função verifica se o ponteiro do paciente é NULL. Se for, imprime uma mensagem de erro em stderr e retorna NULL. Caso contrário, retorna um ponteiro para a data de nascimento do paciente.
     *
     *
     */

     /* Checks if the patient pointer is NULL // Verifica se o ponteiro do paciente é nulo */
     if (!patient){
        fprintf(stderr, "Error: NULL patient pointer");
        return NULL;
     }

    return patient->birthdate;
};
