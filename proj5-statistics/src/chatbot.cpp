// Written by Hannah Faus - CSCE Project 240 - Project 4 - March 2022
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <time.h>

using namespace std;

// vector to store responses
vector<string> chat;
// option to put in sessionSearch
int ssInput;
int iNumber;
// counting number answers and responses
int number_asks, number_responses, duration;


// function for matching input to line
void questionMatch(string inputInfo, double basePercent) {
    string input_filename = "data/input.txt";  // name of file to be parsed
    string matchInfo;  // line from input file, output for the end

    // beginning of stream - taking in info
    ifstream in_myfile (input_filename);
    if (in_myfile.is_open()) {
        double maxPercent;  // the current highest match percentage
        string output = "I do not understand. Please rephrase and try again!";
        while (getline(in_myfile, matchInfo)) {
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
                    output += "\n" + response;  // appending to output for multipe matches
                }
            }
        } //endwhile
        // close file and return output, add to chat vector
        cout << output << endl;
        chat.push_back(output);
        ++number_responses;
        in_myfile.close();
    } else {
        cout << "file cannot be opened." << endl;
    }
}  //endfunct

// function for creating a new chat session
void createSession() {
    int seqNumber = 1;  // keeps track of used file numbers
    bool isCreated = false;  // until file is created

    // creating a new session
    while (isCreated == false) {
        string newFileName = "data/chat_sessions/chatSession" + to_string(seqNumber) + ".txt";  // file with next available seq number
        
        // preparing file
        fstream in_myfile (newFileName);
        if(in_myfile) {  // if file already exists, try next number
            ++seqNumber;
        } else {  // if file doesn't already exist, create it
            isCreated = true;
            ofstream newSession (newFileName);
             if (newSession.is_open()) {
                // looping through chat vector and adding info to new chat session
                for (int i = 0; i < chat.size(); ++i) {
                    string ph = chat[i];  // chat responses / questions from vector
                    newSession << ph << endl;
                }
            } else {
                cout << "New chat session cannot be created." << endl;
            }
            newSession.close();
        }
    }

    // adding session to .csv file
    string csvFileName = "data/chat_statistics.csv";
    ofstream newCsvSession;
    newCsvSession.open(csvFileName, ios::app);
    if (newCsvSession.is_open(), ios::app | ios::binary) {
        cout << seqNumber << number_asks << number_responses << endl;
        newCsvSession << seqNumber << "," << number_asks << "," << number_responses << "," << duration << "\n";//<< "," << number_asks << "," << number_responses << endl;
    } else {
        cout << "CSV file cannot be opened." << endl;
    }
    newCsvSession.close();
}

// function for searching chat sessions for stats
void sessionSearch(int ssInput, int iNumber) {
    // files to use
    string input_filename_csv = "data/chat_statistics.csv";  // csv file
    string input_filename_session = "data/chat_sessions/chatSession" + to_string(iNumber) + ".txt";  // session file
    // for string stream part
    string token;
    string line, word;
    vector<string> result;
    // s = string i = int t = total, for navigating between forms
    string sSession, sAsks, sResponses, sDuration;
    int iSession, iAsks, iResponses, iDuration;
    int tSession = 0;
    int tAsks = 0;
    int tResponses = 0;
    int tDuration = 0;

    string one_output = "";  // initialize output

    vector<string> searchVector;  // vector to hold numbers from csv file
    // preparing file
    fstream in_myfile_csv (input_filename_csv);
    if (in_myfile_csv.is_open()) {
        while (getline(in_myfile_csv, line)) {
            istringstream linestream (line);  // to get csv row
            while (getline(linestream, token, ',')) {  // breaking up csv row
               searchVector.push_back(token);  // each number from row     
            }
            // vector to string value
            sSession = searchVector[0];
            sAsks = searchVector[1];
            sResponses = searchVector[2];
            sDuration = searchVector[3];
            // string to int value
            iSession = stoi(sSession);
            iAsks = stoi(sAsks);
            iResponses = stoi(sResponses);
            iDuration = stoi(sDuration);
            // keeping track of total values
            tSession = iSession;
            tAsks = tAsks + iAsks;
            tResponses += iResponses;
            tDuration += iDuration;

            if (iSession == iNumber) {  // if the session number and input file number are a match
                one_output = "Chat "+sSession+" has user asking "+sAsks+" times and system responding "+sResponses+" times. Total duration is "+sDuration+" seconds.\n";
            }
            
            searchVector.clear();
        }
        if (ssInput == 1) {  // option 1
            if (one_output == "") {  // not found
                cout << "ERROR: there are only " << tSession << " sessions. Please choose a valid session number." << endl;
                string s = to_string(tSession);
                one_output = "ERROR: there are only "+s+" sessions. Please choose a valid session number.\n";
                chat.push_back(one_output);
            } else {  // found
                cout << one_output;
                chat.push_back(one_output);
            }
        } else if (ssInput == 2) {  // option 2
            cout << "There are " << tSession << " chats to date with user asking " << tAsks << " times and system responding " << tResponses << " times. Total duration is " << tDuration << " seconds." << endl;
            // int to string value
            string sS, sA, sR, sD, two_output;
            sS = to_string(tSession);
            sA = to_string(tAsks);
            sR = to_string(tResponses);
            sD = to_string(tDuration);
            two_output = "There are "+sS+" chats to date with user asking "+sA+" times and system responding "+sR+" times. Total duration is "+sD+" seconds.\n";
            chat.push_back(two_output);
        } else if (ssInput == 3) {  // option 3
            // preparing file
            fstream in_myfile_session (input_filename_session);
            if (in_myfile_session.is_open()) {
                cout << "Chat " << iNumber << " chat is:" << endl;
                while (getline(in_myfile_session,line)) {  // looping through session file
                    cout << line << endl;
                    chat.push_back(line);
                }
                in_myfile_session.close();
            } else {  // file not found
                cout << "ERROR: there are only " << tSession << " chat sessions. Please choose a valid number." << endl;
                string s = to_string(tSession);
                string three_output = "ERROR: there are only "+s+" sessions. Please choose a valid session number.\n";
                chat.push_back(three_output);
            }
        }
        ++number_responses;
        in_myfile_csv.close();
    } else {
        cout << "csv file could not be opened." << endl;
    }
}

