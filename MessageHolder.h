#ifndef MESSAGEHOLDER_H
#define MESSAGEHOLDER_H

#include <string>
#include <iostream>
#include "Message.h"

using namespace std;

class Node{
    public:
    Message *message;
    Node *next;
    Node(){};
    ~Node(){
        delete message;
        delete next;
    }
};

class MessageHolder
{
    private:
        Node *messages;
        Node *first;
        Node *last;
        int listSize;

    public:


        MessageHolder();
        ~MessageHolder();
        void addMessage(Message *message);
        Node* getAllMessages();
        void populateMessages();
        int size();

};

#endif
