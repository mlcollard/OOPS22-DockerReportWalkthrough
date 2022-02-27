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
#include <sstream>

#include "YAMLParser.hpp"

int main() {

    std::string version;
    bool inversion = false;
    int keyCount = 0;
    int ubuntuCount = 0;
    int fedoraCount = 0;
    int centosCount = 0;
    int opensuseCount = 0;

    // input complete file into a string
    std::ostringstream sstream;
    sstream << std::cin.rdbuf();
    std::string buffer = sstream.str();

    // parse YAML and update counts
    YAMLParser parser(buffer);
    std::string::const_iterator pc = buffer.cbegin();
    while (true) {
        if (pc == buffer.cend()) {
            break;
        } else if (parser.isKey(pc)) {

            // parse key
            std::string name;
            pc = parser.parseKey(pc, name);

            // update docker counters and version
            if (name == "version") {
                inversion = true;
            } else {
                ++keyCount;
                std::string prefixName = name.substr(0, name.find('_'));
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

        } else if (parser.isValue(pc)) {

            // parse value
            std::string value;
            pc = parser.parseValue(pc, value);

            // save the version value
            if (inversion) {
                version = value;
                inversion = false;
            }
        }
    }

    // Output docker compose report
    std::cout << "# Docker Report: version " << version << '\n';
    std::cout << "| Platform | Count |\n";
    std::cout << "|:-----|-----:|\n";
    std::cout << "| all | " << keyCount << " |\n";
    std::cout << "| ubuntu | " << ubuntuCount << " |\n";
    std::cout << "| fedora | " << fedoraCount << " |\n";
    std::cout << "| centos | " << centosCount << " |\n";
    std::cout << "| opensuse | " << opensuseCount << " |\n";

    return 0;
}
