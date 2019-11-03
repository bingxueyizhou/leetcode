/*
给定一个整数数组 nums?和一个目标值 target，请你在该数组中找出和为目标值的那?两个?整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<iostream>
#include<vector>
#include<map>
#include "liang_shu_zhi_he.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	map<int,int> map;
    	vector<int> ret(2,-1);
        for(int i = 0; i < nums.size(); i++){
        	int value = target - nums[i];
        	if (map.count(target - nums[i]) > 0){
        		ret[0] = map[target - nums[i]];
        		ret[1] = i;
        		return ret;
			}
			map[nums[i]] = i;
		}
		return ret;
    }
    
    vector<int> twoSum_mine(vector<int>& nums, int target) {
    	vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
			for (int j = i+1; j < nums.size(); j ++){
				if ( target == nums[i] + nums[j] ){
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}
        return ret;
    }
};

void print(vector<int> vec){
	for(int i = 0; i < vec.size(); i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

int main_leetcode(){
	Solution *so = new Solution();
	int myarray[5] = {2,7,11,15};  
	vector<int> nums(myarray , myarray+4); 
	vector<int> ret = so->twoSum(nums, 9);
	print(ret);
}
