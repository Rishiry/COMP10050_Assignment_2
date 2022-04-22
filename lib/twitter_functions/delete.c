#include <stdio.h>
#include <string.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"
#include "../../helpers/twitter_helpers.h"

void delete(twitter * twitter_system, user * active_user){

    printf("Deleting your Account...\nBeep Boop Beep\n");

    int unfollow_id;

    for(int i = active_user->num_following - 1; i >= 0; i--){
        unfollow_id = active_user->following[i];
        remove_follow(twitter_system, active_user, unfollow_id);
    }

    for(int i = active_user->num_followers - 1; i >= 0; i--){
        unfollow_id = active_user->followers[i];
        remove_follow(twitter_system, &twitter_system->users[unfollow_id], active_user->user_id);
    }

    active_user->user_id = -1;

}