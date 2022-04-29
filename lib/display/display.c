#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"
#include "../../helpers/helpers.h"

void display_cell(int size, char content[], bool last)
{
    printf("%s", BORDER);

    printf("%-0*s", size, content);

    if (last)
    {
        printf("%s\n", BORDER);
    }
}

void display_row(user row)
{
    display_cell(ID_COL, int_to_str(row.user_id + 1), false);
    display_cell(USERNAME_COL, row.username, false);
    display_cell(FOLLOWERS_COL, int_to_str(row.num_followers), false);
    display_cell(FOLLOWING_COL, int_to_str(row.num_following), true);
}

void display_header()
{
    display_cell(ID_COL, "ID", false);
    display_cell(USERNAME_COL, "USERNAME", false);
    display_cell(FOLLOWERS_COL, "FOLLOWERS", false);
    display_cell(FOLLOWING_COL, "FOLLOWING", true);
    REPEAT_CHAR('-', TOTAL);
}

void display_single_user(user *active_user)
{
    REPEAT_CHAR('=', TOTAL);
    display_cell(ID_COL, "ID", false);
    display_cell(USERNAME_COL, "YOUR USERNAME", false);
    display_cell(FOLLOWERS_COL, "YOUR FOLLOWERS", false);
    display_cell(FOLLOWING_COL, "FOLLOWING", true);
    REPEAT_CHAR('-', TOTAL);
    display_row(*active_user);
    REPEAT_CHAR('=', TOTAL);
}

void display_users(twitter *twitter_system)
{
    REPEAT_CHAR('=', TOTAL);

    display_header();

    for (int j = 0; j < twitter_system->num_users; j++)
    {
        if (twitter_system->users[j].user_id != -1)
        {
            display_row(twitter_system->users[j]);
        }
    }

    REPEAT_CHAR('=', TOTAL);
}

void display_users_by_id(twitter *twitter_system, int ids[], int num_ids)
{
    REPEAT_CHAR('=', TOTAL);

    display_header();

    if (num_ids == 0)
    {
        display_cell(LONG_CELL, "No users to display! Type 'Exit' to Escape!", true);
    }
    else
    {
        for (int j = 0; j < num_ids; j++)
        {
            if (twitter_system->users[ids[j]].user_id != -1)
            {
                display_row(twitter_system->users[ids[j]]);
            }
        }
    }

    REPEAT_CHAR('=', TOTAL);
}

void display_users_with_filter(twitter *twitter_system, int ids[], int num_ids, int active_id)
{
    REPEAT_CHAR('=', TOTAL);

    display_header();

    int shown = 0;
    for (int j = 0; j < twitter_system->num_users; j++)
    {
        if (!value_in_array(ids, num_ids, j) && (j != active_id) && twitter_system->users[j].user_id != -1)
        {
            display_row(twitter_system->users[j]);
            shown++;
        }
    }

    if (shown == 0)
    {
        display_cell(LONG_CELL, "No users to display! Type 'Exit' to Escape!", true);
    }

    REPEAT_CHAR('=', TOTAL);
}

void display_title(char title[])
{
    int len = strlen(title);
    unsigned int pad = LONG_CELL - len;

    unsigned left_pad = pad / 2;
    unsigned int right_pad = pad - left_pad;

    REPEAT_CHAR('=', TOTAL);

    printf("%s", BORDER);

    printf("%*s", left_pad, "");
    printf("%-0*s", LONG_CELL - left_pad - right_pad, title);
    printf("%*s", right_pad, "");

    printf("%s\n", BORDER);

    REPEAT_CHAR('=', TOTAL);
}

void display_menu(int count, ...)
{

    va_list list;
    va_start(list, count);

    int col_a = 0.1 * LONG_CELL;
    int col_b = TOTAL - col_a - strlen(BORDER) * 3;

    REPEAT_CHAR('=', TOTAL);
    display_cell(col_a, "No.", false);
    display_cell(col_b, "Option", true);
    REPEAT_CHAR('-', TOTAL);

    for (int j = 0; j < count; j++)
    {
        char *str = va_arg(list, char *);

        display_cell(col_a, int_to_str(j + 1), false);
        display_cell(col_b, str, true);
    }

    va_end(list);
    REPEAT_CHAR('=', TOTAL);
}

void display_logo(void)
{

    int twitter_art_len = 6;
    char twitter_art[6][36] = {" _____          _ _   _            ",
                               "|_   _|_      _(_) |_| |_ ___ _ __ ",
                               "  | | \\ \\ /\\ / / | __| __/ _ \\ '__|",
                               "  | |  \\ V  V /| | |_| ||  __/ | ",
                               "  |_|   \\_/\\_/ |_|\\__|\\__\\___|_|   ",
                               ""};

    int max = 0;

    for (int i = 1; i < twitter_art_len; i++)
    {
        if (strlen(twitter_art[i]) > strlen(twitter_art[max]))
        {
            max = i;
        }
    }

    int len = strlen(twitter_art[max]);

    unsigned left_pad = (LONG_CELL - len) / 2;

    REPEAT_CHAR('=', TOTAL);

    for (int i = 0; i < twitter_art_len; i++)
    {

        printf("%s", BORDER);

        printf("%*s", left_pad, "");
        printf("%-0*s", strlen(twitter_art[i]), twitter_art[i]);
        printf("%*s", LONG_CELL - strlen(twitter_art[i]) - left_pad, "");

        printf("%s\n", BORDER);
    }
}

void display_tweet(char msg[TWEET_LENGTH], char author[USR_LENGHT])
{

    int col = TOTAL - strlen(BORDER) * 2;

    REPEAT_CHAR('-', TOTAL);

    printf("%s", BORDER);

    int i = 0;

    while (msg[i] != '\0')
    {
        printf("%c", msg[i++]);

        if (i % col == 0 && i != 0)
        {
            printf("%s\n%s", BORDER, BORDER);
        }
    }

    while (i % col != 0)
    {
        printf(" ");
        i++;
    }
    printf("%s\n", BORDER);

    printf("%s%0*s%s\n", BORDER, col, author, BORDER);

    REPEAT_CHAR('-', TOTAL);
}
