// include
#include <iostream>

// definitions
#define NUMBER_OF_CASES 2

void inArr(char a, char arr[NUMBER_OF_CASES]){

  for (size_t i = 0; i < 2; i++) {

    if (arr[i] == a){
      std::cout << "1\n";
      return;
    }
  }
  std::cout << "2\n";

}

struct rockPscissors{

  char R[NUMBER_OF_CASES] = {'L', 'C'};
  char P[NUMBER_OF_CASES] = {'R', 'S'};
  char C[NUMBER_OF_CASES] = {'L', 'P'};
  char L[NUMBER_OF_CASES] = {'S', 'P'};
  char S[NUMBER_OF_CASES] = {'C', 'R'};

};

int main(){

  // I/O begin
  char first;
  char second;

  // cin
  std::cin >> first;
  std::cin >> second;

  // check 1,
  if (first == second){

    std::cout << "D\n";

  }else{
    rockPscissors OBJ;
    switch (first) {
      case 'R':
      inArr(second, OBJ.R);
      break;

      case 'P':
      inArr(second, OBJ.P);
      break;

      case 'C':
      inArr(second, OBJ.C);
      break;

      case 'L':
      inArr(second, OBJ.L);
      break;

      case 'S':
      inArr(second, OBJ.S);
      break;
    }

  }

}
