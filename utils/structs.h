#ifndef COMP10050_ASSIGNMENT_2_STRUCTS_H
#define COMP10050_ASSIGNMENT_2_STRUCTS_H

#include "constants.h"

typedef struct tweet
{
    int id;
    char msg[TWEET_LENGTH];

    int user_id;

    struct tweet *last;
} tweet;

typedef struct user
{
    int user_id;
    char username[USR_LENGHT];

    int followers[MAX_FOLLOWERS];
    int num_followers;

    int following[MAX_FOLLOWING];
    int num_following;
} user;

typedef struct twitter
{
    struct user users[MAX_USERS];
    int num_users;

    struct tweet *latest_tweet;
    int num_tweets;
} twitter;

#endif
