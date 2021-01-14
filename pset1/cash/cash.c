#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float dollars;
    do
    {
        // asks users for height
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // rounds it to nearest penny
    int cents = round(dollars * 100);
    // printf("cents: %i \n",cents);


    int counter = 0;

    // counts if cash is more than 25 than deducts 25 and ads 1 to the counter
    while (cents >= 25)
    {
        cents -= 25;
        counter += 1;
    }

    // counts if cash is more than 10 than deducts 10 and ads 1 to the counter
    while (cents >= 10)
    {
        cents -= 10;
        counter += 1;
    }

    // counts if cash is more than 5 than deducts 5 and ads 1 to the counter
    while (cents >= 5)
    {
        cents -= 5;
        counter += 1;
    }

    // counts if cash is more than 1 than deducts 1 and ads 1 to the counter
    while (cents >= 1)
    {
        cents -= 1;
        counter += 1;
    }
    // returns total counter as change owned
    printf("%i \n", counter);

}