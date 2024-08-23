#include "todolist.h"

namespace todoList {
    TodoList::TodoList() {}

    TodoList::TodoList(const TodoList& todoList) : _tasks(todoList._tasks) {}

    TodoList& TodoList::operator=(const TodoList& todoList) {
        if (this != &todoList){
            _tasks = todoList._tasks;
        }
        return *this;
    }

    void TodoList::addTask(const std::string& task, const date::Date& date, const Priority& priority, bool isDone) {
        Task newTask;
        newTask.task = task;
        newTask.date = date;
        newTask.priority = priority;
        newTask.isDone = isDone;
        _tasks.push_back(newTask);
    }

    void TodoList::removeTask(const std::string& task) {
        for (auto it = _tasks.begin(); it != _tasks.end(); ++it){
            if (it->task == task){
                _tasks.erase(it);
                break;
            }
        }
    }

    void TodoList::print() const {
        for (const auto& task : _tasks){
            std::cout << "Priority: ";

            if (task.priority == Priority::HIGH){
                std::cout << "HIGH ";
            }
            else if (task.priority == Priority::MEDIUM){
                std::cout << "MEDIUM ";
            }
            else {
                std::cout << "LOW ";
            }

            if (task.isDone){
                std::cout << "DONE ";
            }
            else {
                std::cout << "NOT DONE ";
            }


            std::cout << task.task << " ";
            task.date.print();
        }
    }

    void TodoList::updateDate(const std::string& task, const date::Date& date) {
        for (auto& t : _tasks){
            if (t.task == task){
                t.date = date;
                break;
            }
        }
    }

    void TodoList::completeTask(const std::string& task) {
        for (auto& t : _tasks){
            if (t.task == task){
                t.isDone = true;
                break;
            }
        }
    }



    recurringTodoList::recurringTodoList() {}
    recurringTodoList::recurringTodoList(const recurringTodoList& todoList) : TodoList(todoList) {}

    void recurringTodoList::addTask(const std::string& task, const date::Date& date, const Priority& priority, bool isDone , int frequency) {
        Task newTask;
        newTask.task = task;
        newTask.date = date;
        newTask.priority = priority;
        newTask.isDone = isDone;
        newTask.frequency = frequency;
        _tasks.push_back(newTask);
    }

    void recurringTodoList::updateFrequency(const std::string& task, int frequency) {
        for (auto& t : _tasks){
            if (t.task == task){
                t.frequency = frequency;
                break;
            }
        }
    }

    void recurringTodoList::completeTask(const std::string& task) {
        for (auto& t : _tasks){
            if (t.task == task){
                t.isDone = true;

                if(t.frequency > 1){
                    int day = t.date.getDay();
                    t.date.updateDay(day + t.frequency);
                }
                break;
            }
        }
    }

    void recurringTodoList::print() const {
        for (const auto& task : _tasks){
            std::cout << "Priority: ";

            if (task.priority == Priority::HIGH){
                std::cout << "HIGH ";
            }
            else if (task.priority == Priority::MEDIUM){
                std::cout << "MEDIUM ";
            }
            else {
                std::cout << "LOW ";
            }

            if (task.isDone){
                std::cout << "DONE ";
            }
            else {
                std::cout << "NOT DONE ";
            }

            std::cout << task.task << " ";
            task.date.print();
            std::cout << "Frequency: " << task.frequency << std::endl;
        }
    }



}