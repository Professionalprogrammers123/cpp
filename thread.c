#include   <glib-2.0/glib.h>
#include   <stdio.h>


gpointer say_hello(gpointer data){


 printf("hello from thread function\n");

}
int main(int argc,char *argv[]){

    GThread *t1=g_thread_new("thread 1",say_hello,NULL);
    printf("this is a main thread\n");
    g_thread_join(t1);



}
