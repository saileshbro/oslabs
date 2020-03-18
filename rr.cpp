#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Process
{
  int pid;
  int bt;
  int at;
};
void waitingTime(Process proc[], int n, int wt[], int quantum)
{
  int rem_bt[n];
  for (int i = 0; i < n; i++)
  {
    rem_bt[i] = proc[i].bt;
  }
  int current_time = 0;
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
          current_time += quantum;
          rem_bt[i] -= quantum;
        }
        else
        {
          current_time += rem_bt[i];
          wt[i] = current_time - proc[i].bt;
          rem_bt[i] = 0;
        }
      }
    }
    if (done)
      break;
  }
}
void findAvgTime(Process proc[], int n)
{
}
int main(int argc, char const *argv[])
{
  Process proc[] = {{1, 10, 3}, {2, 1, 10}, {3, 6, 1}, {4, 1, 5}};
  int n = sizeof(proc) / sizeof(proc[0]);
  bool isSJF = false;
  cout << "PRIORITY" << endl;

  return 0;
}
