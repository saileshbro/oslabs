#include <iostream>
using namespace std;
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
  wt[0] = 0;
  for (int i = 1; i < n; i++)
  {
    wt[i] = wt[i - 1] + bt[i - 1];
  }
}
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
  for (int i = 0; i < n; i++)
  {
    tat[i] = wt[i] + bt[i];
  }
}
void findAvgTime(int processes[], int n, int bt[])
{
  int total_tat = 0, total_wt = 0;
  int wt[n], tat[n];
  findWaitingTime(processes, n, bt, wt);
  findTurnAroundTime(processes, n, bt, wt, tat);
  for (int i = 0; i < n; i++)
  {
    total_tat += tat[i];
    total_wt += wt[i];
  }
  cout << "avg waiting time " << (float)total_wt / n << endl;
  cout << "avg turn around time " << (float)total_tat / n << endl;
}
int main()
{
  int processes[] = {1, 2, 3};
  int bt[] = {10, 5, 8};
  findAvgTime(processes, 3, bt);
  return 0;
}
