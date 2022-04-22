#include <stdio.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"
#include "../../helpers/helpers.h"
#include "../../helpers/twitter_helpers.h"
#include "../display/display.h"

void follow(twitter *twitter_system, user *active_user)
{
    display_title("FOLLOW SOMEONE! (Type Exit to Quit)");

    display_users_with_filter(twitter_system, active_user->following, active_user->num_following, active_user->user_id);

    char follow_username[USR_LENGHT];
    input_username(twitter_system, &follow_username[0]);

    int follow_id = get_user_id_from_username(twitter_system, follow_username);

    if(follow_id == -2) {
        ;
    }
    else if (follow_id == active_user->user_id)
    {
        printf("Ops that's your ID.\n");
    }
    else if (follow_id < 0 || follow_id > twitter_system->num_users)
    {
        printf("Invalid User ID. Please Try Again.\n");
    }
    else if (value_in_array(active_user->following, active_user->num_following, follow_id))
    {
        printf("You already follow that User ID. Please Choose a new user to follow from the Table above.\n");
    }
    else if (active_user->num_following > MAX_FOLLOWING)
    {
        printf("Sorry, you have hit the Max Following Limit. Please unfollow some people first.\n");
    }
    else
    {
        printf("You have chosen to follow: %s\n", twitter_system->users[follow_id].username);

        add_follow(twitter_system, active_user, follow_id);
    }
}