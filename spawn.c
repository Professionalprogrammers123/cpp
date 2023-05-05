 #include   <glib-2.0/glib.h>
#include   <stdio.h>


void  say_hello(gpointer data){


 printf("hello to the spawned process\n");

}
int main(int argc,char *argv[]){
      gchar *args[];

      args[0]="thread.exe";
    if(g_spawn_async_with_pipes(
         ".",
         args,
         NULL,
         G_SPAWN_DEFAULT,
         say_hello,
        NULL,
        1200,
        G_SPAWN_CHILD_INHERITS_STDIN,
        stdout,
        stderr,NULL
        )){


        printf("program was launched successfully");
    }



}

