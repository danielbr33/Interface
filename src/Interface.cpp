#include "Interface.h"

Interface::Interface() {
    mainMenu = InterfaceBuilder::loadInterFaceFromJsonFile(INTERFACE_FILE);
    if (mainMenu == nullptr) {
        mainMenu = InterfaceBuilder::loadDefaultInterFace();
    }

    // list_of_elements = new List();

    // list_of_elements->addParameter(new Parameter("U battery" , 7.4 , "V", 0 )) ;
    // list_of_elements->addParameter(new Parameter("Work time" , 2 , "h", 1)) ;
    // list_of_elements->addParameter(new Parameter("Distance" , 100 , "m", 1)) ;
    // list_of_elements->addParameter(new Parameter("En consumed" , 3 , "kWh", 0)) ;
    // list_of_elements->addParameter(new Parameter("Temperature" , 20 , "C" , 0)) ;

    // Parameter *pid = new Parameter("pid", 3, "P I D", 0);
    // pid->addToSubList(new Parameter("P" , 20 , "kp" , 1));
    // pid->addToSubList(new Parameter("I" , 20 , "ki" , 1));
    // pid->addToSubList(new Parameter("D" , 20 , "kd" , 1));
    // list_of_elements->addParameter(pid);
}

void Interface::setInputEvent(InterfaceInput::Button event) {
    mainMenu->getCurrentMenuItem()->setInputEvent(event);
}

MenuItem* Interface::getCurrentMenuItem() {
    return mainMenu->getCurrentMenuItem();
}

MenuItem* Interface::getMenuItemByName(std::string name) {
    for (MenuItem* item : mainMenu->subMenuItems) {
        if (item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}

Action* Interface::getActionByName(std::string name) {
    for (MenuItem* item : mainMenu->subMenuItems) {
        if ((item->getName() == name) && (item->getType() == MenuItem::ACTION)) {
            return (Action*)item;
        }
    }
    return nullptr;
}

void Interface::save(std::string filepath) {
    StaticJsonDocument<JSON_DOCUMENT_SIZE> doc;
    JsonArray array = doc.createNestedArray();
    for (MenuItem* item : mainMenu->subMenuItems) {
        JsonObject jsonObject = array.createNestedObject();
        jsonObject[MENU_ITEM_NAME_KEY] = item->getName();
    }
    std::ofstream ofs(filepath, std::ofstream::out);
    serializeJson(doc, ofs);
    ofs.close();
}
