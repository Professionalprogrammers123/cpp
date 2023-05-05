#include <iostream>

extern "C" {

#include  <libavcodec/avcodec.h>
#include  <libavformat/avformat.h>
#include  <libavutil/avutil.h>
}




using namespace std;

int main(int argc,char *argv[]){


        AVFormatContext *in_ctx=avformat_alloc_context();
        AVFormatContext *out_ctx=avformat_alloc_context();

        avformat_open_input(&in_ctx,argv[1],NULL,NULL);

        avformat_find_stream_info(in_ctx,NULL);







}
