#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
/////////////////////////////////////////
// INCLUDE NECESSARY HEADER FILES HERE //
/////////////////////////////////////////

using namespace std;

void func_map (vector<pair<int,string>>& items)
{
  cout << endl << "=== BEGIN func_map ===" << endl;

  ////////////////////////////////////////////////
  // CREATE AN EMPTY map MAPPING int TO string. //
  ////////////////////////////////////////////////

  std::map<int, std::string> thisMap;


  ////////////////////////////////////////////
  // USING A RANGE-BASED for(...) LOOP,     //
  // INSERT EACH ITEM IN items INTO THE MAP //
  ////////////////////////////////////////////

  for (auto const& item : items) {
    thisMap[item.first] = item.second;
  }


  //////////////////////////////////////////////
  // USING A RANGE-BASED for(...) LOOP,       //
  // PRINT OUT EACH KEY-VALUE PAIR IN THE MAP //
  //////////////////////////////////////////////

    for (auto const& [key, value] : thisMap) {
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
  }



  cout << endl << "=== END func_map ===" << endl;
}

void func_unordered_map (vector<pair<int,string>>& items)
{
  cout << endl << "=== BEGIN func_unordered_map ===" << endl;

  //////////////////////////////////////////////////////////
  // CREATE AN EMPTY unordered_map MAPPING int TO string. //
  //////////////////////////////////////////////////////////
  
  std::unordered_map<int, std::string> thisUnorderedMap;


  /////////////////////////////////////////////
  // USING A RANGE-BASED for(...) LOOP,      //
  // INSERT EACH ITEM IN items INTO THE MAP. //
  // AFTER EACH INSERTION, PRINT OUT:        //
  //   o  THE SIZE OF THE MAP                //
  //   o  THE NUMBER OF BUCKETS              //
  //   o  THE LOAD FACTOR                    //
  // IN THE FOLLOWING FORMAT:                //
  //   o  "[N,B,LF] = [3,10,0.4432]"         //
  /////////////////////////////////////////////
  
    for (auto const& item : items) {
    thisUnorderedMap[item.first] = item.second;
    
  std::cout << "[" << thisUnorderedMap.size() << ", " << thisUnorderedMap.bucket_count() << ", "
  << thisUnorderedMap.load_factor() << "]" << std::endl;
  }
  
  


  ///////////////////////////////////////////////
  // USING A RANGE-BASED for(...) LOOP,        //
  // PRINT OUT EACH KEY-VALUE PAIR IN THE MAP. //
  ///////////////////////////////////////////////


  cout << endl << "=== END func_unordered_map ===" << endl;
}

int main ()
{
  vector<pair<int,string>> items = {
    {3, "three"},
    {13, "thirteen"},
    {2, "two"},
    {7, "seven"},
    {11, "eleven"},
    {20, "twenty"},
    {5, "five"},
    {96, "ninety six"},
    {97, "ninety seven"},
    {23, "twenty three"},
    {4, "four"},
    {59, "fifty nine"},
    {17, "seventeen"},
    {1, "one"}
  };

  func_map(items);
  func_unordered_map(items);

  return 0;
}


