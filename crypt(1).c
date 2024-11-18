#include <stdio.h>
#include <string.h>

int encrypt(int k, char s[10]);
int decrypt(int k, char s[10]);

int main(int argc, char *argv[])
{
    int key;
    char message[50];
    char *type = argv[1];

    printf("Message: ");
    fgets(message, sizeof(message), stdin);

    printf("Key: ");
    scanf("%d", &key);

    if (strcmp(type, "encrypt") == 0)
    {
        encrypt(key, message);
    }
    else if (strcmp(type, "decrypt") == 0)
    {
        decrypt(key, message);
    }
    
}

int encrypt(int k, char s[10])
{
    printf("Encrypted: ");
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' || 'A' && s[i] <= 'z' || 'Z')
        {
            printf("%c", s[i] - k);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
}

int decrypt(int k, char s[10])
{
    printf("Decrypted: ");
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' || 'A' && s[i] <= 'z' || 'Z')
        {
            printf("%c", s[i] + k);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
}