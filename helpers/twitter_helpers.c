// C LIBRARIES
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// INCLUDE STRUCTURES USED
#include "../utils/structs.h"

// INCLUDE OTHER HELPER FUNCTIONS
#include "helpers.h"

// FUNCTION TO CHECK IF USERNAME IS UNIQUE
bool check_username_unique(twitter *twitter_system, char username[])
{
    // DECLARE VARIABLE TO STORE IF VALUE UNIQUE
    bool unique = true;

    // ITERATE OVER EACH USER
    for (int j = 0; j < twitter_system->num_users; j++)
    {
        // IF username AND USERNAME OF THE USER ARE THE SAME
        if (strcasecmp(username, twitter_system->users[j].username) == 0)
        {
            // SET unique TO FALSE SINCE THE ENTRY HAS BEEN FOUND ALREADY
            unique = false;
            // BREAK LOOP
            break;
        }
    }

    // IF THE VALUE IS NOT UNIQUE
    if (!unique)
    {
        // PRINT ERROR MESSAGE
        printf("\nThis username is taken, please try again!\n");

        // RETURN FALSE
        return false;
    }
    // IF THE VALUE IS EQUAL TO EXIT
    else if (strcasecmp(username, "Exit") == 0)
    {
        // PRINT ERROR MESSAGE
        printf("\nReserved Keyword, please try another username.\n");

        // RETURN FALSE
        return false;
    }
    // ELSE
    else
    {
        // RETURN TRUE
        return true;
    }
}

// FUNCTION TO GET A USER'S ID FROM USERNAME
int get_user_id_from_username(twitter *twitter_system, char username[])
{
    // DECLARE VARIABLE TO STORE USER'S ID
    int user_id = -1;

    // IF username IS EQUAL TO "Exit" THEN SET user_id TO -2 SINCE IT IS A RESERVED KEYWORD
    if (strcasecmp(username, "Exit") == 0)
    {
        user_id = -2;
    }
    // OTHERWISE
    else
    {
        // ITERATE OVER EACH USER
        for (int j = 0; j < twitter_system->num_users; j++)
        {
            // IF username AND USERNAME OF THE USER ARE THE SAME
            if (strcasecmp(username, twitter_system->users[j].username) == 0)
            {
                // SET user_id TO CURRENT ITERATION USER'S ID
                user_id = twitter_system->users[j].user_id;
                // BREAK LOOP
                break;
            }
        }
    }

    // RETURN THE VALUE FOUND
    return user_id;
}

// FUNCTION TO INPUT USERNAME WHICH MUST BE UNIQUE
void input_unique_username(twitter *twitter_system, char *temp_username)
{
    // PROMPT USER
    printf("Username: ");

    // TAKE USER INPUT (OF LENGTH=USR_LENGHT) AND STORE IT IN temp_username
    // SINCE temp_username IS A POINTER, IT CAN BE PASSED IN AS IT IS
    scanf("%s", temp_username, USR_LENGHT);

    // KEEP ASKING USER OF ANOTHER USERNAME IF THE PREVIOUS INPUT WAS NOT A UNIQUE USERNAME
    while (!check_username_unique(twitter_system, temp_username))
    {
        printf("Username: ");
        scanf("%s", temp_username, USR_LENGHT);
    }

    // FFLUSH STDIN
    fflush(stdin);
}

// FUNCTION TO INPUT USERNAME WHICH MUST EXIST
void input_username(twitter *twitter_system, char *temp_username)
{
    // PROMPT USER
    printf("Username: ");

    // TAKE USER INPUT (OF LENGTH=USR_LENGHT) AND STORE IT IN temp_username
    // SINCE temp_username IS A POINTER, IT CAN BE PASSED IN AS IT IS
    scanf("%s", temp_username, USR_LENGHT);

    // KEEP ASKING USER OF ANOTHER USERNAME IF THE PREVIOUS INPUT DID NOT EXIST
    while (get_user_id_from_username(twitter_system, temp_username) == -1)
    {
        printf("This username is not valid, please try again!\n");

        printf("Username: ");
        scanf("%s", temp_username, USR_LENGHT);
    }

    // FFLUSH STDIN
    fflush(stdin);
}

// FUNCTION TO CREATE EMPTY USER STRUCTS 
void initialize_empty_users(twitter *twitter_system)
{
    // DECLARE EMPTY user STRUCT
    struct user emptyUser = {-1, "\0", {}, 0, {}, 0};

    // ADD MAX_USERS NUMBER OF EMPTY STRUCTS TO twitter_system->users
    for (int i = 0; i < MAX_USERS; i++)
    {
        twitter_system->users[i] = emptyUser;
    }
}

// FUNCTION TO FOLLOW ANOTHER USER
void add_follow(twitter *twitter_system, user *active_user, int follow_id)
{
    // GET POINTER TO TARGET USER BY USING follow_id TO PULL THE ELEMENT FROM twitter_system
    user *target_user = &twitter_system->users[follow_id];

    // ADD target_user->user_id TO END OF active_user->following ARRAY AND INCREMENT num_following
    active_user->following[active_user->num_following++] = target_user->user_id;

    // ADD active_user->user_id TO END OF target_user->followers ARRAY AND INCREMENT num_followers
    target_user->followers[target_user->num_followers++] = active_user->user_id;
}

// FUNCTION TO UNFOLLOW ANOTHER USER
void remove_follow(twitter *twitter_system, user *active_user, int unfollow_id)
{
    // GET POINTER TO TARGET USER BY USING follow_id TO PULL THE ELEMENT FROM twitter_system
    user *target_user = &twitter_system->users[unfollow_id];

    // GET INDEX OF target_user->user_id IN active_user->following ARRAY
    int target_in_active_index = find_index_in_array(active_user->following, active_user->num_following, target_user->user_id);
    // DELETE target_user->user_id FROM active_user->following ARRAY
    delete_index_from_array(active_user->following, active_user->num_following--, target_in_active_index);

    // GET INDEX OF active_user->user_id IN target_user->followers ARRAY
    int active_in_target_index = find_index_in_array(target_user->followers, target_user->num_followers, active_user->user_id);
    // DELETE active_user->user_id FROM target_user->followers ARRAY
    delete_index_from_array(target_user->followers, target_user->num_followers--, active_in_target_index);
}