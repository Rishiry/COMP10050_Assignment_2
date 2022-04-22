#include <stdio.h>
#include <stdbool.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"

#include "../display/display.h"

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
    void (*f[])(twitter * twitter_system, user * active_user) = {follow, unfollow, post, get_news_feed};

    bool game_stop = false;
    bool turn_stop = false;
    int turn_choice = 0;


    display_title("WELCOME TO TWITTER!");

    while (!game_stop)
    {
        for (int j = 0; j < twitter_system->num_users; j++)
        {
            user *active_user = &twitter_system->users[j];

            if(active_user->user_id == -1) {
                turn_stop = true;
            } else {
                turn_stop = false;
                display_single_user(active_user);
            }

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
                else if (turn_choice == 5)
                {
                    delete(twitter_system, active_user);
                    printf("\n");
                    end(&turn_stop);
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