#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"
#include "../../utils/twitter_helpers.h"

#include "../../utils/display_users.h"

void initialize_empty_users(twitter *twitter_system)
{
    struct user emptyUser = {-1, "\0", {}, 0, {}, 0 };

    for (int i = 0; i < MAX_USERS; i++)
    {
        twitter_system->users[i] = emptyUser;
    }
}

bool input_exit(void)
{
    char quit = '\0';

    while (!(quit == 'Y' || quit == 'y' || quit == 'N' || quit == 'n'))
    {
        printf("\nMake Another User (Y/N): ");
        scanf(" %c", &quit);
    }

    printf("\n");

    if (quit == 'N' || quit == 'n')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void create_twitter_system(twitter *twitter_system)
{

    int user_count = 0;

    printf("-- CREATE USERS --\n");

    initialize_empty_users(twitter_system);

    do
    {
        char temp_username[USR_LENGHT];
        input_unique_username(twitter_system, &temp_username[0]);

        twitter_system->users[user_count].user_id = user_count;
        strcpy(twitter_system->users[user_count].username, temp_username);

        user_count++;

    } while (!input_exit());

    twitter_system->num_users = user_count;

    display_users(twitter_system);
}