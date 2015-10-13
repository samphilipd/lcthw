#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
void print_letters(char arg[], size_t len);

void print_arguments(int argc, char *argv[])
{
    int i = 0;

    for(i = 0; i < argc; i++) {
        size_t len = strlen(argv[i]);
        print_letters(argv[i], len);
    }
}

// rewritten so as not to rely on '\0' terminator
void print_letters(char arg[], size_t len)
{
    int i = 0;

    for(i = 0; i < len; i++) {
        char ch = arg[i];

        if(isalpha(ch) || isblank(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }

    printf("\n");
}



int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}
