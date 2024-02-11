#include "question.h"

/** Constructors */

Question::Question(std::string newTitle, std::string newText, std::string newAuthor, long newCreated, std::vector<std::string> newResponses) 
    : Post(newTitle, newText, newAuthor, newCreated) {

        this->responses = newResponses;
}

/** Destructor */

Question::~Question() {}

/** Methods */

void Question::addResponse(std::string newResponse) {
    this->responses.push_back(newResponse);
}

void Question::view() {
    std::cout << "================================================================================\n";
    std::cout << "Question: " << this->title << "\nBy: " << this->author << "\n" << this->text << 
    "\nViews: " << this->views << "\n";
    std::cout << "================================================================================\n";
    this->addView();
}