#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if (argc != 2){
     fprintf(2, "usage: sleep time\n");
     exit(-1);
  }	  
  char* num = argv[1];
  write(1, num, strlen(num));
  sleep(atoi(num));

  exit(0);
}
