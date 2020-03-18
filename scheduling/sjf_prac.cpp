#include <iostream>
#include <bits/stdc++.h>

struct Process
{
  int pid;
  int bt;
};
bool compare(Process a, Process b)
{
  return a.bt < b.bt;
}
void findWaitingTime(Process proc[], int n, int wt[])
{
  wt[0] = 0;
  for (int i = 1; i < n; i++)
  {
    wt[i] = wt[i - 1] + proc[i - 1].bt;
  }
}
void findTurnArondTime(Process proc[], int n, int wt[], int tat[])
{
  for (int i = 0; i < n; i++)
  {
    tat[i] = proc[i].bt + wt[i];
  }
}
void findAverageTime(Process process[], int n)
{
  int wt[n], tat[n], total_wt = 0,
                     total_tat = 0;
  findWaitingTime(process, n, wt);
  findTurnArondTime(process, n, wt, tat);
  for (int i = 0; i < n; i++)
  {
    total_wt += wt[i];
    total_tat += tat[i];
  }
  std::cout << std::endl
            << (float)total_wt / n << std::endl;
  std::cout << (float)total_tat / n << std::endl;
}
int main()
{
  int n = 4;
  Process proc[n] = {{1, 4}, {2, 7}, {3, 1}, {4, 2}};
  std::sort(proc, proc + n, compare);
  for (int i = 0; i < n; i++)
  {
    std::cout << proc[i].bt << " ";
  }
  findAverageTime(proc, n);
  return 0;
}
