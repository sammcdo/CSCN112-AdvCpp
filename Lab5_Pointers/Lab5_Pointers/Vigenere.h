// Lab 5: Secure Messaging System
// Name: Sam McDowell
// Date: 10/25/2023

#pragma once

#include <string>

class Vigenere {
public:
	/*
	* Create a new Vigenere Cypher
	*/
	Vigenere();

	/*
	* Create a new Vigenere Cypher
	* Params:
	* key - The cypher key to use
	*/
	Vigenere(std::string key);

	/*
	* Get the stored cypher key
	* Return:
	* The cypher key as a string
	*/
	std::string getKey() const;

	/*
	* Change the stored cypher key
	* Key will be changed to uppercase
	* Params:
	* newKey - The new cypher key
	*/
	void setKey(std::string newKey);

	/*
	* Encrypt a string (a single word) with the Vigenere
	* cypher using the saved key.
	* Params:
	* word - The word to encrypt
	* Return:
	* The encrypted word in all caps
	*/
	std::string encrypt(std::string word);

	/*
	* Decrypt a string (a single word) with the Vigenere
	* cypher using the saved key.
	* Params:
	* word - The word to decrypt
	* Return:
	* The decrypted word in all caps
	*/
	std::string decrypt(std::string word);

private:
	std::string key;

	std::string convertToUpper(std::string conv);
};