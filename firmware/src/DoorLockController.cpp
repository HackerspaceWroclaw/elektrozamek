#include "DoorLockController.h"

using namespace ::hswro::elektrozamek;

DoorLockController::DoorLockController():
    logger(),
    doorLatch(GpioPin(0), DoorLatch::ActiveState::Low),
    accessController(doorLatch)
{

}

void DoorLockController::run()
{
        logger.info("%s: running", __PRETTY_FUNCTION__);
}
