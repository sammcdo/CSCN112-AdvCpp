// Lab 5: Secure Messaging System
// Name: Sam McDowell
// Date: 10/25/2023

#include <string>
#include <cctype>
#include "Vigenere.h"

/*
* Create a new Vigenere Cypher
*/
Vigenere::Vigenere() {
	key = "";
}

/*
* Create a new Vigenere Cypher
* Params:
* key - The cypher key to use
*/
Vigenere::Vigenere(std::string key) {
	this->key = key;
}

/*
* Get the stored cypher key
* Return:
* The cypher key as a string
*/
std::string Vigenere::getKey() const {
	return key;
}

/*
* Change the stored cypher key
* Key will be changed to uppercase
* Params:
* newKey - The new cypher key
*/
void Vigenere::setKey(std::string newKey) {
	key = convertToUpper(newKey);
}

/*
* Encrypt a string (a single word) with the Vigenere
* cypher using the saved key.
* Params:
* word - The word to encrypt
* Return:
* The encrypted word in all caps
*/
std::string Vigenere::encrypt(std::string word)
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet[65 - 90 | A - Z]
			j = (j + 1) % key.length();
	}
	return output;
}

/*
* Decrypt a string (a single word) with the Vigenere
* cypher using the saved key.
* Params:
* word - The word to decrypt
* Return:
* The decrypted word in all caps
*/
std::string Vigenere::decrypt(std::string word)
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c - key[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet[65 - 90 | A - Z]
			j = (j + 1) % key.length();
	}
	return output;
}

/*
* Convert a string to all upper case.
* Helper function used when saving a key.
* Params:
* conv - The string to convert
* Return:
* The uppercased string
*/
std::string Vigenere::convertToUpper(std::string conv) {
	for (int i = 0; i < conv.size(); i++) {
		conv[i] = std::toupper(conv[i]);
	}

	return conv;
}