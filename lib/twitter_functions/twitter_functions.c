#include <stdio.h>
#include <stdbool.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"

#include "../display/display_users.h"

#include "follow.h"
#include "unfollow.h"
#include "post.h"
#include "get_news_feed.h"
#include "delete.h"

void turn_options()
{
    printf("1. Follow Another User\n");
    printf("2. Unfollow Someone you follow\n");
    printf("3. TWEET SOMETHING!\n");
    printf("4. See What others are TWEETING about...\n");
    printf("5. Delete my Account\n");
    printf("6. End Turn\n");
    printf("7. End Twitter\n");
    printf("I Pick: ");
}

void end(bool *stop){
    *stop = true;
}

void run_twitter_functions(twitter *twitter_system)
{
    void (*f[])(twitter * twitter_system, user * active_user) = {follow, unfollow, post, get_news_feed, delete};

    bool game_stop = false;
    bool turn_stop = false;
    int turn_choice = 0;


    printf("\n\n-- STARTING -- \n\n");

    while (!game_stop)
    {
        for (int j = 0; j < twitter_system->num_users; j++)
        {
            user *active_user = &twitter_system->users[j];
            display_single_user(active_user);

            turn_stop = false;

            while (!turn_stop) {
                turn_options();

                scanf("%d", &turn_choice);
                fflush(stdin);

                printf("\n");


                if (1 <= turn_choice && turn_choice <= 4)
                {
                    (*f[turn_choice - 1])(twitter_system, active_user);
                    printf("\n");
                }
                else if (turn_choice == 6)
                {
                    end(&turn_stop);
                }
                else if (turn_choice == 7)
                {
                    end(&game_stop);
                    end(&turn_stop);
                }

            }

            if(game_stop) {
                break;
            }

        }

    }
}