
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol1065
{

  class Solution
  {
  private:
    Node *buildTrie(const vector<string> &words);

  public:
    vector<vector<int>> findPairs(string S, vector<string> &words);
  };
}
#endif