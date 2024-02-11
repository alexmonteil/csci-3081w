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
    std::cout << "Question: " << this->title << std::endl;
    std::cout << "By: " << this->author << std::endl;
    std::cout << this->text << std::endl;
    std::cout << this->views << std::endl;
    this->addView();
}