#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "constants.h"
#include "structs.h"

void initialize_empty_users(twitter *twitter_system)
{
    struct user emptyUser = {"\0", {}, 0, {}, 0};

    for (int i = 0; i < MAX_USERS; i++)
    {
        twitter_system->users[i] = emptyUser;
    }
}

bool check_username_unique(twitter *twitter_system, char username[USR_LENGHT])
{
    for (int j = 0; j < twitter_system->num_users; j++)
    {
        if (strcmp(username, twitter_system->users[j].username) == 0)
        {
            return false;
        }
    }

    return true;
}

void input_username(twitter *twitter_system, char *temp_username)
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

bool input_exit(void)
{
    char quit = '\0';

    while (!(quit == 'Y' || quit == 'y' || quit == 'N' || quit == 'n'))
    {
        printf("\nMake Another User (Y/N): ");
        scanf(" %c", &quit);
    }

    printf("\n");

    if (quit == 'Y' || quit == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void display_users(twitter *twitter_system)
{
    int ID_COL = 3;
    int USERNAME_COL = 20;
    int FOLLOWERS_COL = 10;
    int FOLLOWING_COL = 10;

    int COLS = 4;

    char BORDER[] = " | ";

    int TOTAL = ID_COL + USERNAME_COL + FOLLOWERS_COL + FOLLOWING_COL + (strlen(BORDER) * (COLS + 1)) - 2;

    printf(" ");
    for (int j = 0; j < TOTAL; j++, printf("%c", '='))
        ;
    printf(" \n");

    printf("%s", BORDER);

    printf("%-0*s", ID_COL, "ID");

    printf("%s", BORDER);

    printf("%-0*s", USERNAME_COL, "USERNAME");
    printf("%s", BORDER);

    printf("%-0*s", FOLLOWERS_COL, "FOLLOWERS");
    printf("%s", BORDER);

    printf("%-0*s", FOLLOWING_COL, "FOLLOWING");
    printf("%s", BORDER);

    printf("\n ");
    for (int j = 0; j < TOTAL; j++, printf("%c", '='))
        ;
    printf(" \n");

    for (int j = 0; j < twitter_system->num_users; j++)
    {
        printf("%s", BORDER);
        printf("%-0*d", ID_COL, j + 1);
        printf("%s", BORDER);
        printf("%-0*s", USERNAME_COL, twitter_system->users[j].username);
        printf("%s", BORDER);
        printf("%-0*d", FOLLOWERS_COL, twitter_system->users[j].num_followers);
        printf("%s", BORDER);
        printf("%-0*d", FOLLOWING_COL, twitter_system->users[j].num_following);
        printf("%s \n", BORDER);
    }
    printf(" ");
    for (int j = 0; j < TOTAL; j++, printf("%c", '='))
        ;

    printf(" \n");
}

void create_twitter_system(twitter *twitter_system)
{

    int user_count = 0;

    printf("-- CREATE USERS --\n");

    initialize_empty_users(twitter_system);

    do
    {
        char temp_username[USR_LENGHT];
        input_username(twitter_system, &temp_username[0]);

        strcpy(twitter_system->users[user_count].username, temp_username);

        user_count++;

    } while (input_exit());

    twitter_system->num_users = user_count;

    display_users(twitter_system);
}