// Written by Hannah Faus - CSCE Project 240 - Project 4 - March 2022

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// function for matching input to line
void match(string inputInfo, double basePercent) {
    string input_filename = "data/input.txt";  // name of file to be parsed
    string matchInfo;  // line from input file, output for the end

    // beginning of stream - taking in info
    ifstream in_myfile (input_filename);
    if (in_myfile.is_open()) {
        double maxPercent;  // the current highest match percentage
        string output = "I do not understand. Please rephrase and try again!";
        while (getline(in_myfile, matchInfo)) {
            //string output;
            string response, promptString, inputString; // holds response, placeholder for prompt, placeholder for input
            double matchCount = 0.1;  // number of words that are in both inputVector and promptVector
            double wordCount = 0.1; // number of words in inputVector
            double actPercent = 0.0;  // match percentage = matchCount/wordCount
            
            vector<string> promptVector;  // holds "buzz" words
            vector<string> inputVector;  // holds the words from inputInfo

            // looping through matchInfo to separate into promptVector and response
            for (int i = 0; i < matchInfo.size(); i++) {
                if (matchInfo[i] != ':') {  // first half of the line - prompt
                    if (matchInfo[i] == ' ') {  // end of a prompt
                        // add prompt to vector and clear placeholder string
                        promptVector.push_back(promptString);
                        promptString.clear();
                    } else if (matchInfo[i+1] == ':') {  // end of first half of line
                        // get last char and add prompt to vector and clear placeholder string 
                        promptString += matchInfo[i];
                        promptVector.push_back(promptString);
                        promptString.clear();
                    } else {  // still within first half of line
                        // add char to placeholder string
                        promptString += matchInfo[i];
                    }
                } else {  // second half of string - response
                    for (int j = i + 2; j < matchInfo.size(); ++j) {
                        // add char to response
                        response += matchInfo[j];
                        ++i;
                    }
                }
            }

            // looping through inputInfo to put into inputVector
            for (int k = 0; k < inputInfo.size(); ++k) {
                if (inputInfo[k] == ' ') {  // end of word
                    // add word to vector and clear placeholder string
                    inputVector.push_back(inputString);
                    inputString.clear();
                } else if (k+1 == inputInfo.size()) {  // end of string
                    // get last char and add input to vector and clear placeholder string 
                    inputString += inputInfo[k];
                    inputVector.push_back(inputString);
                    inputString.clear();
                } else {  // still in inputInfo
                    inputString += inputInfo[k];
                }
            }

            // looking for matches between inputVector and promptVector
            for (int l = 0; l < inputVector.size(); ++l) {
                ++wordCount;  // counting number of words in inputVector
                // looping through promptVector to search for matches
                for (int m = 0; m < promptVector.size(); ++m) {
                    if (inputVector[l] == promptVector[m]) {  // match is found
                        ++matchCount;  // number of matches increase
                    }
                }
            }

            // calculate the actPercent (match percentage)
            actPercent = matchCount / wordCount;
            if (actPercent >= basePercent) {  // if the match percent is above base
                if (actPercent > maxPercent) {  // if the match percent is above current high-max percent
                    maxPercent = actPercent;
                    output = response;
                } else if (actPercent == maxPercent) {  // if the match percent is equal to the current high-max percent
                    output += "\n" + response;
                }
            }
        } //endwhile

        cout << output << endl;
        in_myfile.close();
    }
    else {
        cout << "file cannot be opened." << endl;
    }
}  //endfunct


// main function
int main(int argc, char* argv[]) {
    // ask for what the desired information is
    cout << "Hello! Welcome to the district chatbot!" << endl;
    cout << "If you would like to exit the chatbot at any time please type Quit, quit or q" << endl;
    cout << "What can I help you with today?" << endl;
    
    // what the desired information is
    string inputInfo;
    double basePercent = 0.10;
    getline(cin, inputInfo);

    // infinite loop for user query
    while (inputInfo != "Quit" && inputInfo != "q" && inputInfo != "quit") {
        // what the user asked
        cout << "You asked: " + inputInfo << endl;
        match(inputInfo, basePercent);
        // potential exit
        cout << "Is there anything else I can help you with?" << endl;
        getline(cin, inputInfo);
    }

    // closing remark
    cout << "Thank you for using the chatbot. Have a nice day!" << endl;
}
