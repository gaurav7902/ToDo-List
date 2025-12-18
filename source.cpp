#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    int id;
    string title;
    bool completed;

    Task(int i, string t, bool c = false) {
        id = i;
        title = t;
        completed = c;
    }

    string serialize() const {
        return to_string(id) + "|" + title + "|" + to_string(completed);
    }

    static Task deserialize(const string &line) {
        int id, completed;
        string title;

        size_t p1 = line.find('|');
        size_t p2 = line.rfind('|');

        id = stoi(line.substr(0, p1));
        title = line.substr(p1 + 1, p2 - p1 - 1);
        completed = stoi(line.substr(p2 + 1));

        return Task(id, title, completed);
    }
};

class TodoList {
private:
    vector<Task> tasks;
    const string filename = "tasks.txt";

    void loadFromFile() {
        ifstream file(filename);
        if (!file) return;

        string line;
        while (getline(file, line)) {
            tasks.push_back(Task::deserialize(line));
        }
        file.close();
    }

    void saveToFile() {
        ofstream file(filename);
        for (const auto &task : tasks)
            file << task.serialize() << endl;
        file.close();
    }

public:
    TodoList() {
        loadFromFile();
    }

    void addTask() {
        cin.ignore();
        string title;
        cout << "Enter task description: ";
        getline(cin, title);

        int id = tasks.empty() ? 1 : tasks.back().id + 1;
        tasks.emplace_back(id, title);
        saveToFile();

        cout << "Task added successfully.\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks found.\n";
            return;
        }

        for (const auto &t : tasks) {
            cout << t.id << ". "
                 << (t.completed ? "[✓] " : "[ ] ")
                 << t.title << endl;
        }
    }

    void markCompleted() {
        int id;
        cout << "Enter task ID to mark completed: ";
        cin >> id;

        for (auto &t : tasks) {
            if (t.id == id) {
                t.completed = true;
                saveToFile();
                cout << "Task marked as completed.\n";
                return;
            }
        }
        cout << "Task not found.\n";
    }

    void deleteTask() {
        int id;
        cout << "Enter task ID to delete: ";
        cin >> id;

        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->id == id) {
                tasks.erase(it);
                saveToFile();
                cout << "Task deleted.\n";
                return;
            }
        }
        cout << "Task not found.\n";
    }
};

void intro()
{
	cout<<"\n| To-Do List";
	cout<<"\n\nMADE BY : Gaurav Patidar";
	cout<<"\n\nPress ENTER to continue...";
    cin.get();
}

int main() {
    TodoList todo;
    int choice;
    intro();
    while (true) {
        cout << "\n--- TO-DO LIST ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            todo.addTask();
            break;
        case 2:
            todo.viewTasks();
            break;
        case 3:
            todo.markCompleted();
            break;
        case 4:
            todo.deleteTask();
            break;
        case 5:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
