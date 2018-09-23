#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<limits>

//Calls 
bool game_win(int board[][3]);

//Display's the board's current status
void display_board(int board[][3]);

//Randomly selects two integers and calls place_token()
void comp_select(int board[][3]);

//Inquires the user for a location on the board.
void user_select(int board[][3]);

//Places a X or an O on the board, returns true if the token is placed.
bool place_token(int board[][3], int x, int y, int token_type);

int main()
{
  srand(time(0));//Set the seed for the computer.
  
  bool game_in_progress = true;
  
  //Set the board up.
  int board[3][3];
  for(int i = 0; i < 3; ++i)
  {
    board[i][0] = 0;
    board[i][1] = 0;
    board[i][2] = 0;
  }

  //Display the board...
  display_board(board);
  
  while(game_in_progress)
  {
    
    //Inquire the user...
    user_select(board);
    
    display_board(board);
    
    //Then the computer's turn.
    comp_select(board);
    
    display_board(board);
  }
  
  std::cout << "Thanks for playing!" << std::endl;
  
  return 0;
}

void display_board(int board[][3])
{
  std::cout << "  1 2 3" << std::endl;
  std::cout << "1 " << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << std::endl;
  std::cout << "  -----" << std::endl;
  std::cout << "2 " << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << std::endl;  
  std::cout << "  -----" << std::endl;
  std::cout << "3 " << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << std::endl;
  std::cout << std::endl;
}

bool place_token(int board[][3], int x, int y, int token_type)
{
  if(board[y-1][x-1] == 0)
  {
   board[y-1][x-1] = token_type;
   return true;
  }
  return false;
}

void user_select(int board[][3])
{
  int y, x; 
  bool invalid_int = true;
  bool token_placed = false;
  while(!token_placed)
  {
  
    while(invalid_int)
    {
      std::cout << "Please select a Y between 1 and 3: ";
      std::cin >> y;
    
      if(std::cin.fail() || y < 1 || y > 3)
      {
      std::cout << "Invalid integer! ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
      else
      {
      invalid_int = false;
      }
    }
  
    invalid_int = true;
    while(invalid_int)
    {
      std::cout << "Please select a X between 1 and 3: ";
      std::cin >> x;
    
      if(std::cin.fail() || x < 1 || x > 3)
      {
        std::cout << "Invalid integer! ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else
      {
      invalid_int = false;
      }
  }

    token_placed = place_token(board, x, y, 1);
    if(!token_placed)
    {
      std::cout << "Thats not a great place to pick, try again! \n" << std::endl;
    }
    invalid_int = true; //Logic reasons...
  }
  
}

void comp_select(int board[][3])
{
  int x, y;
  bool valid_int = false;
  bool token_placed = false;
  
  while(!token_placed)
  {
    x = (rand() % 3) + 1;
    y = (rand() % 3) + 1;
    token_placed = place_token(board, x, y, 2);
    valid_int = false; //Logic reasons...
  }
}
