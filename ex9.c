#include <stdio.h>

int main(int argc, char *argv[])
{
        int numbers[4] = {0}; // C autofills the rest of the array with zeroes
        char name[4] = {'a'}; // if you only set the first value

        // print raw
        printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2],
                numbers[3]);

        printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);

        printf("name: %s\n", name);

        // setup the numbers
        numbers[0] = 1;
        numbers[1] = 2;
        numbers[2] = 3;
        numbers[3] = 4;

        // setup the name
        name[0] = 'S';
        name[1] = 'a';
        name[2] = 'm';
        name[3] = '\0';

        // then print them out initialized
        printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2],
                numbers[3]);

        printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);

        // print the name like a string
        printf("name: %s\n", name);

        // another way to use name
        char *another = "Sam"; // == char another[] = "Sam";

        printf("another: %s\n", another);

        // you can access pointers using array notation
        printf("another each: %c %c %c %c\n", another[0], another[1],
                another[2], another[3]);
        // or by incrementing the pointer
        printf("another each with pointers: %c %c %c %c\n", *another,
                *(another+1), *(another+2), *(another+3));

        // BREAKAGE

        // what happens if we do an unsequenced increment?
        printf("another with undefined increment order: %c %c %c %c\n", *another,
                *++another, *++another, *++another);

        // what happens if we assign chars to numbers
        numbers[0] = 'S';
        numbers[0] = 'a';
        numbers[0] = 'm';
        numbers[0] = 0;
        printf("numbers with chars: %c %c %c %c\n", numbers[0], numbers[1],
                numbers[2], numbers[3]);

        // what if we treat name as an array of int
        printf("name as ints: %d %d %d %d\n", name[0], name[1], name[2],
                name[3]);

        // or an array of floats?
        printf("name as floats: %f %f %f %f\n", name[0], name[1], name[2],
                name[3]);

        // what if we treat name as a pointer to ONE int
        printf("name as pointer to int: %d\n", *name);

        // what about if we treat name as an array with one int in it
        printf("name as array of one int: %d\n", name[0]);

        // what about if we treat name as a pointer to a float
        // what if we treat name as a pointer to ONE int
        printf("name as pointer to float: %f\n", *name);

        return 0;
}
