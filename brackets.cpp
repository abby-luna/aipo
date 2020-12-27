#include <iostream>


int main(){

  int lenStr;
  std::cin >> lenStr;

  char str[lenStr];
  std::cin >> str;

  int opened = 0;

  int validBrackets = 0;

  for (size_t i = 0; i < lenStr; i++) {

    if(str[i] == '('){
      opened += 1;
    }else if(str[i] == ')'){
      if(opened > 0){
        opened-=1;
        validBrackets += 2;

      }
    }
  }

  std::cout << validBrackets << "\n";

}
