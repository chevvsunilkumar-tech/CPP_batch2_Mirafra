#include <iostream>
#include <map>
#include <string>

// Define the Task class without operator< overload
class Task {
//public:
    std::string name;
    int priority;

    Task(const std::string &name, int priority) : name(name), priority(priority) {}
};

// Custom comparator for Task objects
struct TaskComparator {
    bool operator()(const Task &t1, const Task &t2) const {
        // Higher priority tasks come first
        if (t1.priority != t2.priority)
            return t1.priority > t2.priority;
        // If priorities are equal, sort by name
        return t1.name < t2.name;
    }
};

int main() {
    // Create a map with the custom comparator
    std::map<Task, std::string, TaskComparator> taskMap;

    // Insert tasks into the map.
/*    taskMap[Task("Task1", 3)] = "Complete report";
    taskMap[Task("Task2", 5)] = "Fix bugs";
    taskMap[Task("Task3", 3)] = "Write tests";
    taskMap[Task("Task4", 4)] = "Update documentation";
*/
    taskMap[{"Task1", 3}] = "Complete report";
    taskMap[Task("Task2", 5)] = "Fix bugs";
    taskMap[Task("Task3", 3)] = "Write tests";
    taskMap[Task("Task4", 4)] = "Update documentation";
    std::cout << "Tasks ordered by custom comparator (highest priority first):\n";
    for (const auto &pair : taskMap) {
        std::cout << pair.first.name << " (Priority: " << pair.first.priority 
                  << ") -> " << pair.second << std::endl;
    }

    return 0;
}

