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

#include "DockerReportParser.hpp"

int main() {

    // input complete file into a string
    std::ostringstream sstream;
    sstream << std::cin.rdbuf();
    std::string buffer = sstream.str();

    // parse the YAML and collect docker compose data
    DockerReportParser parser(buffer);
    parser.parse();

    // Output docker compose report
    std::cout << "# Docker Report: version " << parser.getVersion() << '\n';
    std::cout << "| Platform | Count |\n";
    std::cout << "|:-----|-----:|\n";
    std::cout << "| all | " << parser.getKeyCount() << " |\n";
    std::cout << "| ubuntu | " << parser.getUbuntuCount() << " |\n";
    std::cout << "| fedora | " << parser.getFedoraCount() << " |\n";
    std::cout << "| centos | " << parser.getCentOSCount() << " |\n";
    std::cout << "| opensuse | " << parser.getOpenSUSECount() << " |\n";

    return 0;
}
