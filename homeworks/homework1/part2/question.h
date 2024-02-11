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
        Question(std::string newTitle, std::string newText, std::string newAuthor, long newCreated) : Post(newTitle, newText, newAuthor, newCreated) {};
        Question(std::string newTitle, std::string newText, std::string newAuthor, long newCreated, std::vector<std::string> newResponses);
        ~Question();
        void addResponse(std::string newResponse);
        void view();
};

#endif // QUESTION_H