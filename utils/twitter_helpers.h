#ifndef COMP10050_ASSIGNMENT_2_TWITTER_HELPERS_H
#define COMP10050_ASSIGNMENT_2_TWITTER_HELPERS_H

#endif

#include <stdbool.h>

bool check_username_unique(twitter * twitter_system, char username[]);
int get_user_id_from_username(twitter * twitter_system, char username[]);
void input_unique_username(twitter *twitter_system, char *temp_username);
void input_username(twitter *twitter_system, char *temp_username);