#include  <sigc++-2.0/sigc++/sigc++.h>
#include   <iostream>

using namespace std;


class AlienDetector{

public:
    AlienDetector();
    sigc::signal<void()>signal_detected;
    void run();



};
void warn_people(){

    cout<<"hello from signal"<<endl;

    }
int main(){

    AlienDetector ad;

    ad.signal_detected.connect(sigc::ptr_fun(warn_people));
    ad.run();





}
