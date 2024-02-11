#include "question.h"

/** Constructors */

Question::Question() {}
Question::Question(std::vector<std::string> newResponses) {
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