#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Process
{
  int pid;
  int bt;
  int priority;
};
bool compare(Process a, Process b)
{
  return a.priority < b.priority;
}
void findWaitingTime(Process proc[], int n, int wt[])
{
  wt[0] = 0;
  for (int i = 1; i < n; i++)
  {
    wt[i] = wt[i - 1] + proc[i - 1].bt;
  }
}
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
  for (int i = 0; i < n; i++)
  {
    tat[i] = proc[i].bt + wt[i];
  }
}
void findAverageTime(Process proc[], int n)
{
  int wt[n], tat[n], total_wt = 0, total_tat = 0;
  findWaitingTime(proc, n, wt);
  findTurnAroundTime(proc, n, wt, tat);
  for (int i = 0; i < n; i++)
  {
    total_tat += tat[i];
    total_wt += wt[i];
  }
  cout << "Average waiting time = "
       << (float)total_wt / (float)n;
  cout << "\nAverage turn around time = "
       << (float)total_tat / (float)n;
}
int main()
{
  Process proc[] = {{1, 10, 5}, {2, 2, 1}, {3, 18, 2}, {4, 4, 4}};
  int n = sizeof(proc) / sizeof(proc[0]);
  sort(proc, proc + n, compare);
  findAverageTime(proc, n);
  return 0;
}
