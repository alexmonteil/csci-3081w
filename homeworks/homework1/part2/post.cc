#include "post.h"

/** Constructors */

Post::Post() {
    this->title = "Default_Title";
    this->text = "Default_Text";
    this->author = "Default_Author";
    this->created = 0;
    this->views = 0;
}

Post::Post(std::string newTitle, std::string newText, std::string newAuthor, long newCreated) {
    this->title = newTitle;
    this->text = newText;
    this->author = newAuthor;
    this->created = newCreated;
}


/** Destructor */

Post::~Post() {}

/** Methods */

std::string Post::getTitle() {
    return this->title;
}
std::string Post::getText() {
    return this->text;
}

int Post::getViews() {
    return this->views;
}

std::string Post::getAuthor() {
    return this->author;
}

long Post::getCreated() {
    return this->created;
}

void Post::setTitle(std::string title_) {
    this->title = title_;
}

void Post::setText(std::string text_) {
    this->text = text_;
}

void Post::addView() {
    this->views += 1;
}