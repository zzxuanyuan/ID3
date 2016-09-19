#include <string>

#ifndef INSTANCE_
#define INSTANCE_

using namespace std;
class Instance {
private:
    // Types:
    // 0 = id
    // 1 = numeric
    // 2 = domain
    // 3 = class numeric
    // 4 = class domain
    int type;
    float numValue;
    int domainIndex;
    string id;
public:
    Instance(int type, float value);
    Instance(int type, string id);
    bool isNumeric();
    float getNumValue();
    int getDomainIndex();
    string getId();
};
#endif
