#include <cs50.h>
//needed for isalpha, isupper, islower
#include <ctype.h>
#include <stdio.h>
//needed for atoi
#include <stdlib.h>
//needed for strlen
#include <string.h>

//The variables argc and argv will be computed for by the compiler, so we won't need to explicitly declare them
int main(int argc, string argv[])
{
    //assign the keyword string "kw"
    string kw = argv[1];

    //check acceptability of number of command line arguments
    if (argc == 2)
    {
        //return error if any characters of keyword are not alphabetical
        for (int i = 0, n = strlen(kw); i < n; i++)
        {
            if (!isalpha(kw[i]))
            {
                printf("ERROR\n");
                return 1;
            }
        }

        //prompt the user for the plaintext
        string p = get_string("plaintext: ");

        printf("ciphertext: ");

        //VIGENERE:initialise variables to be used in vigenere ci = (pi + kj) % 26 equation
        int al, ci, kj, kal;

        //initialising keyword place holder
        int x = 0;

        //initialise value for length of keyword
        int w = strlen(kw);

        //for each character in the plaintext
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            //if it is alphabetical then shift by 'kj'
            if (isalpha(p[i]))
            {
                //loop if upper case
                if (isupper(p[i]))
                {
                    //establish kal, the alpha version of kj
                    kal = kw[x];

                    //establish kj, the number of steps the plaintext character must take, for both upper and lower case kj
                    if (isupper(kw[x]))
                    {
                        kj = (kal - 65);
                    }
                    else
                    {
                        kj = (kal - 97);
                    }

                    //move to next letter of keyword, using wraparound. This means that if the plaintext is longer than the keyword, it continues to encrypt correctly
                    x = (x + 1) % w;

                    //ASCII to alphabetical index
                    al = (p[i] - 65);

                    //run the cipher equation and convert back to ASCII
                    ci = ((al + kj) % 26) + 65;

                    //print the cipher character
                    printf("%c", ci);
                }
                //loop if lower case
                else
                {
                    //establish kal, the alpha version of kj, using the wraparound function
                    kal = kw[x];

                    //establish kj, the number of steps the plaintext character must take, for both upper and lower case kj
                    if (isupper(kw[x]))
                    {
                        kj = (kal - 65);
                    }
                    else
                    {
                        kj = (kal - 97);
                    }

                    //move to next letter of keyword, using wraparound
                    x = (x + 1) % w;

                    //ASCII to alphabetical index
                    al = (p[i] - 97);

                    //run the cipher equation and convert back to ASCII
                    ci = ((al + kj) % 26) + 97;

                    //print the cipher character
                    printf("%c", ci);
                }
            }
            //else print as is
            else
            {
                printf("%c", p[i]);
            }
        }

        printf("\n");
        return 0;
    }
    else
    {
        printf("ERROR\n");
        return 1;
    }
}
