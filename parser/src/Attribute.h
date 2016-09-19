#include <string>
#include <vector>

#include "Instance.h"

#ifndef ATTRIBUTE_
#define ATTRIBUTE_

using namespace std;
class Attribute {
private:
    // Types:
    // 0 = id
    // 1 = numeric
    // 2 = domain
    // 3 = class numeric
    // 4 = class domain
    int type;
    vector<string> domain;
public:
    Attribute(int type);
    void addDomain(vector<string> domain);
    float compare(Instance* a, Instance* b);
    bool isNumeric();
    int getType();
    int getIndexInDomain(string value);
    string getValueForIndex(int index);
};

#endif
