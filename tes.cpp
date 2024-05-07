#include <iostream>
#include <string>
using namespace std;


int main()
{
    string s = "ASFdfdfDGgfdg";
    string t = "";

    for (char c : s) t += tolower(c);
    
    cout << s << '\n';
    cout << t << '\n';

    for (int i = 0; i < s.length(); ++i) 
    {
        s[i] = tolower(s[i]);
    }

    cout << s << '\n';

    // char c;
    // cin >> c;
    // cout << c << '\n';

    string str[5] = {"dsfcdsf", "Sdfdf", "SDfetgh"};

    cout << str[1] << '\n';
    cin >> str[1];
    cout << str[1] << '\n';

    return 0;
}