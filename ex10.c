#include <stdio.h>

// another version of 'echo'
int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why am I skipping argv[0]? <= because that is traditioanlly the executable name
    if (argc == 1) {
        printf("no args\n");
    } else {
        for(i = 1; i < argc; i++) { // we also do not print the final one because this is traditionally a nul
            printf("arg %d: %s\n", i, argv[i]);
        }
    }

    // let's make our own array of strings
    char *states[] = { // array of char pointers
        "California", "Oregon", "Washington", "Texas"
    };
    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}
