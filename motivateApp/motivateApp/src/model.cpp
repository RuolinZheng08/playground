//
//  model.cpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/23.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "model.hpp"

MyModel::MyModel() {
    char buffer[256];
    strcpy(buffer, getenv("HOME"));
    strcat(buffer, "/Documents/data.csv");
    std::ifstream in;
//    outfile.open(buffer);
//
//    //Creates an empty file for writing
//    FILE *f = fopen(buffer,"w");
//
//    //Writing something
//    fprintf(f, "%s %s %d", "Hello", "World", 2016);
//
//    //Closing the file
//    fclose(f);
}
