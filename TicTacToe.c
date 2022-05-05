#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// 8 minutes in.

char gameBoard[3][3];
const char THEPLAYER = 'X';
const char THECOMPUTER = 'O';

void boardReset();
void boardPrint();
int spaceCheck();
void movePlayer();
void moveComputer();
char winnerCheck();
void winnerPrint(char);

int main()
{

  char myWinner = ' ';

  boardReset();

  while (myWinner == ' ' && spaceCheck() != 0)
  {
    boardPrint();
    movePlayer();
    myWinner = winnerCheck();
    if (myWinner != ' ' || spaceCheck() == 0)
    {
      break;
    }

    moveComputer();
    myWinner = winnerCheck();
    if (myWinner != ' ' || spaceCheck() == 0)
    {
      break;
    }
  }

  boardPrint();
  winnerPrint(myWinner);

  return 0;
}

void boardReset()
{

  for (int x = 0; x < 3; x++)
  {
    for (int i = 0; i < 3; i++)
    {
      gameBoard[x][i] = ' ';
    }
  }
}

void boardPrint()
{
  printf(" %c | %c | %c ", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
  printf("\n");
}

int spaceCheck()
{
  int spacesFree = 9;

  for (int x = 0; x < 3; x++)
  {
    for (int i = 0; i < 3; i++)
    {
      if (gameBoard[x][i] != ' ')
      {
        spacesFree--;
      }
    }
  }
  return spacesFree;
}

void movePlayer()
{
  int i;
  int j;
  do
  {
    printf("Please enter row (1-3): ");
    scanf("%d", &i);
    i--;
    printf("Please column row (1-3): ");
    scanf("%d", &j);
    j--;

    if (gameBoard[i][j] != ' ')
    {
      printf("That is an invalid move!\n");
    }
    else
    {
      gameBoard[i][j] = THEPLAYER;
      break;
    }
  } while (gameBoard[i][j] != ' ');
}

void moveComputer()
{
  srand(time(0));
  int i;
  int j;

  if (spaceCheck() > 0)
  {
    do
    {
      i = rand() % 3;
      j = rand() % 3;
    } while (gameBoard[i][j] != ' ');

    gameBoard[i][j] = THECOMPUTER;
  }
  else
  {
    winnerPrint(' ');
  }
}

char winnerCheck()
{
  for (int i = 0; i < 3; i++)
  {
    if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2])
    {
      return gameBoard[i][0];
    }
  }
  for (int i = 0; i < 3; i++)
  {
    if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
    {
      return gameBoard[0][i];
    }
  }
  if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2])
  {
    return gameBoard[0][0];
  }
  if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0])
  {
    return gameBoard[0][2];
  }
  return ' ';
}

void winnerPrint(char myWinner)
{
  if (myWinner == THEPLAYER)
  {
    printf("PLAYER WINS!");
  }
  else if (myWinner == THECOMPUTER)
  {
    printf("COMPUTER WINS!");
  }
  else
  {
    printf("SADLY ITS A TIE");
  }
}
