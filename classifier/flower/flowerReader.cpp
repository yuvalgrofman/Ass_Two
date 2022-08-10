#include "flowerReader.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

FlowerReader::FlowerReader(const string &filename) : file(filename) {
    fin.open(file, ios::in);
}

Flower* FlowerReader::readFlower() {

    string line, word;
    getline(fin, line);

    if (line == "")
        return nullptr;

    stringstream streamLine(line);

    getline(streamLine, word, ',');
    double width = stod(word);

    getline(streamLine, word, ',');
    double sepalLength = stod(word);

    getline(streamLine, word, ',');
    double sepalWidth = stod(word);

    getline(streamLine, word, ',');
    double petalLength = stod(word);

    getline(streamLine, word, ',');
    string typeName = word;

    FlowerType type;

    if (word.compare("Iris-setosa") == 0) {
        type = SETOSA;
    } else if (word.compare("Iris-virginica") == 0) {
        type = VIRGINICA;
    } else {
        type = VERSICOLOR;
    }


    FlowerPoint& fp = *(new FlowerPoint(width, sepalLength, sepalWidth, petalLength));
    Flower* flower = new Flower(fp, type);

    return flower;
}

FlowerPoint* FlowerReader::readFlowerPoint() {
    string line, word;
    getline(fin, line);

    if (line == "")
        return nullptr;

    stringstream streamLine(line);

    getline(streamLine, word, ',');
    double width = stod(word);

    getline(streamLine, word, ',');
    double sepalLength = stod(word);

    getline(streamLine, word, ',');
    double sepalWidth = stod(word);

    getline(streamLine, word, ',');
    double petalLength = stod(word);

    return new FlowerPoint(width, sepalLength, sepalWidth, petalLength);
}