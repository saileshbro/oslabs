#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Process
{
  int pid;
  int bt;
  int proirity;
};
bool compateBT(Process a, Process b)
{
  return a.bt < b.bt;
}
bool compatePriority(Process a, Process b)
{
  return a.proirity < b.proirity;
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
    tat[i] = wt[i] + proc[i].bt;
  }
}
void findAverageTime(Process proc[], int n)
{
  int wt[n];
  int tat[n];
  int total_wt = 0, total_tat = 0;
  findWaitingTime(proc, n, wt);
  findTurnAroundTime(proc, n, wt, tat);
  cout << "PID\tBT\tWT\tTAT" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << proc[i].pid << '\t' << proc[i].bt << '\t' << wt[i] << '\t' << tat[i] << endl;
    total_tat += tat[i];
    total_wt += wt[i];
  }
  cout << "Average Waiting time" << (float)total_wt / n << endl;
  cout << "Average Turn around time" << (float)total_tat / n << endl;
}

int main()
{
  Process proc[] = {{1, 4, 5}, {2, 11, 1}, {3, 2, 3}};
  int n = sizeof(proc) / sizeof(proc[0]);
  // SJF
  sort(proc, proc + n, compateBT);
  findAverageTime(proc, n);
  // priority
  sort(proc, proc + n, compatePriority);
  findAverageTime(proc, n);
  return 0;
}
