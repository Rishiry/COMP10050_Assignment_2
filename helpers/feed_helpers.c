// C LIBRARIES
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// INCLUDE STRUCTURES USED
#include "../utils/structs.h"

// INCLUDE DISPLAY MODULE
#include "../lib/display/display.h"

// INCLUDE OTHER HELPER FUNCTIONS
#include "helpers.h"

// FUNCTION TO CREATE A NEW POST
void create_post(twitter *twitter_system, user *active_user, char msg[TWEET_LENGTH])
{
    // ALLOCATE MEMORY
    tweet *new = (struct tweet *)malloc(sizeof(tweet));

    // SET DATA FIELDS
    new->id = twitter_system->num_tweets++;
    new->user_id = active_user->user_id;

    // SET last AS THE LATEST TWEET IN THE SYSTEM
    new->last = twitter_system->latest_tweet;

    // COPY msg PASSED IN TO new->msg USING strcpy
    strcpy(new->msg, msg);

    // PUSH NEW TWEET TO BE ON TOP OF THE LIST
    twitter_system->latest_tweet = new;
}

// FUNCTION TO PRINT POSTS
void print_posts(twitter *twitter_system, user *active_user, int count)
{
    // CREATE POINTER TO THE LATEST TWEET
    tweet *current_tweet = twitter_system->latest_tweet;

    // TRAVERSE TWEETS LINKED LIST UNTIL NEXT ELEMENT IN NULL OR THE NUMBER OF TWEETS TO SHOW HAS REACHED 0
    while (current_tweet != NULL && count != 0)
    {
        // IF TWEET IS BY ACTIVE USER OR A USER THAT THE ACTIVE USER IS FOLLOWING
        if (current_tweet->user_id == active_user->user_id || value_in_array(active_user->following, active_user->num_following, current_tweet->user_id))
        {
            // DISPLAY THE TWEET
            display_tweet(current_tweet->msg, twitter_system->users[current_tweet->user_id].username);
            // DECREASE THE NUMBER OF TWEETS TO SHOW
            count--;
        }

        // MOVE TO NEXT TWEET
        current_tweet = current_tweet->last;
    }

    // IF THE NUMBER OF TWEETS TO SHOW HAS NOT REACHED 0
    if (count > 0)
    {
        // DISPLAY WARNING
        display_tweet("We wanted to show you 10 most recent tweets but there are not enough tweets by people you follow! Add more people to your following list!", "The Developers");
    }
}

// FUNCTION TO DELETE ALL POSTS FOR A USER
void remove_all_user_posts(twitter *twitter_system, user *active_user)
{
    // CREATE POINTER TO THE LATEST TWEET AND ACT AS TEMP STORAGE
    tweet *current_tweet, *hold;

    // KEEP DELETING THE LATEST TWEET IF IT IS BY active_user 
    while (twitter_system->latest_tweet != NULL)
    {
        // IF LATEST TWEET IS BY active_user THEN DELETE THE TWEET
        if (twitter_system->latest_tweet->user_id == active_user->user_id)
        {
            // MAKE A COPY OF latest_tweet 
            hold = twitter_system->latest_tweet;
            // SET latest_tweet TO THE TWEET BEFORE THAT
            twitter_system->latest_tweet = hold->last;
            // FREE MEMORY
            free(hold);
            // DECREMENT TWEET COUNT
            twitter_system->num_tweets--;
        }
        // OTHERWISE WE KNOW THAT latest_tweet IS NOT BY active_user
        else
        {
            // BREAK THE LOOP
            break;
        }
    }

    // CREATE POINTER TO THE LATEST TWEET
    current_tweet = twitter_system->latest_tweet;

    // TRAVERSE TWEETS LINKED LIST UNTIL NEXT ELEMENT IN NULL
    while (current_tweet != NULL)
    {
        // IF THE NEXT TWEET IS BY active_user
        if (current_tweet->last->user_id == active_user->user_id)
        {
            // MAKE A COPY OF current_tweet 
            hold = current_tweet->last;
            // SET current_tweet TO THE TWEET BEFORE THAT
            current_tweet = hold->last;
            // FREE MEMORY
            free(hold);
            // DECREMENT TWEET COUNT
            twitter_system->num_tweets--;
        }
        // OTHERWISE
        else
        {
            // SET current_tweet TO THE TWEET BEFORE THAT
            current_tweet = current_tweet->last;
        }
    }
}