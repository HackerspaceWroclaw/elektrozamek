#ifndef DOORLOCKCONTROLLER_H
#define DOORLOCKCONTROLLER_H

#include "SerialLogger.h"
#include "AccessController.h"

namespace hswro { namespace elektrozamek {

class DoorLockController
{
public:
    explicit DoorLockController(AbstractLogger& logger);
    void run();

private:
    AbstractLogger &logger;
    DoorLatch doorLatch;
    AccessController accessController;
};

}}
#endif // DOORLOCKCONTROLLER_H
