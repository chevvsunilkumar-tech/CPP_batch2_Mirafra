#include <iostream>
#include <queue>
#include <vector>

struct Process {
    int id;
    int burstTime;
    int remainingTime;
};

int main() {
    std::vector<Process> processes = {
        {1, 5, 5},
        {2, 3, 3},
        {3, 1, 1}
    };

    int timeQuantum = 2;
    std::queue<int> readyQueue;

    // Push process indices into queue
    for (int i = 0; i < processes.size(); i++) {
        readyQueue.push(i);
    }

    int currentTime = 0;

    while (!readyQueue.empty()) 
    {
        int index = readyQueue.front();
        readyQueue.pop();

        Process &p = processes[index];

        std::cout << "Executing P" << p.id
                  << " at time " << currentTime;

        if (p.remainingTime > timeQuantum) {
            currentTime += timeQuantum;
            p.remainingTime -= timeQuantum;

            std::cout << " for " << timeQuantum << " units\n";

            readyQueue.push(index); // requeue
        } 
        else {
            currentTime += p.remainingTime;

            std::cout << " for " << p.remainingTime << " units (Finished)\n";

            p.remainingTime = 0;
        }
    }

    return 0;
}

