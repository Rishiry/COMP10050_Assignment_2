#include <stdio.h>
#include <string.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"
#include "../../helpers/helpers.h"
#include "../../helpers/twitter_helpers.h"

#include "../display/display.h"

void create_twitter_system(twitter *twitter_system)
{

    display_logo();
    display_title("CREATE USERS!");

    initialize_empty_users(twitter_system);

    twitter_system->num_users = 0;
    twitter_system->num_tweets = 0;

    twitter_system->latest_tweet = NULL;

    do
    {
        char temp_username[USR_LENGHT];
        input_unique_username(twitter_system, &temp_username[0]);

        twitter_system->users[twitter_system->num_users].user_id = twitter_system->num_users;
        strcpy(twitter_system->users[twitter_system->num_users].username, temp_username);

        twitter_system->num_users++;

    } while (!input_exit());

    clear_screen();

    display_title("USERS CREATED!");
    display_users(twitter_system);

    hold_until_enter();
}