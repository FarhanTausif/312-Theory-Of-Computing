#include <bits/stdc++.h>

using namespace std;

string s;

int main(){

    FILE *fp = fopen("test_code.c", "r");

    int i = 0, num_line = 1;
    
    char ch;

    while(!feof(fp)){
        ch = fgetc(fp);
        if(ch >= 0 && ch <= 127) s += ch;
    }

    //cout << s << endl;
 
    for(int i = 0; i < s.size(); ++i){
        
        if(s[i] == '\n') num_line++;
        
        if(s[i] == '/' && s[i+1] == '/'){
            int j = i+2;
            cout << "*** Single Line comment detected ***" << endl;
            while(1){
                printf("%c", s[j+1]);
                j++;
                
                if(s[j] == '\n'){
                    cout << "@ Line Number: " << num_line << endl << endl;
                    break;      
                }
            }
        }

        if(s[i] == '/' && s[i+1] == '*'){
            int j = i+2;
            cout << "*** Multi Line comment detected ***" << endl;
            while(1){
                printf("%c", s[j]);
                j++;
                
                if(s[j] == '*' && s[j+1] == '/'){
                    cout << "\n@ Line Number: " << num_line << endl << endl;
                    break;      
                }
                
                if(s[j] == '\n'){
                    cout << "The multi line comment in line no " << num_line << " was incomplete (doesn't have an ending */)" << endl << endl;
                    break;
                }
            }
        }
    }
    
    fclose(fp);
}