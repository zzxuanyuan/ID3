#include <vector>

#include "Attribute.h"
#include "Instance.h"

#ifndef PARSER_
#define PARSER_

class Parser {
public:
    Parser();
    int parseFormat(vector<Attribute>* format, string filePath);
    int parseData(vector<Attribute>* format,
        vector< vector<Instance> >* data, string filePath);
};

#endif
