/*By Cebastian Santiago 
* Leetcode 128
*/
#include<iostream>
#include<vector>
#include<set>

int longestConsecutive(std::vector<int>& nums) {
	//if vector empty return 0
	if (nums.empty()){
		return 0;
	}

	
	//variables
	std::set<int> sets;
	int count = 0;
	int big = 0;
	//insert the element into the sets
	for (size_t i = 0; i < nums.size(); i++) {
		sets.insert(nums[i]);
	}


	//check the set
	for (size_t i = 0; i < nums.size(); i++) {
		//1.check if the elment has no left neighbor
		int numbers = nums[i] - 1;
		auto it = sets.find(numbers);


		//2.if the auto returns end that means were at the start of the set
		if (it == sets.end()){
			count++;
			int up = nums[i] + 1;
			it = sets.find(up);

			while (it != sets.end()){
				count++;
				up++;
				it = sets.find(up);
			}
		}

		//if count is ever the size of the vector that means weve loop
		//throught the set
		if (count == nums.size()-1){
			return count;
		}

		big = std::max(big, count);


		if (it == sets.end()){
			count = 0;
		}
		
	}
	return big;
}

int main() {
	std::vector<int> num = { 100,4,200,1,3,2 };

	std::cout << longestConsecutive(num) << std::endl;

	return 0;
}