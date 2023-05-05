#include <iostream>
#include  <vector>
#include   <memory>

using namespace std;
/* */
class student_number{
    
    public:
     int number;
     student_number(){
         
      //   this->number=n;
     }
};


int main(int argc, char *argv[])
{
	
	
       /* vector demo */	vector<shared_ptr<student_number>>numbers;
	for(int i=0;i<10;++i){
	    
	  auto sn=make_shared<student_number>();
	  
	  
	    numbers.push_back(
	    sn
	    );
	}
	
}