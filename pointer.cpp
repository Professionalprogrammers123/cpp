#include <iostream>
#include  <memory>

using namespace std;

    class rectangle{

    int length;
    int height;

public:
    rectangle(int l,int h){

    this->length=l;
    this->height=h;

    }
    int area(){

    return this->length*this->height;

    }

};
 int main(int argc,char * argv[]){

    shared_ptr<rectangle>r1(new rectangle(10,5));


    std::cout<<r1->area()<<endl;


}
