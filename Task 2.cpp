//Muhammad Hasnain
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> tasks;
    int choice;

    do {
        cout << "\n==== TO-DO LIST MENU ====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // clear input buffer

        if (choice == 1) {
            string task;
            cout << "Enter a new task: ";
            getline(cin, task);
            tasks.push_back(task);
            cout << "Task added successfully!\n";
        }
        else if (choice == 2) {
            if (tasks.empty()) {
                cout << "No tasks available.\n";
            } else {
                cout << "\nYour Tasks:\n";
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
            }
        }
        else if (choice == 3) {
            int taskNumber;
            if (tasks.empty()) {
                cout << "No tasks to remove.\n";
            } else {
                cout << "Enter task number to remove: ";
                cin >> taskNumber;

                if (taskNumber > 0 && taskNumber <= tasks.size()) {
                    tasks.erase(tasks.begin() + taskNumber - 1);
                    cout << "Task removed successfully!\n";
                } else {
                    cout << "Invalid task number.\n";
                }
            }
        }
        else if (choice == 4) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
