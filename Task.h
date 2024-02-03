/* Task manager header file.

This is a pet project, it is done non-professionally
and has many flaws. */

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <ostream>
#include <cstdio>
#include <cstring>
#define TXT ".txt"

class Task
{
public:
    Task() = default;
    Task(const std::string&, std::string&, const std::time_t& adding_task_time = std::time(nullptr));
    void add_task(const std::string&, std::string&); //
    void delete_task(const std::string&); //
    void save_task_inFile(const std::string&); //
    void delete_saved_task(const std::string&); //
    void delete_all_tasks(); //
    void display_all_tasks(); //
    friend std::ostream& operator<<(std::ostream&, const Task&); //
private:
    int get_index_task(const std::string&); //
    bool isExists(const std::string&);
    std::string title;
    std::string description;
    std::time_t adding_task_time = std::time(nullptr);
    std::vector<Task> v_tasks;
};