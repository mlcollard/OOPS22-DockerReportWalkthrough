/*
    YAMLParser.cpp

    Implementation file for YAML parsing class
*/

#include "YAMLParser.hpp"
#include "yaml_parser.hpp"

// YAML parsing is at a key
bool YAMLParser::isKey(std::string::const_iterator pc, bool invalue) {

    return ::isKey(pc, invalue);
}

// Parse a YAML key
std::string::const_iterator YAMLParser::parseKey(std::string::const_iterator pc, std::string::const_iterator end, std::string& name, bool& invalue) {

    return ::parseKey(pc, end, name, invalue);
}
