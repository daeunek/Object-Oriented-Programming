#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include<map>

class Mapper {
public:
    std::vector<std::pair<std::string, int>> map(const std::string& filename) {
        std::ifstream file(filename);
        std::vector<std::pair<std::string, int>> pairs;
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                processLine(line, pairs);
            }
            file.close();
        } else {
            std::cerr << "Error: Unable to open file." << std::endl;
        }
        return pairs;
    }

private:
    void processLine(const std::string& line, std::vector<std::pair<std::string, int>>& pairs) {
        std::string word;
        for (char c : line) {
            if (c == ' ' || c == '\t' || c == '\n') {
                if (!word.empty()) {
                    pairs.emplace_back(word, 1);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            pairs.emplace_back(word, 1);
        }
    }
};

class Reducer {
public:
    void reduce(const std::map<std::string, std::vector<int>>& grouped_pairs) {
        for (const auto& pair : grouped_pairs) {
            int sum = 0;
            for (int count : pair.second) {
                sum += count;
            }
            std::cout << pair.first << " " << sum << std::endl;
        }
    }

    void saveToFile(const std::map<std::string, std::vector<int>>& grouped_pairs, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& pair : grouped_pairs) {
                int sum = 0;
                for (int count : pair.second) {
                    sum += count;
                }
                file << pair.first << " " << sum << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Error: Unable to create output file." << std::endl;
        }
    }
};

bool compare(const std::pair<std::string, int> &a, const std::pair<std::string, int>&b) {
        return a.second < b.second;
}

int main() {
    std::string filename;
    std::cout << "Enter the name of the text file: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: File does not exist." << std::endl;
        return 1;
    }

    Mapper mapper;
    std::vector<std::pair<std::string, int>> pairs = mapper.map(filename);

    // Sort the pairs by word

    std::sort(pairs.begin(), pairs.end(), compare);

    // Group the pairs by key (word)
    std::map<std::string, std::vector<int>> grouped_pairs;
    for (const auto& pair : pairs) {
        grouped_pairs[pair.first].push_back(pair.second);
    }

    Reducer reducer;
    reducer.reduce(grouped_pairs);

    std::string output_filename = filename;
    output_filename.insert(output_filename.find_last_of('.'), "_mr");
    reducer.saveToFile(grouped_pairs, output_filename);

    std::cout << "Word count results have been saved to " << output_filename << std::endl;

    return 0;
}
