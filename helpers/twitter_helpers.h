#ifndef COMP10050_ASSIGNMENT_2_TWITTER_HELPERS_H
#define COMP10050_ASSIGNMENT_2_TWITTER_HELPERS_H

// C LIBRARIES
#include <stdbool.h>

// FUNCTION PROTOTYPES FOR TWITTER HELPER FUNCTIONS
bool check_username_unique(twitter *twitter_system, char username[]);
int get_user_id_from_username(twitter *twitter_system, char username[]);
void input_unique_username(twitter *twitter_system, char *temp_username);
void input_username(twitter *twitter_system, char *temp_username);
void initialize_empty_users(twitter *twitter_system);
void add_follow(twitter *twitter_system, user *active_user, int follow_id);
void remove_follow(twitter *twitter_system, user *active_user, int unfollow_id);

#endif