#ifndef TASK_BASE_HPP
#define TASK_BASE_HPP

namespace threads {

class TasksBase {
public:
    virtual ~TasksBase() = default;

    virtual void Act() = 0;

protected:
    TasksBase& operator=(const TasksBase&) = default;
    TasksBase(const TasksBase&) = default;
    TasksBase() = default;
};

} //threads

#endif //TASK_BASE_HPP