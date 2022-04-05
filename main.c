#include <stdio.h>

#include "utils/constants.h"
#include "utils/structs.h"

#include "lib/twitter_create/twitter_create.h"

int main() {

    twitter twitter_system;

    create_twitter_system(&twitter_system);

    return 0;
}