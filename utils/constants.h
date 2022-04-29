#ifndef COMP10050_ASSIGNMENT_2_CONSTANTS_H
#define COMP10050_ASSIGNMENT_2_CONSTANTS_H

#define TWEET_LENGTH 280  // Max length of a tweet
#define USR_LENGHT 100    // Max length of a username
#define MAX_FOLLOWERS 30  // Max num of a followers
#define MAX_FOLLOWING 30  // Max num of following users
#define MAX_USERS 100     // Max num of users
#define DISPLAY_TWEETS 10 // Number of Tweets to Display

#define COLS 4
#define ID_COL 3
#define USERNAME_COL 20
#define FOLLOWERS_COL 15
#define FOLLOWING_COL 15
#define TOTAL (ID_COL + USERNAME_COL + FOLLOWERS_COL + FOLLOWING_COL + (strlen(BORDER) * (COLS + 1)))
#define LONG_CELL (ID_COL + USERNAME_COL + FOLLOWERS_COL + FOLLOWING_COL + (strlen(BORDER) * (COLS - 1)))
#define BORDER " | "

#endif