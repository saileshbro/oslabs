#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Process
{
  int pid;
  int bt;
  int priority;
};
bool compareBT(Process a, Process b)
{
  return a.bt < b.bt;
}
bool comparePriority(Process a, Process b)
{
  return a.priority < b.priority;
}
void findWaitingTime(Process proc[], int n, int wt[], bool isSJF)
{
  if (isSJF)
  {
    sort(proc, proc + n, compareBT);
  }
  else
  {
    sort(proc, proc + n, comparePriority);
  }
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      wt[i] = 0;
    }
    else
    {
      wt[i] = wt[i - 1] + proc[i - 1].bt;
    }
  }
}
void findTurnAroundTime(Process proc[], int n, int tat[], int wt[])
{
  for (int i = 0; i < n; i++)
  {
    tat[i] = wt[i] + proc[i].bt;
  }
}
void findAverageTime(Process proc[], int n, bool isSJF)
{
  int wt[n];
  int tat[n];
  findWaitingTime(proc, n, wt, isSJF);
  findTurnAroundTime(proc, n, tat, wt);
  float total_tat = 0, total_wt = 0;
  cout << "PID BT PRIORITY WT TAT" << endl;

  for (int i = 0; i < n; i++)
  {
    total_tat += tat[i];
    total_wt += wt[i];
    cout << proc[i].pid << '\t' << proc[i].bt << "\t" << proc[i].priority << "\t" << wt[i] << '\t' << tat[i] << endl;
  }
  cout << "Average waiting time " << total_wt / n << endl;
  cout << "Average tat time " << total_tat / n << endl;
}
int main(int argc, char const *argv[])
{
  Process proc[] = {{1, 10, 3}, {2, 1, 10}, {3, 6, 1}, {4, 1, 5}};
  int n = sizeof(proc) / sizeof(proc[0]);
  bool isSJF = false;
  cout << "PRIORITY" << endl;
  findAverageTime(proc, n, isSJF);
  cout << "\n\n\nSJF" << endl;
  findAverageTime(proc, n, !isSJF);
  return 0;
}
