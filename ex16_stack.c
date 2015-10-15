#include <stdio.h>
#include <assert.h> // to use assert
#include <string.h> // to use strdup

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person Person_create(char * name, int age, int height, int weight)
{
    struct Person who;
    who.name = name; // WARNING: name will be immutable
    who.age = age;
    who.height = height;
    who.weight = weight;

    return who;
}

void Person_print(struct Person who)
{
    printf("Name: %s\n", who.name);
    printf("\tAge :%d\n", who.age);
    printf("\tHeight: %d\n", who.height);
    printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
    // declare structs on the stack, no need to worry about freeing memory
    struct Person joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person frank = Person_create("Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at %p\n", &joe);
    Person_print(joe);

    printf("Frank is at %p\n", &frank);
    Person_print(frank);

    // make everyone age 20 years
    joe.age += 20;
    joe.height -= 2;
    joe.weight += 40;
    Person_print(joe);

    frank.age  += 20;
    frank.weight += 20;
    Person_print(frank);

    // BREAKAGE
    // Person_destroy(NULL);
    // Person_print(NULL);
    return 0;
}
