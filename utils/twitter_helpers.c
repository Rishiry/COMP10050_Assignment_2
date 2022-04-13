#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "structs.h"

bool check_username_unique(twitter *twitter_system, char username[])
{
    for (int j = 0; j < twitter_system->num_users; j++)
    {
        if (strcasecmp(username, twitter_system->users[j].username) == 0)
        {
            return false;
        }
    }

    return true;
}

int get_user_id_from_username(twitter * twitter_system, char username[]){
    int user_id = -1;

    for (int j = 0; j < twitter_system->num_users; j++)
    {
        if (strcasecmp(username, twitter_system->users[j].username) == 0)
        {
            user_id = twitter_system->users[j].user_id;
            break;
        }
    }

    return user_id;
}

void input_unique_username(twitter *twitter_system, char *temp_username)
{

    printf("Username: ");
    scanf("%s", temp_username, USR_LENGHT);

    while (!check_username_unique(twitter_system, temp_username))
    {
        printf("\nThis username is taken, please try again!\n");

        printf("Username: ");
        scanf("%s", temp_username, USR_LENGHT);
    }

    fflush(stdin);
}

void input_username(twitter *twitter_system, char *temp_username)
{

    printf("Username: ");
    scanf("%s", temp_username, USR_LENGHT);

    while (get_user_id_from_username(twitter_system, temp_username) == -1)
    {
        printf("This username is not valid, please try again!\n");

        printf("Username: ");
        scanf("%s", temp_username, USR_LENGHT);
    }

    fflush(stdin);
}
