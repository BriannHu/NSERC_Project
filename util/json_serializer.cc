#include "json_serializer.h"

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>

// Converts data structures to JSON strings.
// Supports four different maps that are relevant to current benchmarking.


 /*      EXAMPLE USE CASES

         std::vector<std::string> l_list;
         l_list.push_back("10");
         l_list.push_back("20");
         l_list.push_back("30");
         std::pair<std::vector<std::string>, long> l_pair (l_list, 3);
         std::cout << string_long_pair_to_string(l_pair) << std::endl;

         std::pair<long, std::pair<std::vector<std::string>, long>> big_pair1(1, l_pair);
         std::pair<long, std::pair<std::vector<std::string>, long>> big_pair2(2, l_pair);
         std::pair<long, std::pair<std::vector<std::string>, long>> big_pair3(3, l_pair);


         std::map<long, std::pair<std::vector<std::string>, long>> l_map1;
         l_map1.insert(big_pair1);
         l_map1.insert(big_pair2);
         l_map1.insert(big_pair3);

         std::pair<long, std::map<long, std::pair<std::vector<std::string>, long>>> bigger    _pair1(101, l_map1);
         std::pair<long, std::map<long, std::pair<std::vector<std::string>, long>>> bigger    _pair2(202, l_map1);
         std::map<long, std::map<long, std::pair<std::vector<std::string>, long>>> l_map2;
         l_map2.insert(bigger_pair1);
         l_map2.insert(bigger_pair2);

         std::pair<long, std::map<long, std::map<long, std::pair<std::vector<std::string>,     long>>>> biggest_pair1(1000, l_map2);
         std::pair<long, std::map<long, std::map<long, std::pair<std::vector<std::string>,     long>>>> biggest_pair2(2000, l_map2);

         std::map<long, std::map<long, std::map<long, std::pair<std::vector<std::string>,     long>>>> l_map3;
         l_map3.insert(biggest_pair1);
         l_map3.insert(biggest_pair2);

         std::cout << inner3_map_to_string(l_map3) << std::endl;

         std::cout << inner2_map_to_string(l_map2) << std::endl;

         std::cout << inner1_map_to_string(l_map1) << std::endl;

 */

std::string long_vector_to_string(std::vector<long> a_list) {
  if (a_list.empty()) return "[]";
  std::string output="[";
  std::string result="";
  for (const auto& value : a_list) {
          output += std::to_string(value) + ",";
  }
  result = output.substr(0, output.size()-1) + "]";
  return result;
}

std::string string_vector_to_string(std::vector<std::string> a_list) {
  if (a_list.empty()) return "[]";
  std::string output="[";
  std::string result="";
  for (const auto& value : a_list) {
          output += value + ",";
  }
  result = output.substr(0, output.size()-1) + "]";
  return result;
}
 
std::string long_long_map_to_string(std::map<long, long> m) {
  std::string output="{";
  std::string result="";
  for (auto const& value: m) {
          output += std::to_string(value.first) + ":" + std::to_string(value.second) + ",";
  }
  result = output.substr(0, output.size()-1) + "}";
  return result;
}
 
// inner-most map: key is actionID
std::string inner1_map_to_string(std::map<long, std::pair<std::vector<std::string>, long>> m) {
  std::string output="{";
  std::string result;
  
  for (auto const& value : m) {
          long id = value.first;
          std::pair<std::vector<std::string>, long> pair = value.second;
  
          output += std::to_string(id) + ":" + string_long_pair_to_string(pair) + ",";
  }
  result = output.substr(0, output.size()-1) + "}";
  return result;
}

 // second-inner most map: key is imageID
std::string inner2_map_to_string(std::map<long, std::map<long, std::pair<std::vector<std::string>, long>>> m) {
  std::string output="{";
  std::string result;
  
  for (auto const& value : m) {
          long id = value.first;
          std::string inner_map = inner1_map_to_string(value.second);
  
          output += std::to_string(id) + ":" + inner_map + ";";
  
  }
  result = output.substr(0, output.size()-1) + "}";
  return result;
}

  // outer-most most: key is userID
std::string inner3_map_to_string(std::map<long, std::map<long, std::map<long, std::pair<std::vector<std::string>, long>>>> m) {
  std::string output = "{";
  std::string result;
  
  for (auto const& value : m) {
    long id = value.first;
    std::string inner_map = inner2_map_to_string(value.second);
    output += std::to_string(id) + ":" + inner_map + ",";
  }
  result = output.substr(0, output.size()-1) + "}";
  return result;
}

std::string string_long_pair_to_string(std::pair<std::vector<std::string>, long> p) {
  std::string result="(";

  std::vector<std::string> v_list = p.first;
  long counter = p.second;

  result += string_vector_to_string(v_list) + "|" + std::to_string(counter) + ")";
  return result;
}


std::string user_annotation_to_string(long user, long annotation) {
  std::string result="(" + std::to_string(user) + "," + std::to_string(annotation) + ")";
  return result;
}
