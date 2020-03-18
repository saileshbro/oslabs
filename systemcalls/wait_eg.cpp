#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
  int child_id;
  if (fork() == 0)
  {
    std::cout << "Hello from child process " << getpid() << std::endl;
    std::cout << "My parent process " << getppid() << std::endl;
    exit(0);
  }
  else
  {
    child_id = wait(NULL);
    std::cout << "parent" << getpid() << std::endl;
    std::cout << "child" << child_id << std::endl;
  }
  return 0;
}
