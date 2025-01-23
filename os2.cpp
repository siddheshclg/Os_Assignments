#include <bits/stdc++.h>
using namespace std;
class process{
    public:
        int processId;
        int arrivalTime;
        int burstTime;
        int completionTime;
        int turnAroundTime;
        int waitingTime;
        process(int processId,int arrivalTime,int burstTime){
            this->processId = processId;
            this->arrivalTime = arrivalTime;
            this->burstTime = burstTime;
        }
};
bool comp(process a,process b){
    if(a.arrivalTime > b.arrivalTime){
        return 0;
    }else if (a.arrivalTime < b.arrivalTime){
        return 1;
    }else{
        return a.processId < b.processId;
    }
}
int main(){
    // cout << "Enter the number of processes\n";
    int n;
    cin >> n;
    // cout << "Enter process-Id, arrival-time and burst-time for each process respectively:\n";
    vector<process> processes;
    for(int i = 0;i < n;i++){
        int x,y,z;
        cin >> x >> y >> z;
        process temp =  process(x,y,z);
        processes.push_back(temp);
    }
    sort(processes.begin(), processes.end(), comp);
    int curTime = 0;
    double totalTurnAroundTime = 0, totalWaitingTime = 0;
    for(auto i : processes){
        curTime = max(i.arrivalTime, curTime);
        curTime += i.burstTime;
        i.completionTime = curTime;
        i.turnAroundTime = i.completionTime - i.arrivalTime;
        i.waitingTime = i.turnAroundTime - i.burstTime;
        totalTurnAroundTime += i.turnAroundTime;
        totalWaitingTime += i.waitingTime;
    }
    double avgTurnAroundTime = (double)totalTurnAroundTime/n;
    double avgWaitingTime = (double) totalWaitingTime/n;
    cout << "Average Waiting Time is " << avgWaitingTime << "\n";
    cout << "Average Turn around time is " << avgTurnAroundTime << "\n";
}
