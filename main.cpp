#include <gtkmm.h>
#include <iostream>

extern "C" {

#include  <libavcodec/avcodec.h>
#include  <libavformat/avformat.h>
#include  <libavutil/dict.h>
}




using namespace std;
class main_window:public Gtk::Window{

public:
    main_window();
    Gtk::Button btn1;
    Gtk::Button btn2;
    Gtk::Box vbox;
    Gtk::ProgressBar pb;
    Gtk::Label page1;
    Gtk::Label page2;
    Gtk::Label child1;
    Gtk::Label child2;
    Gtk::Notebook notebook;

    void print_message();
    virtual void switch_tab();


};

main_window::main_window():btn1("click"),btn2("cancel"){

     set_default_size(600,400);
     set_title("gtkmm sample window");
     vbox.set_orientation(Gtk::ORIENTATION_VERTICAL);

     btn1.signal_clicked().connect(sigc::mem_fun(*this,&main_window::print_message));

     notebook.append_page(child1,page1);
     notebook.append_page(child2,page2);
     notebook.set_tab_pos(Gtk::POS_TOP);
     vbox.pack_start(btn1);
     vbox.pack_start(btn2);
     vbox.pack_start(notebook);
     add(vbox);
     show_all();
}
void main_window::print_message(){

    Gtk::FileChooserDialog dialog("Please choose a file",Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);

    dialog.set_transient_for(*this);
    dialog.add_button(Gtk::Stock::CANCEL,Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::OPEN,Gtk::RESPONSE_OK);
    /**
    Gtk::FileFilter filter;
    filter.set_name("Any files");
    filter.add_pattern("*");
    dialog.add_filter(filter);
    **/


    int result=dialog.run();

    switch(result){

    case Gtk::ResponseType::RESPONSE_OK:
        {
        string filenm=dialog.get_filename();
        const char *fname=filenm.c_str();
        AVFormatContext *formctxt=avformat_alloc_context();
        AVDictionaryEntry *tag=NULL;
        avformat_open_input(&formctxt,fname,NULL,NULL);

        cout<<"number of streams:"<<formctxt->nb_streams<<endl;

        AVCodecParameters *Para=formctxt->streams[1]->codecpar;

        cout<<"sample rate:"<<Para->sample_rate<<endl;
        AVStream *o_stream;
        AVStream *i_stream=formctxt->streams[1];


        avformat_free_context(formctxt);

        break;
    }


    }

}
void main_window::switch_tab(){

    int page=notebook.get_current_page();

     if(page==0){

        notebook.set_current_page(1);
     }
     else{
         notebook.set_current_page(0);
     }

}

int main(int argc,char *argv[]){


auto app=Gtk::Application::create(argc,argv);


main_window mw;



return app->run(mw);

}
