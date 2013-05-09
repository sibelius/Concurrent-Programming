/************************************************************************
 * Write an MPI "hello World!" program using the appropriate MPI calls.
 ************************************************************************/

/**************************
1.Include the header 
**************************/
#include	"mpi.h"
#include	<iostream>
using namespace std;

int main(int argc, char** argv)
{
  char message[20];
  MPI::Status status;
  int i,rank, size, tag=11;
  
  /**************************
   2.Initialize MPI 
  **************************/
  MPI::Init(argc, argv);

  /**************************
  3.Find out my rank in the global communicator MPI_COMM_WORLD
  **************************/
  rank = MPI::COMM_WORLD.Get_rank( );

  /**************************
  4.Find out the size of the global communicator MPI_COMM_WORLD
  **************************/
  size = MPI::COMM_WORLD.Get_size( );

  /**************************
  5.Check the rank, and 
  **************************/

  if(rank == 0) {
    /**************************
      a.if the process is the master, then send a "Hello,World!" 
        message, in characters, to each of the workers. 
    **************************/
    strcpy(message, "Hello,World!");
    for (i=1; i<size; i++) 
      MPI::COMM_WORLD.Send(message, 13, MPI::CHAR, i, tag);
  } 
  else {
    /**************************
      b.if the process is a worker, then receive the "Hello,World!" 
        message and print it out. 
    **************************/
    MPI::COMM_WORLD.Recv(message, 20, MPI::CHAR, 0, tag, status );
    cout <<"Process " << rank << " : " << message << endl;
  }

  /**************************
    6.Finalize MPI 
  **************************/
  MPI::Finalize();
}/* End Main */
