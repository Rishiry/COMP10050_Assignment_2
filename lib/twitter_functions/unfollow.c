// C LIBRARIES
#include <stdio.h>

// REQUIRED FOR CONSTANT VALUES
#include "../../utils/constants.h"

// INCLUDE STRUCTURES USED
#include "../../utils/structs.h"

// INCLUDE HELPER FUNCTIONS
#include "../../helpers/helpers.h"
#include "../../helpers/twitter_helpers.h"

// INCLUDE DISPLAY LIBRARY
#include "../display/display.h"

// FUNCTION (WITH USERFLOW) TO UNFOLLOW ANOTHER USER
void unfollow(twitter *twitter_system, user *active_user)
{
    // DISPLAY TITLE
    display_title("UNFOLLOW SOMEONE! (Type Exit to Quit)");

    // DISPLAY ALL USERS ALREADY BEING FOLLOWED
    display_users_by_id(twitter_system, active_user->following, active_user->num_following);

    // DECLARE VARIABLE TO STORE USERNAME
    char unfollow_username[USR_LENGHT];

    // INPUT VALID USERNAME FROM USER
    input_username(twitter_system, &unfollow_username[0]);

    // GET ID OF USER FROM unfollow_username
    int unfollow_id = get_user_id_from_username(twitter_system, unfollow_username);

    // IF unfollow_id IS -2 THEN THE RESERVED KEYWORD "Exit" WAS USED
    if (unfollow_id == -2)
    {
        ;
    }
    // IF unfollow_id IN active_user->following ARRAY
    else if (value_in_array(active_user->following, active_user->num_following, unfollow_id))
    {
        // PRINT MESSAGE
        printf("You have chosen to unfollow: %s\n", twitter_system->users[unfollow_id].username);
        // UNFOLLOW active_user FROM USER WITH unfollow_id
        remove_follow(twitter_system, active_user, unfollow_id);
    }
    // OTHERWISE THE unfollow_id IS NOT BEING FOLLOWED BY active_user
    else
    {
        // PRINT ERROR
        printf("You don't follow that user! Choose a user you follow to unfollow them.\n");
    }
    
    // PAUSE UNTIL USER INPUT
    hold_until_enter();
}