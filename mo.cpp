#include <gtkmm.h>
#include <iostream>
#include <stdio.h>

class primary_window:public Gtk::Window{

public:
    primary_window();
    Gtk::HeaderBar header;
    Gtk::Notebook notebook;
    Gtk::Label child1;
    Gtk::Label label1;
    Gtk::Label child2;
    Gtk::Label label2;
    Gtk::Label child3;
    Gtk::Label label3;
    Gtk::Label child4;
    Gtk::Label label4;
    Gtk::Label child5;
    Gtk::Label label5;
    Gtk::Label child6;
    Gtk::Label label6;
    Gtk::Label child7;
    Gtk::Label label7;
    Gtk::Label child8;
    Gtk::Label label8;
    Gtk::Label child9;
    Gtk::Label label9;
    Gtk::Label child10;
    Gtk::Label label10;
    Gtk::Label child11;
    Gtk::Label label11;
    Gtk::Label child12;
    Gtk::Label label12;
    Gtk::Label child13;
    Gtk::Label label13;



private:
    virtual void switch_tab(Gtk::Widget *tab,guint page_number);
    void extract_media_metadata(const char *filename);
};
void primary_window::switch_tab(Gtk::Widget *tab,guint page_number){

    notebook.set_current_page(page_number);

}
primary_window::primary_window():
    child1("Media metadata"),
    label1("Media metadata"),
    child2("Transmuxer"),
    label2("Transmuxer"),
     child3("Transrater"),
    label3("Transrater"),
     child4("Transsizer"),
    label4("Transsizer"),
     child5("AV encoder"),
    label5("AV encoder"),
     child6("AV decoder"),
    label6("AV decoder"),
     child7("AV filter"),
    label7("AV filter"),
     child8("Muxer"),
    label8("Muxer"),
     child9("Remuxer"),
    label9("Remuxer"),
     child10("Transcoder"),
    label10("Transcoder"),
     child11("Audio resampler"),
    label11("Audio resampler"),
     child12("Video scaler"),
    label12("Video scaler"),
     child13("Stream extractor"),
    label13("Stream extractor")
    {
    /****** widgets configurations ******/
    /*** header ***/
    header.set_show_close_button(true);

    /**window configurations **/
    set_default_size(900,500);
    set_titlebar(header);
    set_title("LibAV media operations");
    set_resizable(true);





        notebook.append_page(child1,label1);
        notebook.append_page(child2,label2);
        notebook.append_page(child3,label3);
        notebook.append_page(child4,label4);
        notebook.append_page(child5,label5);
        notebook.append_page(child6,label6);
        notebook.append_page(child7,label7);
        notebook.append_page(child8,label8);
        notebook.append_page(child9,label9);
        notebook.append_page(child10,label10);
        notebook.append_page(child11,label11);
        notebook.append_page(child12,label12);
        notebook.append_page(child13,label13);

    notebook.signal_switch_page().connect(sigc::mem_fun(*this,&primary_window::switch_tab));
    add(notebook);
    show_all();
}


int main(int argc,char *argv[]){


auto app=Gtk::Application::create(argc,argv);


primary_window pw;



return app->run(pw);

}
