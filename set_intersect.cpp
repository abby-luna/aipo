#include <iostream>
#include <algorithm>

int main(){

  int lenSet;
  std::cin >> lenSet;
  int set1[lenSet];
  for (size_t i = 0; i < lenSet; i++) {
    int temp;
    std::cin >> temp;
    set1[i] = temp;
  }

  int lenSet2;
  std::cin >> lenSet2;
  int set2[lenSet2];
  for (size_t i = 0; i < lenSet2; i++) {
    int temp;
    std::cin >> temp;
    set2[i] = temp;
  }
  int lenFinal = 0;
  int *final = new int[lenFinal];

  std::sort(set1, set1 + lenSet);

  for (size_t i = 0; i < lenSet; i++) {

    for (size_t j = 0; j < lenSet2; j++) {

      if(set1[i] == set2[j]){

        final[lenFinal] = set1[i];
        lenFinal++;

      }

    }

  }

  for (size_t i = 0; i < lenFinal; i++) {
    std::cout << final[i] << ' ';
  }
  if(lenFinal == 0){

    std::cout << "Empty Set";

  }
  std::cout << "\n";



}
