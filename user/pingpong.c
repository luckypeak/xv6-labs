#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int current_pid, status;	
  //int pid = fork();
  int p2c_fds[2];
  int c2p_fds[2];
  pipe(p2c_fds);
  pipe(c2p_fds);
  int pid = fork(); 
  char *buf = malloc(5);  
  if (pid == 0 ){
     close(c2p_fds[0]);     
     write(c2p_fds[1], "pong", 4);
     close(c2p_fds[1]);     
     current_pid = getpid();
     
     close(p2c_fds[1]);
     read(p2c_fds[0], buf, 4);
     close(p2c_fds[0]);     
     fprintf(1, "%d: recived %s \n", current_pid, buf);
  }else{
    current_pid =getpid();
    close(p2c_fds[0]);
    write(p2c_fds[1], "ping", 4);
    close(p2c_fds[1]);    
    
    wait(&status);
    
    close(c2p_fds[1]);
    read(c2p_fds[0], buf, 4);
    close(c2p_fds[0]);
    fprintf(1,"%d: recived %s \n", current_pid, buf); 
  }	  

  exit(0);
}
