#include "crypto.h"

Crypto::Crypto(int k1,int k2)
{
    key1 = k1;
    key2 = k2;
}

char* Crypto::encrypt(char* beforeEncryption)
{
    lengthPhrase = strlen(beforeEncryption);
    int code;
    for (int i = 0; i < lengthPhrase; i++)
    {
        if (beforeEncryption[i] != ' ')
        {
            code = (((int)beforeEncryption[i] - ((int)'A')) * key1 + key2) % sizeAlphabet;
            beforeEncryption[i] = (int)'A' + code;
        }
    }

    return beforeEncryption;
}

char* Crypto::decrypt(char* beforeDecryption)
{
    int code, reverseKey;

    for (int i = 0; i < sizeAlphabet; i++)
    {
        if (key1 * i % sizeAlphabet == 1) reverseKey = i;
    }

    for (int i = 0; i < lengthPhrase; i++)
    {
        if (beforeDecryption[i]!= ' ')
        {
            code = ((((int)beforeDecryption[i] - ((int)'A')) - key2) * (reverseKey)) % sizeAlphabet;
            beforeDecryption[i] = (int)'A' + code;
        }
    }

    return beforeDecryption;
}