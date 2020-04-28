#include<iostream>
#include<string>
using namespace std;
int* KMP(string s)
{
	int length1 = s.length();
	int next[100];
	int k = -1;
	int j = 0;
	next[0] = -1;
	while (1)
	{
		if (j >= s.length())
		{
			break;
		}
		if ( k == -1||s[k] == s[j])
		{
			//ABABDABDE
			k++;    //k标记记录的是前缀
			j++;   //j标记记录的是后缀 
			/*
			  如果当前位置相等的话
			  那么说明 如果在 j+1位置不匹配的话 可以 直接比较k+1的位置 
			  所以 next[j] = k
			*/
			next[j] = k;
		}
		else
		{
			/*
			  如果当前位置的两个不相等的话
			  那么需要找到 k 位置的上一个匹配点 
			  就是 如果 k位置不相等的话 比较 next[k]位置
			*/
			k = next[k];
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		cout << next[i] << endl;
	}
	return next;
};
int* KMPFATHER(string s)
{

    /*
		为了理解kmp 
		从kmp的根源出发
		即找到当前位置 与前一个位置的后缀相同的长度 

	*/
	int length1 = s.length();
	int next[100];
	int k = 0;//记录前缀
	int j = 1;//记录后缀
	next[0] = 0; //默认0号位置为0 方便while循环回滚的时候判断当前已无可匹配项 将 j 后移
	while (1)
	{
		if (j >= s.length())
		{
			break;
		}
		if (s[j] == s[k])  // 判断当前 s[j] 与 s[k]是否相等 如果相等那么 说明 当前位置 相同元素有 k+1个 然后将j 后挪
		{
			k++;
			next[j] = k;
			j++;
		}
		else {
			if (k == 0 || k == -1) // 判断当前 k是否是0 如果k是0 说明当前位置没有前缀后缀相等 则 j后移 
			{
				next[j] = k;
				j++;
				continue;
			}
			k = (next[k]-1)+1;//这么写比较明白 这个是记录的相同的个数 但是下标是从0开始的 比如 有1个相同的 那么 就要从第二个位置开始比 0-1+1
			//如果当前位置 存在k有 比如 ababdabde 中的第二个b 那么 
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		cout << next[i] << endl;
	}
	return next;
}
int main()
{
	int *a;//= new int[100];
	a = KMPFATHER("ababdabde");
	cout << a[5] << endl;
	system("pause");
}