#include <iostream>
#include <vector>
#include <bitset>
#include <iterator>
#include <algorithm>
#include <functional>

template<int N>
std::ostream & operator<<(std::ostream & os, const std::bitset<N> & bset) {
  os << bset.to_string();
  return os;
}

// solution 1
// class solution {
// public:
//   int findMaximumXOR(std::vector<int> & nums) {
//     std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, "\t"));
//     std::cout << std::endl;
//     std::vector<std::bitset<6>> temp(nums.begin(), nums.end());
//     std::copy(temp.begin(), temp.end(), std::ostream_iterator<std::bitset<6>>(std::cout, " "));
//     std::cout << std::endl;

//     std::vector<std::bitset<32>> bins(nums.begin(), nums.end());
//     size_t mIdx = std::distance(nums.begin(), std::max_element(nums.begin(), nums.end()));
//     auto mBin = bins[mIdx];
//     int first = mBin.size()-1;
//     while (first >= 0 && mBin[first] == 0)
//       first--;

//     std::vector<int> same;
//     same.reserve(nums.size());
//     for (size_t i = 0; i < bins.size(); ++i) {
//       int idx = first;
//       while (idx >= 0 && bins[i][idx] != mBin[idx])
// 	idx--;
//       same.push_back(idx);
//     }

//     auto it = std::min_element(same.begin(), same.end());

//     std::cout << "The two numbers found are:\n"
// 	      << nums[std::distance(same.begin(), it)] << ", " << nums[mIdx] << std::endl;
//     return std::bit_xor<int>()(nums[std::distance(same.begin(), it)], nums[mIdx]);
//   }
// };

// solution 2
// class solution {
// public:
//    int findMaximumXOR(std::vector<int> & nums) {
//      int result;
//      if (nums.size() == 2)
//        result = std::bit_xor<int>()(nums.front(), nums.back());
//      else {
//        std::vector<int> cands;
//        std::vector<int> rest(nums.begin()+1, nums.end());
//        for (size_t i = 0; i < rest.size(); ++i)
// 	 cands.push_back(std::bit_xor<int>()(nums[0], rest[i]));
//        cands.push_back(findMaximumXOR(rest));
//        result = *std::max_element(cands.begin(), cands.end());
//      }
//      return result;
//    }
// };

// solution 3
class solution {
public:
  int findMaximumXOR(std::vector<int> & nums) {
    // std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, "\t"));
    // std::cout << std::endl;
    // std::vector<std::bitset<6>> temp(nums.begin(), nums.end());
    // std::copy(temp.begin(), temp.end(), std::ostream_iterator<std::bitset<6>>(std::cout, " "));
    // std::cout << std::endl;

      std::vector<std::bitset<32>> bins(nums.begin(), nums.end());
      size_t mx = std::distance(nums.begin(), std::max_element(nums.begin(), nums.end()));
      size_t highest = bins[mx].size()-1;
      while (bins[mx][highest] == 0)
          highest--;

      std::vector<std::bitset<32>> large, small;
      for (size_t i = 0; i < bins.size(); i++) {
          if (bins[i][highest] == 1)
              large.push_back(bins[i]);
          else
              small.push_back(bins[i]);
      }
  }
};


int main() {
  std::vector<int> nums{3,10,5,25,2,8};
  // std::vector<int> nums{1,3,2,4,6,10,9};
  
  solution soln;
  int result = soln.findMaximumXOR(nums);
  std::cout << "The largest XOR of two numbers is:\n"
	    << result << std::endl;
}
