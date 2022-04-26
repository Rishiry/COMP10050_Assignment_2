#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../utils/structs.h"

#include "helpers.h"

bool check_username_unique(twitter *twitter_system, char username[])
{
    bool unique = true;
    for (int j = 0; j < twitter_system->num_users; j++)
    {
        if (strcasecmp(username, twitter_system->users[j].username) == 0)
        {
            unique = false;
            break;
        }
    }

    if (!unique)
    {
        printf("\nThis username is taken, please try again!\n");
        return false;
    }
    else if (strcasecmp(username, "Exit") == 0)
    {
        printf("Reserved Keyword, please try another username.\n");
        return false;
    }
    else
    {
        return true;
    }
}

int get_user_id_from_username(twitter *twitter_system, char username[])
{
    int user_id = -1;

    if (strcasecmp(username, "Exit") == 0)
    {

        user_id = -2;
    }
    else
    {
        for (int j = 0; j < twitter_system->num_users; j++)
        {
            if (strcasecmp(username, twitter_system->users[j].username) == 0)
            {
                user_id = twitter_system->users[j].user_id;
                break;
            }
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

void initialize_empty_users(twitter *twitter_system)
{
    struct user emptyUser = {-1, "\0", {}, 0, {}, 0};

    for (int i = 0; i < MAX_USERS; i++)
    {
        twitter_system->users[i] = emptyUser;
    }
}

void add_follow(twitter *twitter_system, user *active_user, int follow_id)
{
    user *target_user = &twitter_system->users[follow_id];

    active_user->following[active_user->num_following++] = target_user->user_id;
    target_user->followers[target_user->num_followers++] = active_user->user_id;
}

void remove_follow(twitter *twitter_system, user *active_user, int unfollow_id)
{
    user *target_user = &twitter_system->users[unfollow_id];

    int target_in_active_index = find_index_in_array(active_user->following, active_user->num_following, target_user->user_id);
    delete_index_from_array(active_user->following, active_user->num_following--, target_in_active_index);

    int active_in_target_index = find_index_in_array(target_user->followers, target_user->num_followers, active_user->user_id);
    delete_index_from_array(target_user->followers, target_user->num_followers--, active_in_target_index);
}