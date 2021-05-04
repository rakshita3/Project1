#include <cstdlib>
#include <iostream>
#include <map>

#include "MessageHolder.h"
#include "Analysis.h"
#include "Dictionary.h"


using namespace std;

int main(int argc, char** argv) {

    MessageHolder *holder = new MessageHolder();
    holder->populateMessages();

    Dictionary *dictionary = new Dictionary();
    std::map<std::string,int> map = dictionary->getDictionary("AFINN-111.txt");

    Analysis *analysis = new Analysis();
    holder = analysis->analyseMessages(holder,map);

	delete holder;
    delete dictionary;

	int p;
	cout << "Press Enter to exit" << endl;
	cin.get();

    return 0;
}



