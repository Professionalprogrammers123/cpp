#include  <iostream>
#include  <cstdlib>

using namespace std;

struct term_t{

char value;
struct term_t *l_term;
struct term_t *r_term;
};
typedef term_t term;
int main(int argc,char *argv[]){


        string expression;

        cout<<"enter two operand expression"<<endl;
        getline(cin,expression);
        int n=expression.length();
        char terms[n];
        for(int i=0;i<expression.length();++i){

           terms[i]=expression[i];
        }
        /**==|lexer-start |==**/
        for(int i=0;i<n;++i){


                if(terms[i]=='+'){

                    cout<<terms[i]<<":operator"<<endl;
                }
                else if(terms[i]=='-'){
                     cout<<terms[i]<<":operator"<<endl;
                }
                else if(terms[i]=='*'){
                     cout<<terms[i]<<":operator"<<endl;
                }
                else if(terms[i]=='/'){
                     cout<<terms[i]<<":operator"<<endl;
                }
                else {
                     cout<<terms[i]<<":number"<<endl;
                }

        }
        /**==|lexer-end |==**/



}
