/*
    YAMLParser.cpp

    Implementation file for YAML parsing class
*/

#include "YAMLParser.hpp"

// constructor
YAMLParser::YAMLParser(const std::string& buffer,
                       std::function<void(std::string_view)> handleKey,
                       std::function<void(std::string_view)> handleValue)
    : handleKey(handleKey), handleValue(handleValue), buffer(buffer), pc(buffer.cbegin()), end(buffer.cend())
{}

// parse the YAML using the registered handlers
void YAMLParser::parse() {

    while (true) {
        if (isDone()) {
            break;
        } else if (isKey()) {

            // parse key
            parseKey();

        } else if (isValue()) {

            // parse value
            parseValue();
        }
    }
}

// Done with parsing
bool YAMLParser::isDone() {
    return pc == end;
}

// YAML parsing is at a key
bool YAMLParser::isKey() {

    return !inValue && isalpha(*pc);
}

// Parse a YAML key
void YAMLParser::parseKey() {

    auto endname = std::find_if_not(pc, end, [] (char c) { return isalnum(c) || c == '_' || c == '.'; });
    if (endname == end)
        exit(1);
    std::string_view name(std::addressof(*pc), std::distance(pc, endname));
    pc = endname;
    pc = std::find_if_not(pc, end, [] (char c) { return isspace(c); });
    if (*pc != ':')
        exit(1);
    std::advance(pc, 1);
    pc = std::find_if_not(pc, end, [] (char c) { return isspace(c); });
    inValue = true;

    handleKey(name);
}

// YAML parsing is at a value
bool YAMLParser::isValue() {

    return inValue && (isalpha(*pc) || *pc == '"');
}

// Parse a YAML value
void YAMLParser::parseValue() {

    pc = std::find_if_not(pc, end, [] (char c) { return isspace(c); });
    if (*pc == '"')
        std::advance(pc, 1);
    auto valueend = std::find_if(pc, end, [] (char c) { return c == '"' || c == ' ' || c == '\n'; });
    std::string_view value(std::addressof(*pc), std::distance(pc, valueend));
    pc = valueend;
    if (*pc == '"')
        std::advance(pc, 1);
    pc = std::find_if_not(pc, end, [] (char c) { return isspace(c); });
    inValue = false;

    handleValue(value);
}
