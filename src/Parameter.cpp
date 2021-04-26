#include "Parameter.h"

Parameter::Parameter(std::string name) : MenuItem(name) {
    type = MenuItem::PARAMTER;
}

void Parameter::setInputEvent(InterfaceInput::Button event) {
    switch (event) {
        case InterfaceInput::LEFT_BUTTON:
            decrementValue();
            break;
        case InterfaceInput::RIGHT_BUTTON:
            incrementValue();
            break;
        case InterfaceInput::ENTER_BUTTON:
            if (parentMenuItem != nullptr) {
                parentMenuItem->setAsActiveItem();
            }
            break;
        case InterfaceInput::OTHER_BUTTON:
            break;
    }
}

void Parameter::decrementValue(){
    if(value > minValue){
        value--;
    }
}

void Parameter::incrementValue(){
    if(value < maxValue){
        value++;
    }
}

void Parameter::setValue(PARAMETER_VALUE_TYPE value) {
    this->value = value;
}

void Parameter::setMinValue(PARAMETER_VALUE_TYPE minValue) {
    this->minValue = minValue;
}

void Parameter::setMaxValue(PARAMETER_VALUE_TYPE maxValue) {
    this->maxValue = maxValue;
}

void Parameter::setUnit(std::string unit) {
    this->unit = unit;
}

void Parameter::display() {
    #ifdef __linux__
    printw("%s\n", name.c_str());
    //printw("%d %s\n", value, name.c_str());
    printw("-   %d %s   +%s\n", value, unit.c_str(), " | editing");
#elif defined (_WIN32) || defined (_WIN64 )
    std::cout << name << std::endl << "   " << value << "   " << unit << "| editing" << std::endl;
#endif
}