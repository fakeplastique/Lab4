//Bondar Ihor, K-15, Variant 8 
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

bool parse_line(const std::string& line, int& day, int& pair_num, std::string& subject, int& room_num) {
    std::stringstream ss(line);
    char c1, c2;
    return (ss >> day >> c1 >> pair_num >> c2) && c1 == ',' && c2 == ',' &&
           std::getline(ss, subject, ',') && (ss >> room_num) &&
           day >= 1 && day <= 5 && pair_num >= 1 && pair_num <= 4;
}

void print_results(const std::map<int, int>& room_count, int total) {
    int max_pairs = 0;
    for (const auto& p : room_count)
        max_pairs = std::max(max_pairs, p.second);
    
    std::vector<int> rooms;
    for (const auto& p : room_count)
        if (p.second == max_pairs) rooms.push_back(p.first);
    
    std::sort(rooms.begin(), rooms.end());
    
    std::cout << "*****\n" << total << "\n" << rooms.size() << "\n" << max_pairs << "\n";
    for (int r : rooms) std::cout << r << "\n";
}

int main() {
    std::map<int, int> room_count;
    int count_entries = 0;
    std::string line;
    
    while (std::getline(std::cin, line)) {
        int day, pair_num, room_num;
        std::string subject;
        
        if (!parse_line(line, day, pair_num, subject, room_num))
            break;
        
        room_count[room_num]++;
        count_entries++;
    }
    
    print_results(room_count, count_entries);
    return 0;
}
