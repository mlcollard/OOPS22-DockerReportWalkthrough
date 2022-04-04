/*
    DockerReportParser.cpp

    Implementation for DockerReportParser class
*/

#include "DockerReportParser.hpp"

DockerReportParser::DockerReportParser(const std::string& buffer)
    : YAMLParser(buffer)
{}

// key count
int DockerReportParser::getKeyCount() const {
    return keyCount;
}

// Ubuntu count
int DockerReportParser::getUbuntuCount() const {
    return ubuntuCount;
}

// Fedora count
int DockerReportParser::getFedoraCount() const {
    return fedoraCount;
}

// CentOS count
int DockerReportParser::getCentOSCount() const {
    return centosCount;
}

// OpenSUSE count
int DockerReportParser::getOpenSUSECount() const {
    return opensuseCount;
}

// version
std::string_view DockerReportParser::getVersion() const {
    return version;
}

// key handler
void DockerReportParser::handleKey(std::string_view name) {

    // update docker counters and version
    if (name == "version") {
        inversion = true;
    } else {
        ++keyCount;
        auto prefixName = name.substr(0, name.find('_'));
        if (prefixName == "ubuntu") {
            ++ubuntuCount;
        } else if (prefixName == "fedora") {
            ++fedoraCount;
        } else if (prefixName == "centos") {
            ++centosCount;
        } else if (prefixName == "opensuse") {
            ++opensuseCount;
        }
    }
}

// value handler
void DockerReportParser::handleValue(std::string_view value) {

    // save the version value
    if (inversion) {
        version = value;
        inversion = false;
    }
}
