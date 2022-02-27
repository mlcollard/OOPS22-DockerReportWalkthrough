/*
    YAMLParser.cpp

    Implementation file for YAML parsing class
*/

#include "YAMLParser.hpp"
#include "yaml_parser.hpp"

// YAML parsing is at a key
bool YAMLParser::isKey(std::string::const_iterator pc) {

    return ::isKey(pc, inValue);
}

// Parse a YAML key
std::string::const_iterator YAMLParser::parseKey(std::string::const_iterator pc, std::string::const_iterator end, std::string& name) {

    return ::parseKey(pc, end, name, inValue);
}

// YAML parsing is at a value
bool YAMLParser::isValue(std::string::const_iterator pc) {

    return ::isValue(pc, inValue);
}

// Parse a YAML value
std::string::const_iterator YAMLParser::parseValue(std::string::const_iterator pc, std::string::const_iterator end, std::string& value) {

    return ::parseValue(pc, end, value, inValue);
}
