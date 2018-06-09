#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt user to input how much change is owed
    float i;

    do
    {
        i = get_float("Change owed: ");
    }
    while (i < 0);

    //declare variables for available coins and final output
    int q = 25;
    int d = 10;
    int n = 5;
    int p = 1;
    int c = 0;
    //convert input from float to int, and round to avoid inaccuracies
    int j = round(i * 100);

    //count the number of quarters needed
    while (j >= q)
    {
        c++;
        j = j - q;
    }

    //count the number of dimes needed
    while (j >= d)
    {
        c++;
        j = j - d;
    }

    //count the number of nickels needed
    while (j >= n)
    {
        c++;
        j = j - n;
    }

    //count the number of pennies needed
    while (j > 0)
    {
        c++;
        j = j - p;
    }

    //print the output
    printf("%i\n", c);

}
