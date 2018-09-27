// C++ program for implementation of RR scheduling
#include<iostream.h>
using namespace std;

int main()
{
    cout<<"enter number of processes: ";
    int numProcess = 0;
    cin>>numProcess;
    // process id's
    int processes[numProcess];
    int burst_time[numProcess];
    cout<<"enter burst time of processes : "<<endl;
    for(int i=0;i<numProcess;i++)
    {
        cout<<"p["<<i<<"] = ";
        cin>>burst_time[i];

    }

    //int n = sizeof processes / sizeof processes[0];

	// Burst time of all processes
	// = {10, 5, 8};

	// Time quantum
	int quantum = 2;



	int wt[numProcess], tat[numProcess], total_wt = 0, total_tat = 0;

	// Function to find waiting time of all processes
    // findWaitingTime(processes, n, bt, wt, quantum);

    //---------------------------------------------//

    	// Make a copy of burst times burst_time[] to store remaining
	// burst times.
	int rem_bt[numProcess];
	for (int i = 0 ; i < numProcess ; i++)
		{
		    rem_bt[i] = burst_time[i];
		}

	int t = 0; // Current time

	// Keep traversing processes in round robin manner
	// until all of them are not done.
	while (1)
	{
		bool done = true;

		// Traverse all processes one by one repeatedly
		for (int i = 0 ; i < numProcess; i++)
		{
			// If burst time of a process is greater than 0
			// then only need to process further
			if (rem_bt[i] > 0)
			{
				done = false; // There is a pending process

				if (rem_bt[i] > quantum)
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t += quantum;

					// Decrease the burst_time of current process
					// by quantum
					rem_bt[i] -= quantum;
				}

				// If burst time is smaller than or equal to
				// quantum. Last cycle for this process
				else
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t = t + rem_bt[i];

					// Waiting time is current time minus time
					// used by this process
					wt[i] = t - burst_time[i];

					// As the process gets fully executed
					// make its remaining burst time = 0
					rem_bt[i] = 0;
				}
			}
		}

		// If all processes are done
		if (done == true)
		break;

}

    //---------------------------------------------//

	// Function to find turn around time for all processes
	//findTurnAroundTime(processes, n, bt, wt, tat);
    //---------------------------------------------//

        	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < numProcess ; i++)
		tat[i] = burst_time[i] + wt[i];




    //---------------------------------------------//
	// Display processes along with all details
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";

	// Calculate total waiting time and total turn
	// around time
	for (int i=0; i<numProcess; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << burst_time[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)numProcess;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)numProcess;






	return 0;

}

