/**
* @file GameUtility.c
* @brief Library with functions for setting up and playing the game.
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/

/* libc include for random numbers function */
#include <math.h>

/* libc include for the tiem function*/
#include <time.h>

/* libc include for the malloc and srand function */
#include <stdlib.h>

/* declares the function provided by this library */
#include "GameUtility.h"

//local variables which saves field parameters
int rs;
int cs;
int totc;
int const SIZE_THRESHOLD=100;

/**
* @brief Builds the game field.
*
* @param settingField the matrix of the field to set up with random values.
* @param n the number of elements of the matrix.
* @param cl the number of elements in a raw.
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
void setField(int* settingField,int n,int cl)
{
    //setting local variable with actual values of total cells
    totc=n;

    //setting the cells with random values between 0 and c depending on n
    srand(time(NULL));
    int c=(4*n+100-1)/100;
    if(c>9)
    {
      c=9;
    }
    for(int i=0;i<n;i++)
    {
      *(settingField+i)=rand()%c;;
    }
    //setting the 90 percent of the cells to 0;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
      if((rand()%50)<45)
      {
        *(settingField+i)=0;
      }
    }
    *(settingField)=0;
    *(settingField+n-cl)=0;
}

/**
* @brief Turn the game field into a string.
*
* @param setField the matrix of the field to turn into a string.
* @param rr the number of raws of the matrix.
* @param cc the number of colums of the matrix.
*
* @return the string with the field.
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
char* printField(int* setField,int rr,int cc)
{
    //setting local variables with actual values of number of raws and columns
    rs=rr;
    cs=cc;

    char* field=malloc(rr*(2*cc+1)*sizeof(char));
    for(int i=0;i<rr;i++)
    {
      for(int j=0;j<cc+1;j++)
      {
        if(j!=cc)
        {
          char value=*(setField+i*(cc)+j)+'0';
          if(value!='0')
          {
            *(field+i*(2*cc+1)+2*j)=value;
          }
          else
          {
            *(field+i*(2*cc+1)+2*j)=' ';
          }
          *(field+i*(2*cc+1)+2*j+1)='|';
        }
        else
        {
          *(field+i*(2*cc+1)+2*j)='\n';
        }
      }
    }
    return field;
}

/**
* @brief Rolls a dice.
*
* @return a integer 1-6 for large fields, 1-4 for small fields.
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
int dice()
{
    if(totc>SIZE_THRESHOLD)
    {
      return rand()%6+1;
    }
    return rand()%4+1;
}

/**
* @brief Does the player move.
*
* @param move pointer to the specified move, move points to intial raw coordinate
* move+1 points to intial column coordinate
* move+2 points to the direction to walk towards
* @param quantity the number of cells to walk
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
void updatePosition(int* move,int quantity)
{
    int raw=*(move);
    int column=*(move+1);
    int direction=*(move+2);

    //update x
    switch (direction) {
      case 1:
      case 2:
      case 3:
        *(move)=(*(move)+quantity)%(rs);
        break;
      case 7:
      case 8:
      case 9:
        *(move)=(rs+(*(move)-quantity))%(rs);
        break;
    }

    //update y
    switch (direction) {
      case 3:
      case 6:
      case 9:
          *(move+1)=(*(move+1)+quantity)%(cs);
        break;
      case 1:
      case 4:
      case 7:
          *(move+1)=(cs+(*(move+1)-quantity))%(cs);
        break;
    }
}

/**
* @brief Says if there is a winner.
*
* @param ps 4 integers pointer to the pawns
* ps points to server raw coordinate
* ps+1 points to server column coordinate
* ps+2 points to client raw coordinate
* ps+3 points to client column coordinate.
*
* @return 1 server is the winner, -1 client is the winner, 0 there is no winner.
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
int winner(int* ps)
{
  //flags to indicate winners
  int s=0;
  int c=0;

  //the server is winner
  if((*(ps)==(rs-1)) && (*(ps+1)==0))
  {
    s=1;
  }
  //the client is winner
  if((*(ps+2)==(rs-1)) && (*(ps+3)==(cs-1)))
  {
    c=1;
  }
  return 0-c+s;
}

/**
* @brief Decide which direction get closer to the goal.
*
* @param x points to intial raw coordinate.
* @param y points to intial column coordinate.
* @param distance the number of cells to walk.
*
* @return the number of the best way to walk towards
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
int bestChoice(int x,int y,int distance)
{
  int b;

  //if already diagonally aligned
  if(y==(rs-1-x))
  {
    return 1;
  }

  //if already orizzontaly aligned
  if(x==(rs-1))
  {
    if((cs+(y-distance))%(cs)<(y+distance)%(cs))
    {
      return 4;
    }
    return 6;
  }

  //if already vertically aligned
  if(y==0)
  {
    if((rs+(x-distance))%(rs)<(x+distance)%(rs))
    {
      return 8;
    }
    return 2;
  }

  //trying to orizzontaly or diagonnally align to goal
  if((rs+(x-distance))%(rs)==(rs) || rs-1-(rs+(x-distance))%(rs)==y)
  {
    return 8;
  }
  if((x+distance)%(rs)==(rs) || rs-1-(x+distance)%(rs)==(y))
  {
    return 2;
  }

  //trying to vertically or diagonally align to goal
  if((cs+(y-distance))%(cs)==0 || (cs+(y-distance))%(cs)==rs-1-x)
  {
    return 4;
  }
  if((y+distance)%(cs)==0 || (y+distance)%(cs)==rs-1-x)
  {
    return 6;
  }

  //giving a casual direction
  do
  {
    b=rand()%9+1;
  }while(b==5);
  return b;
}
