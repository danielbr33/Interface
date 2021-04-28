#ifndef SWITCH_H_
#define SWITCH_H_


#include "InterfaceInput.h"
#include "MenuItem.h"

class Switch : public MenuItem {
   public:
    Switch(std::string name);
    void setInputEvent(InterfaceInput::Button event);

    void setValue(uint8_t value);

    void display();

    uint8_t getValue(); 

    void prepareJsonObject(JsonObject jsonObject);

    protected:
    uint8_t value = 0;
};

#endif
