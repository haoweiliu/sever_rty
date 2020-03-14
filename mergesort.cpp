#include<iostream>
#include<vector>
using namespace std;

void mergesort(vector<int>& data, vector<int>& copy, int start, int end){
	if(start < end){
	int mid = (start+end)/2;
	mergesort(copy,data,start,mid);
	mergesort(copy,data,mid+1,end);
	int l = mid, r = end, k = end;
	while(l >= start && r > mid){
		if(data[l] < data[r])
			copy[k--] = data[r--];
		else 
			copy[k--] = data[l--];
	}
	while(l >= start)
		copy[k--] = data[l--];
	while(r > mid)
		copy[k--] = data[r--];	
	}
}

int main(){
	int n,num;
	vector<int> copy,data;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>num;
		copy.push_back(num);
		data.push_back(num);
	}
	mergesort(copy,data,0,n-1);
	for(int i = 0; i < n; i++)
		cout<<data[i]<<endl;
	return 0;
}
