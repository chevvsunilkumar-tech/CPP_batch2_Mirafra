#include <iostream>
#include <queue>
#include <vector>
#include<deque>
using namespace std;
struct Process {
    int id;
    int burstTime;
    int remainingTime;

};


struct CompareTask
{

bool operator ()(const Process &obj1,const Process &obj2) const
{
return obj1.remainingTime>obj2.remainingTime;//reaminng_time less is first

//return obj1.remainingTime<obj2.remainingTime;//reaminng_time more   is first

}


};

int main() {
    std::vector<Process> processes = {
        {1, 5, 5},
        {2, 3, 3},
        {3, 1, 1}
    };
//std::  deque<Process>d={ {1, 5, 5}, {2, 3, 3},{3, 1, 1}};


    int timeQuantum = 2;
priority_queue<Process, vector<Process>,CompareTask> readyQueue(processes.begin(), processes.end());


/*    // Push process indices into queue
    for (int i = 0; i < processes.size(); i++) {
        readyQueue.push(processes[i]);
    }*/

    int currentTime = 0;

    while (!readyQueue.empty()) 
    {
        auto p = readyQueue.top();
        readyQueue.pop();

       

        std::cout << "Executing P" << p.id
                  << " at time " << currentTime;

        if (p.remainingTime > timeQuantum) {
            currentTime += timeQuantum;
            p.remainingTime -= timeQuantum;

            std::cout << " for " << timeQuantum << " units\n";

            readyQueue.push(p); // requeue
            timeQuantum=2;
        } 
        else {
            currentTime += p.remainingTime;
             timeQuantum+=(timeQuantum-p.remainingTime);//utilizing remaining clock

            std::cout << " for " << p.remainingTime << " units (Finished)\n";

            p.remainingTime = 0;
        }
    }

    return 0;
}

