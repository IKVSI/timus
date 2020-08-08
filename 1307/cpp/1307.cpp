#include <iostream>
using namespace std;

void encode(char * c)
{
    cout<<"f(\"";
    for(int i=0; c[i]!=0; ++i)
    {
        if(c[i] == '\r') continue;
        else if(c[i] == '\n') cout<<char(128);
        else if(c[i] == '\t') cout<<char(129);
        else if(c[i] == '\"') cout<<char(130);
        else if(c[i] == '\'') cout<<char(131);
        else if(c[i] == '\\') cout<<char(132);
        else if((c[i] == 'e')&&(c[i+1] == ' ')) { cout<<char(133); ++i;}
        else if((c[i] == ' ')&&(c[i+1] == 't')) { cout<<char(134); ++i;}
        else if((c[i] == 't')&&(c[i+1] == 'h')) { cout<<char(135); ++i;}
        else if((c[i] == 's')&&(c[i+1] == ' ')) { cout<<char(136); ++i;}
        else if((c[i] == ' ')&&(c[i+1] == 'a')) { cout<<char(137); ++i;}
        else if((c[i] == 'r')&&(c[i+1] == 'e')) { cout<<char(138); ++i;}
        else if((c[i] == 'h')&&(c[i+1] == 'e')) { cout<<char(139); ++i;}
        else if((c[i] == 't')&&(c[i+1] == ' ')) { cout<<char(140); ++i;}
        else if((c[i] == 'd')&&(c[i+1] == ' ')) { cout<<char(141); ++i;}
        else if((c[i] == 'i')&&(c[i+1] == 'n')) { cout<<char(142); ++i;}
        else if((c[i] == ' ')&&(c[i+1] == 's')) { cout<<char(143); ++i;}
        else cout<<c[i];
    }
    cout<<"\");\n";
}

int main()
{
    cout<<"//CPP\n#include <iostream>\n#include <string>\nusing namespace std;\n";
    cout<<"const char*d[] = {\"\\n\", \"\\t\", \"\\\"\", \"\\'\", \"\\\\\", \"e \", \" t\", \"th\", \"s \", \" a\", \"re\", \"he\", \"t \", \"d \", \"in\", \" s\"};\n";
    cout<<"void f(string c){for(int i=0; i<c.length(); ++i){\nunsigned char p = c[i];if(p > 127) cout<<d[int(p-128)];else cout<<p;}}";
    cout<<"int main(){\n";
    char c[1001]={0}, d;
    int i=0;
    while(cin.get(d))
    {
        c[i] = d;
        c[++i] = 0;
        if(i == 1000)
        {
            encode(c);
            i = 0;
        }
    }
    if (i) encode(c);
    cout<<"return 0;}";
    return 0;
}