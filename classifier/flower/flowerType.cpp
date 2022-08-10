#include "flowerType.h"
std::ostream& operator<<(std::ostream& os, const FlowerType type) {
    switch(type){
        case FlowerType::SETOSA:
            os << "Iris-setosa";
            break;
        case FlowerType::VIRGINICA:
            os << "Iris-virginica";
            break;
        case FlowerType::VERSICOLOR:
            os << "Iris-versicolor";
            break;
        default:
            os << "UNKNOWN";
            break;
    }
    return os;
}