#include <iostream>////дебаг 
#include "crypto.h"

using namespace std;////дебаг 


void Crypto::freeMem(char* arr)
{
    delete[] arr;
}

void Crypto::encrypt(char* beforeEncryption, int key1, int key2)
{
    lengthPhrase = strlen(beforeEncryption);
    int code;
    afterEncryption = new char[lengthPhrase];

    for (int i = 0; i < lengthPhrase; i++)
    {
        if (beforeEncryption[i] == ' ')
        {
            afterEncryption[i] = beforeEncryption[i];
        }
        else
        {
            code = (((int)beforeEncryption[i] - ((int)'A')) * key1 + key2) % 26;
            afterEncryption[i] = (int)'A' + code;
        }
    }
}

void Crypto::showEncryptedInfo()
{

    cout << "\tЗакодированное сообщение: ";
    for (int i = 0; i < lengthPhrase; i++)
    {
        cout << afterEncryption[i];
    }
    cout << endl;

}

void Crypto::decrypt(int key1, int key2)
{
    int code, reverseKey;
    afterDecryption = new char[lengthPhrase];
    //вычисляю обратное значение 1го ключа по модулю 26
    for (int i = 0; i < 26; i++)
    {
        if (5 * i % 26 == 1) reverseKey = i;
    }
    for (int i = 0; i < lengthPhrase; i++)
    {
        if (afterEncryption[i] == ' ')
        {
            afterDecryption[i] = afterEncryption[i];
        }
        else
        {
            code = ((((int)afterEncryption[i] - ((int)'A')) - key2) * (reverseKey)) % 26;
            afterDecryption[i] = (int)'A' + code;
        }
    }

}

void Crypto::showDecryptedInfo()
{
    cout << "\tРаскодированное сообщение: ";
    for (int i = 0; i < lengthPhrase; i++)
    {
        cout << afterDecryption[i];
    }
    cout << endl;

    freeMem(afterEncryption);
    freeMem(afterDecryption);
}
