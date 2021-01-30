#include <iostream>
#include <string>



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
            }else if(over2[i][j] == 'a'){

                if(over2[i][j] == 'V'){
                    overret[i][j] = 'Z';
                }

            }else if(over2[i][j] == 'b'){

                if(over2[i][j] == 'G'){
                    overret[i][j] = 'Z';
                }


            }

        }
    }


}

bool verifyLine(std::string *grid, int x, int y, int w, char dirrection,int monsterNum, bool hitMirror = false){

    static int theNumber = 0;
    std::string *grid2 = StupidCopy(grid, w);

    switch (dirrection) {
        case 'd':
        for (size_t i = 0; i < w; i++) {


            if(y+i >= w){
                break;
            }

            if(grid[y+i][x] == 'Z'){

                theNumber++;

            }else if(grid[y+i][x] == 'G'){
                if(hitMirror){
                    theNumber++;
                }
            }else if(grid[y+i][x] == 'V'){
                if(!hitMirror){
                    theNumber++;
                }
            }
            if(grid[y+i][x] == '/'){

                return verifyLine(grid2, x-1, y+i,  w, 'r',monsterNum, true);

            }
            if(grid[y+i][x] == '\\'){
                return verifyLine(grid2, x+1, y+i,  w, 'l',monsterNum, true);

            }

        }

        break;

        case 'u':
        for (size_t i = 0; i < w; i++) {

            if(y-i == -1){
                break;
            }

            if(grid[y-i][x] == 'Z'){

                theNumber++;

            }else if(grid[y-i][x] == 'G'){
                if(hitMirror){
                    theNumber++;
                }
            }else if(grid[y-i][x] == 'V'){
                if(!hitMirror){
                    theNumber++;
                }
            }
            if(grid[y-i][x] == '/'){

                return verifyLine(grid2, x+1, y-i,  w, 'l',monsterNum, true);

            }
            if(grid[y-i][x] == '\\'){
                return verifyLine(grid2, x-1, y-i,  w, 'r',monsterNum, true);

            }

        }

        break;

        case 'r':


        for (size_t i = 0; i < w; i++) {


            if(x-i == -1){
                break;
            }

            if(grid[y][x-i] == 'Z'){

                theNumber++;

            }else if(grid[y][x-i] == 'G'){
                if(hitMirror){
                    theNumber++;
                }
            }else if(grid[y][x-i] == 'V'){
                if(!hitMirror){
                    theNumber++;
                }
            }
            if(grid[y][x-i] == '/'){

                return verifyLine(grid2, x-i, y+1,  w, 'd',monsterNum, true);

            }
            if(grid[y][x-i] == '\\'){
                return verifyLine(grid2, x-i, y-1,  w, 'u',monsterNum, true);

            }

        }


        break;

        case 'l':

        for (size_t i = 0; i < w; i++) {


            if(x+i == w){
                break;
            }

            if(grid[y][x+i] == 'Z'){

                theNumber++;

            }else if(grid[y][x+i] == 'G'){
                if(hitMirror){
                    theNumber++;
                }
            }else if(grid[y][x+i] == 'V'){
                if(!hitMirror){
                    theNumber++;
                }
            }
            if(grid[y][x+i] == '/'){

                return verifyLine(grid2, x+i, y-1,  w, 'u',monsterNum, true);

            }
            if(grid[y][x+i] == '\\'){
                return verifyLine(grid2, x+i, y+1,  w, 'd',monsterNum, true);

            }

        }


        break;

    }
    int saved = theNumber;
    theNumber= 0;

    if(saved == monsterNum){
        return true;

    }else{
        return false;

    }

}


