# mint

Provides operators overloading for int type in modulo sense.

```cpp
constexpr int P=998244353;
mint<P>a=300000000;
for(int i=1;i<=5;i++){
	cout<<a*i<<' '<<(a^i)<<'\n';
}
```