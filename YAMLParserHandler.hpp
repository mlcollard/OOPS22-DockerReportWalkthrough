/*
    YAMLParserHandler.hpp

    Declaration file for YAML parsing class handler
*/

#ifndef INCLUDED_YAMLPARSERHANDLER_HPP
#define INCLUDED_YAMLPARSERHANDLER_HPP

#include <string_view>

class YAMLParserHandler {
public:

    // process Key
    virtual void handleKey(std::string_view  name) = 0;

    // process Value
    virtual void handleValue(std::string_view value) = 0;
};

#endif
