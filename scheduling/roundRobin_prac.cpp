#include <iostream>
using namespace std;
struct Process
{
  int pid;
  int bt;
};
void findWaitingTime(Process proc[], int n, int wt[], int quantum)
{
  int rem_bt[n];
  for (int i = 0; i < n; i++)
    rem_bt[i] = proc[i].bt;
  int currentTime = 0;
  while (true)
  {
    bool done = true;
    for (int i = 0; i < n; i++)
    {
      if (rem_bt[i] > 0)
      {
        done = false;
        if (rem_bt[i] > quantum)
        {
          currentTime += quantum;
          rem_bt[i] -= quantum;
        }
        else
        {
          currentTime += rem_bt[i];
          wt[i] = currentTime - proc[i].bt;
          rem_bt[i] = 0;
        }
      }
    }
    if (done)
      break;
  }
}
int main(int argc, char const *argv[])
{
  Process proc[] = {{1, 10}, {2, 5}, {3, 8}};
  int n = 3;
  int quantum = 2;
  return 0;
}
