#ifndef COMP10050_ASSIGNMENT_2_DISPLAY_USERS_H
#define COMP10050_ASSIGNMENT_2_DISPLAY_USERS_H

// C LIBRARIES
#include <stdbool.h>

// FUNCTION PROTOTYPES
void display_cell(int size, char content[], bool last);
void display_row(user row);
void display_header();
void display_single_user(user *active_user);
void display_users(twitter *twitter_system);
void display_users_by_id(twitter *twitter_system, int ids[], int num_ids);
void display_users_with_filter(twitter *twitter_system, int ids[], int num_ids, int active_id);
void display_title(char title[]);
void display_menu(int count, ...);
void display_logo(void);
void display_tweet(char *msg, char *author);

#endif