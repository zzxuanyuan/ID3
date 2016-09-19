#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Attribute.h"
#include "Instance.h"
#include "Parser.h"

Parser::Parser() {

}

int Parser::parseFormat(vector<Attribute>* format, string filePath) {
    ifstream file;
    file.open(filePath);
    if (!file.is_open()) {
        cout << "Format file was not successfully opened." << endl;
        return 1;
    }
    if(file.eof()) {
        cout << "Empty format file." << endl;
        return 1;
    }
    string formatLine;
    getline(file, formatLine);
    char delim = formatLine[0];
    formatLine = formatLine.substr(1);
    stringstream formatstream(formatLine);
    string token;
    *format = vector<Attribute>();
    while (getline(formatstream, token, ' ')) {
        int type = 0;
        if(token[0] == 'C') {
            type += 2;
            token = token.substr(1);
        }
        if (token.compare("ID") == 0) {
            cout << "ID: " << token << endl;
            Attribute a = Attribute(0);
            format->push_back(a);
        } else if(token[0] == 'N') {
            Attribute a = Attribute(type + 1);
            format->push_back(a);
        } else if (token[0] == '/') {
            stringstream tokenstream(token.substr(1));
            vector<string> domain = vector<string>();
            string value;
            while(getline(tokenstream, value, ',')) {
                domain.push_back(value);
            }
            Attribute a = Attribute(type + 2);
            a.addDomain(domain);
            format->push_back(a);
        } else {
            cout << "Error parsing, unkown token: " << token << endl;
        }
    }
    file.close();
    return 0;
}

int Parser::parseData(vector<Attribute>* format,
        vector< vector<Instance> >* data, string filePath) {
    ifstream file;
    file.open(filePath);
    if (!file.is_open()) {
        cout << "Data file was not successfully opened." << endl;
        return 1;
    }
    *data = vector< vector<Instance> >();
    string line;
    while (!file.eof()) {
        getline(file, line);
        replace(line.begin(), line.end(), ' ', ',');
        vector<Instance> instances = vector<Instance>();
        stringstream linestream(line);
        int i = 0;
        string token;
        while (getline(linestream, token, ',')) {
            if((int)token[0] == 0) {
                continue;
            }
            if ((*format)[i].isNumeric()) {
                try {
                    float value = stof(token);
                    Instance a = Instance((*format)[i].getType(), value);
                    instances.push_back(a);
                } catch( ... ) {
                    cout << "Parsed bad float: " << token << " for attribute: " << i << endl;
                }
            } else if((*format)[i].getType() == 0){
                Instance a = Instance(0, token);
                instances.push_back(a);
            } else {
                int index = (*format)[i].getIndexInDomain(token);
                Instance a = Instance((*format)[i].getType(), index);
                instances.push_back(a);
            }
            i++;
        }
        if(instances.size() == format->size()) {
            data->push_back(instances);
        }
    }
    file.close();
    return 0;
}
