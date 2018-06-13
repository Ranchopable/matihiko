#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for credit card number
    long n;
    do
    {
        n = get_long_long("Number: ");
    }
    while (n < 0);

    //assign variables to each card digit;
    int n1 = n % 10;
    int n2 = (n % 100) / 10;
    int n3 = (n % 1000) / 100;
    int n4 = (n % 10000) / 1000;
    int n5 = (n % 100000) / 10000;
    int n6 = (n % 1000000) / 100000;
    int n7 = (n % 10000000) / 1000000;
    int n8 = (n % 100000000) / 10000000;
    int n9 = (n % 1000000000) / 100000000;
    int n10 = (n % 10000000000) / 1000000000;
    int n11 = (n % 100000000000) / 10000000000;
    int n12 = (n % 1000000000000) / 100000000000;
    int n13 = (n % 10000000000000) / 1000000000000;
    int n14 = (n % 100000000000000) / 10000000000000;
    int n15 = (n % 1000000000000000) / 100000000000000;
    int n16 = (n % 10000000000000000) / 1000000000000000;

    //Luhn's algorithm
    //Get the products of every second digit from the right times 2, then get the individual digits, e.g. 12 becomes 2,1
    int i2 = 2 * n2;
    int j2 = i2 % 10;
    int k2 = (i2 % 100) / 10;
    int i4 = 2 * n4;
    int j4 = i4 % 10;
    int k4 = (i4 % 100) / 10;
    int i6 = 2 * n6;
    int j6 = i6 % 10;
    int k6 = (i6 % 100) / 10;
    int i8 = 2 * n8;
    int j8 = i8 % 10;
    int k8 = (i8 % 100) / 10;
    int i10 = 2 * n10;
    int j10 = i10 % 10;
    int k10 = (i10 % 100) / 10;
    int i12 = 2 * n12;
    int j12 = i12 % 10;
    int k12 = (i12 % 100) / 10;
    int i14 = 2 * n14;
    int j14 = i14 % 10;
    int k14 = (i14 % 100) / 10;
    int i16 = 2 * n16;
    int j16 = i16 % 10;
    int k16 = (i16 % 100) / 10;

    //add these digits
    int l1 = j2 + k2 + j4 + k4 + j6 + k6 + j8 + k8 + j10 + k10 + j12 + k12 + j14 + k14 + j16 + k16;
    //add the other digits from the card number
    int l2 = n1 + n3 + n5 + n7 + n9 + n11 + n13 + n15;
    //get the sum
    int l = l1 + l2;

    //validity test based on luhn's algorithm and card length (13 to 16 digits long)
    if (l % 10 == 0 && n < 10000000000000000 && n > 999999999999)
    {
        //AMEX
        //Card number length (15 digits) verification and first digit verification
        if (n < 1000000000000000 && n > 99999999999999 && n15 == 3)
        {
            //Second digit verification
            if (n14 == 4 || n14 == 7)
            {
                printf("AMEX\n");
            }
            //when the if criteria are met for a card, there must also be an "else print invalid"
            else
            {
                printf("INVALID\n");
            }
        }
        //Mastercard
        //Card number length (16 digits) verification and first digit verification
        else if (n < 10000000000000000 && n > 999999999999999 && n16 == 5)
        {
            //Second digit verification
            if (n15 > 0 && n15 < 6)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        //VISA
        //verify a first digit of 4 for all four possible card lengths
        //13 digits long
        else if (n < 10000000000000 && n13 == 4)
        {
            printf("VISA\n");
        }
        //14 digits long
        else if (n < 100000000000000 && n > 9999999999999 && n14 == 4)
        {
            printf("VISA\n");
        }
        //15 digits long
        else if (n < 1000000000000000 && n > 99999999999999 && n15 == 4)
        {
            printf("VISA\n");
        }
        //16 digits long
        else if (n < 10000000000000000 && n > 999999999999999 && n16 == 4)
        {
            printf("VISA\n");
        }
        //print "INVALID" if card length and Luhn's algorithm apply, but is not verified as a card type
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    //return 0 as per the spec of the problem
    return 0;
}
