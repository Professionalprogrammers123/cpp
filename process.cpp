#include <windows.h>
#include  <iostream>



using namespace std;


int main(int argc,char *argv[]){

        string appname="ffmpeg.exe\t";
        string para1="-i\t";
        string input="korean.mp4";

        string ffmpeg_command=appname+para1+input;


       system(ffmpeg_command.c_str());




}
