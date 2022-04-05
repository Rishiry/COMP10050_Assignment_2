#ifndef COMP10050_ASSIGNMENT_2_STRUCTS_H
#define COMP10050_ASSIGNMENT_2_STRUCTS_H

#endif

typedef struct tweet{
    int id;
    char msg[TWEET_LENGTH];
    char user[USR_LENGHT];

}tweet;

typedef struct user{
    char username[USR_LENGHT];

    char followers[MAX_FOLLOWERS];
    int num_followers;

    char following[MAX_FOLLOWING];
    int num_following;
}user;

typedef struct twitter{
    struct user users[MAX_USERS];
    struct tweet tweets[MAX_TWEETS];

    int num_users;
} twitter;
