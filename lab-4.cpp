#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double my_sqrt(double x) {
  if (x < 0) {
    return NAN;
  }
  double left = 0, right = x + 1;

  for (int i = 0; i < 20; i++) {
    double middle = (left + right) / 2;
    if (middle * middle < x) {
      left = middle;
    } else {
      right = middle;
    }
  }

  return left;
}
int main() {
    long long n;
    cin >> n;

    ofstream outfile("lab4");  
   
    long long sum = n * (n + 1) / 2;

    if (sum % 2 != 0) {
        outfile << "NO" << endl;
        outfile.close();
        return 0;
    }

    outfile << "YES" << endl;

    long long half_sum = sum / 2;
    long long x = (my_sqrt(1 + 8 * half_sum) + 1) / 2;

    long long current_sum = x * (x + 1) / 2; 
    long long t = current_sum - half_sum;

    outfile <<  "Petya: " << x - (t > 0) << " тарелок" << endl;
    for (long long i = 1; i <= x; i++) {
        if (i != t) 
        outfile << i << " ";
    }
    outfile << endl;

    outfile <<  "Masha: "<< n - (x - (t > 0)) << "тарелок "  << endl;
    for (long long i = x + 1; i <= n; i++) {
        outfile << i << " ";
    }
    if (t > 0) 
    outfile << t << endl;;

    outfile.close();
    return 0;
}
