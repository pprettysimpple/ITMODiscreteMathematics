//
// Created by kirill on 06.11.2019.
//

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

int main() {
    std::ifstream fin;
    std::ofstream fout;
    fin.open("lzw.in");
    fout.open("lzw.out");

    std::vector<std::string> dictionary;
    for (int i = 0; i < 26; i++) {
        std::string temp;
        temp += char(97 + i);
        dictionary.push_back(temp);
    }

    std::string input;
    fin >> input;

    for (int i = 0; i < input.size(); i++) {
        std::string comb;
        comb += input[i];
        if (i == input.size() - 1) {
            fout << std::find(dictionary.begin(), dictionary.end(), comb) - dictionary.begin() << ' ';
        } else {
            for (int j = i + 1; j < input.size(); j++) {
                if (std::find(dictionary.begin(), dictionary.end(), comb + input[j]) == dictionary.end()) {
                    dictionary.push_back(comb + input[j]);
                    fout << std::find(dictionary.begin(), dictionary.end(), comb) - dictionary.begin() << ' ';
                    i = j - 1;
                    break;
                } else {
                    comb += input[j];
                }
            }
        }
    }

    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}