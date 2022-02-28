/*
    YAMLParser.hpp

    Declaration file for YAML parsing class
*/

#ifndef INCLUDED_YAMLPARSER_HPP
#define INCLUDED_YAMLPARSER_HPP

#include <string>
#include <string_view>

class YAMLParser {
public:

    // constructor
    YAMLParser(std::string_view buffer);

    // Done with parsing
    bool isDone();

    // YAML parsing is at a key
    bool isKey();

    // Parse a YAML key
    void parseKey(std::string& name);

    // YAML parsing is at a value
    bool isValue();

    // Parse a YAML value
    void parseValue(std::string& value);

private:
    bool inValue = false;
    std::string buffer;
    std::string::const_iterator pc;
    std::string::const_iterator end;
};

#endif
