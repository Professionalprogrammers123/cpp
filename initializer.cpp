#include  <iostream>


using namespace std;

class initializer{

private:
    int i;
    double d;
    char c;
    char *str;
public:
    initializer();

};
initializer::initializer():i(1),d(1.0),c('c'),str("initializer"){

    cout<<this->i<<endl;
    cout<<this->d<<endl;
    cout<<this->c<<endl;
    cout<<this->str<<endl;


}
int main(int argc,char *argv[]){

    initializer init1;

    initializer *init2=new initializer();

}
