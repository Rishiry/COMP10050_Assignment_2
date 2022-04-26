#include <stdio.h>
#include <string.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"
#include "../../helpers/feed_helpers.h"

#include "../display/display.h"

void post(twitter *twitter_system, user *active_user)
{

    char tweet_text[TWEET_LENGTH];

    display_title("TWEET SOMETHING!");

    printf("Remember your Limit is %d Chars!\n\n", TWEET_LENGTH);

    fgets(tweet_text, TWEET_LENGTH, stdin);
    tweet_text[strcspn(tweet_text, "\n")] = 0;

    if (strlen(tweet_text) == 0)
    {
        printf("Can't post an empty tweet!");
    }
    else
    {

        create_post(twitter_system, active_user, tweet_text);

        printf("\nPosted!\n");
    }
}