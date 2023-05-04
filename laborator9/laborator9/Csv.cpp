#include "Csv.h"
#include <fstream>
#include <string>
#include <vector>
bool CsvIterator::readLine() {
    std::string line;
    if (!std::getline(input, line))
        return false;

    columns.clear();
    std::string column;
    bool inQuotes = false;
    for (char c : line) {
        if (c == '"') {
            inQuotes = !inQuotes;
        }
        else if (c == ',' && !inQuotes) {
            columns.push_back(column);
            column.clear();
        }
        else {
            column.push_back(c);
        }
    }
    columns.push_back(column);
    return true;
}


CsvIterator::CsvIterator(std::istream& input): input(input)
{
    readLine();
}

std::vector<std::string> CsvIterator::operator*() const
{
    return columns;
}

CsvIterator& CsvIterator::operator++()
{
    readLine();
    return *this;
}

bool CsvIterator::operator==(CsvIterator& other) const
{
    return &input == &other.input;
}

bool CsvIterator::operator!=(CsvIterator& other) const
{
    return !(*this == other);
}

CsvReader::CsvReader(std::istream& input) :input(input)
{
}

CsvIterator CsvReader::begin() const
{
    return CsvIterator(input);
}

CsvIterator CsvReader::end() const
{
    return CsvIterator(input);
}

