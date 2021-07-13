#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> coupon;
vector<int> product;
bool cmp1(int a,int b){
	return a<b;
}
int main()
{
	int max=0;
	int nc,np;
	scanf("%d",&nc);   //nc个coupons 
	coupon.resize(nc);
	for(int i=0;i<nc;i++)
		scanf("%d",&coupon[i]);
	scanf("%d",&np);   //np个product 
	product.resize(np);
	for(int i=0;i<np;i++)
		scanf("%d",&product[i]);
	sort(coupon.begin(),coupon.end(),cmp1);    //从高到低排序 
	sort(product.begin(),product.end(),cmp1); 
	int q=0,p=0;
	while(coupon[q]<0&&product[p]<0){
		max+=coupon[q]*product[p];
		q++;
		p++;
	} 
	q=coupon.size()-1;
	p=product.size()-1;
	while(coupon[q]>0&&product[p]>0){
		max+=coupon[q]*product[p];
		q--;
		p--;
	}
	printf("%d",max);
	return 0;
	
} 
