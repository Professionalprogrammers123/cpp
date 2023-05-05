#include <gtkmm-3.0/gtkmm.h>

using namespace Gtk;
using namespace Glib;
using namespace std;



class example_stack:public Window{

public:
    example_stack();
protected:
    Grid grid;
    Stack m_stack;

    StackSwitcher stack_switcher;
    Button btn1;
    Button btn2;
};

example_stack::example_stack():
    btn1("Page 1"),
    btn2("Page 2")
    {

     set_title("stack-example");

     m_stack.add(btn1,"Page 1","page 1");
     m_stack.add(btn2,"Page 2","page 2");

     m_stack.set_transition_type(StackTransitionType::STACK_TRANSITION_TYPE_CROSSFADE);

     stack_switcher.set_stack(m_stack);
     grid.attach(stack_switcher,0,0,1,1);
     grid.attach(m_stack,0,1,1,1);

     add(grid);
     show_all();

    }


int main(int argc,char *argv[]){

        auto app=Application::create(argc,argv);

        example_stack es;

        return app->run(es);

}


