/*задача о покрытии строк(лекция 2)

-std=c++17
*/
#include <stdio.h>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

struct tree{
    enum {CHILDREN=4};
    tree *c[CHILDREN] {};
    bool end {false};
};

tree *build_tree(vector<string> const &pat){
    tree *root = new tree();
    for(auto const &str:pat){
        auto curr =root;
        for (auto c:str){
            assert(c>='a' && c< 'a'+tree::CHILDREN);
            if (curr->c[c-'a']==nullptr){
                curr->c[c-'a']=new tree();
            }
            curr=curr->c[c-'a'];
            assert(!curr->end);
        } // for auto c
        curr->end =true; //проверка на детей
    } //цикл по словам
   return root;
} //конец функии

bool check(const tree *root,string  const &s){
    auto curr =root;
    for(auto c:s){
        if (c<'a'||c>='a'+tree::CHILDREN || curr->c[c-'a']==nullptr) return false;
        curr=curr->c[c-'a'];
        if (curr->end) curr=root;
    }
    return curr==root;
}







int main(){
    string s= "abcaca";
    vector<string> w{"ab","ca"};
    tree *tre = build_tree(w);

return check(tre,s);
}
