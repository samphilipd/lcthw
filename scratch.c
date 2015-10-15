#include <stdio.h>

int main(int argc, char *argv[])
{
    char mutable[] = "Hello"; // allocate space on the stack and fill it with 'Hello'
    mutable[3] = 'X';
    printf("%s\n", mutable);

    char *immutable = "Hello"; // create a pointer to the literal
    immutable[3] = 'X'; // nonsense, literals are immutable. This will probably cause a crash
    printf("%s\n", immutable);
}
