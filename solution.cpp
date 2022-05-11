#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <bitset>
using namespace sol1065;
using namespace std;

/*takeaways
  - build a Tire tree from the words
  - search the tree using the following prefixes
    S[0..n-1], S[1..n-1]...S[n-1..n-1]
*/
Node *Solution::buildTrie(const vector<string> &words)
{
  auto root = new Node();
  for (auto w : words)
  {
    auto visit = root;
    for (auto c : w)
    {
      auto idx = c - 'a';
      if (visit->children[idx] == nullptr)
        visit->children[idx] = new Node();
      visit = visit->children[idx];
    }
    visit->isWord = true;
  }

  return root;
}

vector<vector<int>> Solution::findPairs(string S, vector<string> &words)
{
  auto tire = buildTrie(words);
  auto result = vector<vector<int>>();
  for (auto i = 0; i < S.size(); i++)
  {
    auto visit = tire;
    /* for the prefix S[i..n-1] see if
       we can find any words in the tree
    */
    for (auto j = i; j < S.size() && visit != nullptr; j++)
    {
      auto idx = S[j] - 'a';
      visit = visit->children[idx];
      /* find a word using prefix s[i..j] */
      if (visit != nullptr && visit->isWord)
        result.push_back({i, j});
    }
  }
  return result;
}