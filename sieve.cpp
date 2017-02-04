#include <bits/stdc++.h>
using namespace std;

int sundaram[100005];
int eratosthenes[1000050];

int seive_of_sundaram(int n){
	int nn=(n-2)/2;
	
	for(int i=1;i<=nn;i++)
		for(int j=i;i+j+2*i*j<=nn;j++)
			sundaram[i+j+2*i*j]=1;
			
	if(n>2)
		cout<<"2 ";
	for(int i=1;i<=nn;i++)
		if(sundaram[i]==0)
			cout<<2*i+1<<" ";
	cout<<endl;
	return 0;
}

int seive_of_eratosthenes(int n){
	memset(eratosthenes,0,sizeof(eratosthenes));
	
	for(int i=2;i*i<=n;i++)
		if(eratosthenes[i]==0)
			for(int j=2*i;j<=n;j+=i)
				eratosthenes[j]=1;

	for(int i=2;i<=n;i++)
		if(eratosthenes[i]==0)
			cout<<i<<" ";
	cout<<endl;
	return 0;
}

int main(){
	int n;
	cin>>n;
	seive_of_sundaram(n); 
	seive_of_eratosthenes(n);
	return 0;
}