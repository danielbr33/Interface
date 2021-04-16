#ifndef INTERFACE_BUILDER_H_
#define INTERFACE_BUILDER_H_

#include <fstream>
#include "MenuItemsList.h"
#include "Parameter.h"
#include "ArduinoJson-v6.17.3.h"

class InterfaceBuilder {
public:
    static MenuItemsList* loadInterFaceFromFile(std::string  filepath);
    static MenuItemsList* loadDefaultInterFace();
    static void loadMenuItemsListFromJsonArray(MenuItemsList* parent, JsonArray array);
};

#endif 