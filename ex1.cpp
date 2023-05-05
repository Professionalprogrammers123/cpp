#include <gtkmm-3.0/gtkmm.h>
#include <iostream>
using namespace Gtk;
using namespace Glib;
using namespace std;

     /** declarations **/
     RefPtr<Application>app;
     /** top-level container **/
     Window *win;
     Window *page2;
     Window *page3;
     /** container **/
     Box *vbox;

     /** widgets **/
     Button *btn1;
     Button *btn2;
     Button *btn3;


void print_message(){

    cout<<"program successfully"<<endl;
}
void onActivate(){

        /** *loading glade file ***/
        RefPtr<Builder>builder=Builder::create_from_file("win32.glade");
        RefPtr<Builder>builder2=Builder::create_from_file("page2.glade");
        RefPtr<Builder>builder3=Builder::create_from_file("page3.glade");
        /** reference widget from glade file into gtk app **/
        builder->get_widget<Window>("sample",win);
        builder2->get_widget<Window>("page2",page2);
        builder3->get_widget<Window>("page3",page3);
        builder->get_widget<Box>("vbox",vbox);
        builder->get_widget<Button>("btn1",btn1);
        builder->get_widget<Button>("btn2",btn2);
        builder->get_widget<Button>("btn3",btn3);

        /** widget configurations **/
        btn1->signal_clicked().connect([](){ print_message();});
        btn2->signal_clicked().connect([](){ page2->show();});
        btn3->signal_clicked().connect([](){ page3->show();});
        app->add_window(*win);

        win->set_title("Glade sample app");
        win->show();


}

int main(int argc,char *argv[]){


      app=Application::create("org.group.bainari");


      app->signal_activate().connect([](){ onActivate();});

      return app->run(argc,argv);

}
