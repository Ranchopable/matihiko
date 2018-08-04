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
    //Run the algorithm if command line input criteria met
    //In this case argc needs to equal 2;
    //1) ./caesar
    //2) k
    if (argc == 2)
    {
        //get the key by using atoi to convert the command line input (data type string) to an int
        int k = atoi(argv[1]);
        //initialise variables to be used during ascii>alpha>ascii conversions
        int al;
        int as;
        char al2;

        //prompt the user for the plaintext
        string p = get_string("plaintext: ");

        printf("ciphertext: ");

        //for each character in the plaintext
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            //if it is alphabetical then shift by 'k'
            if (isalpha(p[i]))
            {
                //loop if upper case
                if (isupper(p[i]))
                {
                    //ASCII to alphabetical index
                    al = (p[i] - 65);

                    //alphabetical index to ASCII
                    as = (al + k) % 26;
                    al2 = (as + 65);

                    //print the cipher character
                    printf("%c", al2);
                }
                //loop if lower case
                else if (islower(p[i]))
                {
                    //ASCII to alphabetical index
                    al = (p[i] - 97);

                    //alphabetical index to ASCII
                    as = (al + k) % 26;
                    al2 = (as + 97);

                    //print the cipher character
                    printf("%c", al2);
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
    //Return error message if command line input criteria not met
    else
    {
        printf("ERROR\n");
        //return 1 for error, as per program spec
        return 1;
    }
}
