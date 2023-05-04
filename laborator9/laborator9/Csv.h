#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class CsvIterator {
	std::istream& input;
	std::vector<std::string> columns;
	friend class CsvReader;

public:
	bool readLine();
	CsvIterator(std::istream& input);
	std::vector<std::string> operator*() const;
	CsvIterator& operator++();
	bool operator==(CsvIterator& other) const;
	bool operator!=(CsvIterator& other) const;

};

class CsvReader {
	std::istream& input;

public:
	CsvReader(std::istream& input);
	CsvIterator begin() const;
	CsvIterator end() const;
};
class Episode {
public:
	std::string title;
	std::string date;
	std::string length;
	std::string viewersmm;
	std::string score;

	Episode(const std::vector<std::string>& columns) {
		title = columns[0];
		date = columns[1];
		length = columns[2];
		viewersmm = columns[3];
		score = columns[4];
	}
	bool operator<(const Episode& other) const {
		return score > other.score || (score == other.score && length > other.length) || (score == other.score && length == other.length && date < other.date) || (score == other.score && length == other.length && date == other.date && title < other.title);
	}

};