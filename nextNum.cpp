// ��һ������
// ��������,�ٴ��������ҵ���ת��׺

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> nextPermutation(vector<int>& nums) {
		if (nums.empty()) {
			return nums;
		}
		int left = nums.size();
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1]) {
				left = i;
				break;
			}
		}
		if (left == nums.size()) {
			std::reverse(nums.begin(), nums.end());
			return nums;
		}

		for (int i = nums.size() - 1; i >= 0; i--) {
			if (nums[i] > nums[left]) {
				mySwap(nums[i], nums[left]);
				break;
			}
		}
		reverse(nums.begin() + left + 1, nums.end());
		return nums;
	}

	void mySwap(int& a, int& b) {
		int temp = a ^ b;
		a = temp ^ a;
		b = temp ^ b;
	}
};

int main() {
	vector<int> nums{ 1,3,2 };
	Solution solution;

	auto result = solution.nextPermutation(nums);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}