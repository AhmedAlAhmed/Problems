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


//long long sum = 0;

void insert(string str, Node* root)
{
    for(int i=0; i<str.length(); i++)
    {
        if(root->next.find(str[i]) ==   root->next.end())
        {
            root->next[str[i]] = new Node(str[i]);
            //sum++;
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


bool isPrefix(string str, Node* root)
{
    for (int var = 0; var < str.length(); ++var)
    {
        if(root->next.find(str[var]) == root->next.end())
            return false;

        root = root->next[str[var]];
    }
    return true;
}

vector<string> vec;


void dfs(string str, Node* root)
{
    
    
    
    for(int i=0;i<26;i++)
    {
        char ch = 'a' + i;
        
        if(root->next.find(ch) != root->next.end())
        {
            // found current letter.
            str.push_back(ch);
            Node* newRoot = root->next[ch];
            dfs(str, newRoot);
            str.pop_back();
        }
    }
    if(root->flag)
    {
        vec.push_back(str);
        return ;
    }
    
    
}

void getAnswer(string str, Node* root)
{
    // Search for the first intersections point .
    for (int var = 0; var < str.length(); ++var)
    {
        root = root->next[str[var]];
    }
    // now root at intersection point , we should to try all chars.
    
   
    dfs(str, root);
   

    sort(vec.begin(), vec.end());
    
    for(int i=0;i<vec.size();i++)
    {
        if(i > 0 && vec[i] != vec[i-1])
            cout << vec[i] << endl;
        if(i == 0)
            cout << vec[i] << endl;
    }


}

string str;

int main()
{
    
    //freopen("input.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    Node* root = new Node('\0');

    int n;
    cin >> n;

    while(n--)
    {
        cin >> str;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        insert(str, root);
    }
    int q;
    cin >> q;
    while(q--)
    {
        
        Node* alt = root;
        vec.clear();
        cin >> str;
        
        if(!isPrefix(str, alt))
        {
            insert(str, root);
            cout << "No suggestions" << endl;
            continue;
        }
        
        getAnswer(str, alt);
        
    }


    return 0;
}
