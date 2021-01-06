#include <iostream>
#include <stdexcept>
#include "../include/csv/csv.hpp"

// Tests invalid file.
bool test_invalid() {
    try {
        csv::csv{"doesn't exist"};
    } catch (const std::invalid_argument&) {
        return true;
    } catch (...) {
        return false;
    }
    return false;
}

// Tests first line: aaaa,bbbb,cccc,dddd
bool test_first_line(const std::vector<std::string>& line) {
    return line.size() == 4
        && line[0] == "aaaa"
        && line[1] == "bbbb"
        && line[2] == "cccc"
        && line[3] == "dddd";
}

// Tests second line: a,,c,d,
bool test_second_line(const std::vector<std::string>& line) {
    return line.size() == 4
        && line[0] == "a"
        && line[1] == ""
        && line[2] == "c"
        && line[3] == "d";
}

// Tests third line: ,,,,,
bool test_third_line(const std::vector<std::string>& line) {
    return line.size() == 5
        && line[0] == ""
        && line[1] == ""
        && line[2] == ""
        && line[3] == ""
        && line[4] == "";
}

int main(int argc, const char *argv[]) {
    if (!test_invalid())
        std::cerr << "test_invalid failed" << std::endl;

    csv::csv reader{"test/test.csv"};
    if (!test_first_line(reader.readline().value()))
        std::cerr << "test_first_line failed" << std::endl;
    if (!test_second_line(reader.readline().value()))
        std::cerr << "test_second_line failed" << std::endl;
    if (!test_third_line(reader.readline().value()))
        std::cerr << "test_third_line failed" << std::endl;
    std::cout << "all tests passed" << std::endl;
    return 0;
}
