/*
    DockerReport.cpp

    Produces a report with various counts of the parts
    of a DockerCompose file.

    Input is an YAML file in the Docker Compose format.

    Limitations:
    * Much of YAML is not supported
*/

#include <iostream>
#include <string>
#include <string_view>
#include <sstream>

#include "YAMLParser.hpp"
#include "DockerReportHandler.hpp"

int main() {

    // input complete file into a string
    std::ostringstream sstream;
    sstream << std::cin.rdbuf();
    std::string buffer = sstream.str();

    // parse the YAML and collect docker compose data
    DockerReportHandler handler;
    YAMLParser parser(handler, buffer);
    parser.parse();

    // Output docker compose report
    std::cout << "# Docker Report: version " << handler.getVersion() << '\n';
    std::cout << "| Platform | Count |\n";
    std::cout << "|:-----|-----:|\n";
    std::cout << "| all | " << handler.getKeyCount() << " |\n";
    std::cout << "| ubuntu | " << handler.getUbuntuCount() << " |\n";
    std::cout << "| fedora | " << handler.getFedoraCount() << " |\n";
    std::cout << "| centos | " << handler.getCentOSCount() << " |\n";
    std::cout << "| opensuse | " << handler.getOpenSUSECount() << " |\n";

    return 0;
}
