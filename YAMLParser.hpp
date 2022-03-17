/*
    YAMLParser.hpp

    Declaration file for YAML parsing class
*/

#ifndef INCLUDED_YAMLPARSER_HPP
#define INCLUDED_YAMLPARSER_HPP

#include <functional>
#include <string>
#include <string_view>

class YAMLParser {
public:

    // constructor
    YAMLParser(const std::string& buffer);

    // register handler for a key
    void registerKeyHandler(std::function<void(std::string_view)> handleKey);

    // register handler for a value
    void registerValueHandler(std::function<void(std::string_view)> handleValue);

    // parse the YAML using the registered handlers
    void parse();

private:

    // Done with parsing
    bool isDone();

    // YAML parsing is at a key
    bool isKey();

    // Parse a YAML key
    void parseKey();

    // YAML parsing is at a value
    bool isValue();

    // Parse a YAML value
    void parseValue();

    std::function<void(std::string_view)> handleKey;
    std::function<void(std::string_view)> handleValue;
    bool inValue = false;
    std::string buffer;
    std::string::const_iterator pc;
    std::string::const_iterator end;
};

#endif
