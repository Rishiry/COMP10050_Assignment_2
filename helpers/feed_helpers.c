#include <string.h>
#include <stdio.h>
#include "../utils/structs.h"
#include "helpers.h"

void create_post(twitter *twitter_system, user *active_user, char msg[TWEET_LENGTH]){

    tweet new = {-1, "", -1};

    new.id = twitter_system->num_tweets++;
    new.user_id = active_user->user_id;
    strcpy(new.msg, msg);
    
    twitter_system->tweets[new.id] = new;

}

void print_posts(twitter *twitter_system, user *active_user, int count) {

    if(twitter_system->num_tweets > 0) {
        for(int i = twitter_system->num_tweets-1; i >= 0; i--) {
            if(twitter_system->tweets[i].user_id == active_user->user_id || value_in_array(active_user->following, active_user->num_following, twitter_system->tweets[i].user_id)) {
                printf("%s:\t%s\n", twitter_system->users[twitter_system->tweets[i].user_id].username, twitter_system->tweets[i].msg);
                count--;
            }

            if(count == 0){
                break;
            }
        }
    }

    if (count > 0) {
        printf("Not enough tweets by people you follow! Add more people to your following list!\n\n");
    }
}

void remove_all_user_posts(twitter *twitter_system, user *active_user) {
    for(int i = twitter_system->num_tweets-1; i >= 0; i--) {
        if(twitter_system->tweets[i].user_id == active_user->user_id) {
            twitter_system->tweets[i].user_id = -1;
            strcpy(twitter_system->tweets[i].msg, "\0");
        }
    }
}