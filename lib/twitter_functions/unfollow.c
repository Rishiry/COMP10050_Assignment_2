#include <stdio.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"
#include "../../utils/helpers.h"

#include "../../utils/display_users.h"

void unfollow(twitter *twitter_system, user *active_user)
{
    display_users_by_id(twitter_system, active_user->following, active_user->num_following);

    char unfollow_username[USR_LENGHT];
    input_username(twitter_system, &unfollow_username[0]);

    int unfollow_id = get_user_id_from_username(twitter_system, unfollow_username);

    if (value_in_array(active_user->following, active_user->num_following, unfollow_id))
    {
        printf("You have chosen to unfollow: %s\n", twitter_system->users[unfollow_id].username);

        delete_element_from_array(active_user->following, active_user->num_following--, unfollow_id);
        delete_element_from_array(twitter_system->users[unfollow_id].followers, twitter_system->users[unfollow_id].num_followers--, active_user->user_id);
    }
    else
    {
        printf("You don't follow that user! Choose a user you follow to unfollow them.\n");
    }
}