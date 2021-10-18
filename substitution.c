#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
bool check_cypher(string encoder);
string encoding(string plain, string encoder);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string encoder = argv[1];
        string encoded_text;

        // Checking if the word inserted from the user contains all the 26 letter of the alphabet and there are no repetitions
        if (check_cypher(encoder) == true && strlen(encoder) == 26)
        {
            string plain_text = get_string("plaintext: ");
            encoded_text = encoding(plain_text, encoder);
            printf("ciphertext: %s\n", encoded_text);
            return 0;
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

}


// Function chech_cypher will check if there are all the 26 letters of the alphabet and no repetitions
bool check_cypher(string encoder)
{
    // Transform every letter in the encoder word in lower capitalization in order to check
    // the validity of the cypher (no repetitions and 26 chars)
    char new_encoder[strlen(encoder)];
    for (int i = 0; encoder[i] != '\0'; i++)
    {
        new_encoder[i] = tolower(encoder[i]);
    }
    new_encoder[strlen(encoder)] = '\0';

// strchr() function is used to find when the character first occurred in the string.
// This function returns the pointer to the location where the character first appeared in the string.
// If the character doesn't exist in the string the function returns the null pointer.

    const char *cypher = new_encoder;
    char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    char *c = alphabet;
    while (*c)
    {
        if (strchr(cypher, *c))
        {

        }
        else
        {
            return false;
        }
        c++;
    }

    return true;
}
// Encode plain_text with the given encoder maintaining the capitalization
string encoding(string plain, string encoder)
{
    string encoded_text = plain;
    // Going through every letter in the plain word
    for (int i = 0, n = strlen(encoded_text); i < n; i++)
    {
        // Comparing every letter in with the whole alphabet
        for (int z = 0, m = strlen(letters); z < m; z++)
        {
            // When we find the correspondent letter we will use the zth letter of the encoder, lower or upper
            // depending on the letter we are replacing
            if (tolower(plain[i]) == letters[z])
            {
                if (isupper(plain[i]) == 0)
                {
                    encoded_text[i] = tolower(encoder[z]);
                    z = 0;
                    break;
                }
                else
                {
                    encoded_text[i] = toupper(encoder[z]);
                    z = 0;
                    break;
                }
            }
        }
    }

    return encoded_text;
}
