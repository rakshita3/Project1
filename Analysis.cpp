#include "Analysis.h"

Analysis::Analysis(){

}

MessageHolder* Analysis::analyseMessages(MessageHolder* holder, std::map<std::string, int> map){
    Node * messages = holder->getAllMessages();
	double negativeCount = 0;
	double positiveCount = 0;
	double neutralCount = 0;
	double generalCount = 0;

    while(messages !=0)
    {
        string message = messages->message->getMessage();

		//To lower case all messages
		std::transform(message.begin(), message.end(), message.begin(), ::tolower);

		int sentimentCount= 0;

        std::vector<string> wordList;
        int i = 0;

        istringstream iss(message);
        copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter<vector<string> >(wordList));

        for (std::vector<string>::iterator it = wordList.begin(); it != wordList.end(); ++it){
          sentimentCount +=map[*it];
        }

		if (sentimentCount < 0){
			messages->message->setSentiment(0);
			negativeCount++;
		}
		else if (sentimentCount > 0){
			messages->message->setSentiment(1);
			positiveCount++;
		}
		else if (sentimentCount == 0){
			messages->message->setSentiment(2);
			neutralCount++;
		}

		generalCount += sentimentCount;

        messages= messages->next;
    }

	cout << "sentiment for message: " <<endl;
	double total = (negativeCount + positiveCount + neutralCount);
	cout << "Total Messages: " << total << endl;
	cout << "Positive %: " << ((positiveCount / total)*100) << endl;
	cout << "Negative %: " << ((negativeCount / total) * 100) << endl;
	cout << "Neutral %: " << ((neutralCount / total) * 100) << endl;

	if (generalCount>0)
		cout << "General Consensus is Positive " << endl;
	else if (generalCount<0)
		cout << "General Consensus is Negative " << endl;
	else if (generalCount==0)
		cout << "General Consensus is Neutral " << endl;

    return holder;
}
