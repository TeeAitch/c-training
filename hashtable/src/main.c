#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct item
{
    char name[MAX_NAME];

    //...could be add more attri.
} item_t;

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

int main()
{
    printf("Josh     ==> %u\n", hash("Josh"));
    printf("Helena   ==> %u\n", hash("Helena"));
    printf("Gabriel  ==> %u\n", hash("Gabriel"));
    printf("Jenna    ==> %u\n", hash("Jenna"));
    printf("Dariel   ==> %u\n", hash("Dariel"));
    printf("Doe      ==> %u\n", hash("Doe"));

    return 0;
}