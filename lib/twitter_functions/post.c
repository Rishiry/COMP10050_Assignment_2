// C LIBRARIES
#include <stdio.h>
#include <string.h>

// REQUIRED FOR CONSTANT VALUES
#include "../../utils/constants.h"

// INCLUDE STRUCTURES USED
#include "../../utils/structs.h"

// INCLUDE HELPER FUNCTIONS
#include "../../helpers/helpers.h"
#include "../../helpers/feed_helpers.h"

// INCLUDE DISPLAY LIBRARY
#include "../display/display.h"

// FUNCTION (WITH USERFLOW) TO POST A NEW TWEET
void post(twitter *twitter_system, user *active_user)
{

    // DISPLAY TITLE
    display_title("TWEET SOMETHING!");

    // PRINT ALERT
    printf("Remember your Limit is %d Chars!\n\n> ", TWEET_LENGTH);

    // DECLARE VARIABLE TO HOLD TWEET TEXT
    char tweet_text[TWEET_LENGTH];

    // USER INPUT (OF LENGTH=TWEET_LENGTH) 
    fgets(tweet_text, TWEET_LENGTH, stdin);
    
    // REMOVE NEWLINE CHAR FROM TWEET (ALWAYS PRESENT AT THE END AS USER HITS ENTER TO SUBMIT)
    tweet_text[strcspn(tweet_text, "\n")] = 0;

    // IF TWEET LEN IS 0
    if (strlen(tweet_text) == 0)
    {
        // PRINT ERROR
        printf("Can't post an empty tweet!");
    }
    // OTHERWISE
    else
    {
        // ADD TWEET TO THE LINKED LIST
        create_post(twitter_system, active_user, tweet_text);

        // PRINT MESSAGE
        printf("\nPosted!\n");
    }

    // PAUSE UNTIL USER INPUT
    hold_until_enter();
}