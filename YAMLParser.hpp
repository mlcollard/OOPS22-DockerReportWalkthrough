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

    // parse the YAML using the registered handlers
    void parse();

    // destructor
    virtual ~YAMLParser() = default;

protected:
    // key handler
    virtual void handleKey(std::string_view key) = 0;

    // value handler
    virtual void handleValue(std::string_view key) = 0;

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

    bool inValue = false;
    std::string buffer;
    std::string::const_iterator pc;
    std::string::const_iterator end;
};

#endif
