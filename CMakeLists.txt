cmake_minimum_required(VERSION 3.21)
project(COMP10050_Assignment_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(COMP10050_Assignment_2 main.c utils/structs.h utils/constants.h lib/twitter_create/twitter_create.h lib/twitter_create/twitter_create.c utils/display_users.h utils/display_users.c lib/twitter_functions/twitter_functions.h lib/twitter_functions/twitter_functions.c)
