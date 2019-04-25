/**
* @file GameClient.c
* @brief Client-side file of a Goose Game.
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

/* libc include for ip address convertion */
#include <arpa/inet.h>

/* libc include for sockets functions */
#include <sys/types.h>

/* libc include for sockets functions */
#include <sys/socket.h>

/* libc include for ip addresses proper convertion */
#include <netinet/in.h>

/* define a macro to empty the input buffer */
#define fflushscanf while ((getchar()) != '\n')

/**
* @brief Exit the program with an error and communicate it to the user.
*
* @param message the string to show on standard output.
*
* @author Luca Pietrogrande
* @version 1.0
* @since 1.0
*/
void DieWithError(char* message)
{
  perror(message);
  exit(1);
}

int main(void)
{

    //client socket descriptor
    int clientSocket;

    //server port number
    int serverPort=1748;

    //struct to describe the server address
    struct sockaddr_in serverAddress;
    //address type is set to internet
    serverAddress.sin_family=AF_INET;
    //client will connect to the loopback address (server on this machine)
    serverAddress.sin_addr.s_addr=inet_addr("127.0.0.1");
    //client will connect to the specified port
    serverAddress.sin_port=htons(serverPort);

    if((clientSocket=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP))<0)
    {
      DieWithError("function socket() for socket creation failed");
    }
    if(connect(clientSocket,(struct sockaddr *) &serverAddress, sizeof(serverAddress))<0)
    {
      DieWithError("function connect() for connection to server failed");
    }
    printf("\nSuccesfully connected to the Game Server\n");

    //game field building with the user

    //the field coordinates to send
    //xy[0] is the number of number of raws, xy[1] is the number of colums
    int* xy;

    //the lower bound for major fields
    int const SIZE_B=100;

    //the minimum size of dimensions for minor fiels
    int const MIN_D=4;

    //the minimum size of dimensions for major fields
    int const MIN_L=10;

    //the number of raws of the field matrix
    int rs;

    //the number of colums of the field matrix
    int cs;

    //the number of cells of the field matrix
    int totc;

    //the results of the two dices
    int* ds;

    //char pointer that contains the formatted field
    char* printedField;

    //the number of the decided direction for the move
    int choice;

    //pointer to the client and server positions(server 0-1 and client 2-3)
    int* pawns;

    //flag to indicate the end of the game
    int quit=0;

    //the client answer about another match
    char a='Y';

    //the content of the arriving cell of the field after a move
    int add=0;

    printf("\n\nWelcome to Matrix GooseGame\n\n");

    while(a=='Y')
    {

      xy=malloc(2*sizeof(int));
      ds=malloc(2*sizeof(int));
      pawns=malloc(4*sizeof(int));

      //game field building with the user
      do
      {
        printf("\nLet's build the game field \nMinimum dimensions value for minor fields: %d\nMinimum dimensions value for major fields: %d\nMajor fields from a total boxes of %d\nInsert the number of raws you want: ",MIN_D,MIN_L,SIZE_B);
        scanf("%d", xy);
        fflushscanf;
        printf("\nInsert the number of colums you want: ");
        scanf("%d", xy+1);
        fflushscanf;
      }while(*xy<MIN_D || *(xy+1)<MIN_D || (((*xy<MIN_L)||(*(xy+1)<MIN_L))&&(*xy**(xy+1)>=SIZE_B)));

      if(send(clientSocket,xy,2*sizeof(int),0)<0)
      {
        DieWithError("function send() for sending coordinates failed");
      }
      printf("\nCoordinates have been communicated to the server\nYou might wait the server to be free\n");

      totc=(*(xy)**(xy+1));
      rs=(*(xy));
      cs=(*(xy+1));

      //setting the coordinates free
      free(xy);

      printedField=malloc((2*totc+rs)*sizeof(char));

      //receiving the field string
      if(recv(clientSocket,printedField,(2*totc+rs)*sizeof(char),0)<=0)
      {
        DieWithError("function recv() for receiving the field failed");
      }

      //setting intial positions of both players
      *(pawns)=0;
      *(pawns+1)=cs-1;
      *(pawns+2)=0;
      *(pawns+3)=0;

      //printing positions on the field string
      *(printedField+(*(pawns+2))*(2*cs+1)+2*(*(pawns+3)))='P';
      *(printedField+(*(pawns))*(2*cs+1)+2*(*(pawns+1)))='C';
      printf("\nHere is the field\n%s\n",printedField);

      while(!quit)
      {
        //cleaning positions on the field string
        *(printedField+(*(pawns+2))*(2*cs+1)+2*(*(pawns+3)))=' ';
        *(printedField+(*(pawns))*(2*cs+1)+2*(*(pawns+1)))=' ';

        //receiving the dices results from server
        if(recv(clientSocket,ds,2*sizeof(int),0)<=0)
        {
          DieWithError("function recv() for receiving the dices failed");
        }
        printf("\nRoll of the dice gave %d + %d = %d\n",*(ds),*(ds+1),*(ds)+*(ds+1));
        do
        {
          printf("\nChoose your move typing a number :\n7|8|9\n4| |6\n1|2|3\n");
          scanf("%d",&choice);
          if(choice<0||choice>9)
          {
            printf("\nYou have to type an integer number beetwen 1-9\n");
          }
        }while(choice<0||choice>9);
        fflushscanf;

        //sending path choice to the server
        if(send(clientSocket,&choice,sizeof(int),0)<0)
        {
          DieWithError("function send() for sending choice failed");
        }

        //receiving the value of the new cell after the move
        if(recv(clientSocket,&add,sizeof(int),0)<=0)
        {
          DieWithError("function recv() for receiving the dices failed");
        }

        while(add!=0)
        {
          printf("\nYou can walk for %d more steps\n",add);
          printf("\nChoose your move typing a number :\n7|8|9\n4| |6\n1|2|3\n");
          scanf("%d",&choice);
          fflushscanf;
          //sending path choice to the server
          if(send(clientSocket,&choice,sizeof(int),0)<0)
          {
            DieWithError("function send() for sending choice failed");
          }
          if(recv(clientSocket,&add,sizeof(int),0)<0)
          {
            DieWithError("function recv() for receiving the dices failed");
          }
        }

        //receiving the updated positions from server
        if(recv(clientSocket,pawns,4*sizeof(int),0)<=0)
        {
          DieWithError("function recv() for receiving the positions failed");
        }

        if(*(pawns)==-1)
        {
          *(pawns)=rs-1;
          quit=1;
        }
        if(*(pawns+2)==-1)
        {
          *(pawns+2)=rs-1;
          quit=2;
        }

        //printing positions on the field string
        if((*pawns)!=*(pawns+2)||(*pawns+1)!=(*pawns+3))
        {
          *(printedField+(*(pawns+2))*(2*cs+1)+2*(*(pawns+3)))='P';
          *(printedField+(*(pawns))*(2*cs+1)+2*(*(pawns+1)))='C';
        }
        else
        {
          *(printedField+(*(pawns+2))*(2*cs+1)+2*(*(pawns+3)))='B';
        }
        printf("\n%s\n",printedField);

      }

      if(quit==1)
      {
        printf("\nYou lost, let's play another match");
      }
      if(quit==2)
      {
        printf("\nYou won, nice play");
      }

      do
      {
        printf("\nDo you want to play another match? (Y/N) : ");
        scanf("%c",&a);
        fflushscanf;
      }while(!(a=='Y'||a=='N'));

      //sending the client answer to the server
      if(send(clientSocket,&a,sizeof(char),0)<0)
      {
        DieWithError("function send() for sending client answer failed");
      }

      //reinitating the quit flag
      quit=0;

      //setting all pointers free
      free(printedField);
      free(ds);
      free(pawns);

    }

    //setting socket to closed
    close(clientSocket);
}
