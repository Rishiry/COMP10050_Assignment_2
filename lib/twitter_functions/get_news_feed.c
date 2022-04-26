#include <stdio.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"
#include "../../helpers/feed_helpers.h"

#include "../display/display.h"

void get_news_feed(twitter *twitter_system, user *active_user)
{

    display_title("YOUR FEED");
    print_posts(twitter_system, active_user, DISPLAY_TWEETS);

    printf("(Press Enter to Continue)");
    while (getchar() != '\n')
        ;
}