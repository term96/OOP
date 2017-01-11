#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using Dictionary = std::map<std::string, std::string>;
typedef std::map<std::string, std::string>::iterator DictElement;

// ��������� �� ��� ������: ���������� ����������������� ����� � �������, ��������������� ������� ��������, ����������, ���������� ����� � ��������� ��������
void ReadFromFile(Dictionary &dictionary, std::ifstream &file);
void SaveChanges(Dictionary &dictionary, std::ofstream &file);
void HandleUserInput(std::string const& input, Dictionary &dictionary, bool &dictionaryChanged, std::istream &inStream = std::cin);
bool InteractionLoop(Dictionary &dictionary, std::istream &inStream = std::cin);
bool IsSaveNeeded(std::istream &inStream = std::cin);