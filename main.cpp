#include "Task.h"

enum MenuChoice {
    Add = 1,
    Remove,
    Save,
    RemoveSaved,
    DisplayAll,
    RemoveFull,
    Quit,
};

int main() {
    Task task_manager;
    std::string choice;
    while (true) {
        std::cout << "Choose one:\n";
        std::cout << "1. Add task\n";
        std::cout << "2. Remove task\n";
        std::cout << "3. Save task\n";
        std::cout << "4. Remove saved task\n";
        std::cout << "5. Display all tasks\n";
        std::cout << "6. Remove tasks\n";
        std::cout << "7. Quit\n";
        getline(std::cin,choice);

        switch (std::stoi(choice)) {
            case Add: {
                std::cout << "Enter task details (name description): ";
                std::string title_task;
                std::string description;
                getline(std::cin,title_task);
                getline(std::cin,description);

                try {
                    task_manager.add_task(title_task, description);
                    std::cout << "Task added successfully!\n";
                } catch (const char* er) {
                    std::cout << er << "\n";
                }
                break;
            }
            case Remove: {
                std::string title_task;
                std::cout << "Enter title details for remove task: ";
                getline(std::cin,title_task);

                try {
                    task_manager.delete_task(title_task);
                    std::cout << "Task removed successfully!\n";
                } catch (const char* er) {
                    std::cout << er << "\n";
                }
                break;
            }
            case Save: {
                std::string title_task;
                std::cout << "Enter title details for save task: ";
                getline(std::cin,title_task);

                try {
                    task_manager.save_task_inFile(title_task);
                    std::cout << "Task saved successfully!\n";
                } catch (const char* er) {
                    std::cout << er << "\n";
                }
                break;
            }
            case RemoveSaved: {
                std::string title_task;
                std::cout << "Enter title details for remove saved task: ";
                getline(std::cin,title_task);

                try {
                    task_manager.delete_saved_task(title_task);
                    std::cout << "Task remove successfully!\n";
                } catch (const char* er) {
                    std::cout << er << "\n";
                }
                break;
            }
            case RemoveFull: {
                std::cout << "Removing...\n";
                task_manager.delete_all_tasks();
                break;
            }
            case DisplayAll: {
                std::cout << "Displaying...\n";
                task_manager.display_all_tasks();
                break;
            }
            case Quit:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
