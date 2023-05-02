//
// Created by Khanh Nguyen on 3/23/23.
//

#ifndef MULTITEXT_FILEREADER_H
#define MULTITEXT_FILEREADER_H

#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <iostream>
template<typename T>
class FileReader : public std::iterator<std::random_access_iterator_tag, T>
{
private:
    std::vector<T> data;
public:
    typedef typename std::vector<T>::iterator iterator;
    FileReader();
    FileReader(const std::string& filename);
    iterator begin();
    iterator end();
    void print();
    void getData(const std::string& filename);

};

#include "FileReader.cpp"
#endif //MULTITEXT_FILEREADER_H
