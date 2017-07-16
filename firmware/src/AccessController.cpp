#include "AccessController.h"

hswro::elektrozamek::AccessController::AccessController(DoorLatch &doorLatch):
    doorLatch(doorLatch)
{

}

hswro::elektrozamek::AccessController::onKeyEntered(const std::string &key)
{
        if(key == "dupa")
        {
            doorLatch.open();
            sslep(3);
            doorLatch.close();
        }
}
