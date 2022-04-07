/*
    DockerReportHandler.cpp

    Implementation for DockerReportHandler class
*/

#include "DockerReportHandler.hpp"

// key count
int DockerReportHandler::getKeyCount() const {

    return keyCount;
}

// Ubuntu count
int DockerReportHandler::getUbuntuCount() const {

    return ubuntuCount;
}

// Fedora count
int DockerReportHandler::getFedoraCount() const {

    return fedoraCount;
}

// CentOS count
int DockerReportHandler::getCentOSCount() const {

    return centosCount;
}

// OpenSUSE count
int DockerReportHandler::getOpenSUSECount() const {

    return opensuseCount;
}

// version
std::string_view DockerReportHandler::getVersion() const {

    return version;
}

// key handler
void DockerReportHandler::handleKey(std::string_view name) {

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
void DockerReportHandler::handleValue(std::string_view value) {

    // save the version value
    if (inversion) {
        version = value;
        inversion = false;
    }
}
