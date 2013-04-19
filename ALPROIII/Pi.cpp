#include <cmath>
#include <cstdlib>
#include <iostream>

typedef long long ll;

void help() {
  std::cout << "Usage: pi2 <digits>" << std::endl;
  exit(1);
}

void pi(const long long digits) {
  ll q, r, t, k, n, l;
  q=1;
  r=0;
  t=1;
  k=1;
  n=3;
  l=3;
  for(ll i=0; i<digits; ++i) {
    if(4*q+r-t < n*t) {
      std::cout << n;
      q=10*q;
      r=10*(r-n*t);
      n = ( 10 * ( 3 * q + r) / t ) - 10 * n; //Thanks to maverik
    } else {
      q=q*k;
      r=(2*q+r)*l;
      t=t*l;
      k=k+1;
      n=(q*(7*k+2)+r*l)/(t*l);
      l=l+2;
    }
  }
}

int main(int argc, char** argv) {
  if(argc<2) help();
  ll digits = 0;
  if(digits=atoll(argv[1])<1) help();
  pi(digits);
  return 0;
}
