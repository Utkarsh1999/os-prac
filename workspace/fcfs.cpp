#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int numProcess=0;
    int i=0;
    cout<<"enter the no. of processes\n";
    cin>>numProcess;
    double pBurst[numProcess];
    double Wtime[numProcess];
    double tat[numProcess];
    double totalWtime=0;
    double totalTAT=0;
    cout<<"Enter the burst time of Processes\n";
    for(i=0;i<numProcess;i++)
    {
        cin>>pBurst[i];
        if(i==0)
        {
            Wtime[i]=0.0;
        }
        else
        {
            Wtime[i]=pBurst[i-1]+Wtime[i-1];
        }
        tat[i]=Wtime[i]+pBurst[i];
        totalWtime+= Wtime[i];
        totalTAT+= tat[i];
    }
    cout<<"|| PROCESS NO. ||"<<" BURST TIME ||"<<" WAITING TIME ||"<<" TURN AROUND TIME ||"<<endl;
    for(i=0;i<numProcess;i++)
    {
        cout<<"\t"<<i<<"\t\t"<<pBurst[i]<<"\t\t"<<Wtime[i]<<"\t\t"<<tat[i]<<"\n";
    }

    double avgWtime= totalWtime/numProcess;
    double avgTAT= totalTAT/numProcess;
    cout<<"\nAVERAGE WAITING TIME:"<< avgWtime;
    cout<<"\nAVERAGE TURN AROUND TIME: "<<avgTAT<<"\n";
    return 0;
}