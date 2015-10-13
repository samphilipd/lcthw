#include <stdio.h>

// another version of 'echo'
int main(int argc, char *argv[])
{
    int i = 0;

    // let's make our own array of strings
    char *states[] = { // array of char pointers
        "California", "Oregon", "Washington", "Texas"
    };
    int num_states = 4;

    // BREAKAGE: what if I assign an element from states to argv
    argv[1] = states[1];
    states[2] = argv[2];
    // result: its perfectly fine

    // go through each string in argv
    // why am I skipping argv[0]? <= because that is traditioanlly the executable name
    if (argc == 1) {
        printf("no args\n");
    } else {
        for(i = 1; i < argc; i++) { // we also do not print the final one because this is traditionally a nul
            printf("arg %d: %s\n", i, argv[i]);
        }
    }

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    // BREAKAGE
    // what happens if I try to print a null pointer?
    printf("%s\n", NULL);
    // prints (null)

    return 0;
}
