#ifndef ISENDER_HXX
#define ISENDER_HXX

inline void SendToScreen::Send(std::string& a_message) {
    std::cout << a_message << '\n';
}

inline void SendToFile::Send(std::string& a_message) {
    std::cout << "to file check" <<'\n';
}

#endif //ISENDER_HXX