# Flower Classifier

## About The Project

Our project predicts flower classifications using the KNN algorithm using the euclidean distance metric.
The attributes with which we defined a flower were: width, sepal length, sepal width, petal length.
In addition, each flower has a type. The types are:
- Iris-setosa
- Iris-versicolor
- Iris-virginica

The project is divided into to parts, The server and the client. 
The server is responsible for receiving the data from the client, 
predicting the flower type based on a file of classified flowers the server holds
and sending the predicted type to the client.
On the other hand, the client is responsible for reading unclassified flowers from a giving file,
responsible for sending the unclassified flowers to the server, 
receiving the predicted types and writing them to a file. 
The server and the client communicate using the TCP protocol.

The client is in another github repository and can be found [here](https://github.com/OldRimStalker/Ass_Two_Client).

## Running The Whole Project

In order to run the project, the user must first run the server according to the instructions in the server's README.md
and then run the client according to the instructions in the client's README.md.

## The Server

As mentioned above, the project contains a server and a client. 
This part of the README.md is dedicated to the server.

## Getting Started

### 1) Prerequisites

This project requires CMake (3.16 or above) in order to function properly.
To install CMake, follow the instructions [here](https://cmake.org/install/). In addition, a cpp compiler that supports c++11 is required.

### 2) Install And Run Project

Firstly, clone the project from the GitHub repository:

        git clone 'https://github.com/yuvalgrofman/Ass_Two'

Then, to run the project execute the following commands (in the terminal):

        mkdir -p build && cd build
        cmake ..
        make -j
        ./AssTwo.out

Executing these commands will run the server which will wait for a client to connect to.

### 3) .csv Files

This project relies on one .csv files to properly function.
1. classified.csv - contains the data of classified flowers used for the KNN algorithm.

This file contains the following columns (separated by a comma):

- width - the width of the flower
- sepal length - the length of the flower's sepal
- sepal width - the width of the flower's sepal
- petal length - the length of the flower's petal
- type - the type of the flower

The server assumes this file is located in Ass-Two/server/data/flower_data.csv.
Please note, that this **csv file must end with a blank line**. Otherwise, the program will not operate properly.
## Output

The output of the program is a csv file containing the predicted flower types.
The file is named: Classified.csv and is located in Ass_Two_Client/Output/Classified.csv.

## Algorithm

The algorithm works, by reading the classified.csv file thus creating a database of flowers.
Then it predicts every unpredicted flower using one of the distance functions, and a specified number of neighbours.
Subsequently, it sorts the database using merge sort, from closest to farthest (by distance).
Finally, it retrieves the k closest neighbours, finds their most common classification 
and returns aforementioned classification as the "predicted type".
It then sends the predicted type to the client, which writes it to a file.

## Additional Info

Firstly, the algorithm currently supports running the client and server on the same machine. 
In order to change this behavior, the ip address in the client must be changed.

Secondly, This algorithm automatically sets the k value used in the KNN algorithm to 3
and the distance metric used is the euclidean distance. 


## Authors

[Yuval Grofman](https://github.com/yuvalgrofman)

[Jonathan Moiseyev](https://github.com/OldRimStalker)