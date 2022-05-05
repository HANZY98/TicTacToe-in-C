#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// 8 minutes in.

char gameBoard[3][3];
const char THEPLAYER = 'X' const char THECOMPUTER = 'O'

    void
    boardReset();
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
  }

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
  printf("\n")
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

  printf("Please enter row (1-3): ");
  scanf("%d", &i);
  i--;
}

void moveComputer()
{
}

char winnerCheck()
{
}

void winnerPrint(char myWinner)
{
}
