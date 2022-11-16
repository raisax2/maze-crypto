/* Author: Raisa Methila
Task: Write a program that uses the above functions to demonstrate 
encryption and decryption for both ciphers; Vigenere and Caesar. */

#include <iostream>
#include <string>
using namespace std;

int vigenereIndex = -1;

int key(char a)
{                    
    int temp = (int) a;
    if(temp >=97 && temp <= 122)
        return temp - 97;
    else return -1;
}

char fromkey(int x)
{               
    x+=26;
    return (char)((x%26)+97);
}

int myhash(string codeword)
{
    vigenereIndex++;
    vigenereIndex%=codeword.length();
    return key(codeword[vigenereIndex]);
}

char shiftChar(char c, int rshift)
{
    char temp = tolower(c);
    int raw = ((int)temp - 97 + rshift);
    raw += 26;
    raw =  raw % 26;
    raw += 97;
    temp = (char)raw;

    if((int)c >= 65 && (int)c <= 90)
    { 
        temp = toupper(temp);
        return temp;
    }

    if((int)c >= 97 && (int)c <= 122)
        return temp;
    else return c;
}

string encryptCaesar(string plaintext, int rshift)
{
    string output;
    for(int i=0; i < plaintext.length(); i++)
        output += shiftChar(plaintext[i], rshift);
    return output;
}

string encryptVigenere(string plaintext, string keyword){
    string output;
    char tempchar;
    bool plainCASE = true; 
    vigenereIndex = -1;
    for(int j=0; j<plaintext.length(); j++){
        tempchar = tolower(plaintext[j]);
        plainCASE = (plaintext[j] == tempchar);

        if((int)tempchar >= 97 && (int)tempchar <= 122){
            if(plainCASE)
                output += fromkey(myhash(keyword)+key(tempchar));            
            else
                output += toupper(fromkey(myhash(keyword)+key(tempchar)));
        }
        else output += plaintext[j];
    }
    return output;
}

string decryptCaesar(string ciphertext, int rshift)
{   
    return encryptCaesar(ciphertext, 0-rshift);
}

string decryptVigenere(string ciphertext, string keyword)
{ 
    string output;
    char tempchar;
    bool plainCASE = true; 
    vigenereIndex = -1; 
    for(int j=0; j<ciphertext.length(); j++){
        
        tempchar = tolower(ciphertext[j]);
        plainCASE = (ciphertext[j] == tempchar);

        if((int)tempchar >= 97 && (int)tempchar <= 122){
            if(plainCASE)
                output += fromkey(key(tempchar)-myhash(keyword));            
            else output += toupper(fromkey(key(tempchar)-myhash(keyword)));
        }
        else output += ciphertext[j];
    }
    return output;
}


int main()
{
    string input = "";
    int shift;
    cout << "Caesar encryption, enter plaintext: ";
    getline(cin, input);
    cout << "Enter charecter shift: ";
    cin >> shift;
    string caesarText = encryptCaesar(input, shift);
    cout << "Ciphertext: " << caesarText << endl;
    cout << "Decrypted: " << decryptCaesar(caesarText, shift) << endl;
    cout << "Vigenere encryption: "<<endl;
    string vigenereText = encryptVigenere(input, input);
    cout << "Ciphertext: " << vigenereText << endl;
    cout << "Decrypted: " << decryptVigenere(vigenereText, input) << endl;
    return 0;
}