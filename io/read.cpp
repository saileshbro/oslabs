#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
int main()
{
  // open if not found, create
  int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  char *buffer = (char *)calloc(100, sizeof(char));
  cout << fd << endl;

  if (fd < 0)
  {
    perror("r1");
    exit(1);
  }
  int size = read(fd, buffer, 10);
  printf("called read(% d, c, 10).  returned that"
         " %d bytes  were read.\n",
         fd, size);
  cout << errno << endl;
  buffer[size] = '\0';
  cout << buffer << endl;
  return 0;
}
