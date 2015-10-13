#include <stdio.h>

int main(int arg, char * argv[])
{
        int distance = 100;
        float power = 2.345f;
        double superpower = 56789.4532;
        char initial = 'P';
        char first_name[] = "Sam";
        char last_name[] = "Davies";

        printf("You are %d miles away.\n", distance);
        printf("You have %f levels of power.\n", power);
        printf("You have %f awesome superpowers.\n", superpower);
        printf("I have an initial %c.\n", initial);
        printf("I have a first name %s.\n", first_name);
        printf("I have a last name %s.\n", last_name);
        printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);
        printf("");

        return 0;
}
