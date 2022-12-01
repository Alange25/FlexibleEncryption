#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Encryption class.h"
using namespace std;


int main()
{
	char choice = 0; // Initializing the repeat the program var.
	// Using a do/while loop to run the program again.
	do {
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
		cout << endl;

		// Asking user to run the program again.
		cout << "Would you like to run the program again (y/n): ";
		cin >> choice;
		cout << endl;
	} while (choice == 'Y' || choice == 'y');
	return 0;
}