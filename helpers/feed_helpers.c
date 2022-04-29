#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/structs.h"
#include "../lib/display/display.h"
#include "helpers.h"

void create_post(twitter *twitter_system, user *active_user, char msg[TWEET_LENGTH])
{

    tweet *new = (struct tweet *)malloc(sizeof(tweet));

    new->id = twitter_system->num_tweets++;
    new->user_id = active_user->user_id;
    strcpy(new->msg, msg);
    new->last = twitter_system->latest_tweet;

    twitter_system->latest_tweet = new;
}

void print_posts(twitter *twitter_system, user *active_user, int count)
{

    tweet *current_tweet = twitter_system->latest_tweet;

    while (current_tweet != NULL)
    {
        if (current_tweet->user_id == active_user->user_id || value_in_array(active_user->following, active_user->num_following, current_tweet->user_id))
        {
            display_tweet(current_tweet->msg, twitter_system->users[current_tweet->user_id].username);
            count--;
        }
        current_tweet = current_tweet->last;
    }

    if (count > 0)
    {
        printf("Not enough tweets by people you follow! Add more people to your following list!\n\n");
    }
}

void remove_all_user_posts(twitter *twitter_system, user *active_user)
{
    tweet *current_tweet = twitter_system->latest_tweet;

    while (current_tweet != NULL)
    {
        if (current_tweet->last->user_id == active_user->user_id)
        {
            tweet *hold = current_tweet->last->last;
            free(current_tweet->last);
            current_tweet->last = hold;
            twitter_system->num_tweets--;
        }
        else
        {
            current_tweet = current_tweet->last;
        }
    }
}