#ifndef DOORLOCKCONTROLLER_H
#define DOORLOCKCONTROLLER_H

#include "Logger.h"
#include "AccessController.h"

namespace hswro { namespace elektrozamek {

class DoorLockController
{
public:
    DoorLockController();
    void run();

private:
    Logger logger;
    DoorLatch doorLatch;
    AccessController accessController;
};

}}
#endif // DOORLOCKCONTROLLER_H
