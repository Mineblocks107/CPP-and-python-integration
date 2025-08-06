// files.h
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept> // for std::runtime_error

namespace py_fsrw
{
    class py_file {
    public:
        std::fstream file;
        std::string mode;

        std::string read() {
            std::cout << "debug" << std::endl;
            std::string ans;
            std::string line;
            while (std::getline(this->file, line)) {
                std::cout << "debug here" << std::endl;
                ans += line;
                ans += '\n';
                std::cout << line << "debug" << std::endl;
            }
            return ans;
        }
    };

    py_file open(const std::string& filename, const std::string& mode) {
        py_file output;

        if (mode == "r") {
            output.file.open(filename, std::ios::in); // open for reading

            if (!output.file.is_open()) {
                throw std::runtime_error("Could not open file for reading: " + filename);
            }

            output.mode = "r";
        }
        // You can add more modes later ("w", "a", etc.)
        else {
            throw std::invalid_argument("Unsupported mode: " + mode);
        }

        return output;
    }
}
