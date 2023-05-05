#include <gtk-3.0/gtk/gtk.h>

int main(int argc,char *argv[]){




    gtk_init(&argc,&argv);

    GtkBuilder *builder=gtk_builder_new();
    GtkWidget *header=gtk_header_bar_new();

    gtk_builder_add_from_file(builder,"builder.glade",NULL);

    GObject *window=gtk_builder_get_object(builder,"main-window");

    gtk_window_set_title(GTK_WINDOW(window),"gtk");
    gtk_window_set_titlebar(GTK_WINDOW(window),header);

    gtk_widget_show(GTK_WIDGET(window));

    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

    gtk_main();

    return 0;

}
