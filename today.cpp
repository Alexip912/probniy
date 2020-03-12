#include <bits/stdc++.h>

using namespace std; 

float fe(float x,int n){
  float pev=x;
  if(n==0)
  return 1;
  if(n==1)
  return x;
  for(int i=1;i<abs(n);i++){
  pev*=x;
  }
  if(n<0) pev=1./pev;
  return pev;
}
int main(){
	float a,b;
	int c;
	cin>>c>>a;
	b=fe(c,a);
	cout<<b<<endl;
 system("PAUSE");
return 0; 
}