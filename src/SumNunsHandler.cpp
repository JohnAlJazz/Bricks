#include "SumNunsHandler.hpp"

#include <vector>

namespace net {

void SumNumsHandler::HandleClientIncoming(std::unique_ptr<Client> a_client) {

    std::vector<int> v = a_client->Receive<std::vector<int>>();
    a_client->Send(v);
}






} //net