#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("ERROR: You need at least one argument.\n");
        // this is how you abort a program
        return 1;
    }

    for (int j = 1; j < argc; ++j) {
        printf("Argument %d was %s\n", j, argv[j]);
        int i;
        char ciletter;
        char letter;
        for (i = 0; argv[j][i] != '\0'; i++) {
            letter = argv[j][i];
            if (letter > 90) // treat as lowercase
                ciletter = letter - 32; // convert to uppercase
            else
                ciletter = letter;

            switch(ciletter) {
                case 'A':
                    printf("%d: %c\n", i, letter);
                    break;

                case 'E':
                    printf("%d: %c\n", i, letter);
                    break;

                case 'I':
                    printf("%d: %c\n", i, letter);
                    break;

                case 'O':
                    printf("%d: %c\n", i, letter);
                    break;

                case 'U':
                    printf("%d: %c\n", i, letter);
                    break;

                case 'Y':
                    if(i > 1) {
                        // it's only sometimes Y
                        printf("%d: %c\n", i, letter);
                        break;
                    }

                default:
                    printf("%d: %c is not a vowel\n", i, letter);
            }
        }
    }

    return 0;
}
