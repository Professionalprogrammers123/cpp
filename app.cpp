#include <gtkmm-3.0/gtkmm.h>

using namespace Gtk;
using namespace Glib;


int main(int argc,char *argv[]){

    auto app=Application::create(argc,argv);

    Window win;

    return app->run(win);
}
