/*
    DockerReportHandler.hpp

    Declaration file for DockerReportHandler
*/

#ifndef INCLUDED_DOCKERREPORTHANDLER_HPP
#define INCLUDED_DOCKERREPORTHANDLER_HPP

#include "YAMLParserHandler.hpp"
#include <string_view>
#include <string>

class DockerReportHandler : public YAMLParserHandler {
public:

    // key count
    int getKeyCount() const;

    // Ubuntu count
    int getUbuntuCount() const;

    // Fedora count
    int getFedoraCount() const;

    // CentOS count
    int getCentOSCount() const;

    // OpenSUSE count
    int getOpenSUSECount() const;

    // version
    std::string_view getVersion() const;

protected:

    // key handler
    void handleKey(std::string_view name) override;

    // value handler
    void handleValue(std::string_view value) override;

private:
    std::string version;
    bool inversion = false;
    int keyCount = 0;
    int ubuntuCount = 0;
    int fedoraCount = 0;
    int centosCount = 0;
    int opensuseCount = 0;
};

#endif
