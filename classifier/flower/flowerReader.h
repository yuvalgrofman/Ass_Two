#ifndef ASS_ONE_FLOWER_READER_H
#define ASS_ONE_FLOWER_READER_H

#include "flower/flower.h"
#include <fstream>

/**
 * @brief The FlowerReader class
 *
 * This class is responsible for reading flowers and flower-points from files.
 */
class FlowerReader {
    private:
        // The file stream to read from.
        string file;

        //the stream used to read the file
        fstream fin;

    public:
        /**
         * Constructor.
         * @param file the file to read from
         */
        FlowerReader(const string &filename);

        /**
         * Reads a flower from the file.
         * if the file is empty, it returns nullptr.
         * @return the flower
         */
        Flower* readFlower();

        /**
         * Reads a flower point from the file.
         * if the file is empty, it returns nullptr.
         * @return the flower point
         */
        FlowerPoint* readFlowerPoint();
};

#endif //ASS_ONE_FLOWER_READER_H
