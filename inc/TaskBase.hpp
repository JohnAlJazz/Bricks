#ifndef TASK_BASE_HPP
#define TASK_BASE_HPP

namespace threads {

class TasksBase {
public:
    virtual ~TasksBase() = default;
    virtual void Act() = 0;
};

} //threads

#endif //TASK_BASE_HPP