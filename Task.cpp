#include "Task.h"
#include <ctime>

Task::Task(const std::string& title, std::string& description, const std::time_t& adding_task_time) :
        title(title), description(description), adding_task_time(adding_task_time) {}

void Task::add_task(const std::string& title, std::string& description) {
    if (isExists(title)) {
        throw "This title is already in use";
    }

    Task task(title, description, std::time(nullptr));
    v_tasks.push_back(task);
}

bool Task::isExists(const std::string& title) {
    auto iter = v_tasks.begin();
    for(;iter != v_tasks.end();){
        if (title == iter->title){
            return true;
        }
        iter++;
    }
    return false;
}

void Task::delete_task(const std::string& title) { //delete task
    auto iter = v_tasks.begin();
    for(;iter != v_tasks.end();) {
        if (title == iter->title){
            iter = v_tasks.erase(iter);
        }
        else {
            iter++;
        }
    }
    if (isExists(title)) {
        throw "Could not delete task, name is incorrect";
    }
}

void Task::delete_all_tasks() { //clear vector tasks
    v_tasks.clear();
}

std::ostream& operator<<(std::ostream& stream,const Task& temp_task) { //overloaded output operator
    stream << "Title: " << temp_task.title << "\n";
    stream << "Description: " << temp_task.description << "\n";
    stream << "Date: " << std::ctime(&temp_task.adding_task_time) << "\n";
    return stream;
}

void Task::display_all_tasks(){ //displays all tasks
    for (auto& iter : v_tasks) {
        std::cout << iter;
    }
}

int Task::get_index_task(const std::string& title) { //returns task index by name
    if (!isExists(title)) {
        return -1;
    }
    int index = 0;
    for (; index < v_tasks.size(); index++) {
        if (v_tasks[index].title == title) {
            break;
        }
    }
    return index;
}

void Task::save_task_inFile(const std::string& title) { //input task in file
    if (!isExists(title)) {
        throw "There is no such task";
    }
    std::ofstream file(title + TXT);
    if (!file.is_open()) {
        throw "Error! Failed to save file in current directory";
        return;
    }

    file << v_tasks[get_index_task(title)];

    file.close();
}

void Task::delete_saved_task(const std::string& file_name) {

    std::string file_with_extension = file_name + TXT;
    const char* filename = file_with_extension.c_str();

    if (remove(filename) == 0) {
        std::cout << "operation completed, task deleted from saving";
    }
    else {
        throw "Could not delete the file, the path may be incorrect";
    }
}