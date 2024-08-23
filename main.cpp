#include "date.h"
#include "todolist.h"

int main(int argc, char const *argv[]) {

    std::cout << "Date" << std::endl;

    date::Date date1(2020, 12, 31);
    date1.print();

    date1.nextDay();
    date1.print();

    date1.previousDay();
    date1.print();

    date1.setYear(2021);
    date1.updateMonth(1);
    date1.updateDay(1);
    date1.print();

    std::cout << "Todo List" << std::endl;

    todoList::TodoList todoList;
    todoList.addTask("Task1", date1, todoList::Priority::HIGH);
    todoList.addTask("Task2", date1, todoList::Priority::MEDIUM);
    todoList.print();
    todoList.updateDate("Task1", date::Date(2021, 1, 2));
    todoList.print();
    todoList.removeTask("Task1");
    todoList.print();

    std::cout << "Recurring Todo List" << std::endl;

    todoList::recurringTodoList recurringTodoList;
    recurringTodoList.addTask("Task1", date1, todoList::Priority::HIGH, 2);
    recurringTodoList.addTask("Task2", date1, todoList::Priority::MEDIUM, 3);
    recurringTodoList.print();

    recurringTodoList.updateFrequency("Task1", 3);
    recurringTodoList.print();

    recurringTodoList.completeTask("Task1");
    recurringTodoList.print();



    return 0;
}