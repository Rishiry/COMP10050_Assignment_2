#include <stdio.h>
#include <string.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"
#include "../../helpers/helpers.h"

void post(twitter * twitter_system, user * active_user){

    char tweet_text[TWEET_LENGTH];

    printf("Write a Post!\n Remember your Limit is %d Chars!\n\n", TWEET_LENGTH);

    fgets(tweet_text, TWEET_LENGTH, stdin);

    printf("%s", tweet_text);
    // NOW NEED TO PUT THIS INTO THE SYSTEM


}