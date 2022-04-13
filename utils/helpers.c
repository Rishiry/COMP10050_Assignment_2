#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *int_to_str(int input)
{
    int length = snprintf(NULL, 0, "%d", input);
    char *output = malloc(length + 1);
    snprintf(output, length + 1, "%d", input);

    return output;
}

bool value_in_array(int array[], int length, int value)
{
    bool exists = false;

    for (int j = 0; j < length; j++)
    {
        if (array[j] == value)
        {
            exists = true;
            break;
        }
    }

    return exists;
}

void input_user_id(int *user_id)
{
    printf("User ID: ");
    scanf("%d", user_id);
    fflush(stdin);
    *user_id = *user_id - 1;
}


int find_index_in_array(int array[], int length, int element) {
    int index = -1;

    for(int i = 0; i < length; i++) {
        if(array[i] == element) {
            index = i;
            break;
        }
    }

    return index;
}

void delete_index_from_array(int *array[], int length, int index)
{
    for (int i = index; i < length - 1; i++)
    {
        *array[i] = *array[i + 1];
    }
}

void delete_element_from_array(int *array[], int length, int element){
    delete_index_from_array(&array, length, find_index_in_array(array, length, element));
}