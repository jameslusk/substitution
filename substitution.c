//James Lusk - cs50 12/2020 - PSET 2/Substitution

//List libraries
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


//List creadted functions

bool key_check(string s); 
void encrypt(string plaintext, string ciphertext);
char mapping[26];

int main(int argc, string argv[])
{
    //Check that program was run with one command-line argument
    if (argc != 2 || !key_check(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Convert that command-line argument from a string to an int
    
    for (int i = 0; i < strlen(argv[1]); i++)//0->, 1->, 2->...
    {
        mapping[i] = tolower(argv[1][i]);
    }
    
    string s = get_string("plaintext: ");
    int n = strlen(s);
    char ciphertext[n + 1];
    encrypt(s, ciphertext);
    
    printf("ciphertext: %s\n", ciphertext);
    
    return 0;
}

bool key_check(string s)
//Verify that the key is 26 characters and letters only
{
    int i = 0;
    int buf[26];

    for (i = 0; i < 26; i++)
    {
        buf[i] = -1;
    }
    
    for (i = 0; i < strlen(s); i++)
    {
        char ch = s[i];
        if (!isalpha(ch))
        {
            return false;
        }
        if (buf[tolower(ch) - 'a'] != -1)
        {
            return false;
        }
        else
        {
            buf[tolower(ch) - 'a'] = 1;
        }
        
    }
    
    return i == 26;
}

void encrypt(string plaintext, string ciphertext)
//Encrypt plain text entry using the variable key as entered by the user
{
    int i = 0;
    for (i = 0; i < strlen(plaintext); i++)
    {
        char ch = plaintext[i];
        
        if (isalpha(ch))
        {
            char interim = tolower(ch);
            int pi = interim - 'a';
            char ci = mapping[pi]; //Encryption process / letter
            ciphertext[i] = islower(ch) ? ci : toupper(ci);
        }
        else
        {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0';
}

