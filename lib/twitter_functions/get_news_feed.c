// REQUIRED FOR CONSTANT VALUES
#include "../../utils/constants.h"

// INCLUDE STRUCTURES USED
#include "../../utils/structs.h"

// INCLUDE HELPER FUNCTIONS
#include "../../helpers/helpers.h"
#include "../../helpers/feed_helpers.h"

// INCLUDE DISPLAY LIBRARY
#include "../display/display.h"

// FUNCTION (WITH USERFLOW) TO SHOW TWITTER FEED
void get_news_feed(twitter *twitter_system, user *active_user)
{
    // DISPLAY TITLE
    display_title("YOUR FEED");

    // SHOW 10 MOST RECENT POSTS
    print_posts(twitter_system, active_user, DISPLAY_TWEETS);

    // PAUSE UNTIL USER INPUT
    hold_until_enter();
}