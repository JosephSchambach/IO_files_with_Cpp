#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void readIntoFile(ofstream&);
void readIntoNewFile(ifstream&);
void printFile(const string&);

int main(){
   // Ask the user for input or output
   cout << "Do you want to read into file or out of file?(i or o): ";
   char answer;
   cin >> answer;

   // If the user wants to do an input
   if (answer == 'i'){
       // Create an output file stream and call the function
       ofstream input{"input.txt", ios::out};
       readIntoFile(input);
   }
   // If the user wants to do an output
   if (answer == 'o') {
       // Create an input stream and call function
       ifstream output{"input.txt", ios::in | ios::out};
       readIntoNewFile(output);
   }
   return 0;
}

// Function to read into a file
void readIntoFile(ofstream& file){
   // Check for opening success
   if (!file){
       cerr << "File could not be opened" << endl;
       exit(EXIT_FAILURE);
   }

   string word; // Word to be read in
   while (cin >> word){
       // Read in word with a space
       file << word << ' ';
   }
}

// Function to read out of a file
void readIntoNewFile(ifstream& file){
   // Check if file can be opened
   if (!file){
       cerr << "File could not be opened" << endl;
       exit(EXIT_FAILURE);
   }

   // Create a new output file stream to read into a new file
   ofstream readInFile{"output.txt", ios::out};
   string word; // Word to be read
   char c; // Char for capitalizing

   // Read in from file
   while (file >> word) {
       // Check if first letter is a
       if (word[0] == 'a') {
           // Loop through the word and capitalize all letters
           for (int i{0}; i < word.length(); i++) {
               c = word[i];
               c -= 32;
               word[i] = c;
           }
           // Read into the new file with a space
           readInFile << word << ' ';
       }
       // If the first letter is not an a, read word as is
       else {
           // Read word into the new file
           readInFile << word << ' ';
       }
       // Print out contents of the new file as they are read
       printFile(word);
   }
}

// Function to print out contents of file
void printFile(string const &str){
   cout << str << ' ';
}
