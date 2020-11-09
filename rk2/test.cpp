#include <bits/stdc++.h>

using namespace std;
struct point{
    double x, y, z;
};
bool cmp(point a, point b){
if(a.x != b.x)
        return a.x < b.x;
else if(a.y != b.y)
        return a.y < b.y;
else
        return a.z < b.z;

}
point half(point a, point b){
    point c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    c.x /= 2;
    c.y /= 2;
    c.z /= 2;
    return c;
}
int main()
{
    int n;
    cin >> n;
    vector <point> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a.begin(), a.end(), cmp);
    if(n % 2){
        int index = n / 2;
        point center = a[index];
        for(int i = 0; i < n; i++)
            if(half(a[i], a[n - i - 1]).x != center.x ||
               half(a[i], a[n - i - 1]).y != center.y ||
               half(a[i], a[n - i - 1]).z != center.z){
                   cout << "No";
                return 0;
               }
    }
    else {
        point center;
        center = half(a[0], a[n - 1]);
        for(int i = 0; i < n; i++)
            if(half(a[i], a[n - i - 1]).x != center.x ||
               half(a[i], a[n - i - 1]).y != center.y ||
               half(a[i], a[n - i - 1]).z != center.z){
                cout << "No";
                return 0;
               }

    }
    cout << "Yes";
    return 0;
}
