#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Instance.h"
#include "Parser.h"

#include "Main.h"

using namespace std;

int main(int argc, char* argv[]) {
    switch (argc) {
        case 1:
            cout << "Please specify an file type: MonkI, CongressVote, HumanAcitivity." << endl;
            cout << "Syntax: ./main fileType dataFile" << endl;
            return 1;
        case 2:
            cout << "Please specify a input data file." << endl;
            cout << "Syntax: ./main fileType dataFile" << endl;
            return 1;
        case 3:
            break;
        default:
            cout << "Too many arguments." << endl;
            cout << "Syntax: ./main fileType dataFile" << endl;
            return 1;
    }

    vector<Instance> data;
    Parser parser = Parser(argv[1], argv[2]);

    return 0;
}
