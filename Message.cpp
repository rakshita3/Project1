#include "Message.h"

// Date constructor
Message::Message(string message){
    this->sentiment = 2;
    this->message = message;
}

Message::~Message(){
}

// Date member function
void Message::setMessage(string message){
    this->message = message;
}

void Message::setSentiment(int sentiment){
    this->sentiment = sentiment;
}

string Message::getMessage(){
    return this->message;
}

int Message::getSentiment(){
    return this->sentiment;
}
