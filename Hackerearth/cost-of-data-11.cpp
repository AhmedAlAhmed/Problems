#include <bits/stdc++.h>
using namespace std;

/*
 *     Coded by : Ahmed Al-Ahmed
 *     se.ahmedalahmed@hotmail.com
 */
struct Node
{
    char c;
    int count;
    bool flag;
    map<char, Node*> next;
    Node(char ch)
    {
        c = ch;
        count = 0;
        flag = false;
    }
};


long long sum = 0;

void insert(string str, Node* root)
{
    for(int i=0;i<str.length();i++)
    {
        if(root->next.find(str[i]) ==   root->next.end())
        {
            root->next[str[i]] = new Node(str[i]);
            sum++;
        }
        root->count++;

        root = root->next[str[i]];
        if(i == str.length()-1)
        {
            root->flag = true;
            return;
        }
    }
}
/*
bool isWord(string str, Node* root)
{
    for (int var = 0; var < str.length(); ++var) {
        if(root->next.find(str[var]) == root->next.end())
            return false;

        root = root->next[str[var]];
        if(var == str.length()-1)
            return root->flag;
    }
    return false;

}

bool isPrefix(string str, Node* root)
{
    for (int var = 0; var < str.length(); ++var) {
        if(root->next.find(str[var]) == root->next.end())
            return false;

        root = root->next[str[var]];
    }
    return true;
}
*/
int main()
{
    Node* root = new Node('\0');

    int n;
    cin >> n;
    string str;
    while(n--)
    {
        cin >> str;
        insert(str, root);
    }

    cout << (sum+1) << endl;

    return 0;
}
