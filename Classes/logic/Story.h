#pragma once
#include <vector>
#include <string>
#include <map>


class Story {
public:
	Story(std::string word1, std::string word2, std::string word3, std::string dialogue);
	Story(std::string word1, std::string word2, std::string word3, std::vector<std::string> dialogue);

	bool check(std::map<std::string, bool> selectedWords);

	std::vector<std::string> getDialogue();

	bool isRead = false;

private:
	std::vector<std::string> activators;
	std::vector<std::string> dialogue;

};