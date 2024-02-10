#include <string>
#include <iostream>

#ifndef POST_H
#define POST_H

class Post {
 protected:
    std::string title;
    std::string text;
    std::string author;
    long created;
    int views;
    
 public:

    /** Getters */
    std::string getTitle();
    std::string getText();
    std::string getAuthor();
    int getViews();
    long getCreated();

    /** Setters */
    void setTitle(std::string title_);
    void setText(std::string text_);
};


#endif  // POST_H
