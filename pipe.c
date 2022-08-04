// #include<stdio.h>
// #include<unistd.h>

// int main() {
//    int pipefds[2];
//    int returnstatus;
//    char writemessages[2][20]={"Hi", "Hello"};
//    char readmessage[20];
//   // returnstatus = pipe(pipefds);
   
//    if (returnstatus == -1) {
//       printf("Unable to create pipe\n");
//       return 1;
//    }
   
//    printf("Writing to pipe - Message 1 is %s\n", writemessages[0]);
//    write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
//    read(pipefds[0], readmessage, sizeof(readmessage));
//    printf("Reading from pipe – Message 1 is %s\n", readmessage);
//    printf("Writing to pipe - Message 2 is %s\n", writemessages[0]);
//    write(pipefds[1], writemessages[1], sizeof(writemessages[0]));
//    read(pipefds[0], readmessage, sizeof(readmessage));
//    printf("Reading from pipe – Message 2 is %s\n", readmessage);
//    return 0;
// }

// A C program to demonstrate Zombie Process. 
// Child becomes Zombie as parent is sleeping
// when child process exits.
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    // Fork returns process id
    // in parent process
    pid_t child_pid = fork();
  
    // Parent process 
    if (child_pid > 0)
        sleep(50);
  
    // Child process
    else        
        exit(0);
  
    return 0;
}