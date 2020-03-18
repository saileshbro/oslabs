#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
  int sz;
  int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0)
  {
    exit(1);
  }
  sz = write(fd, "hello sarayu", strlen("hello sarayu"));
  close(fd);
  return 0;
}
