// Lab 5: Secure Messaging System
// Name: Sam McDowell
// Date: 10/25/2023

#include <string>
#include <iostream>
#include <fstream>
#include "Message.h"

/*
* Create a new Message
*/
Message::Message() {
}

/*
* Create a new Message
* Params:
* key - the cypher key for the encoder
*/
Message::Message(std::string key) {
	encoder.setKey(key);
}

/*
* Get the cypher key
* Return:
* The cypher key as a string
*/
std::string Message::getKey() const {
	return encoder.getKey();
}

/*
* Change the stored cypher key
* Params:
* newKey - The new cypher key
*/
void Message::setKey(std::string newKey) {
	encoder.setKey(newKey);
}

/*
* Encrypt a word and store it to the message
* Params:
* word - The word to encrypt
*/
void Message::encrypt(char* word) {
	std::string w = word;

	w = encoder.encrypt(w);

	message.push_back(w);
}

/*
* Decrypt a word and store it to the message
* Params:
* word - The word to decrypt
*/
void Message::decrypt(char* word) {
	std::string w = word;

	w = encoder.decrypt(w);

	message.push_back(w);
}

/*
* Print the whole message to the console
*/
void Message::showWords() {
	for (std::string w : message) {
		std::cout << w << " ";
	}

	std::cout << "\n";
}

/*
* Write the output of the message to a file
* Params:
* name - The name of the file to write to
*/
void Message::makeFile(std::string name) {
	std::ofstream file(name);

	for (std::string w : message) {
		file << w << " ";
	}

	file << "\n";
}