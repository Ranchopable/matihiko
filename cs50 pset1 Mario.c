#include <stdio.h>
#include <cs50.h>

//next step is to make bottom row have "n+1" blocks and top row have two blocks!

int main(void)
{
    //prompt user for a non-negative integer no greater than 23
    int n;
    //declare loop variables
    int i;
    int j;
    int k;
    int o;
    //declare block counter variable
    int l = 0;

    do
    {
        n = get_int("Height: ");
    }
    while (n > 23 || n < 0);

    //declare space counter variable
    int m = n - 1;

    //using the integer n provided by user to build a half-pyramid of that height, eg "n" rows tall
    //print this many rows
    for (i = 0; i < n; i ++)
    {
        //print pyramid 1
        //print columns
        //print spaces
        for (j = m; j > 0; j --)
        {
            printf(" ");
        }

        //add one to block counter l
        l ++;

        //subtract one from the space counter
        m --;

        //print blocks
        for (k = 0; k < l; k ++)
        {
            printf("#");
        }

        //print the gap
        printf("  ");

        //print pyramid 2
        //print columns
        //print blocks
        for (o = 0; o < l; o ++)
        {
            printf("#");
        }

        //new line
        printf("\n");
    }
}
