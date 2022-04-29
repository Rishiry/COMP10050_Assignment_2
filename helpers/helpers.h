#ifndef COMP10050_ASSIGNMENT_2_HELPERS_H
#define COMP10050_ASSIGNMENT_2_HELPERS_H

#include <stdbool.h>

#define REPEAT_CHAR(C, N)                        \
    for (int j = 0; j < N; j++, printf("%c", C)) \
        ;                                        \
    printf("\n");

char *int_to_str(int input);
bool value_in_array(int array[], int length, int value);
void input_user_id(int *user_id);
int find_index_in_array(int array[], int length, int element);
void delete_index_from_array(int *array, int length, int index);
bool input_exit(void);
void clear_screen(void);
void hold_until_enter(void);

#endif