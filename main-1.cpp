#include <iostream>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

// Hàm tính hiệu số giữa số lớn nhất và số nhỏ nhất từ các chữ số của một số nguyên
long kaprekar(long n) {
    // tìm kiếm bội số của 9 lớn hơn hoặc bằng n và gần n nhất
    long k = ceil(n/9.0) * 9;
    
    // chạy vòng lặp
    while(true){
        
        // chuyển số là bội của 9 về dạng chuỗi
        string s = to_string(k);
        string temp = s;
        
        
        // sắp xếp lại chuỗi để tìm số nhỏ nhất của chuỗi
        sort(s.begin(), s.end());
        
        // sắp xếp lại chuỗi để tìm số lớn nhất của chuỗi
        sort(temp.begin(), temp.end(), greater<char>());
        
        // chuyển 2 chuỗi sang kiểu long
        long low = stoi(s);
        long upper = stoi(temp);
        
        // kiểm tra hiệu của số lớn nhất và nhỏ nhất nếu bằng k thì trả về số đó và kết thúc tính toán
        if (upper - low == k){
            return k;
        }
        
        // ngược lại tăng k lên và tiếp tục kiểm tra
        k += 9;
    }
}

int main() {
    long n;
    cin >> n;
    long t = kaprekar(n);
    cout << t;
}
