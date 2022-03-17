/*
    YAMLParser.cpp

    Implementation file for YAML parsing class
*/

#include "YAMLParser.hpp"

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

    return !inValue && isalpha(*pc);
}

// Parse a YAML key
void YAMLParser::parseKey(std::string& name) {

    auto endname = std::find_if_not(pc, end, [] (char c) { return isalnum(c) || c == '_' || c == '.'; });
    if (endname == end)
        exit(1);
    name.assign(pc, endname);
    pc = endname;
    pc = std::find_if_not(pc, end, [] (char c) { return isspace(c); });
    if (*pc != ':')
        exit(1);
    std::advance(pc, 1);
    pc = std::find_if_not(pc, end, [] (char c) { return isspace(c); });
    inValue = true;
}

// YAML parsing is at a value
bool YAMLParser::isValue() {

    return inValue && (isalpha(*pc) || *pc == '"');
}

// Parse a YAML value
void YAMLParser::parseValue(std::string& value) {

    pc = std::find_if_not(pc, end, [] (char c) { return isspace(c); });
    if (*pc == '"')
        std::advance(pc, 1);
    auto valueend = std::find_if(pc, end, [] (char c) { return c == '"' || c == ' ' || c == '\n'; });
    value.assign(pc, valueend);
    pc = valueend;
    if (*pc == '"')
        std::advance(pc, 1);
    pc = std::find_if_not(pc, end, [] (char c) { return isspace(c); });
    inValue = false;
}
