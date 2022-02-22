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

// YAML parsing is at a value
bool YAMLParser::isValue(std::string::const_iterator pc, bool invalue) {

    return ::isValue(pc, invalue);
}

// Parse a YAML value
std::string::const_iterator YAMLParser::parseValue(std::string::const_iterator pc, std::string::const_iterator end, std::string& value, bool& invalue) {

    return ::parseValue(pc, end, value, invalue);
}
