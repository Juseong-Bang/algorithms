	#include<iostream>
	using namespace std;
	int main ()
	{
		int h[1024],w,n[1024];
		int k=0;
		cin>>k;
		for(int p=0;p<k;p++){
			cin>>h[p]>>w>>n[p];
		}
		for(int p=0;p<k;p++){

			cout<<n[p]%h[p];
			cout.fill('0');
			cout.width(2);
			if(h[p]==0)
				h[p]=1;
			
			cout<<(n[p]/h[p])+1<<endl;		

		}

	}
