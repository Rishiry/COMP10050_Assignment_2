#ifndef COMP10050_ASSIGNMENT_2_TWITTER_CREATE_H
#define COMP10050_ASSIGNMENT_2_TWITTER_CREATE_H

#include <stdbool.h>

#endif

void initialize_empty_users(twitter * twitter_system);
bool check_username_unique(twitter * twitter_system, char username[USR_LENGHT]);
void input_username(char * temp_username);
bool input_exit(void);
void display_users(twitter * twitter_system);
void create_twitter_system(twitter * twitter_system);