bool verifyPosibility(std::string *grid, int x, int y, int w, char dirrection,int monsterNum, bool hitMirror = false){

    static int theNumber = 0;
    std::string *grid2 = StupidCopy(grid, w);

    switch (dirrection) {
        case 'd':
        for (size_t i = 0; i < w; i++) {


            if(y+i >= w){
                break;
            }

            if(grid[y+i][x] == 'Z'){

                theNumber++;

            }else if(grid[y+i][x] == 'G'){
                if(hitMirror){
                    theNumber++;
                }
            }else if(grid[y+i][x] == 'V'){
                if(!hitMirror){
                    theNumber++;
                }
            }
            if(grid[y+i][x] == '/'){

                return verifyPosibility(grid2, x-1, y+i,  w, 'r',monsterNum, true);

            }
            if(grid[y+i][x] == '\\'){
                return verifyPosibility(grid2, x+1, y+i,  w, 'l',monsterNum, true);

            }

        }

        break;

        case 'u':
        for (size_t i = 0; i < w; i++) {

            if(y-i == -1){
                break;
            }

            if(grid[y-i][x] == 'Z'){

                theNumber++;

            }else if(grid[y-i][x] == 'G'){
                if(hitMirror){
                    theNumber++;
                }
            }else if(grid[y-i][x] == 'V'){
                if(!hitMirror){
                    theNumber++;
                }
            }
            if(grid[y-i][x] == '/'){

                return verifyPosibility(grid2, x+1, y-i,  w, 'l',monsterNum, true);

            }
            if(grid[y-i][x] == '\\'){
                return verifyPosibility(grid2, x-1, y-i,  w, 'r',monsterNum, true);

            }

        }

        break;

        case 'r':


        for (size_t i = 0; i < w; i++) {


            if(x-i == -1){
                break;
            }

            if(grid[y][x-i] == 'Z'){

                theNumber++;

            }else if(grid[y][x-i] == 'G'){
                if(hitMirror){
                    theNumber++;
                }
            }else if(grid[y][x-i] == 'V'){
                if(!hitMirror){
                    theNumber++;
                }
            }
            if(grid[y][x-i] == '/'){

                return verifyPosibility(grid2, x-i, y+1,  w, 'd',monsterNum, true);

            }
            if(grid[y][x-i] == '\\'){
                return verifyPosibility(grid2, x-i, y-1,  w, 'u',monsterNum, true);

            }

        }


        break;

        case 'l':

        for (size_t i = 0; i < w; i++) {


            if(x+i == w){
                break;
            }

            if(grid[y][x+i] == 'Z'){

                theNumber++;

            }else if(grid[y][x+i] == 'G'){
                if(hitMirror){
                    theNumber++;
                }
            }else if(grid[y][x+i] == 'V'){
                if(!hitMirror){
                    theNumber++;
                }
            }
            if(grid[y][x+i] == '/'){

                return verifyPosibility(grid2, x+i, y-1,  w, 'u',monsterNum, true);

            }
            if(grid[y][x+i] == '\\'){
                return verifyPosibility(grid2, x+i, y+1,  w, 'd',monsterNum, true);

            }

        }


        break;

    }
    int saved = theNumber;
    theNumber= 0;

    if(saved <= monsterNum){
        return true;

    }else{
        return false;

    }

}

bool verifyPossibleWorkingGrid(std::string *grid, int w, int top[], int bottom[], int left[], int right[]){
    // int walk(std::string *grid, int x, int y, int w, char dirrection, bool hitMirror = false){
    for (size_t i = 0; i < w; i++) {
        // top
        bool line = verifyPosibility(grid,i,0,w,'d',top[i]);
        if(!line){


            return line;
        }

        bool line2 = verifyPosibility(grid,i,w-1,w,'u', bottom[i]);
        if(!line2){

            return line2;
        }


        bool line3 = verifyPosibility(grid,w-1,i,w,'r', right[i]);
        if(!line3){

            return line3;
        }

        bool line4 = verifyPosibility(grid,0,i,w,'l', left[i]);
        if(!line4){

            return line4;
        }
    }

    return true;


}


