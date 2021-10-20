#ifndef GUARD_find_urls_h
#define GUARD_find_urls_h

#include <vector>
#include <string>

std::string::const_iterator
url_end(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator
url_beg(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);
#endif