#ifndef MINT_H
#define MINT_H
#include<iostream>
template<int P>
struct mint{
	int d;
	mint()=default;
	mint(int x):d(x){}
	explicit operator bool()const{return bool(d);};
	friend std::istream&operator>>(std::istream&x,mint&y){return x>>y.d;}
	friend std::ostream&operator<<(std::ostream&x,mint y){return x<<y.d;}
	friend mint operator+(mint x,mint y){return (x.d+=y.d)<P?x.d:x.d-P;}
	friend mint operator-(mint x,mint y){return (x.d-=y.d)<0?x.d+P:x.d;}
	friend mint operator*(mint x,mint y){return int(1ll*x.d*y.d%P);}
	static mint qp(mint x,int y=P-2){mint z=1;for(;y;y>>=1,x*=x)if(y&1)z*=x;return z;}
	friend mint operator/(mint x,mint y){return x=x*qp(y);}
	friend mint operator^(mint x,int y){return qp(x,y);}
	mint&operator+=(mint z){return (*this)=(*this)+z;}
	mint&operator-=(mint z){return (*this)=(*this)-z;}
	mint&operator*=(mint z){return (*this)=(*this)*z;}
	mint&operator/=(mint z){return (*this)=(*this)/z;}
	mint&operator^=(int z){return (*this)=(*this)^z;}
	mint operator()(int z)const{return (*this)^z;}
	mint&operator[](int z){return (*this)=(*this)^z;}
	mint inv()const{return qp(d);}
	mint pow(int z)const{return (*this)^z;}
	int operator+()const{return d;}
	mint operator-()const{return P-d;}
	int operator~()const{return ~d;}
};
#endif