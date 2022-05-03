// C LIBRARIES
#include <stdio.h>

// INCLUDE STRUCTURES USED
#include "../../utils/structs.h"

// INCLUDE HELPER FUNCTIONS
#include "../../helpers/helpers.h"
#include "../../helpers/twitter_helpers.h"
#include "../../helpers/feed_helpers.h"

// INCLUDE DISPLAY LIBRARY
#include "../display/display.h"

// FUNCTION (WITH USERFLOW) TO DELETE AN ACCOUNT
void delete (twitter *twitter_system, user *active_user)
{
    // DISPLAY TITLE
    display_title("YOUR ACCOUNT IS BEING DELETED!");
    
    // PRINT STATEMENT
    printf("Deleting your Account...\nBeep Boop Beep\n");

    // 
    int unfollow_id;

    // FOR EACH USER THE active_user WAS FOLLOWING
    for (int i = active_user->num_following - 1; i >= 0; i--)
    {
        // UNFOLLOW THE USER
        unfollow_id = active_user->following[i];
        remove_follow(twitter_system, active_user, unfollow_id);
    }

    // FOR EACH USER THAT WAS FOLLOWING active_user
    for (int i = active_user->num_followers - 1; i >= 0; i--)
    {
        // UNFOLLOW active_user FROM THEIR ACCOUNT
        unfollow_id = active_user->followers[i];
        remove_follow(twitter_system, &twitter_system->users[unfollow_id], active_user->user_id);
    }

    // DELETE ALL TWEETS BY USER
    remove_all_user_posts(twitter_system, active_user);

    // SET USER ID AS -1 TO INDICATE DELETED USER
    active_user->user_id = -1;

    // PAUSE UNTIL USER INPUT
    hold_until_enter();
}