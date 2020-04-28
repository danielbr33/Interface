#include "List_element.h"


class List{
private:

    List_element *current_element;
    List_element *last_element ;
    List_element *first_element ;

    void addFirstElement(List_element *element);
    void addNextElement(List_element *element);

    uint16_t size = 0;
public :
    List() ;
    Parameter* get_Parameter(int index);
    void add_Parameter(Parameter *parameter) ;
    void print();
    uint16_t getSize() ;
};

