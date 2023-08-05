// Project:		emoji-analyzer
// File:		src/Caption.h
// Team:		Esse Ciego
//			Justin Galin
//			Daniel Pernar
// Description:		Provides the Caption class prototype that stores 
//			certain data from an Instagram caption. This data
//			is loaded from a CSV file, and the class is 
//			designed to be used with a CaptionList object.
// Last Updated On:	5 August 2023

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>



class Caption {
	
	private:

	std::vector<std::string> emojis;
	std::string username;
	std::string post;


	public:
	
	// Parametrized constructor for Caption class
	Caption(std::vector<std::string> emojis, std::string username, std::string post);

	// Return the emojis vector
	std::vector<std::string> getEmojis();

	// Return the number of emojis
	int getNumEmojis();

	// Return the username
	std::string getUsername();

	// Return the post
	std::string getPost();
	
	// Set the emojis vector
	void setEmojis(std::vector<std::string> emojis);

	// Set the username
	void setUsername(std::string username);

	// Set the post
	void setPost(std::string post);
	
};


