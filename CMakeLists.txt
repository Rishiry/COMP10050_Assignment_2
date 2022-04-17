cmake_minimum_required(VERSION 3.21)
project(COMP10050_Assignment_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(COMP10050_Assignment_2 main.c utils/structs.h utils/constants.h lib/twitter_create/twitter_create.h lib/twitter_create/twitter_create.c lib/display/display_users.h lib/display/display_users.c lib/twitter_functions/twitter_functions.h lib/twitter_functions/twitter_functions.c lib/twitter_functions/follow.h lib/twitter_functions/follow.c lib/twitter_functions/unfollow.c lib/twitter_functions/unfollow.h helpers/helpers.h helpers/helpers.c helpers/twitter_helpers.c helpers/twitter_helpers.h lib/twitter_functions/post.h lib/twitter_functions/post.c helpers/feed_helpers.h helpers/feed_helpers.c)
