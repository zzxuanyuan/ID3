#include <iostream>

#include "Instance.h"

using namespace std;
Instance::Instance(int type, float value) {
    this->type = type;
    switch (type) {
        case 1:
        case 3:
            numValue = value;
            break;
        case 2:
        case 4:
            domainIndex = (int)value;
            break;
        default:
            cout << "Invalid instance type given: " << type <<
                " for " << value << endl;
    }
}

Instance::Instance(int type, string id) {
    this->type = type;
    switch (type) {
        case 0:
            this->id = id;
            break;
        default:
            cout << "Invalid id instance type given: " << type <<
                " for " << id << endl;
    }
}

bool Instance::isNumeric() {
    return type == 1 || type == 3;
}

float Instance::getNumValue() {
    if(type != 1 || type == 3) {
        cout << "Error: Instance accessed is not numeric" << endl;
    }
    return numValue;
}

int Instance::getDomainIndex() {
    if(type != 2 && type != 4) {
        cout << "Error: Instance accessed is not domain based" << endl;
    }
    return domainIndex;
}

string Instance::getId() {
    if (type != 0) {
        cout << "Error: Instance accessed is not id based" << endl;
    }
    return id;
}
