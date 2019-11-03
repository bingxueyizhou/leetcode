/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]
*/ 
#include "fen_ge_hui_wen_chuan.h"
#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	bool is_pal_number(string s){
	    int start = 0;
		int end   = s.size()-1;
		while(true){
		    if (start >= end){
		    	break;
			}
			
			if (s[start] == s[end]){
				start ++;
				end --;
				continue;
			}
			
			return false;
		}   
		
		return true;
	}
	
	void print_stack( vector<string> stack){
		cout<<"stack: ";
		for (int i = 0; i < stack.size(); i++){
  			cout<<stack[i]<<" ";
		}
	    cout<<endl;
	}
	
	void part_split(int idx, int end, string *s, vector<string> stack, vector<vector<string> > *ret){
        //cout<<"debug:"<<idx<<", "<<end << ", " << *s << endl;
		if (idx == end){
			//cout<<"test:"<<idx<<endl;
			//print_stack(stack);
			ret->push_back(stack);
			return;
		}
			
		for(int offset = 1; offset <= (end - idx); offset ++){
			string part_str = s->substr(idx, offset);
			//cout<<"substr["<<idx<<","<<offset<<"]:"<<part_str<<endl;
			if (is_pal_number(part_str)){
				stack.push_back(part_str);
				part_split(idx+offset, end, s, stack, ret);
				stack.pop_back();
			}
		}
	}

		 
    vector<vector<string> > partition(string s) {
    	vector<vector<string> > ret;
    	vector<string> stack;
			
		part_split(0, s.size(), &s, stack, &ret);
		return ret;
    }
};

void print( vector<vector<string> > vec){
	for (int i = 0; i < vec.size(); i++){
	    for(int j = 0; j <vec[i].size(); j++)
	        cout<<vec[i][j]<<" ";    
     	cout<<endl;
	}
    cout<<endl;
}

int main_leetcode(){
	Solution *so = new Solution();
	vector<vector<string> > ret = so->partition("aab");
	print(ret);
}
