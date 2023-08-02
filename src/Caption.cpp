#include "Caption.h"


Caption::Caption(std::vector<std::string> emojis, std::string username, std::string post)
:
	emojis(emojis),
	username(username),
	post(post)
{}

std::vector<std::string> Caption::getEmojis() {
	return emojis;
}

int Caption::getNumEmojis() {
	return emojis.size();
}

std::string Caption::getUsername() {
	return username;
}

std::string Caption::getPost() {
	return post;
}

void Caption::setEmojis(std::vector<std::string> emojis) {
	this->emojis = emojis;
}

void Caption::setUsername(std::string username) {
	this->username = username;
}

void Caption::setPost(std::string post) {
	this->post = post;
}

