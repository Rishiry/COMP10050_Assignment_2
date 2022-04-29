#include <stdio.h>

#include "utils/structs.h"

#include "lib/twitter_create/twitter_create.h"
#include "lib/twitter_functions/twitter_functions.h"

int main()
{

    struct twitter twitter_system;

    create_twitter_system(&twitter_system);
    run_twitter_functions(&twitter_system);

    return 0;
}