//
// Created by Khanh Nguyen on 3/23/23.
//

#ifndef MULTITEXT_FILEREADER_CPP
#define MULTITEXT_FILEREADER_CPP

#include "FileReader.h"


template<typename T>
FileReader<T>::FileReader()
{
    getData("testnames");
}

template<typename T>
FileReader<T>::FileReader(const std::string& filename)
{
    getData(filename);
    // print();
}
template<typename T>
void FileReader<T>::getData(const std::string& filename)
{
    std::ifstream fin;
    fin.open(filename);
    if(fin.fail())
        exit(28);
    T next;
    while(fin >> next)
    {
        data.push_back(next);
    }
    fin.close();
}

template<typename T>
typename FileReader<T>::iterator FileReader<T>::end()
{
    return data.end();
}

template<typename T>
typename FileReader<T>::iterator FileReader<T>::begin()
{
    return data.begin();
}

template<typename T>
void FileReader<T>::print()
{
    for(T i : data)
    {
        std::cout << i << " ";
    }
}


#endif
