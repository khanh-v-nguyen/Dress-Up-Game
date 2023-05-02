//
// Created by Khanh Nguyen on 3/23/23.
//

#include "WordSort.h"

WordSort::WordSort()
{

}

WordSort::WordSort(const std::string & fileName)
{
    fileReader.getData(fileName);
    init();

}

WordSort::WordSort(const FileReader<std::string> &reader, const std::string &string)
{
    this -> reader = reader;
    this -> typedString = string;
    init();
}

void WordSort::init()
{
    reset();
    prioritize();
    sortByHeap();
    updatePosition();
}



void WordSort::setFile(const std::string & fileName, const std::string &string)
{
    this -> reader = FileReader<std::string>(fileName);
    this -> typedString = string;
}


void WordSort::updateAutoCorrect()
{
    init();
}

void WordSort::updateAutoCorrect(std::string text)
{
    this -> typedString = text;
    init();
}

void WordSort::heuristic()
{

}

void WordSort::reset()
{
    while(!suggestions.empty())
    {
        suggestions.pop_back();
    }
    while(!heap.empty())
    {
        heap.pop();
    }

    while(!sortedWords.empty())
    {
        sortedWords.pop_back();
    }
}

void WordSort::prioritize()
{
    //pushing back words and setting priority, not sorting in order yet

    int idx =0;
    int xpos = 200;
    int ypos = 200;

    for(auto it = fileReader.begin(); it != fileReader.end(); ++it)
    {
        suggestions.emplace_back(*it);

        if(std::tolower((*it)[0]) == tolower(typedString[0]))
        {
            suggestions.back().addPriority(4);
        }

        for(int i = 0; i<it->size(); ++i)
        {
            if(std::tolower((*it)[i]) == tolower(typedString[i])) // if name in file exists in typed word AT THE EXACT PLACE
            {
                suggestions.back().addPriority(2); // adding a priority point (update name of function later)
            }
            else
            {
                suggestions.back().addPriority(-1);
            }
        }
    }
}

void WordSort::sortByHeap()
{
    for(int i = 0; i < suggestions.size(); ++i)
    {
        heap.push(suggestions[i]);
    }

    while(!heap.empty())
    {
        sortedWords.push_back(new Word(heap.top().getString()));
        sortedWords.back()->addPriority(heap.top().getPriority());
        heap.pop();
    }
}

void WordSort::setPosition(sf::Vector2f position)
{
    if(!sortedWords.empty())
    {
        (*sortedWords[0]).setPosition(position);
    }
    updatePosition();
}

void WordSort::updatePosition()
{

    for(int i = 1; i < sortedWords.size(); ++i)
    {
        Position::bottom(*sortedWords[i-1], *sortedWords[i]);
    }

}

void WordSort::printByPriority()
{
    for(Word * w : sortedWords)
    {
        std::cout << w->getString();
        std::cout << w->getPriority();
    }
}

void WordSort::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    updatePosition();
}

void WordSort::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(int i = 0; i < sortedWords.size(); ++i)
    {
        if(sortedWords[0]->getPriority() > 0 && i < 5)
        {
            target.draw(*sortedWords[i]);
        }
    }
}
