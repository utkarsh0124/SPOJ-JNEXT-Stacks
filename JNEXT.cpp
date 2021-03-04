#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

//Contributed By: utkarsh0124@gmail.com
//github: utkarsh0124

int main(){
	fastIO
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++) cin>>arr[i];
		
		//solution
		if(n==1) cout<<-1<<'\n';
		else{
			int index = -1;
			for(int i=n-2; i>-1; i--){
				if(arr[i]<arr[i+1]){
					index =i;
					break;
				}
			}
			if(index<0) cout<<-1<<'\n';
			else{
				stack<int> s1,s2;
				int i=index+1;
				
				while(i<n){
					if(arr[i]<=arr[index]) break;
					s1.push(arr[i]);
					i++;
				}
				while(i<n){
					if(arr[i]<=arr[index]) s2.push(arr[i]);
					i++;
				}
				
				int tmp = arr[index];
				arr[index] = s1.top();
				s1.pop();
				s1.push(tmp);
				
				while(!s2.empty()){
					arr[index+1]=s2.top();
					s2.pop();
					index++;
				}
				while(!s1.empty()){
					arr[index+1]=s1.top();
					s1.pop();
					index++;
				}
				for(int j:arr) cout<<j;
				cout<<'\n';
			}
		}		
		
	}
	return 0;
}
