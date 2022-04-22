#include <stdio.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"
#include "../../helpers/feed_helpers.h"


void get_news_feed(twitter * twitter_system, user * active_user) {

    printf("This is what everyone else is upto:\n\n");
    print_posts(twitter_system, active_user, DISPLAY_TWEETS);

}