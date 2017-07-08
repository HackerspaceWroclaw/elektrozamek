#ifndef ACCESSCONTROLLER_H
#define ACCESSCONTROLLER_H
#include "DoorLatch.h"
#include "IKeyEventListener.h"

namespace hswro {
namespace elektrozamek {

class AccessController: public IKeyEventListener
{
public:
    explicit AccessController(DoorLatch& doorLatch);
    virtual onKeyEntered(const std::string& key);

private:
    DoorLatch& doorLatch;
};

}}

#endif // ACCESSCONTROLLER_H
