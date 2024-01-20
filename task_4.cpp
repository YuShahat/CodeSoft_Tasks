#include <iostream>
#include <vector>
#include <iomanip>

struct Task {
    std::string description;
    bool completed;
};

// Function to add a task to the list
void addTask(std::vector<Task>& tasks, const std::string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    std::cout << "Task added: " << description << std::endl;
}

// Function to view tasks with their status
void viewTasks(const std::vector<Task>& tasks) {
    std::cout << "Task List:\n";
    std::cout << std::setw(4) << "ID" << std::setw(20) << "Description" << std::setw(12) << "Status\n";
    
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << std::setw(4) << i + 1 << std::setw(20) << tasks[i].description << std::setw(12);
        if (tasks[i].completed) {
            std::cout << "Completed\n";
        } else {
            std::cout << "Pending\n";
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(std::vector<Task>& tasks, size_t taskId) {
    if (taskId > 0 && taskId <= tasks.size()) {
        tasks[taskId - 1].completed = true;
        std::cout << "Task marked as completed: " << tasks[taskId - 1].description << std::endl;
    } else {
        std::cout << "Invalid task ID.\n";
    }
}

// Function to remove a task from the list
void removeTask(std::vector<Task>& tasks, size_t taskId) {
    if (taskId > 0 && taskId <= tasks.size()) {
        std::cout << "Task removed: " << tasks[taskId - 1].description << std::endl;
        tasks.erase(tasks.begin() + taskId - 1);
    } else {
        std::cout << "Invalid task ID.\n";
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                size_t taskId;
                std::cout << "Enter task ID to mark as completed: ";
                std::cin >> taskId;
                markTaskCompleted(tasks, taskId);
                break;
            }
            case 4: {
                size_t taskId;
                std::cout << "Enter task ID to remove: ";
                std::cin >> taskId;
                removeTask(tasks, taskId);
                break;
            }
            case 5:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}