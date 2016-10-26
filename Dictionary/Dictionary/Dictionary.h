#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

typedef std::map<std::string, std::string> Dictionary;
typedef std::map<std::string, std::string>::iterator DictElement;

void ReadFromFile(Dictionary &dictionary, std::ifstream &file);
void SaveChanges(Dictionary &dictionary, std::ofstream &file);
void HandleUserInput(std::string const& input, Dictionary &dictionary, bool &dictionaryChanged, std::istream &inStream = std::cin);
bool InteractionLoop(Dictionary &dictionary, std::istream &inStream = std::cin);
bool NeedToSave(std::istream &inStream = std::cin);