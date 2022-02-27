/*
    YAMLParser.cpp

    Implementation file for YAML parsing class
*/

#include "YAMLParser.hpp"
#include "yaml_parser.hpp"

// constructor
YAMLParser::YAMLParser(const std::string& buffer)
    : buffer(buffer), pc(buffer.cbegin()), end(buffer.cend())
{}

// Done with parsing
bool YAMLParser::isDone() {
    return pc == end;
}

// YAML parsing is at a key
bool YAMLParser::isKey() {

    return ::isKey(pc, inValue);
}

// Parse a YAML key
void YAMLParser::parseKey(std::string& name) {

    pc = ::parseKey(pc, end, name, inValue);
}

// YAML parsing is at a value
bool YAMLParser::isValue() {

    return ::isValue(pc, inValue);
}

// Parse a YAML value
void YAMLParser::parseValue(std::string& value) {

    pc = ::parseValue(pc, end, value, inValue);
}
