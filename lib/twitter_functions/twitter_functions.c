#include <stdio.h>
#include <stdbool.h>

#include "../../utils/constants.h"
#include "../../utils/structs.h"

void run_twitter_functions(twitter * twitter_system) {
    bool stop = false;

    while (!stop){
        for(int j = 0; j < twitter_system->num_users; j++){
            user *active_user = &twitter_system->users[j];
            printf("Active User: %s", active_user->username);
        }

        stop = true;
    }

}