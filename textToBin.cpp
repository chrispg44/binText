//Convert text -> binary 
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <fstream>

/*
Process:
  1) get string
  2) break up into chars
  3) statically cast all chars to int (ascii)
  4) convert ascii number to binary
  4) print out binary string 
*/

template <typename T>
void printElements(const T& container){
  for (size_t i = 0; i < container.size(); i++) {
    std::cout << container[i] << " ";
  }

}

//convert string to ascii
std::vector<int> strToASCII(std::string text){

  unsigned int n = text.size();

  std::vector<int> ascii_arr;
  ascii_arr.reserve(n);

  for (unsigned char c: text){
    ascii_arr.push_back(static_cast<unsigned char>(c));  //get ASCII val 
  }
  return ascii_arr;

}


//base_10 -> base_2
std::string decToBinary(int decNum) {

  std::string binary_str = "";
  int rem;

  if (decNum == 0) {  //0 is special case      
    return "0";
  }

  while (decNum > 0) {
    rem = decNum % 2;
    decNum = decNum / 2;
    binary_str += std::to_string(rem);
  }
  std::reverse(binary_str.begin(), binary_str.end());
  return binary_str;

}


int main() {

  std::string text = "";
  std::string binary_text = "";

  //file I/O
  std::string filename = "input.txt";
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Error: Could not open 'input.txt' file" << std::endl;
    return 1;
  }

  std::getline(file,text, '\0');

  file.close();
  

  std::vector<int> ascii_arr = strToASCII(text);

  for (int c: ascii_arr) {
    binary_text += decToBinary(c);
    binary_text += " ";
  }
  std::cout << binary_text << std::endl;

}


