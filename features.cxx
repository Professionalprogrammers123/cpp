#include <iostream>
#include  <memory>


using namespace std;
class demo{
    
    public:
    
    demo(){
        
        
        cout<<"this is a demo for smart pointer"<<endl;
    }
    
};
int main(int argc, char *argv[])
{
	
	/* lambda expression */
	auto area=[](double radius){
	    
	    return 3.14*radius*radius;
	};
	
	
	
	cout<<area(55.5)<<endl;
	
	/* smart pointer */
	unique_ptr<demo> d(new demo());
	
	
}