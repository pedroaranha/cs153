//Author: Pedro Aranha. Section: B
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//C == clam
//  == unwalked path
//. == walked path
//Z == start
//E == exit

void solveMaze(string* maze, int rows, int cols){
  //find start
  int current_row, current_col;
  for(int i = 0; i < rows; i++){
    for(int k = 0; k < cols; k++){
      if(maze[i][k] == 'Z'){
        current_row = i;
        current_col = k;
        break;
      }
    }
  }

  //finding possible paths while not success
  while(maze[current_row][current_col] != 'E'){

    //north
    if(maze[current_row-1][current_col] == ' '){
      //valid, going north
      maze[current_row-1][current_col] = '.';
      current_row -= 1;
    }
    //east
    else if(maze[current_row][current_col+1] == ' '){
      //going east
      maze[current_row][current_col+1] = '.';
      current_col += 1;
    }
    //south
    else if(maze[current_row+1][current_col] == ' '){
      //going south
      maze[current_row+1][current_col] = '.';
      current_row += 1;
    }
    //west
    else if(maze[current_row][current_col-1] == ' '){
      //going west
      maze[current_row][current_col-1] = '.';
      current_col -= 1;
    }

    //nowhere to go... is goal?
    else if(maze[current_row-1][current_col] == 'E')
      break;
    else if(maze[current_row][current_col+1] == 'E')
      break;
    else if(maze[current_row+1][current_col] == 'E')
      break;
    else if(maze[current_row][current_col-1] == 'E')
      break;

    //not goal? backtracking!

    //checking breadcrumbs...
    //north
    else if(maze[current_row-1][current_col] == '.'){
      //going north
      maze[current_row][current_col] = 'x';
      current_row -= 1;
    }
    //east
    else if(maze[current_row][current_col+1] == '.'){
      //going east
      maze[current_row][current_col] = 'x';
      current_col += 1;
    }
    //south
    else if(maze[current_row+1][current_col] == '.'){
      //going south
      maze[current_row][current_col] = 'x';
      current_row += 1;
    }
    //west
    else if(maze[current_row][current_col-1] == '.'){
      //going west
      maze[current_row][current_col] = 'x';
      current_col -= 1;
    }
  }

  //all done! removing breadcrumbs...
  for(int i = 0; i < rows; i++){
    for(int k = 0; k < cols; k++){
      if(maze[i][k] == 'x')
        maze[i][k] = ' ';
    }
  }
}

int main() {
  int rows, cols;
  string* maze;
  int maze_count = 0;

  cin >> cols >> rows;
  cin.ignore();

  while(rows > 0 && cols > 0){
    maze = new string[rows];
    for(int i = 0; i < rows; i++){
      getline(cin, maze[i]);
    }

    solveMaze(maze, rows, cols);

    //Print Solution
    cout << "Map : " << maze_count << endl;
    for(int k=0; k < rows; k++){
      cout << maze[k] << endl;
    }
    cout << endl;

    //tidying house for next maze (if any)
    maze_count++;
    delete [] maze;
    cin >> cols >> rows;
    cin.ignore();
  }

  return 0;
}