#include <stdio.h>

void toh(int no_disk, char from, char to, char aux);

void main()
{
    toh(3, 'A', 'C', 'B');
}

void toh(int no_disk, char from, char to, char aux)
{
    if (no_disk > 1)
    {
        toh(no_disk - 1, from, aux, to);
        printf("Move  disk from %c to %c.\n", from, to);

        toh(no_disk - 1, aux, to, from);
    }
    else if (no_disk == 1)
    {
        printf("Move disk from %c to %c.\n", from, to);
    }
}