bool verify(std::string *grid, int w, int top[], int bottom[], int left[], int right[]){
    // int walk(std::string *grid, int x, int y, int w, char dirrection, bool hitMirror = false){
    for (size_t i = 0; i < w; i++) {
        // top
        bool line = verifyLine(grid,i,0,w,'d',top[i]);
        if(!line){
            return line;
        }

        bool line2 = verifyLine(grid,i,w-1,w,'u', bottom[i]);
        if(!line2){
            return line2;
        }

        bool line3 = verifyLine(grid,w-1,i,w,'r', right[i]);
        if(!line3){
            return line3;
        }


        bool line4 = verifyLine(grid,0,i,w,'l', left[i]);
        if(!line4){
            return line4;
        }
    }

    return true;


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
int *count(std::string *grid, int w){

    int *array = new int[3];
    int v = 0;
    int g = 0;
    int z = 0;

    for (size_t i = 0; i < w; i++) {
        for (size_t j = 0; j < w; j++) {
            if(grid[i][j] == 'V'){
                v++;
            }else if(grid[i][j] == 'Z'){
                z++;

            }else if(grid[i][j] == 'G'){
                g++;

            }
        }
    }
    array[0] = v;
    array[1] = g;
    array[2] = z;

    return array;
}

void generateAllGrids(std::string *grid, int w,  int zo, int gh, int va, int top[], int bottom[], int left[], int right[], int x=0, int y=0){
    std::string *grid2 = StupidCopy(grid, w);

    if(zo + gh + va == 0){
        // bool verify(std::string *grid, int w, int top[], int bottom[], int left[], int right[], int zo, int gh, int va){

        bool isValid = verify(grid2, w, top, bottom, left, right);
        if(isValid){
            for (size_t i = 0; i < w; i++) {
                std::cout << grid2[i] << "\n";
            }
            exit(0);
            return;
        }
    }else{

        int moveX = x + 1;
        int moveY = y;
        if(moveX == w){
            moveX = 0;
            moveY++;
        }

        if(verifyPossibleWorkingGrid(grid2, w, top, bottom, left, right)){


            if(grid2[y][x] == '.'){

                if(zo > 0){
                    grid2[y][x] = 'Z';
                    generateAllGrids(grid2, w, zo-1, gh, va, top, bottom, left, right, moveX, moveY);
                }
                if(gh > 0){
                    grid2[y][x] = 'G';
                    generateAllGrids(grid2, w, zo, gh-1, va, top, bottom, left, right, moveX, moveY);
                }
                if(va > 0){
                    grid2[y][x] = 'V';
                    generateAllGrids(grid2, w, zo, gh, va-1, top, bottom, left, right, moveX, moveY);
                }

            }else if(grid2[y][x] == 'a'){

                if(zo > 0){
                    grid2[y][x] = 'Z';
                    generateAllGrids(grid2, w, zo-1, gh, va, top, bottom, left, right, moveX, moveY);
                }
                if(gh > 0){
                    grid2[y][x] = 'G';
                    generateAllGrids(grid2, w, zo, gh-1, va, top, bottom, left, right, moveX, moveY);
                }


            }else if(grid2[y][x] == 'b'){

                if(zo > 0){
                    grid2[y][x] = 'Z';
                    generateAllGrids(grid2, w, zo-1, gh, va, top, bottom, left, right, moveX, moveY);
                }
                if(va > 0){
                    grid2[y][x] = 'V';
                    generateAllGrids(grid2, w, zo, gh, va-1, top, bottom, left, right, moveX, moveY);
                }

            }else{

                generateAllGrids(grid2, w, zo, gh, va, top, bottom, left, right, moveX, moveY);

            }
        }
    }
}


std::string *walk(std::string *grid, int x, int y, int w, char dirrection,int monsterNum ,bool hitMirror = false){

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

                        grid2[y+i][x] = 'a';

                    }else{
                        grid2[y+i][x] = 'b';
                    }

                }



            }
            if(grid[y+i][x] == '/'){

                return walk(grid2, x-1, y+i,  w, 'r',monsterNum, true);

            }
            if(grid[y+i][x] == '\\'){
                return walk(grid2, x+1, y+i,  w, 'l',monsterNum, true);

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

                        grid2[y-i][x] = 'a';

                    }else{
                        grid2[y-i][x] = 'b';
                    }

                }

            }
            if(grid[y-i][x] == '/'){

                return walk(grid2, x+1, y-i,  w, 'l',monsterNum, true);

            }
            if(grid[y-i][x] == '\\'){
                return walk(grid2, x-1, y-i,  w, 'r',monsterNum, true);

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

                        grid2[y][x-i] = 'a';

                    }else{
                        grid2[y][x-i] = 'b';
                    }

                }


            }
            if(grid[y][x-i] == '/'){

                return walk(grid2, x-i, y+1,  w, 'd',monsterNum, true);

            }
            if(grid[y][x-i] == '\\'){
                return walk(grid2, x-i, y-1,  w, 'u',monsterNum, true);

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

                        grid2[y][x+i] = 'a';

                    }else{
                        grid2[y][x+i] = 'b';
                    }

                }

            }
            if(grid[y][x+i] == '/'){

                return walk(grid2, x+i, y-1,  w, 'u',monsterNum, true);

            }
            if(grid[y][x+i] == '\\'){
                return walk(grid2, x+i, y+1,  w, 'd',monsterNum, true);

            }

        }


        break;

    }
    int saved = theNumber;
    theNumber= 0;

    if(saved == monsterNum){

        return grid2;

    }else if(monsterNum == 0){


        return grid2;

    }else{
        return NULL;

    }

}

void definteHit(std::string *grid, int w, int h, int top[], int bottom[], int left[], int right[], int zo, int gh, int va){


    int vamps = va;
    int zombies = zo;
    int ghosts = gh;

    std::string *grid2 = StupidCopy(grid, w);

    std::string *finalGrid = StupidCopy(grid, w);

    // int walk(std::string *grid, int x, int y, int w, char dirrection, bool hitMirror = false){
    for (size_t i = 0; i < w; i++) {
        // top
        std::string *currentGrid = walk(grid,i,0,w,'d',top[i]);
        if(currentGrid != NULL){



            OverLay(finalGrid, currentGrid, w);

        }


    }


    for (size_t i = 0; i < w; i++) {

        std::string *currentGrid = walk(grid,i,w-1,w,'u', bottom[i]);
        if(currentGrid != NULL){

            OverLay(finalGrid, currentGrid, w);

        }
    }
    for (size_t i = 0; i < h; i++) {

        // bool line = verifyLine(grid,w-1,i,w,'r', right[i]);
        std::string *currentGrid = walk(grid,0,i,w,'l', left[i]);
        if(currentGrid != NULL){

            OverLay(finalGrid, currentGrid, w);

        }

    }
    // yeah i win. ghosts dont exisy
    for (size_t i = 0; i < h; i++) {
        std::string *currentGrid = walk(grid,w-1,i,w,'r', right[i]);
        if(currentGrid != NULL){

            OverLay(finalGrid, currentGrid, w);

        }
    }

     // void count(std::string *grid, int w, int *v, int *g, int *z){

         int *arr = count(finalGrid, w);
         generateAllGrids(finalGrid, w, zo - arr[2], gh- arr[1], va - arr[0], top, bottom, left, right);


    /*
    array[0] = v;
    array[1] = g;
    array[2] = z;
    */

    // int walk(std::string *grid, int x, int y, int w, char dirrection){

}


//generateAllGrids(finalGrid, w, zo - arr[2], gh- arr[1], va - arr[0], top, bottom, left, right);


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
