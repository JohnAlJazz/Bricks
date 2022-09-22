#ifndef THREADSERRORS_HXX
#define THREADSERRORS_HXX

inline ThreadsErrors::ThreadsErrors(const char* a_what)
: m_what(a_what)
{}

inline const char* ThreadsErrors::what() const noexcept {
    return m_what;
}

#endif //THREADS_ERRORS_HXX