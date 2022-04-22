#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"
#include "../../helpers/helpers.h"
#include "../../helpers/twitter_helpers.h"

#include "../display/display_users.h"


void create_twitter_system(twitter *twitter_system)
{

    printf("-- CREATE USERS --\n");

    initialize_empty_users(twitter_system);

    twitter_system->num_users = 0;
    twitter_system->num_tweets = 0;


    do
    {
        char temp_username[USR_LENGHT];
        input_unique_username(twitter_system, &temp_username[0]);

        twitter_system->users[twitter_system->num_users].user_id = twitter_system->num_users;
        strcpy(twitter_system->users[twitter_system->num_users].username, temp_username);

        twitter_system->num_users++;

    } while (!input_exit());
;

    display_users(twitter_system);
}