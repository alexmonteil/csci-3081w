#include "post.h"
#include <iostream>
#include <string>
#include <vector>


#ifndef QUESTION_H
#define QUESTION_H

class Question : public Post {

    private:
        std::vector<std::string> responses;

    public:
        Question::Question();
        Question::Question(std::vector<std::string> newResponses);
        Question::~Question();
        void Question::addResponse(std::string newResponse);
        void Question::view();
};

#endif