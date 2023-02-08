#include<iostream>
using namespace std;
int main(){
	int n,a[n];
	cin>>n;
	int sum=0;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	cout<<sum;
}
