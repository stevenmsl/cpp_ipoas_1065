#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1065;

/*
Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]
*/

tuple<string, vector<string>, vector<vector<int>>>
testFixture1()
{
  auto text = string("thestoryofleetcodeandme");
  auto words = vector<string>{"story", "fleet", "leetcode"};
  auto output = vector<vector<int>>{
      {3, 7}, {9, 13}, {10, 17}};

  return make_tuple(text, words, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.findPairs(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  return 0;
}