#ifndef THREADS_ERRORS_HXX
#define THREADS_ERRORS_HXX

#include <exception>
#include <string>

namespace threads {

class ThreadsErrors : public std::exception {
public:

    ThreadsErrors(const char* a_what);   

    const char* what() const noexcept override;

private:

    const char* m_what;
};

#include "inl/ThreadsErrors.hxx"

} //threads

#endif //THREADS_ERRORS_HXX