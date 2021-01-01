//����� ���������� - Fizick14
//alex.pevnenko@gmail.com

//������� ������������
//������� ������� �� 
//��������� ����� 

//*********!!!!!!!!!!***********
//������� ���������� �������������� ������ � ���� �����, ��������� !!!
////////////////////////////////
#pragma once 

class Crypto
{
public:
    //����������� 
    Crypto(int ,int);
        /*
        *brief ����� ��� �������� ����������
        *param1 beforeEncryption ����� ��� ����� , ������� ���������� �����������
        *param2 key1 ���� ��� �������� ������
        *param3 key2 ���� ��� �������� ������
        *retuen void
        */
    char* encrypt(char* beforeEncryption);
        /*
        *@brief ����� ��� ����������� ���������
        *@param1 key1 ���� ��� �����������
        *@param2 key2 ���� ��� �����������
        *@return void
        */
    char* decrypt(char* beforeDecryption);

private:
    int lengthPhrase;
    int key1, key2;
    int sizeAlphabet = 26;
};