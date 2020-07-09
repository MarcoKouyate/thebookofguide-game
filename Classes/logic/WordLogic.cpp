#include "WordLogic.h"
#include "tools/Console.h"

WordLogic::WordLogic() {
	stories.push_back(Story("Travel", "Book", "Write", "I like to Write what I see during my Travel around the world in this Book"));
	stories.push_back(Story("Travel", "Book", "Oasis", "Oasis told me to get a Book for my Travel"));
	stories.push_back(Story("Travel", "Gluttony", "Oasis", "Oasis is always Hungry when we travel Together"));
	stories.push_back(Story("Ice Cream", "Handbag", "Oasis", std::vector<std::string>({ "Hello mate", "How are you ?"})));
}

void WordLogic::select(std::string word) {
	words[word] = true;

	std::string message = word + " selected!";
	Console::log(message);
}

void WordLogic::unselect(std::string word) {
	words[word] = false;

	std::string message = word + " unselected!";
	Console::log(message);
}

void WordLogic::clear() {
	words.clear();
}

std::vector<std::string> WordLogic::choose(std::string word1, std::string word2, std::string word3) {
	select(word1);
	select(word2);
	select(word3);
	std::vector<std::string> messages = getResult();
	return messages;
}

std::vector<std::string> WordLogic::getResult() {
	for (Story& story : stories) {
		if (story.check(words)) {
			return checkIfRead(story);
		}
	}

	notifyObservers(false);
	return { "I don't know what to say" };
}

void WordLogic::subscribe(WordLogicObserver* subscriber) {
	observers.push_back(subscriber);
}

void WordLogic::unsubscribe(WordLogicObserver* subscriber) {
	observers.remove(subscriber);
}

std::vector<std::string> WordLogic::checkIfRead(Story& story) {
	std::vector<std::string> dialogues = story.getDialogue();
	if (story.isRead) {
		dialogues.push_back("But I already told you that so it doesn't really help me...");
	}
	else {
		notifyObservers(true);
		story.isRead = true;
	}

	return dialogues;
}

void WordLogic::notifyObservers(bool result) {
	for (auto observer : observers) {
		observer->updateFromWordLogic(result);
	}
}