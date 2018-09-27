#include <iostream>
#include<iomanip>
#include<queue>
using namespace std;
int main()
{
    queue<int> sc;

    float tat = 0, total_tat = 0, tw=0, total_tw = 0;
    int n = 0,i,j, bt = 0;

    cout << "Enter number of processes : ";
    cin >> n;

    cout << "\nEnter process working time : \n";
    for (i = 0; i < n; i++){
        cout << "p[" << i+1 << "]:";
        cin >> bt;
        sc.push(bt);
    }

    cout << "\n process "<<setw(3)<<" burst time"<<setw(15)<<"waiting time"<<setw(19)<<"turnaround time";
    int pbt = 0;
    for (j = 0; j < n; j++)
    {
        bt = sc.front();
        tw = tw + pbt;
        tat = bt + tw;
        total_tw = total_tw + tw;
        total_tat = total_tat + tat;
  5      cout << "\n p[" << j +1 << "]" << setw(7) << bt << setw(17) << tw<< setw(20) << tat;
        pbt = bt;
        sc.pop();
    }
    cout << "\nAverage waiting time : " << total_tw / n << endl;
    cout << "Average turnaround time : " << total_tat / n << endl;

    return 0;
}