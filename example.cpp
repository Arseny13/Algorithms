#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> v(5,0);
    vector<int>::iterator iter;
    for(iter = v.begin();iter!=v.end();++iter){
       cout << ++(*iter)<<endl;

    }
    return 0;
}
