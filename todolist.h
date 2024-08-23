#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <string>
#include <vector>
#include "date.h"

namespace todoList {
    enum class Priority {
        HIGH,
        MEDIUM,
        LOW
    };

    class TodoList {
    public:
        TodoList();
        TodoList(const TodoList& todoList);
        TodoList& operator=(const TodoList& todoList);
        

        void addTask(const std::string& task, const date::Date& date, const Priority& priority, bool isDone = false);
        void removeTask(const std::string& task);
        virtual void print() const;
        void updateDate(const std::string& task, const date::Date& date);
        virtual void completeTask(const std::string& task);
        
        


    private:
        struct Task {
            std::string task;
            date::Date date;
            Priority priority;
            bool isDone;
        };

        std::vector<Task> _tasks;
    };

    class recurringTodoList : public TodoList {
    public:
        recurringTodoList();
        recurringTodoList(const recurringTodoList& todoList);
        

        void addTask(const std::string& task, const date::Date& date, const Priority& priority, bool isDone = false, int frequency = 1);
        
        void updateFrequency(const std::string& task, int frequency);

        void completeTask(const std::string& task) override;

        void print() const override;

    private:
        struct Task {
            std::string task;
            date::Date date;
            Priority priority;
            bool isDone;
            int frequency;
        };

        std::vector<Task> _tasks;
};

}







#endif // TODOLIST_H