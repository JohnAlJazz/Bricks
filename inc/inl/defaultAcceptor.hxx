#include "defaultAcceptor.hpp"

inline bool DefaultAcceptor::DoAccept(std::unique_ptr<Client>*) {
    return true;
}