#include <iostream>
#include <queue>

struct Process {
    int id;
    int burstTime;
};

int main() {
    std::queue<Process> readyQueue;

    // Add processes
    readyQueue.push({1, 5});
    readyQueue.push({2, 3});
    readyQueue.push({3, 2});

    int currentTime = 0;

    while (!readyQueue.empty()) {
        Process p = readyQueue.front();
        readyQueue.pop();

        std::cout << "Executing Process P" << p.id
                  << " from time " << currentTime;

        currentTime += p.burstTime;

        std::cout << " to " << currentTime << "\n";
    }

    return 0;
}
