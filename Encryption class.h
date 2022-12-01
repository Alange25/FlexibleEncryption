// This program demonstrates an application 
// of pure virtual functions.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Encryption
{
protected:
    ifstream inFile;
    ofstream outFile;
    int key; // The key var for encryption/decryption.
public:
    Encryption(const string& inFileName, const string& outFileName, int key);
    virtual  ~Encryption();
    // Pure virtual functions.
    virtual char transformEncryption(char ch, int key) const = 0;
    // Do the actual work.
    virtual void encrypt() final;
   
};

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption::Encryption(const string& inFileName, const string& outFileName, int k)
{
    inFile.open(inFileName);
    outFile.open(outFileName);
    key = k;
    if (!inFile)
    {
        cout << "The file " << inFileName
            << " cannot be opened.";
        exit(1);
    }
    if (!outFile)
    {
        cout << "The file " << outFileName
            << " cannot be opened.";
        exit(1);
    }
}

//**************************************************
//Destructor closes files.                         *
//**************************************************
Encryption::~Encryption()
{
    inFile.close();
    outFile.close();
}

//*****************************************************
//Encrypt function uses the virtual transform         *
//member function to transform individual characters. *
//***************************************************** 
void Encryption::encrypt()
{
    char ch;
    char transCh;
    inFile.get(ch);
    while (!inFile.fail())
    {
        transCh = transformEncryption(ch, key);
        outFile.put(transCh);
        inFile.get(ch);
    }
}


// The subclass simply overides the virtual
// transformation function
class SimpleEncryption : public Encryption
{
public:
    char transformEncryption(char ch, int key) const override
    {
        
            // Add the key in ch.
            return ch + key; // Encryption || Decryption...
                             // To decrypt the text file use a negative value for the key.
          
    }
    SimpleEncryption(const string& inFileName, const string& outFileName, int key)
        : Encryption(inFileName, outFileName, key)
    {
    }
};

