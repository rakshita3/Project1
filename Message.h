#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>


using namespace std;

class Message
{
private:
    string message;
    //0 for negative 1 for positive 2 for neutral
    int sentiment;

    Message() { } // private default constructor

public:
    Message(string message);
    ~Message();

    void setMessage(string message);
    void setSentiment(int sentiment);
    string getMessage();
    int getSentiment();
};

#endif



