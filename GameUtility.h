/**
* @file GameUtility.h
* @brief Library with functions for setting up and playing the game.
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/

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
void setField(int* settingField,int n,int cl);

/**
* @brief Turns the game field into a string.
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
char* printField(int* setField,int rr,int cc);

/**
* @brief Rolls a dice.
*
* @return a integer 1-6 for large fields, 1-4 for small fields.
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
int dice();

/**
* @brief Does the player move.
*
* @param move pointer to the updating move, move points to intial raw coordinate
* move+1 points to intial column coordinate
* move+2 points to the direction to walk towards.
* @param quantity the number of cells to walk.
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
void updatePosition(int* move,int direction);

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
int winner(int* ps);

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
int bestChoice(int x,int y,int distance);
