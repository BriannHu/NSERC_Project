#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <map>
#include <vector>

std::string long_vector_to_string(std::vector<long> a_list);

std::string string_vector_to_string(std::vector<std::string> a_list);

std::string UAS_map_to_string(std::map<long, long> m);

std::string long_long_map_to_string(std::map<long, long> m);

std::string inner1_map_to_string(std::map<long, std::pair<std::vector<std::string>, long>    > m);

std::string inner2_map_to_string(std::map<long, std::map<long, std::pair<std::vector<std:    :string>, long>>> m);

std::string inner3_map_to_string(std::map<long, std::map<long, std::map<long, std::pair<s    td::vector<std::string>, long>>>> m);

std::string string_long_pair_to_string(std::pair<std::vector<std::string>, long> p);

std::string user_annotation_to_string(long user, long annotation);
