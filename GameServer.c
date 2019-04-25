/**
* @file GameServer.c
* @brief Server-side file of a Goose Game.
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/

/* libc include for the printf function */
#include <stdio.h>

/* libc include for strings functions */
#include <string.h>

/* libc include for the exit and malloc functions */
#include <stdlib.h>

/* libc include for sockets function */
#include <unistd.h>

/* libc include for sockets functions */
#include <sys/types.h>

/* libc include for sockets functions */
#include <sys/socket.h>

/* libc include for ip addresses proper convertion */
#include <netinet/in.h>

/* libc include for signal handling */
#include <signal.h>

/* declares the GameUtility library */
#include "GameUtility.h"

//the flag to indicate the answer and exit, exit N repeat Y
char c='Y';

//the flag to indicate the winner and exit, server 1 client -1 nobody 0
int win=0;

//server socket descriptor
int serverSocket;

//client socketDescriptor
int clientSocket;

/**
* @brief The handler for the server shutdown
*
* @param sign the signal to be handle
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
void closing_handler(int sign)
{
  if(close(clientSocket)==0)
  {
    printf("\n\nClient socket has been correctly closed\n\n");
  }
  if(close(serverSocket)==0)
  {
    printf("\n\nServer socket has been correctly closed\n\n");
  }
  exit(0);
}

/**
* @brief The handler for the client shutdown
*
* @param sign the signal to be handle
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
void setting_handler(int sign)
{
  c='N';
  win=1;
  printf("\n\nClient has closed connection\n\n");
}

/**
* @brief Sets the flag for exit with the error on ouput.
*
* @param message the string to show on standard output.
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
void closeWithError(char* message)
{
  perror(message);
  c='N';
  win=1;
}

int main(void)
{

    //constant for the maximun number of possible connection
    int const MAX_QUEUE = 2;

    //server port number
    int serverPort=1748;

    //struct to describe the server address
    struct sockaddr_in serverAddress;
    //address type is set to internet
    serverAddress.sin_family=AF_INET;
    //server accept any address
    serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
    //server port is set to the specified number
    serverAddress.sin_port=htons(serverPort);

    if((serverSocket=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP))<0)
    {
      perror("function socket() for socket creation failed");
      exit(1);
    }
    if(bind(serverSocket,(struct sockaddr *) &serverAddress, sizeof(serverAddress))<0)
    {
      perror("function bind() for socket binding failed");
      exit(1);
    }
    if(listen(serverSocket,MAX_QUEUE)<0)
    {
      perror("function listen() for listening new clients failed");
      exit(1);
    }

    //handling the server shutdown
    struct sigaction server_behaviour;
    server_behaviour.sa_handler=closing_handler;
    sigemptyset(&server_behaviour.sa_mask);
    server_behaviour.sa_flags=0;

    sigaction(SIGINT,&server_behaviour,NULL);

    //handling the client shutdown
    struct sigaction client_behaviour;
    client_behaviour.sa_handler=setting_handler;
    sigemptyset(&client_behaviour.sa_mask);
    client_behaviour.sa_flags=0;

    sigaction(SIGPIPE,&client_behaviour,NULL);

    while(1)
    {
      printf("\nServer listening\n");
      //struct to describe the clientAddress
      struct sockaddr_in clientAddress;
      unsigned int clientLen=sizeof(clientAddress);
      if((clientSocket=accept(serverSocket,(struct sockaddr *) &clientAddress, &clientLen))<0)
      {
        closeWithError("function accept() for accepting a new client failed");
      }
      else
      {
        printf("\nSuccesfully connected with a new Client\n");
      }

      //field coordinates, wx[0] is the number of raws and wx[1] of columns
      int* wx;

      //the number of raws of the field matrix
      int rs;

      //the number of colums of the field matrix
      int cs;

      //the number of cells of the field matrix
      int totc;

      //the results of the two dices
      int* ds;

      //the move done by the server or by the client
      int* move;

      //the positions of both players, server (0-1) and the client (2-3)
      int* pawns;

      //the pointer to the field to randomly fill with numbers
      int* field;

      //the pointer to the field to print
      char* stringField;

      //indicate the direction chosen by the server
      int path;

      //the content of the arriving cell of the field after a move
      int add;

      //the flag that indicates the field has been allocated
      int m=0;

      while(c=='Y')
      {

        wx=malloc(2*sizeof(int));
        ds=malloc(2*sizeof(int));
        move=malloc(3*sizeof(int));
        pawns=malloc(4*sizeof(int));

        printf("\n\nMatch began\n\n");

        //Game building with the user
        if(recv(clientSocket,wx,2*sizeof(int),0)<=0)
        {
          closeWithError("function recv() for receiving coordinates failed");
        }
        else
        {
          printf("\nNumber of raws: %d\nNumber of colums: %d\n", *(wx), *(wx+1));

          totc=(*(wx)**(wx+1));
          rs=(*(wx));
          cs=(*(wx+1));

          //setting intial positions
          *(pawns)=0;
          *(pawns+1)=cs-1;
          *(pawns+2)=0;
          *(pawns+3)=0;

          m=1;
          field=malloc(totc*sizeof(int));
          stringField=malloc((2*totc+rs)*sizeof(char));
          setField(field,totc,cs);
          stringField=printField(field,rs,cs);

          if(send(clientSocket,stringField,((2*totc+rs)*sizeof(char)),0)<0)
          {
            closeWithError("function send() for sending field failed");
          }
          else
          {
            printf("\nField has been sent to the client\n");
          }

          //setting the sent string with the field free
          free(stringField);

        }

        //setting the coordinates free
        free(wx);

        while(!win)
        {

          //rolling the dice for the client move
          *(ds)=dice();
          *(ds+1)=dice();

          //sending the dices results to client
          if(send(clientSocket,ds,(2*sizeof(int)),0)<0)
          {
            closeWithError("function send() for sending dices failed");
          }
          else
          {
            printf("\nDices have been sent to the client\n");
          }

          //receiving the direction chosen by the client
          if(recv(clientSocket,move+2,sizeof(int),0)<=0)
          {
            closeWithError("function recv() for receiving direction failed");
          }
          else
          {
            printf("\nMove has been received\n");
          }

          //updating the client position
          *(move)=*(pawns+2);
          *(move+1)=*(pawns+3);
          updatePosition(move,*(ds)+*(ds+1));

          //value of the new position for another move
          add=*(field+(*move)*cs+*(move+1));
          if(send(clientSocket,&add,sizeof(int),0)<0)
          {
            closeWithError("function send() for sending add failed");
          }
          while(add>0)
          {
            //receiving the direction chosen by the client
            if(recv(clientSocket,move+2,sizeof(int),0)<=0)
            {
              closeWithError("function recv() for receiving direction failed");
            }
            updatePosition(move,add);
            add=*(field+(*move)*cs+*(move+1));
            if(send(clientSocket,&add,sizeof(int),0)<0)
            {
              closeWithError("function send() for sending add failed");
            }
          }

          //saving the updated positions
          *(pawns+2)=*(move);
          *(pawns+3)=*(move+1);

          //roll the dice for the server move
          *(ds)=dice();
          *(ds+1)=dice();

          //updating the server position
          path=bestChoice(*(pawns),*(pawns+1),*(ds)+*(ds+1));
          *(move)=*(pawns);
          *(move+1)=*(pawns+1);
          *(move+2)=path;
          updatePosition(move,*(ds)+*(ds+1));

          //value of the new position for another move
          add=*(field+(*move)*cs+*(move+1));
          while(add>0)
          {
            path=bestChoice(*(move),*(move+1),add);
            *(move+2)=path;
            updatePosition(move,add);
            add=*(field+(*move)*cs+*(move+1));
          }

          //saving the updated positions
          *(pawns)=*(move);
          *(pawns+1)=*(move+1);

          win=winner(pawns);

          //preparing notice of the winner in order to send it to the client
          if(win>0)
          {
            *(pawns)=-1;
          }
          if(win<0)
          {
            *(pawns+2)=-1;
          }

          //sending the updated position
          if(send(clientSocket,pawns,(4*sizeof(int)),0)<0)
          {
            closeWithError("function send() for sending positions failed");
          }

        }

        //receiving the answer from the client
        if(recv(clientSocket,&c,sizeof(char),0)<=0)
        {
          closeWithError("function recv() for receiving answer failed");
        }

        //reinitiating the win flag
        win=0;

        //setting the field free only if it had been previously allocated
        if(m==1)
        {
          free(field);
          m=0;
        }

        //setting all pointers free
        free(ds);
        free(move);
        free(pawns);

        printf("\n\n-- Match ended --\n\n");

      }

      //reinitiate the answer flag
      c='Y';

      printf("\n\nClient disconnected\n\n");
      close(clientSocket);

    }
}
