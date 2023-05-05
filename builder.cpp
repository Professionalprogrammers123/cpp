#include <gtkmm-3.0/gtkmm.h>
#include <iostream>

using namespace std;
using namespace Glib;
using namespace Gtk;

namespace {

        Window *main_window=nullptr;
        RefPtr<Application>app;

        void on_activate(){

            auto builder=Builder::create();

            try{
                builder->add_from_file("win32.glade");
            }
            catch(Error &e){

            cout<<"failed to load ui file"<<endl;


            }
            main_window=Builder::get_widget_derived<Window>(builder,"main_window");

            if(!main_window){

                cerr<<"couldnot get the window"<<endl;

            }
            app->add_window(*main_window);
            main_window->show();


        }

}

int main(int argc,char *argv[]){

    app=Application::create("org.gtkmm.example");

    app->signal_activate().connect([](){

        on_activate();
    });

    return app->run(argc,argv);
}
