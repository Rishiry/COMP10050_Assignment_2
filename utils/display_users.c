#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "constants.h"
#include "structs.h"

#define REPEAT(C, N)                             \
    for (int j = 0; j < N; j++, printf("%c", C)); printf("\n"); \

char *int_to_str(int input) {
    int length = snprintf( NULL, 0, "%d", input );
    char* output = malloc( length + 1 );
    snprintf( output, length + 1, "%d", input );

    return output;
}

void display_cell(int size, char content[], bool last) {
    printf("%s", BORDER);

    printf("%-0*s", size, content);

    if(last) {
        printf("%s\n", BORDER);
    }
}

void display_row(user row) {
    display_cell(ID_COL, int_to_str(row.user_id), false);
    display_cell(USERNAME_COL, row.username, false);
    display_cell(FOLLOWERS_COL, int_to_str(row.num_followers), false);
    display_cell(FOLLOWING_COL, int_to_str(row.num_following), true);
}

void display_header() {
    display_cell(ID_COL, "ID", false);
    display_cell(USERNAME_COL, "USERNAME", false);
    display_cell(FOLLOWERS_COL, "FOLLOWERS", false);
    display_cell(FOLLOWING_COL, "FOLLOWING", true);
}

void display_users(twitter *twitter_system)
{
    REPEAT('=', TOTAL);

    display_header();

    REPEAT('=', TOTAL);

    for (int j = 0; j < twitter_system->num_users; j++)
    {
        display_row(twitter_system->users[j]);
    }

    REPEAT('=', TOTAL);

}