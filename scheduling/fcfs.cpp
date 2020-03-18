// Input the processes along with their brust time(bt) and arrival time(at)
// find waiting time for all other processes for given i
// wt[i] = (bt[0]+bt[1]+....+bt[i-1])-at[i]
// find turn around time wt+bt

// c++ program for implementation of FCFS
// Different arrival times

// service time means addition of brust times of previous processes
#include <iostream>
using namespace std;
void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[])

{
  int service_time[n];
  service_time[0] = 0;
  wt[0] = 0;
  // calculate waiting time
  for (int i = 1; i < n; i++)
  {
    // add brust time of previous provesses
    service_time[i] = service_time[i - 1] + bt[i - 1];
    // fint waiting time of current process
    // sum -at[i]
    wt[i] = service_time[i] - at[i];
    /**
     * If waiting time for process is in negative that means it is already in the ready queue
     */
    if (wt[i] < 0)
    {
      wt[i] = 0;
    }
  }
}

// find turn around time
// tat[i] = bt[i]+wt[i]
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
  for (int i = 0; i < n; i++)
  {
    tat[i] = bt[i] + wt[i];
  }
}

// avg waiting time and avg turnaround time

void findAvgTime(int processes[], int n, int bt[], int at[])
{
  int wt[n], tat[n], total_wt = 0, total_tat = 0;
  findWaitingTime(processes, n, bt, at, wt);
  findTurnAroundTime(processes, n, bt, wt, tat);
  cout << "PROCESSES\tBRUST TIME\tARRIVAL TIME\tWAITING TIME\tTURN AROUND TIME\t COMPLETION TIME" << endl;
  for (int i = 0; i < n; i++)
  {
    total_tat += tat[i];
    total_wt += wt[i];
    int completion = tat[i] + at[i];
    cout << i + 1 << '\t' << bt[i] << '\t' << at[i] << '\t' << wt[i] << '\t' << tat[i] << '\t' << completion << endl;
  }
  cout << "Average turn around time " << (float)total_tat / (float)n << endl;
  cout << "Average waiting time " << (float)total_wt / (float)n << endl;
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
