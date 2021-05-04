#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Message.h"
#include "MessageHolder.h"


using namespace std;

class Analysis
{


public:
    Analysis();
    MessageHolder* analyseMessages(MessageHolder* holder, std::map<std::string, int>);
};

#endif
