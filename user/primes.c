#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int current_pid, status;	
  int p2c_fds[2];
  int c2p_fds[2];
  pipe(p2c_fds);
  pipe(c2p_fds);
  int pid = fork(); 
  for (int i = 2; i < 35; i++){
  		
  }	  
  exit(0);
}
