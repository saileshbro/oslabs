#include <iostream>
using namespace std;
void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[])
{
  wt[0] = 0;
  int service_time[n];
  service_time[0] = 0;
  for (int i = 1; i < n; i++)
  {
    service_time[i] = service_time[i - 1] + bt[i - 1];
    wt[i] = service_time[i] - at[i];
  }
}
void findTurnAroundTime(int processes[], int n, int bt[], int at[], int wt[], int tat[])
{
  for (int i = 0; i < n; i++)
  {
    tat[i] = bt[i] + wt[i];
  }
}
void findAvgTime(int processes[], int n, int bt[], int at[])
{
  int wt[n];
  int tat[n];
  findWaitingTime(processes, n, bt, at, wt);
  findTurnAroundTime(processes, n, bt, at, wt, tat);
  int total_wt = 0, total_tat = 0;
  for (int i = 0; i < n; i++)
  {
    total_tat += tat[i];
    total_wt += wt[i];
  }
  cout << "avg waiting time" << (float)total_wt / n << "\n";
  cout << "avg tat time" << (float)total_tat / n << "\n";
}

int main()
{
  int processes[] = {1, 2, 3};
  int n = 3;
  int brust_time[] = {5, 9, 6};
  int arrival_time[] = {0, 3, 6};
  findAvgTime(processes, n, brust_time, arrival_time);
  return 0;
}
