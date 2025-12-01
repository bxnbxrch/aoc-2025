#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include "inttypes.h"
#include <algorithm>


// wrapping clamp function.
// wraps value around a min and max instead of std::clamp
template <typename T>
constexpr T wrap(T val, T min, T max){

    static_assert(std::is_integral_v<T>, "wrap only supports integers");
    T range = max - min + 1;

    if(range <= 0)
        return min;

    val = (val - min) % range;
    if(val < 0) val += range;
    return val + min;
}


// function to open file and read into std::vector
auto read_file_lines(const std::filesystem::path& path) -> std::vector<std::string> {
    
    std::ifstream ifs ( path );

    if(!ifs) throw std::runtime_error("File does not exist: " + path.string());
    
    std::vector<std::string> lines;

    for( std::string line; std::getline(ifs, line); ) 
        lines.push_back(line);

    return lines;
}


// start at 50
// wrap at 0 and 100
// count amount of times it lands on 0
// L means -, R means + 
// e.g. L23
int main(){

    constexpr int   START_IDX       = 50;
    constexpr int   MIN_IDX         = 0;
    constexpr int   MAX_IDX         = 99;
    
    
    int             current_idx =   START_IDX;
    size_t          zero_count =    0;
    
    const auto input = read_file_lines(std::filesystem::current_path() / "input.txt");


    for(std::string_view line : input){
        char direction = line.front();
        int dist = std::stoi(std::string(line.substr(1)));
        current_idx += (direction == 'R') ? dist : -dist;
        current_idx = wrap(current_idx, MIN_IDX, MAX_IDX);

        if(current_idx == 0)
            zero_count++;
    }

    printf("answer: %ld", zero_count);

    
}


