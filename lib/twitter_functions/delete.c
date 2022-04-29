#include <stdio.h>

#include "../../utils/structs.h"
#include "../../helpers/helpers.h"
#include "../../helpers/twitter_helpers.h"
#include "../../helpers/feed_helpers.h"

#include "../display/display.h"

void delete (twitter *twitter_system, user *active_user)
{

    display_title("YOUR ACCOUNT IS BEING DELETED!");

    printf("Deleting your Account...\nBeep Boop Beep\n");

    int unfollow_id;

    for (int i = active_user->num_following - 1; i >= 0; i--)
    {
        unfollow_id = active_user->following[i];
        remove_follow(twitter_system, active_user, unfollow_id);
    }

    for (int i = active_user->num_followers - 1; i >= 0; i--)
    {
        unfollow_id = active_user->followers[i];
        remove_follow(twitter_system, &twitter_system->users[unfollow_id], active_user->user_id);
    }

    remove_all_user_posts(twitter_system, active_user);

    active_user->user_id = -1;

    hold_until_enter();
}