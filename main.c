// C LIBRARIES
#include <stdio.h>

// INCLUDE STRUCTURES USED
#include "utils/structs.h"

// INCLUDE DRIVER MODULES
#include "lib/twitter_create/twitter_create.h"
#include "lib/twitter_functions/twitter_functions.h"

int main()
{

    // DECLARE TWITTER SYSTEM WHICH ACTS LIKE A DATABASE
    struct twitter twitter_system;

    // CREATE TWITTER SYSTEM
    create_twitter_system(&twitter_system);

    // RUN TWITTER SYSTEM
    run_twitter_functions(&twitter_system);

    return 0;
}