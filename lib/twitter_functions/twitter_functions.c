// C LIBRARIES
#include <stdio.h>
#include <stdbool.h>

// INCLUDE STRUCTURES USED
#include "../../utils/structs.h"

// INCLUDE HELPER FUNCTIONS
#include "../../helpers/helpers.h"

// INCLUDE DISPLAY LIBRARY
#include "../display/display.h"

// INCLUDE TWITTER FUNCTION LIBRARIES
#include "follow.h"
#include "unfollow.h"
#include "post.h"
#include "get_news_feed.h"
#include "delete.h"

// FUNCTION TO TRIGGER STOPS
void end(bool *stop)
{
    *stop = true;
}

// FUNCTION TO ACT AS DRIVER FOR ALL TWITTER FUNCTIONS
void run_twitter_functions(twitter *twitter_system)
{
    // LIST OF TWITTER FUNCTIONS
    void (*f[])(twitter * twitter_system, user * active_user) = {follow, unfollow, post, get_news_feed};

    // VARIABLE TO HALT THE ENTIRE PROGRAM
    bool game_stop = false;

    // VARIABLE TO HALT TURN
    bool turn_stop = false;

    // VARIABLE TO STORE USER CHOICE
    int turn_choice = 0;

    // DISPLAY TITLE
    display_title("WELCOME TO TWITTER!");

    // DISPLAY MESSAGE
    display_tweet(&"For the best experience, ensure your terminal can display more than 70 characters in one line!"[0], &"The Developers"[0]);

    // PAUSE UNTIL USER INPUT
    hold_until_enter();

    // UNTIL game_stop IS TRIGGERED
    while (!game_stop)
    {
        // ITERATE OVER EACH USER
        for (int j = 0; j < twitter_system->num_users; j++)
        {
            // SET POINTER TO USER WITH TURN IN active_user
            user *active_user = &twitter_system->users[j];

            // IF ACTIVE USER'S ID IS -1 THEN THE USER WAS DELETED
            if (active_user->user_id == -1)
            {
                // NEXT TURN
                turn_stop = true;
            }
            else
            {
                // START ACTIVE USER'S TURN
                turn_stop = false;
            }

            // UNTIL turn_stop IS TRIGGERED
            while (!turn_stop)
            {
                // DISPLAY USER STATS
                display_single_user(active_user);

                // DISPLAY OPTIONS MENU
                display_menu(7, "Follow (another user)", "Unfollow (another user)", "Tweet!", "My News Feed", "Delete Account", "End Turn", "End Twitter");
                // PROMPT MESSAGE
                printf("I Pick: ");

                // INPUT USER CHOICE
                scanf("%d", &turn_choice);
                // FFLUSH STDIN
                fflush(stdin);

                // CLEAR SCREEN
                clear_screen();

                // IF turn_choice IS BETWEEN 1 AND 4 (INCLUSIVE)
                if (1 <= turn_choice && turn_choice <= 4)
                {
                    // RUN CORRESPONDING FUNCTION FROM f ARRAY
                    (*f[turn_choice - 1])(twitter_system, active_user);
                }
                // IF turn_choice IS 5
                else if (turn_choice == 5)
                {
                    // RUN DELETE USER FUNCTION
                    delete (twitter_system, active_user);
                    // TRIGGER turn_stop
                    end(&turn_stop);
                }
                // IF turn_choice IS 6
                else if (turn_choice == 6)
                {
                    // TRIGGER turn_stop

                    end(&turn_stop);
                }
                // IF turn_choice IS 7
                else if (turn_choice == 7)
                {
                    // TRIGGER game_stop AND turn_stop
                    end(&game_stop);
                    end(&turn_stop);
                }
            }

            // IF game_stop IS TRIGGERED
            if (game_stop)
            {
                // BREAK FOR LOOP AND DON'T MOVE TO NEXT USER
                break;
            }
        }
    }
}