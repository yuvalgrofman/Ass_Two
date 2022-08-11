#include "flowerReader.h"
#include <string>
#include "flowerDetector.h"
using namespace std;

FlowerReader::FlowerReader(const string &filename) : file(filename) {
    fin.open(file, ios::in);
}

Flower* FlowerReader::readFlower() {
    string line;
    getline(fin, line);
    return detectFlower(line);
}

FlowerPoint* FlowerReader::readFlowerPoint() {
    string line;
    getline(fin, line);
    return detectFlowerPoint(line);
}