#include <stdlib.h>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <iterator>
#include <string>
/* Utility functions to get a lowercase version and delete spaces*/
void lowerCase(std::string& ans){
    std::transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
}

int main(){
std::string lineInput;
std::getline(std::cin, lineInput);
lowerCase(lineInput);
lineInput.erase(std::remove_if(lineInput.begin(), lineInput.end(), ::isspace), lineInput.end());
std::string sub;
std::getline(std::cin, sub);
lowerCase(sub);
sub.erase(std::remove_if(sub.begin(), sub.end(), ::isspace), sub.end());
//convert the strings to char vectors.
std::vector<char>* orig = new std::vector<char>();
for(int i=0; i<lineInput.size(); i++){
  orig->push_back(lineInput[i]);
}
//Do the letter subtraction.
for(int i=0; i<sub.size(); i++){
  for(int j=0; j<orig->size(); j++){
    if(orig->at(j) == sub[i]){
      orig->erase(orig->begin()+j);
      break;
    }
    else if(j == orig->size()-1)//If we're at the end.
      std::cout<<"This is not a complete anagram!  One letter was not found!";
}
}


std::cout<<"remaining letters: ";
for(int i=0; i<orig->size(); i++)//print
  std::cout<<orig->at(i);
  
}