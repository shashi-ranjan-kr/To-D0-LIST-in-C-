#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to display the list of tasks
void displayTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty." << endl;
    } else {
        cout << "Your tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

// Function to add a task
void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter the task to add: ";
    cin.ignore(); // To clear the buffer
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
}

// Function to delete a task
void deleteTask(vector<string>& tasks) {
    int taskNumber;
    displayTasks(tasks);

    if (!tasks.empty()) {
        cout << "Enter the task number to delete: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        cout << "\nTo-Do List Menu" << endl;
        cout << "1. Display tasks" << endl;
        cout << "2. Add a task" << endl;
        cout << "3. Delete a task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
