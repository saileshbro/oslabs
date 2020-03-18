#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main()
{
  int n;
  cout << "Enter the number of child process to be created" << endl;
  cin >> n;
  cout << "Parent PID " << getpid() << endl;
  for (int i = 0; i < n; i++)
  {
    if (fork() == 0)
    {
      cout << "The PID of the child is " << getpid() << " and PID of parent is " << getppid() << endl;
      exit(0);
    }
  }
}
