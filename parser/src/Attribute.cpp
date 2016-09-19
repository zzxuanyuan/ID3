#include <string>
#include <sstream>
#include <iostream>

#include "Attribute.h"
#include "Instance.h"

using namespace std;
Attribute::Attribute(int type) {
    this->type = type;
    if(type < 0 || type > 4) {
        cout << "Invalid Attribute input type." << endl;
    }
}

void Attribute::addDomain(vector<string> domain) {
    this->domain = domain;
}

float Attribute::compare(Instance* a, Instance* b) {
    if(type == 1 || type == 3) {
        return a->getNumValue() - b->getNumValue();
    } else {
        return (float)domain[a->getDomainIndex()].compare(domain[b->getDomainIndex()]);
    }
}

bool Attribute::isNumeric() {
    return type == 1 || type == 3;
}

int Attribute::getType() {
    return type;
}

int Attribute::getIndexInDomain(string value) {
    if (type != 2 && type != 4) {
        cout << "Error: Attribute accessed is not domain based" << endl;
    }
    for (int i = 0; i < domain.size(); i++){
        if(value.compare(domain[i])) {
            return i;
        }
    }
    return -1;
}

string Attribute::getValueForIndex(int index) {
    if (type != 2 && type != 4) {
        cout << "Error: Attribute accessed is not domain based" << endl;
    }
    return domain[index];
}
