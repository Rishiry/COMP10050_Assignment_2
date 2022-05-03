#ifndef COMP10050_ASSIGNMENT_2_FEED_HELPERS_H
#define COMP10050_ASSIGNMENT_2_FEED_HELPERS_H

// FUNCTION PROTOTYPES FOR FEED HELPER FUNCTIONS
void create_post(twitter *twitter_system, user *active_user, char msg[TWEET_LENGTH]);
void print_posts(twitter *twitter_system, user *active_user, int count);
void remove_all_user_posts(twitter *twitter_system, user *active_user);

#endif