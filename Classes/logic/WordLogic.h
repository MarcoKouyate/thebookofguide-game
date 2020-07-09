#pragma once
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Story.h"

class WordLogicObserver {
public:
	virtual void updateFromWordLogic(bool result) = 0;
};

class WordLogicSubject {
public:
	virtual void notify(bool result) = 0;
	virtual void subscribe(WordLogicObserver* observer) = 0;
	virtual void unsubscribe(WordLogicObserver* observer) = 0;
};

class WordLogic : public WordLogicSubject {
public:
	void select(std::string word);
	void unselect(std::string word);

	void clear();
	
	void subscribe(WordLogicObserver* observer) override;
	void unsubscribe(WordLogicObserver* observer) override;
	void notify(bool result) override;
	
	//void reset(); //to unselect all
	std::vector<std::string> choose(std::string word1, std::string word2, std::string word3);
	std::vector<std::string> getResult(); //to get the sentence corresponding to the words

	WordLogic();

private:
	std::map<std::string, bool> words;
	std::list<WordLogicObserver*> observers;
	std::vector<Story> stories;
};