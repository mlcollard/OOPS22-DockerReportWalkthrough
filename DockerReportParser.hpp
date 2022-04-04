/*
    DockerReportParser.hpp

    Declaration file for DockerReportParser
*/

#ifndef INCLUDED_DOCKERREPORTPARSER_HPP
#define INCLUDED_DOCKERREPORTPARSER_HPP

#include "YAMLParser.hpp"

class DockerReportParser : public YAMLParser {
public:
    DockerReportParser(const std::string& buffer);
};

#endif
