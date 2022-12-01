#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Encryption class.h"
using namespace std;


int main()
{
        string inFileName, outFileName;
		int key;
		cout << "Enter name of file to encrypt: ";
		cin >> inFileName;
		cout << "Enter name of file to receive " << "the encrypted text: ";
		cin >> outFileName;

		
		// Get key value.
		// To decrypt enter a negative value opposite of the positive value.
		// So decrypting a text file with the value of 2, to decrypt would be -2.
		cout << "Enter key value: ";
        cin >> key;
		SimpleEncryption obfuscate(inFileName, outFileName, key);
		obfuscate.encrypt();
	
	    return 0;
}