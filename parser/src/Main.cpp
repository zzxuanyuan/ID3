#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Attribute.h"
#include "Instance.h"
#include "Parser.h"

#include "Main.h"

using namespace std;

int main(int argc, char* argv[]) {
    switch (argc) {
        case 1:
            cout << "Please specify an input file." << endl;
            cout << "Syntax: ./decisionTree.o dataFile formatFile" << endl;
            return 1;
        case 2:
            cout << "Please specify a format file." << endl;
            cout << "Syntax: ./decisionTree.o dataFile formatFile" << endl;
            return 1;
        case 3:
            break;
        default:
            cout << "Too many arguments." << endl;
            cout << "Syntax: ./decisionTree.o dataFile formatFile" << endl;
            return 1;
    }

    vector< vector<Instance> > data;
    vector<Attribute> format;
    Parser parser = Parser();

    if (parser.parseFormat(&format, argv[2])) return 1;
    if (parser.parseData(&format, &data, argv[1])) return 1;

    cout << "Format:" << endl;
    for (int i = 0; i < format.size(); i++) {
        switch(format[i].getType()){
            case 0:
                cout << "id ";
                break;
            case 1:
                cout << "numeric ";
                break;
            case 2:
                cout << "domain ";
                break;
            case 3:
                cout << "class_numeric ";
                break;
            case 4:
                cout << "class_domain ";
                break;
        }
    }

    cout << endl;
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < format.size(); j++) {
            switch (format[j].getType()) {
                case 0:
                    cout << data[i][j].getId() << " ";
                    break;
                case 1:
                case 3:
                    cout << data[i][j].getNumValue() << " ";
                    break;
                case 2:
                case 4:
                    cout << format[j].getValueForIndex(data[i][j].getDomainIndex()) << " ";
                    break;
                default:
                    cout << "Bad type found: " << format[j].getType() << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
