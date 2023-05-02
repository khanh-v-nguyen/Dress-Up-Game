//
// Created by Khanh Nguyen on 3/23/23.
//

#ifndef MULTITEXT_WORDSORT_H
#define MULTITEXT_WORDSORT_H
#include <vector>
#include "Word.h"
#include "FileReader.h"
#include "Heap.h"
#include "MultiText.h"
#include <string>
#include "Position.h"

class WordSort : public sf::Drawable
{
public:
    WordSort();
    WordSort(const std::string & fileName);

    WordSort(const FileReader<std::string> &reader, const std::string & string);
    std::vector<Word> suggestions;
    void printByPriority();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow & window, sf::Event event);
    void setFile(const std::string & fileName,  const std::string &string);
    void updateAutoCorrect();
    void updateAutoCorrect(std::string text);

    void setPosition(sf::Vector2f position);
private:
    FileReader<std::string> fileReader; // has iterator to iterate thru data which is the vector of words
    void heuristic();
    void prioritize();
    Heap<Word> heap;
    Heap<int> intHeap;
    std::vector<Word *> sortedWords;
    std::vector<Word> test;
    void updatePosition();
    void init();
    void reset();



    void sortByHeap();


    FileReader<std::string> reader;
    std::string typedString;
};


#endif //MULTITEXT_WORDSORT_H
