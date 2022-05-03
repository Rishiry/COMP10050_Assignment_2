// C LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// FUNCTION TO CONVERT INT TO STRING
char *int_to_str(int input)
{
    // GET LENGTH OF input
    int length = snprintf(NULL, 0, "%d", input);
    // ALLOCATE MEMORY EQUAL TO LENGTH OF INT + 1 (+1 FOR THE NULL CHAR)
    char *output = malloc(length + 1);
    // CONVERT INT TO STRING
    snprintf(output, length + 1, "%d", input);

    // RETURN STRING
    return output;
}

// FUNCTION TO CHECK IF VALUE EXISITS IN ARRAY
bool value_in_array(int array[], int length, int value)
{
    // VARIABLE TO STORE IF VALUE FOUND
    bool exists = false;

    // ITERATE OVER EACH ELEMENT IN ARRAY
    for (int j = 0; j < length; j++)
    {
        // IF IS element EQUAL TO TARGET value
        if (array[j] == value)
        {
            // SET exists TO TRUE
            exists = true;

            // BREAK FOR LOOP SINCE element FOUND
            break;
        }
    }

    // RETURN VARIABLE HOLDING FINAL VALUE
    return exists;
}

// FUNCTION TO FIND AN ELEMENT'S INDEX IN AN ARRAY
int find_index_in_array(int array[], int length, int element)
{
    // DECLARE INDEX VARIABLE
    int index = -1;

    // ITERATE OVER EACH ELEMENT IN ARRAY
    for (int i = 0; i < length; i++)
    {
        // IF IS element EQUAL TO TARGET value
        if (array[i] == element)
        {
            // SET index TO i
            index = i;

            // BREAK FOR LOOP SINCE ELEMENT FOUND
            break;
        }
    }

    // RETURN VARIABLE HOLDING FINAL VALUE
    return index;
}

// FUNCTION TO DELETE INDEX FROM AN ARRAY
void delete_index_from_array(int *array, int length, int index)
{

    // SET index VALUE IN array TO -1
    array[index] = -1;

    // ITERATE OVER REMAINING ELEMENTS
    for (int i = index; i <= length - 1; i++)
    {
        // SHIFT ELEMENTS TOWARDS THE FRONT BY 1 POSITION
        array[i] = array[i + 1];
    }
}

// FUNCTION TO INPUT YES OR NO FROM USER
bool input_exit(void)
{
    // DECLARE VARIABLE TO HOLD INPUT
    char quit = '\0';

    // KEEP ASKING FOR INPUT UNLESS VALUE OF quit IS EITHER Y OR y OR N OR n
    while (!(quit == 'Y' || quit == 'y' || quit == 'N' || quit == 'n'))
    {
        // PROMPT USER
        printf("\nMake Another User (Y/N): ");
        // INPUT VALUE
        scanf(" %c", &quit);
    }

    // FFLUSH STDIN
    fflush(stdin);

    printf("\n");

    // IF VALUE IS N OR n THEN RETURN TRUE ELSE RETURN FALSE
    return (quit == 'N' || quit == 'n');
}

// FUNCTION TO CLEAR SCREEN
void clear_screen(void)
{
    // REFERENCED FROM https://stackoverflow.com/questions/228617/how-do-i-clear-the-console-in-both-windows-and-linux-using-c
    system("@cls||clear");
}

// FUNCTION TO PAUSE PROGRAM UNTIL USER INPUT
void hold_until_enter(void)
{
    // PROMPT USER
    printf("(Press Enter to Continue)");
    // HOLD UNTIL ENTER IS PRESSED
    while (getchar() != '\n')
        ;
    // CLEAR SCREEN
    clear_screen();
}