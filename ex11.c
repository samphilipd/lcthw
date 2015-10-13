#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = 0;  // watch for this
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    // EXTRA CREDIT
    // print it backards
    for (int i = num_states; i > 0; --i)
        printf("state %d: %s\n", i, states[i - 1]);

    // copy values from argv to states
    i = 0;
    while(i < num_states) {
        states[i] = argv[i];
        ++i;
    }
    // strings are not copied, only the pointers to them.
    // for example, if I modify argv[1]
    argv[1] = "hello, I am a new string";
    // and now print states[1]
    printf("what? this one hasn't changed: %s\n", states[1]);

    return 0;
}
