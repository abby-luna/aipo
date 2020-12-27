#include <iostream>
#include <cmath>

bool isPrime(int input){
  if(input == 2){
    return true;
  }

  for (size_t i = std::ceil(std::sqrt(input)); i > 1; i--) {

    if(input % i == 0){
      return false;
    }

  }
  return true;

}


// n = 4506  case = {4, 5, 0, 6} endBigO = 4
bool isPalindrome(int inputNum){

  int arrLen = 0;
  int *arr = new int[arrLen];

  // slice it into an array
  int slicedNum = inputNum;

  while(slicedNum){

    arr[arrLen] = slicedNum % 10;
    slicedNum = std::floor(slicedNum / 10);
    arrLen++;

  }
  ////////////////////////////////////


  // reconstruct bot sides
  int side1 = 0;
  int side2 = 0;

  if(arrLen == 1){
    return true;
  }

  for (size_t i = 0; i < std::round(arrLen/2); i++) {
    side1 += arr[i] * std::pow(10, std::round(arrLen/2) - i-1);
  }


  for (size_t i = arrLen-1; i > std::round(arrLen/2)-1; i--) {

    side2 += arr[i] * std::pow(10, std::round(arrLen/2) - (std::round(arrLen/2) - (i-std::round(arrLen/2) - (arrLen%2))));

  }

  return side1 == side2;
}

int main(){

  int inputNum;
  std::cin >> inputNum;

  for (size_t i = std::ceil(std::sqrt(inputNum)); i > 1; i--) {

    // if its a factor, case 1
    if (inputNum % i == 0) {

      if(isPalindrome(i)){

        if(isPrime(i)){
          std::cout << i << "\n";
          return 0;
        }
      }

    }

  }
  std::cout << "-1\n";

}
