// Lab 5: Secure Messaging System
// Name: Sam McDowell
// Date: 10/25/2023

#pragma once

#include <string>
#include <vector>
#include "Vigenere.h"

class Message {
public:
	/*
	* Create a new Message
	*/
	Message();

	/*
	* Create a new Message
	* Params:
	* key - the cypher key for the encoder
	*/
	Message(std::string key);

	/*
	* Get the cypher key
	* Return:
	* The cypher key as a string
	*/
	std::string getKey() const;

	/*
	* Change the stored cypher key
	* Params:
	* newKey - The new cypher key
	*/
	void setKey(std::string newKey);

	/*
	* Encrypt a word and store it to the message
	* Params:
	* word - The word to encrypt
	*/
	void encrypt(char* word);

	/*
	* Decrypt a word and store it to the message
	* Params:
	* word - The word to decrypt
	*/
	void decrypt(char* word);

	/*
	* Print the whole message to the console
	*/
	void showWords();

	/*
	* Write the output of the message to a file
	* Params:
	* name - The name of the file to write to
	*/
	void makeFile(std::string name);

private:
	std::vector<std::string> message;
	Vigenere encoder;
};