// function for matching input to command
void commandMatch(string inputInfo) {
    // variables for command and chat number
    string sNumber, ph;
    int iNumber;
    int numSummary = 0;
    int numShowchat = 0;
    vector<string> commandVector;

    // putting string into vector
    for (int i = 1; i < inputInfo.length(); ++i) {
        if ((inputInfo[i] == '-') || (inputInfo[i] == ' ')) {
            commandVector.push_back(ph);
            ph.clear();
        } else if (inputInfo.length() == i+1) {
            ph += inputInfo[i];
            commandVector.push_back(ph);  
            ph.clear();     
        } else {
            ph += inputInfo[i];
        }
    }

    // figuring out what is being asked
    for (int j = 0; j < commandVector.size(); ++j) {
        if (commandVector[j] == "summary") {
            numSummary = 1;
        } else if (commandVector[j] == "showchat") {
            numShowchat = 1;
        } else {
            sNumber = commandVector[j];
            iNumber = stoi(sNumber);
        }
    }

    // different command word combos
    if ((numSummary == 1) && (numShowchat == 1)) {
        ssInput = 1;
        sessionSearch(ssInput, iNumber);
    } else if ((numSummary == 1) && (numShowchat == 0)) {
        ssInput = 2;
        iNumber = 0;
        sessionSearch(ssInput, iNumber);
    } else if ((numSummary == 0) && (numShowchat == 1)) {
        ssInput = 3;
        sessionSearch(ssInput, iNumber);
    } else {
        cout << "Invalid command entered. Please try again." << endl;
    }
}

// main function
int main(int argc, char* argv[]) {
    // for time duration
    time_t start, end;

    // ask for what the desired information is
    cout << "Hello! Welcome to the district chatbot!" << endl;
    cout << "If you would like to exit the chatbot at any time please type Quit, quit or q" << endl;
    cout << "What can I help you with today?" << endl;
    
    // what the desired information is
    string inputInfo;
    double basePercent = 0.60;
    getline(cin, inputInfo);
    time(&start);
    
    // infinite loop for user query
    while (inputInfo != "Quit" && inputInfo != "q" && inputInfo != "quit") {
        // adding inputInfo to chat vector
        chat.push_back(inputInfo);
        ++number_asks;
        // what the user asked
        cout << "You asked: " + inputInfo << endl;
        if(strcasestr(inputInfo.c_str(),"-")) {
            commandMatch(inputInfo);
        } else {
            questionMatch(inputInfo, basePercent);
        }

        // potential exit
        cout << "Is there anything else I can help you with?" << endl;
        getline(cin, inputInfo);
    } 
    // closing remark
    cout << "Thank you for using the chatbot. Have a nice day!" << endl;

    time(&end);
    double time_taken = double(end - start);
    setprecision(5);
    duration = time_taken; 

    createSession();
}
