/*
    YAMLParser.hpp

    Declaration file for YAML parsing class
*/

#ifndef INCLUDED_YAMLPARSER_HPP
#define INCLUDED_YAMLPARSER_HPP

#include <string>

class YAMLParser {
public:
    // YAML parsing is at a key
    bool isKey(std::string::const_iterator pc, bool invalue);
};

#endif
