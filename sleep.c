#include <time.h>
#include <stdio.h>
#include "sleep.h"


void my_sleep(unsigned int seconds) {
/**
 * @brief Suspends execution for a specified number of seconds using clock cycles.
 *
 * @param seconds Number of seconds to suspend execution.
 */
    clock_t start_time = clock();
    clock_t end_time = seconds * CLOCKS_PER_SEC;

    while (clock() - start_time < end_time) {
        // Waiting...
    }
}


void stopping(unsigned int sec) {
/**
 * @brief Displays a countdown and then stops the program.
 *
 * @param sec Number of seconds for the countdown.
 */
    for (int i = sec; i > 0; i--) {
        printf("\n\nClosing Program in %d second(s)....", i);
        my_sleep(1);
    }
    printf("\nProgram closed.\n");
}
