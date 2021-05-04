#include "MessageHolder.h"
#include <sstream>



MessageHolder::MessageHolder(){
    this->first = 0;
    this->last = 0;
    this->messages = 0;
    this->listSize = 0;
}

MessageHolder::~MessageHolder(){
    delete messages;
    first = 0;
    last = 0;
}

void MessageHolder::addMessage(Message *message){
    if(messages == 0)
    {
        messages = new Node();
        messages->message = message;
        messages->next = 0;
        first = messages;
        last = messages;
    }else if(first == last){
        first->next = new Node();
        last = first->next;
        last->message = message;
        last->next = 0;
    }else{
        last->next = new Node();
        last = last->next;
        last->message = message;
        last->next = 0;
    }
    listSize++;
}

void MessageHolder::populateMessages(){
	string message = "";
	while (message != "*"){
		cout << "enter your message (enter only * to stop): " << endl;

		char input[500];
		cin.getline(input, 500);
		message = input;

		if (message != "*"){
			std::ostringstream oss;
			oss << message;

			Message * m = new Message(oss.str());
			addMessage(m);
		}
	}

}


Node* MessageHolder::getAllMessages(){
    return this->messages;
}

int MessageHolder::size(){
    return listSize;
}

