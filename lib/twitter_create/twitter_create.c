// C LIBRARIES
#include <stdio.h>
#include <string.h>

// REQUIRED FOR CONSTANT VALUES
#include "../../utils/constants.h"

// INCLUDE STRUCTURES USED
#include "../../utils/structs.h"

// INCLUDE HELPER FUNCTIONS
#include "../../helpers/helpers.h"
#include "../../helpers/twitter_helpers.h"

// INCLUDE DISPLAY MODULE
#include "../display/display.h"

// FUNCTION TO CREATE TWITTER SYSTEM
void create_twitter_system(twitter *twitter_system)
{
    // DISPLAY LOGO
    display_logo();
    // DISPLAY TITLE
    display_title("CREATE USERS!");

    // ADD EMPTY USERS TO TWITTER SYSTEM
    initialize_empty_users(twitter_system);

    // SET INITAL VALUES FOR NUMBER OF USERS AND TWEETS TO 0
    twitter_system->num_users = 0;
    twitter_system->num_tweets = 0;

    // SET LATEST TWEET TO NULL
    twitter_system->latest_tweet = NULL;

    // KEEP ASKING CREATING USERS AS LONG AS USER ANSWERS YES TO PROMPT SERVED BY THE input_exit FUNCTION
    do
    {
        // TEMP VARIABLE TO HOLD INPUT USERNAME
        char temp_username[USR_LENGHT];

        // INPUT USERNAME WHICH MUST BE UNIQUE AND ALLOWED
        input_unique_username(twitter_system, &temp_username[0]);

        // SET NEW USER'S user_id
        twitter_system->users[twitter_system->num_users].user_id = twitter_system->num_users;

        // COPY USERNAME TO THE USER'S STRUCT IN THE TWITTER SYSTEM USING strcpy AND INCREMENT twitter_system->num_users
        strcpy(twitter_system->users[twitter_system->num_users++].username, temp_username);

    } while (!input_exit());


    // CLEAR SCREEN
    clear_screen();

    // DISPLAY ALL USERS MADE
    display_title("USERS CREATED!");
    display_users(twitter_system);

    // PAUSE UNTIL USER PRESSES ENTER
    hold_until_enter();
}