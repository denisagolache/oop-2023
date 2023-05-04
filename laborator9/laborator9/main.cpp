#include "Csv.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    std::ifstream input_file("episodes.csv");
    if (!input_file.is_open()) {
        printf("File couldn't be opened\n");
        return 1;
    }
    CsvReader reader(input_file);
    std::vector<Episode> episodes;
    for (std::vector<std::string> columns : reader) {
        episodes.push_back(Episode(columns));
    }

    std::sort(episodes.begin(), episodes.end());

    std::cout << "number of episodes: " << episodes.size() << "\n\n";

    std::ofstream output_file("output.txt");
    for (auto& episode : episodes) {
        output_file << episode.title << " (" << episode.length << "m" << ")" << " - " << episode.score << "\n";
    }

    output_file << "\nThe most appreciated episodes:\n";
    std::vector<Episode> sorted_by_score(episodes);
    std::sort(sorted_by_score.begin(), sorted_by_score.end(), [](const Episode& a, const Episode& b) { return a.score > b.score || (a.score == b.score && a.title < b.title); });
    for (int i = 0; i < 10 && i < sorted_by_score.size(); ++i) {
        output_file << i + 1 << ". " << sorted_by_score[i].score << " -> " << sorted_by_score[i].title << "\n";
    }

    output_file << "\nThe longest episodes:\n";
    std::vector<Episode> sorted_by_length(episodes);
    std::sort(sorted_by_length.begin(), sorted_by_length.end(), [](const Episode& a, const Episode& b) { return a.length > b.length || (a.length == b.length && a.title < b.title); });
    for (int i = 0; i < 10 && i < sorted_by_length.size(); ++i) {
        output_file << i + 1 << ". " << sorted_by_length[i].length << "m" << " -> " << sorted_by_length[i].title << "\n";
    }
}