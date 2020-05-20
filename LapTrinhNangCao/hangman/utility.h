#ifndef __UTILITY_H__
#define __UTILITY_H__
#include <string>

std::string normalize(const std::string& s);
std::string chooseWord(const std::string& fileName);
bool contains(std::string word, char guess);

#endif // __UTILITY_H__
