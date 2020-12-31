#include <iostream>
#include <string>

void printArr(int x[], int sizeOfArr){

  for (size_t i = 0; i < sizeOfArr; i++) {
    std::cout << x[i] << " ";
  }
  std::cout << "\n";

}

void printArr(std::string x, int sizeOfArr){

  for (size_t i = 0; i < sizeOfArr; i++) {
    std::cout << x[i];
  }
  std::cout << "\n";

}

int walk(std::string *grid, int x, int y, int w, char dirrection, bool hitMirror = false){

    static int theNumber = 0;
    int returnN = 0;

    switch (dirrection) {
        case 'd':
        for (size_t i = 0; i < w; i++) {


            if(y+i >= w){
                break;
            }

            if(grid[y+i][x] == '.'){

                theNumber++;
                /*
                if(hitMirror){

                    grid[y+i][x] = 'G';

                }else{
                    grid[y+i][x] = 'V';
                }
                */

            }
            if(grid[y+i][x] == '/'){

                return walk(grid, x-1, y+i,  w, 'r', true);

            }
            if(grid[y+i][x] == '\\'){
                return walk(grid, x+1, y+i,  w, 'l', true);

            }

        }

        break;

        case 'u':
        for (size_t i = 0; i < w; i++) {

            if(y-i == -1){
                break;
            }

            if(grid[y-i][x] == '.'){
                theNumber++;
                /*
                if(hitMirror){

                    grid[y-i][x] = 'G';

                }else{
                    grid[y-i][x] = 'V';
                }
                */

            }
            if(grid[y-i][x] == '/'){

                return walk(grid, x+1, y-i,  w, 'l', true);

            }
            if(grid[y-i][x] == '\\'){
                return walk(grid, x-1, y-i,  w, 'r', true);

            }

        }

        break;

        case 'r':


        for (size_t i = 0; i < w; i++) {


            if(x-i == -1){
                break;
            }

            if(grid[y][x-i] == '.'){
                theNumber++;
                /*
                if(hitMirror){

                    grid[y][x-i] = 'G';

                }else{
                    grid[y][x-i] = 'V';
                }
                */

            }
            if(grid[y][x-i] == '/'){

                return walk(grid, x-i, y+1,  w, 'd', true);

            }
            if(grid[y][x-i] == '\\'){
                return walk(grid, x-i, y-1,  w, 'u', true);

            }

        }


        break;

        case 'l':

        for (size_t i = 0; i < w; i++) {


            if(x+i == w){
                break;
            }

            if(grid[y][x+i] == '.'){
                theNumber++;
                /*
                if(hitMirror){

                    grid[y][x+i] = 'G';

                }else{
                    grid[y][x+i] = 'V';
                }
                */

            }
            if(grid[y][x+i] == '/'){

                return walk(grid, x+i, y-1,  w, 'u', true);

            }
            if(grid[y][x+i] == '\\'){
                return walk(grid, x+i, y+1,  w, 'd', true);

            }

        }


        break;

    }

    returnN = theNumber;
    theNumber = 0;

    return returnN;

}

std::string *definteHit(std::string *grid, int w, int h, int top[], int bottom[], int left[], int right[], int zo, int gh, int va){


    static int vamps = va;
    static int zombies = zo;
    static int ghosts = gh;

    // std::string newGrid = grid;

    std::cout << grid[2][2] << "\n";

    // int walk(std::string *grid, int x, int y, int w, char dirrection, bool hitMirror = false){
    for (size_t i = 0; i < w; i++) {
        // top
        std::cout << walk(grid,i,0,w,'d') << '\n';

    }
    for (size_t i = 0; i < w; i++) {

        std::cout << walk(grid,i,w-1,w,'u') << '\n';

    }
    for (size_t i = 0; i < h; i++) {

        std::cout << walk(grid,0,i,w,'l') << '\n';

    }
    for (size_t i = 0; i < h; i++) {
        std::cout << walk(grid,w-1,i,w,'r') << '\n';

    }


    // int walk(std::string *grid, int x, int y, int w, char dirrection){

    return grid;

}


int main(){

  // get all inputs
  int vampireNumber;
  int ghostNumber;
  int zombieNumber;

  std::cin >> vampireNumber;
  std::cin >> zombieNumber;
  std::cin >> ghostNumber;

  //////////////////////////

  // w is the amount on top

  int h;
  int w;
  std::cin >> w;
  std::cin >> h;

  int top[w];
  int bottom[w];
  int left[h];
  int right[h];

  for (size_t i = 0; i < w; i++) {
    int temp;
    std::cin >> temp;
    top[i] = temp;
  }
  for (size_t i = 0; i < w; i++) {
    int temp;
    std::cin >> temp;
    bottom[i] = temp;
  }
  for (size_t i = 0; i < h; i++) {
    int temp;
    std::cin >> temp;
    left[i] = temp;
  }
  for (size_t i = 0; i < h; i++) {
    int temp;
    std::cin >> temp;
    right[i] = temp;
  }

  std::string grid[h];

  for (size_t i = 0; i < h; i++) {

    std::cin >> grid[i];

  }


  definteHit(grid, w, h, top, bottom, left, right, zombieNumber, ghostNumber, vampireNumber);



}
