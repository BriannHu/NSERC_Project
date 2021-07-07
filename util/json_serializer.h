#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <map>
#include <vector>

// Returns string form of input long vector.
// Note: String will use square [] brackets instead of curly {} brackets.
// These brackets differentiates the string from a stringified map.
// This is used to create the values for Map1.
std::string long_vector_to_string(std::vector<long> a_list);

// Returns string form of input string vector..
// Note: String will use square [] brackets instead of curly {} brackets.
// These brackets differentiates the string from a stringified map.
// This is used to build the string in string_long_pair_to_string().
std::string string_vector_to_string(std::vector<std::string> a_list);

// Returns string form of map with long key and long value.
// This is used to create the values for Map4.
std::string long_long_map_to_string(std::map<long, long> m);

// Returns string form of one "level deep" map.
// Input map is in form {ID: ([timestamps], counter)...}
// This is used for the inner-most maps of Map2 and Map3.
std::string inner1_map_to_string(std::map<long, std::pair<std::vector<std::string>, long>> m);

// Returns string form of two "level deep" map.
// Input map is in form {ID: {ID: ([timestamps], counter)...}...}
// This is used for the final values of Map2 and Map3.
std::string inner2_map_to_string(std::map<long, std::map<long, std::pair<std::vector<std::string>, long>>> m);

std::string inner3_map_to_string(std::map<long, std::map<long, std::map<long, std::pair<std::vector<std::string>, long>>>> m);

// Returns string form of pair with string vector and long.
// Input is in form ([timestamps], counter)
// This is used to build the string in inner1_map_to_string and inner2_map_to_string.
std::string string_long_pair_to_string(std::pair<std::vector<std::string>, long> p);

// Returns string form similar to tuple given two input longs.
// This is used to create the keys for Map4 (only Map to have a key that isn't a long).
std::string user_annotation_to_string(long user, long annotation);
