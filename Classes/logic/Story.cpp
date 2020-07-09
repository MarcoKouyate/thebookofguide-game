#include "Story.h" 


Story::Story(std::string word1, std::string word2, std::string word3, std::string dialogue) : activators({word1, word2, word3}), dialogue({ dialogue }), isRead(false)
{}

Story::Story(std::string word1, std::string word2, std::string word3, std::vector<std::string> dialogue) : activators({ word1, word2, word3 }), dialogue(dialogue), isRead(false)
{}

bool Story::check(std::map<std::string, bool> selectedWords) {
	bool isCorrect = true;

	for (std::string activator : activators) {
		isCorrect = isCorrect && selectedWords[activator];
	}

	return isCorrect;
}

std::vector<std::string> Story::getDialogue(){
	return dialogue;
}

