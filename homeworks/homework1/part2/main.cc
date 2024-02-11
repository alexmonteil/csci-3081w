#include <string>
#include <vector>
#include <iostream>
#include <chrono>

#include "post.h"
#include "note.h"
#include "question.h"
#include "poll.h"

/**
 * TODO: Why is our argument a const? What is the importance of this?
 * Response:
 * Using const for the argument ensures the function cannot modify the content of the vector posts.
 * This is useful for functions that are meant to only read data without altering it.
 * 
 * TODO: What does the "&" symbol do?
 * Response:
 * The & symbol ensures the posts vector is passed as a reference therefore avoiding an unneeded copy of the vector.
 * This allows for higher performance / efficiency as the function will waste performance and memory copying the vector.
*/
void previewPosts(const std::vector<Post*>& posts) {
    int counter = 0;
    std::cout << "==============================Posts Preview=====================================\n";
    for(Post* p : posts) {
        std::cout << counter++ << ": " << p->getTitle() << std::endl;
    }
    std::cout << "================================================================================\n\n";
    return;
}

/**
 * TODO: Sometimes this function throws an error. Find out why and fix it
*/
void displayPost(const std::vector<Post*>& posts, int i) {
    if(i < 0 || i >= posts.size()) {
        std::cout << "Invalid selection: " << i << std::endl;
        return;
    }

    posts.at(i)->view();
    return;
}

/**
 * TODO: Give a description of what is happening in this method
 * Response:
 * 
 * The method checks if the index selected by the user is out of bounds for the posts vector,
 * It then attempts a to dynamic cast the member of posts at index i into a question pointer.
 * If the cast succeeds it displays the question and prompts the user for a response to the question
 * It then adds the response to the Question object and returns (ending the method execution).
 * 
 * If the dynamic cast to a Question pointer fails, the method attempts to dynamic cast the member of posts at index i
 * into a Poll pointer.
 * If the cast succeeds it displays the poll and prompts the user to select a poll option.
 * It records the user vote for the poll and returns (ending the method execution).
 * 
 * If none of the dynamics casts succeeded, the method displays "This post can not be interacted with" to the console.
 * 
 * TODO: Why are we dynamically casting?
 * Response:
 * 
 * We are dynamically casting because the method relies on user input, the user decides which post to interact with.
 * This means we do not know ahead of time what polymorphic type the post should be downcasted into.
 * Dynamic casting allows to perform safe downcasting of polymorphic types and to check whether the conversion is possible at runtime.
 * In terms of the reason for downcasting in this specific method, we receive input from the user on their choice of which post to interact with,
 * we then try to downcast the post (pointer) they selected into either a question (pointer) or a poll (pointer) at runtime, this will decide the behavior of the program,
 * if it is a question we will prompt the user for an answer to that question while if it is a poll we will prompt the user for a vote on the poll.
 * if it is neither of those then the post is not a type of post that can be interacted with.
 *  
 * TODO: What does dynamic casting do?
 * Response:
 * 
 * Dynamic casting allows to convert a pointer or reference to a base class type to a pointer or reference to a derived class type.
 * This is commonly referred to as downcasting.
 * If it succeeds it returns the pointer to the derived class type.
 * If it fails it returns a null pointer.
 * 
 * 
 * TODO: How is dynamic casting different from static casting?:
 * Response:
 * 
 * Dynamic casting occurs at runtime while static casting occurs at compile time.
 * Dynamic casting can only be used with pointers or references to classes with a polymorphic behavior.
 * Static casting works with pointers, reference types, and fundamental types.
 * Static casting is used for implicit conversions that are safe and well defined at compile time.
 * Dynamic casting is used mainly for performing safe downcasting of polymorphic types at runtime and performing runtime type checking.
 * 
 * 
*/
void interactWithPost(const std::vector<Post*>& posts, int i) {

    if(i < 0 || i >= posts.size()) {
      std::cout << "Invalid selection: " << i << std::endl;
      return;
    }

    Question* q = dynamic_cast<Question*>(posts.at(i));
    if (q) {
      q->view();
      std::string response;
      std::cout << "Enter a response to the question above.\n >";
      std::getline(std::cin,response); // Need this to grab the endline character from the previous selection in the cin buffer. This input is "thrown away"
      std::getline(std::cin,response); // Actual user input
      q->addResponse(response);
      return;
    }

    Poll* p = dynamic_cast<Poll*>(posts.at(i));
    if (p) {
      p->view();
      int selection;
      std::cout << "Enter the option you would like to vote for:";
      std::cin >> selection;
      p->castVote(selection);
      return;
    }

    std::cout << "This post can not be interacted with\n";
    
}
/**
 * TODO: Make 'getUsernameFromConsole` method here
*/ 
void getUsernameFromConsole(std::string &name) {
  while (true) {
    std::cout << "Please enter your name: " << std::endl;
    std::cin >> name;
    if (name.find_first_not_of(' ') != std::string::npos && !name.empty()) {
      return;
    }
  }
}


int main() {

  std::string username;
  /** TODO: Get username using the `getUsernameFromConsole` function*/
  getUsernameFromConsole(username);
  

  std::vector<Post*> database;
  database.push_back(new Note("Y2K Computers","Are the computers really going to break tonight?","Tim Hatman",946684800));
  database.push_back(new Note("First Day","First day of class is this Tuesday 1/16","Alec Lorimer",1705400645));
  database.push_back(new Note("Leap Year!","Happy 2024 everyone! It's a leap year this year. How exciting","Calendar man",1704067200));
  database.push_back(new Question("Homework 3 Crunch","Is it possible to start and complete homework 3 on the day its due?","Concerned Student",1714517376));
  database.push_back(new Poll("Who is where?","What lecture section is everybody in?","Potential Teammate",1714517376, std::vector<std::string>({"01","10","20","30"})));

  int selection;
  bool run = true;
  std::string menu = "\n=====Menu=====\n0. Quit\n1. Preview\n2. Read post\n3. Interact with Post\nEnter an action:";

  while(run) {
    std::cout << menu;
    std::cin >> selection;
    switch (selection)
    {
      case 0:
        run = false;
        break;

      case 1:
        previewPosts(database);
        break;

      case 2:
        std::cout << "Enter the index of the post you would like to view.\nPost Index:";
        std::cin >> selection;
        displayPost(database,selection);
        break;
        
      case 3:
        std::cout << "What post would you like to interact with?.\nPost Index:";
        std::cin >> selection;
        interactWithPost(database,selection);
        break;
          
      default:
        break;
    }
  }

  std::cout << "Goodbye.\n";

  for(auto post : database) {
    delete post;
  }

  return 0;
}
