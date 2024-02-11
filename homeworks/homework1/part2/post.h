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

  /** Constructors */
  Post::Post();
  Post::Post(std::string newTitle, std::string newText, std::string newAuthor, long newCreated);

  /** Destructor */
  virtual Post::~Post();

  /** Getters */
  std::string getTitle();
  std::string getText();
  std::string getAuthor();
  int getViews();
  long getCreated();

  /** Setters */
  void setTitle(std::string title_);
  void setText(std::string text_);

  /** methods */
  virtual void view() = 0;
  void addView();
};


#endif  // POST_H
