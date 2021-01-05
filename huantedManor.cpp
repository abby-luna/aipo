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

std::string *StupidCopy(std::string *Ele, int n){
    std::string *Stupid = new std::string[n];

    for (size_t i = 0; i < n; i++) {
        Stupid[i] = Ele[i];
    }
    return Stupid;

}

void OverLay(std::string *overret, std::string *over2, int w){

    for (size_t i = 0; i < w; i++) {
        for (size_t j = 0; j < w; j++) {

            if(overret[i][j] == '.'){
                overret[i][j] = over2[i][j];
            }else if(overret[i][j] == 'V'){
                if (over2[i][j] == 'G'){
                    overret[i][j] = 'Z';
                }
            }else if(over2[i][j] == 'V'){
                if (overret[i][j] == 'G'){
                    overret[i][j] = 'Z';
                }
            }

        }
    }


}

int max(int f, int s, int t){

    if(f > s & f > t){
        return f;
    }else if(s > f & s > t){
        return s;
    }else{
        return t;
    }

}

void generateAllGrids(std::string *grid, int w,  int zo, int gh, int va){
    std::string *grid2 = StupidCopy(grid, w);

    if(zo + gh + va == 0){

        for (size_t i = 0; i < w; i++) {
            std::cout << grid2[i] << "\n";
        }
    }else{

        int maximum = max(zo, gh, va);

        for (size_t i = 0; i < maximum; i++) {
            for (size_t j = 0; j < w; j++) {
                for (size_t k = 0; k < w; k++) {
                    if(grid2[j][k] == '.'){
                        if(zo > 0){
                            grid2[j][k] = 'Z';
                            generateAllGrids(grid2, w, zo-1, gh, va);
                        }
                        if(gh > 0){
                            grid2[j][k] = 'G';
                            generateAllGrids(grid2, w, zo, gh-1, va);
                        }
                        if(va > 0){
                            grid2[j][k] = 'V';
                            generateAllGrids(grid2, w, zo, gh, va-1);
                        }
                    }
                }
            }
        }

    }



}


std::string *walk(std::string *grid, int x, int y, int w, char dirrection,int monsterNum, std::string *gridSave,bool hitMirror = false){

    static int theNumber = 0;
    std::string *grid2 = StupidCopy(grid, w);

    switch (dirrection) {
        case 'd':
        for (size_t i = 0; i < w; i++) {


            if(y+i >= w){
                break;
            }

            if(grid[y+i][x] == '.'){

                theNumber++;
                if(monsterNum == 0){
                    if(hitMirror){

                        grid2[y+i][x] = 'V';

                    }else{
                        grid2[y+i][x] = 'G';
                    }
                }else{
                    if(hitMirror){

                        grid2[y+i][x] = 'G';

                    }else{
                        grid2[y+i][x] = 'V';
                    }
                }


            }
            if(grid[y+i][x] == '/'){

                return walk(grid2, x-1, y+i,  w, 'r',monsterNum,gridSave, true);

            }
            if(grid[y+i][x] == '\\'){
                return walk(grid2, x+1, y+i,  w, 'l',monsterNum,gridSave, true);

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
                if(monsterNum == 0){
                    if(hitMirror){

                        grid2[y-i][x] = 'V';

                    }else{
                        grid2[y-i][x] = 'G';
                    }
                }else{
                    if(hitMirror){

                        grid2[y-i][x] = 'G';

                    }else{
                        grid2[y-i][x] = 'V';
                    }
                }

            }
            if(grid[y-i][x] == '/'){

                return walk(grid2, x+1, y-i,  w, 'l',monsterNum,gridSave, true);

            }
            if(grid[y-i][x] == '\\'){
                return walk(grid2, x-1, y-i,  w, 'r',monsterNum, gridSave, true);

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
                if(monsterNum == 0){
                    if(hitMirror){

                        grid2[y][x-i] = 'V';

                    }else{
                        grid2[y][x-i] = 'G';
                    }
                }else{
                    if(hitMirror){

                        grid2[y][x-i] = 'G';

                    }else{
                        grid2[y][x-i] = 'V';
                    }
                }

            }
            if(grid[y][x-i] == '/'){

                return walk(grid2, x-i, y+1,  w, 'd',monsterNum,gridSave, true);

            }
            if(grid[y][x-i] == '\\'){
                return walk(grid2, x-i, y-1,  w, 'u',monsterNum,gridSave, true);

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
                if(monsterNum == 0){
                    if(hitMirror){

                        grid2[y][x+i] = 'V';

                    }else{
                        grid2[y][x+i] = 'G';
                    }
                }else{
                    if(hitMirror){

                        grid2[y][x+i] = 'G';

                    }else{
                        grid2[y][x+i] = 'V';
                    }
                }
            }
            if(grid[y][x+i] == '/'){

                return walk(grid2, x+i, y-1,  w, 'u',monsterNum,gridSave, true);

            }
            if(grid[y][x+i] == '\\'){
                return walk(grid2, x+i, y+1,  w, 'd',monsterNum,gridSave, true);

            }

        }


        break;

    }
    int saved = theNumber;
    theNumber= 0;

    if(saved == monsterNum){

        std::cout << "hit\n";
        return grid2;

    }else if(monsterNum == 0){

        std::cout << "hit2\n";

        return grid2;

    }else{
        std::cout << "hit3\n";
        return NULL;

    }

}

std::string *definteHit(std::string *grid, int w, int h, int top[], int bottom[], int left[], int right[], int zo, int gh, int va){


    static int vamps = va;
    static int zombies = zo;
    static int ghosts = gh;

    // std::string newGrid = grid;

    //void generateAllGrids(std::string *grid, int w,  int zo, int gh, int va){

    generateAllGrids(grid, w, zo, gh, va);

    std::string *finalGrid = grid;

    // int walk(std::string *grid, int x, int y, int w, char dirrection, bool hitMirror = false){
    for (size_t i = 0; i < w; i++) {
        // top
        std::string *currentGrid = walk(grid,i,0,w,'d',top[i], grid);
        if(currentGrid != NULL){
            OverLay(finalGrid, currentGrid, w);
            for (size_t j = 0; j < w; j++) {

                std::cout << currentGrid[j] << "\n";

            }

        }


    }


    for (size_t i = 0; i < w; i++) {

        std::string *currentGrid = walk(grid,i,w-1,w,'u', bottom[i], grid);
        if(currentGrid != NULL){
            OverLay(finalGrid, currentGrid, w);

            for (size_t j = 0; j < w; j++) {
                std::cout << currentGrid[j] << "\n";

            }
        }
    }
    for (size_t i = 0; i < h; i++) {

        std::string *currentGrid = walk(grid,0,i,w,'l', left[i], grid);
        if(currentGrid != NULL){
            OverLay(finalGrid, currentGrid, w);

            for (size_t j = 0; j < w; j++) {
                std::cout << currentGrid[j] << "\n";
            }
        }

    }
    for (size_t i = 0; i < h; i++) {
        std::string *currentGrid = walk(grid,w-1,i,w,'r', left[i], grid);
        if(currentGrid != NULL){
            OverLay(finalGrid, currentGrid, w);

            for (size_t j = 0; j < w; j++) {
                std::cout << currentGrid[j] << "\n";

            }
        }
    }


    std::cout << "\n\n\nFinal Grid:\n";
    for (size_t i = 0; i < w; i++) {
        std::cout << finalGrid[i] << "\n";
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
