#ifndef COMP10050_ASSIGNMENT_2_STRUCTS_H
#define COMP10050_ASSIGNMENT_2_STRUCTS_H

#include "constants.h"

#endif

typedef struct tweet{
    int id;
    char msg[TWEET_LENGTH];
    char user[USR_LENGHT];

}tweet;

typedef struct user{
    int user_id;
    char username[USR_LENGHT];

    int followers[MAX_FOLLOWERS];
    int num_followers;

    int following[MAX_FOLLOWING];
    int num_following;
}user;

typedef struct twitter{
    struct user users[MAX_USERS];
    int num_users;

    struct tweet tweets[MAX_TWEETS];
    int num_tweets;
} twitter;
