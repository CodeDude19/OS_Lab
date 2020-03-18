#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
class Process{
public: int id, at, bt, ct, tt, rt, wt;
};
bool compareProcess(Process a, Process b) {
    return (a.at < b.at);
}
bool compareId(Process a, Process b) {
    return (a.id < b.id);
}
void RoundRobin(Process P[], int tq, int n){
    int currTime = 0;
    int comp = 0;
    int remTime[n];
    queue<Process> q;

    // Remaining Time Init
    for (int i = 0; i < n; i++){
        remTime[i] = P[i].bt;
    }
    Process p;
    p.id = -1;
    bool check[n];

    // Check Init
    for (int i = 0; i < n; i++){
        check[i] = false;
        P[i].rt = -1;
    }

    //Main Logic
    while(comp != n){
        //Check First Arrival
        for (int i = 0; i < n; i++){
            if(currTime >= P[i].at && remTime[i] > 0 && !check[i]) {
                q.push(P[i]);                
                check[i] = true;
            }
        }
        // Base Case 
        if(q.empty()){
            currTime++;
            cout<< " --> Slack --> "<<currTime;
            continue;
        }     
        // If not yet added in queue   
        if(p.id != -1)
            q.push(p);

        p = q.front();
        q.pop();
        cout<< " --> P"<< p.id;
        int j;

        // Retrieve Actual Process Index
        for (int i = 0; i < n; i++){
            if(P[i].id == p.id){
                j = i;
            }
        }

        if(P[j].rt == -1)
            P[j].rt = currTime - P[j].at;

        if(remTime[j] > tq){            
            remTime[j] -= tq;
            currTime += tq;
        }else{
            currTime += remTime[j];
            remTime[j] -= remTime[j];
            P[j].ct = currTime;
            P[j].tt = P[j].ct - P[j].at;
            P[j].wt = P[j].tt - P[j].bt;            
            p.id = -1;
            comp++;
        }
        cout<<" --> "<<currTime;
    }
    cout<<endl;
}

int main(){
    int n,tq;
    cout<<"Enter Number Of Process: ";
    cin >> n;
    Process P[n];
    for (int i = 0; i < n; i++){
        cout<<"Enter AT and BT for P"<<i+1<<" : ";
        P[i].id = i+1;
        cin >> P[i].at >> P[i].bt;
    }
    cout<<"Enter Time Quantam: ";
    cin >> tq;
    cout<<endl;
    sort(P, P+n, compareProcess);
    cout<<"0 ";
    RoundRobin(P,tq,n);        
    sort(P, P+n, compareId);
    cout<<"ID\tAT\tBT\tCT\tTT\tWT\tRT"<<endl;
    for (int i = 0; i < n; i++){
        cout<<P[i].id<<"\t"<<P[i].at<<"\t"<<P[i].bt<<"\t"<<P[i].ct<<"\t"<<P[i].tt<<"\t"<<P[i].wt<<"\t"<<P[i].rt<<endl;
    }
    return 0;
}