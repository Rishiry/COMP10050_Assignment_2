#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

void display_single_user(user *active_user){
    REPEAT_CHAR('-', TOTAL);
    display_cell(ID_COL, "ID", false);
    display_cell(USERNAME_COL, "YOUR USERNAME", false);
    display_cell(FOLLOWERS_COL, "YOUR FOLLOWERS", false);
    display_cell(FOLLOWING_COL, "FOLLOWING", true);
    REPEAT_CHAR('-', TOTAL);
    display_row(*active_user);
    REPEAT_CHAR('-', TOTAL);
}

void display_users(twitter *twitter_system)
{
    REPEAT_CHAR('=', TOTAL);

    display_header();

    for (int j = 0; j < twitter_system->num_users; j++)
    {
        display_row(twitter_system->users[j]);
    }

    REPEAT_CHAR('=', TOTAL);
}

void display_users_by_id(twitter *twitter_system, int ids[], int num_ids)
{
    REPEAT_CHAR('=', TOTAL);

    display_header();

    for (int j = 0; j < num_ids; j++)
    {
        display_row(twitter_system->users[ids[j]]);
    }

    REPEAT_CHAR('=', TOTAL);
}

void display_users_with_filter(twitter *twitter_system, int ids[], int num_ids, int active_id)
{
    REPEAT_CHAR('=', TOTAL);

    display_header();

    for (int j = 0; j < twitter_system->num_users; j++)
    {
        if(!value_in_array(ids, num_ids, j) && !(j == active_id)) {
            display_row(twitter_system->users[j]);
        }
    }

    REPEAT_CHAR('=', TOTAL);
}