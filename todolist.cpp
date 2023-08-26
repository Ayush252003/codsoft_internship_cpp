#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};


void addTask(vector<Task>& tasks, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added: " << description << endl;
}


void viewTasks(const vector<Task>& tasks) {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << "[" << i + 1 << "] ";
        if (tasks[i].completed) {
            cout << "[Done] ";
        } else {
            cout << "[Pending] ";
        }
        cout << tasks[i].description << endl;
    }
}


void markTaskCompleted(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks[taskIndex].completed = true;
        cout << "Task marked as completed: " << tasks[taskIndex].description << endl;
    } else {
        cout << "Invalid task number. No task marked as completed." << endl;
    }
}


void removeTask(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        cout << "Task removed: " << tasks[taskIndex].description << endl;
        tasks.erase(tasks.begin() + taskIndex);
    } else {
        cout << "Invalid task number. No task removed." << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore(); 
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int taskIndex;
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                markTaskCompleted(tasks, taskIndex - 1);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskIndex - 1);
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
