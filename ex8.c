#include <stdio.h>

int main(int argc, char *argv[])
{
        int areas[] = {10, 12, 13, 14, 20};
        char name[] = "Sam";
        char full_name[] = {
                'S', 'a', 'm', ' ', 'P', '.', ' ', 'D', 'a', 'v', 'i', 'e', 's',
                '\0'
        };

        // On OS X, sizeof returns signed Long
        printf("The size of an int: %ld\n", sizeof(int)); // 4

        printf("The size of areas (int[]): %ld\n", sizeof(areas)); // 20

        printf("The number of ints in areas: %ld\n",
               sizeof(areas) / sizeof(int)); // 5

        printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1]); // 10, 12

        printf("The size of a char: %ld\n", sizeof(char)); // 1
        printf("The size of name (char[]): %ld\n", sizeof(name)); // 4 <= nul byte is included in size
        printf("The number of chars: %ld\n", sizeof(name) / sizeof(char)); // 4

        printf("The size of full_name (char[]): %ld\n", sizeof(full_name)); // 14
        printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char)); // 14

        printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

        // breakage
        char name_bad[] = { 'S', 'a', 'm'};
        printf("name without nul terminator: %s\n", name_bad);

        printf("out of bounds access: %c\n", areas[1000]);
        printf("out of bounds access: %c\n", name[10]);

        return 0;
}
