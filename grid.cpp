#include <gtkmm.h>
#include <gdkmm-3.0/gdkmm.h>
#include <iostream>
using namespace Glib;
using namespace Gtk;
using namespace std;

int main(int argc, char* argv[]) {

  string image_list[6]={
  "image/1.jpg",
  "image/2.jpg",
  "image/3.jpg",
  "image/4.jpg",
  "image/5.jpg",
  "image/6.jpg",
  };

  auto application = Application::create(argc, argv);
  Window window;
  HeaderBar header;
  Grid grid;
  auto pixbuff0=Gdk::Pixbuf::create_from_file(image_list[0],256,256,true);
  auto pixbuff1=Gdk::Pixbuf::create_from_file(image_list[1],256,256,true);
  auto pixbuff2=Gdk::Pixbuf::create_from_file(image_list[2],256,256,true);
  auto pixbuff3=Gdk::Pixbuf::create_from_file(image_list[3],256,256,true);
  auto pixbuff4=Gdk::Pixbuf::create_from_file(image_list[4],256,256,true);
  auto pixbuff5=Gdk::Pixbuf::create_from_file(image_list[5],256,256,true);
  Image i0(pixbuff0);

  Image i1(pixbuff1);
  Image i2(pixbuff2);
  Image i3(pixbuff3);
  Image i4(pixbuff4);
  Image i5(pixbuff5);
  grid.attach(i0,0,0,30,30);
  grid.attach(i1,0,30,30,30);
  grid.attach(i2,30,30,30,30);
  grid.attach(i3,90,30,30,30);
  grid.attach(i4,90,0,30,30);
  grid.attach(i5,30,0,30,30);
  header.set_show_close_button(true);
  window.set_titlebar(header);
  window.set_title("Gallery");
  window.set_size_request(500,600);
  window.add(grid);
  window.show_all();

  return application->run(window);
}
