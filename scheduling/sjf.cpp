#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Process
{
  int pid;
  int bt;
};
bool comparision(Process a, Process b)
{
  return (a.bt < b.bt);
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
  Process proc[] = {{1, 4}, {2, 7}, {3, 1}, {4, 2}};
  int n = sizeof(proc) / sizeof(proc[0]);
  for (int i = 0; i < n; i++)
  {
    cout << proc[i].bt << endl;
  }
  sort(proc, proc + n, comparision);
  for (int i = 0; i < n; i++)
  {
    cout << proc[i].bt << endl;
  }
  findAverageTime(proc, n);
}
