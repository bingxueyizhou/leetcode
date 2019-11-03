/*
����һ���������� nums?��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ����?����?���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/two-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
