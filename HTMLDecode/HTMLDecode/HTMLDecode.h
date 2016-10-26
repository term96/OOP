#pragma once

#include <string>

void FindAndReplace(std::string &text, std::string const& oldText, std::string const& newText);
std::string HtmlDecode(std::string const& html);
bool ReadStream(std::istream &stream, std::string &line);