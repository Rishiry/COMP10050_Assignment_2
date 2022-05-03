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

// FUNCTION (WITH USERFLOW) TO FOLLOW ANOTHER USER
void follow(twitter *twitter_system, user *active_user)
{
    // DISPLAY TITLE
    display_title("FOLLOW SOMEONE! (Type Exit to Quit)");

    // DISPLAY ALL USERS NOT ALREADY BEING FOLLOWED
    display_users_with_filter(twitter_system, active_user->following, active_user->num_following, active_user->user_id);

    // DECLARE VARIABLE TO STORE USERNAME
    char follow_username[USR_LENGHT];

    // INPUT VALID USERNAME FROM USER
    input_username(twitter_system, &follow_username[0]);

    // GET ID OF USER FROM follow_username
    int follow_id = get_user_id_from_username(twitter_system, follow_username);

    // IF follow_id IS -2 THEN THE RESERVED KEYWORD "Exit" WAS USED
    if (follow_id == -2)
    {
        // HENCE WE DO NOTHING
        ;
    }
    // IF follow_id IS THE SAME AS active_user->user_id
    else if (follow_id == active_user->user_id)
    {
        // USER WAS TRYING TO FOLLOW THEMSELVES, PRINT ERROR
        printf("Ops that's your ID.\n");
    }
    // IF follow_id IS LESS THAN 0 OR MORE THAN NUMBER OF USERS
    else if (follow_id < 0 || follow_id > twitter_system->num_users)
    {
        // PRINT ERROR
        printf("Invalid User ID. Please Try Again.\n");
    }
    // IF follow_id IN active_user->following
    else if (value_in_array(active_user->following, active_user->num_following, follow_id))
    {
        // USER WAS ALREADY FOLLOWING THAT USER, PRINT ERROR
        printf("You already follow that User. Please Choose a new user to follow from the Table above.\n");
    }
    // IF active_user HAS REACHED MAX_FOLLOWING LIMIT
    else if (active_user->num_following > MAX_FOLLOWING)
    {
        // PRINT ERROR
        printf("Sorry, you have hit the Max Following Limit. Please unfollow some people first.\n");
    }
    // IF USER THAT IS BEING FOLLOWED HIT FOLLOWER COUNT
    else if (twitter_system->users[follow_id].num_followers > MAX_FOLLOWERS)
    {
        // PRINT ERROR
        printf("Sorry, the person you are trying to follow has hit the Max Followers Limit.\n");
    }
    // FINALLY, IF NONE OF THE CONDITIONS MET, WE KNOW IT IS A VALID REQUEST
    else
    {
        // PRINT MESSAGE
        printf("You have chosen to follow: %s\n", twitter_system->users[follow_id].username);

        // MAKE active_user FOLLOW USER WITH follow_id
        add_follow(twitter_system, active_user, follow_id);
    }


    // PAUSE UNTIL USER INPUT
    hold_until_enter();
}