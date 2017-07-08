#ifndef IKEYEVENTLISTENER_H
#define IKEYEVENTLISTENER_H

#include <string>
namespace hswro {
namespace elektrozamek {

class IKeyEventListener
{
public:
    IKeyEventListener();
    virtual void onKeyEntered(const std::string& key) = 0;
};

}}

#endif // IKEYEVENTLISTENER_H
