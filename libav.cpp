#include  <stdio.h>
#include  <libavcodec/avcodec.h>
#include  <libavformat/avformat.h>
#include  <libavutil/avutil.h>
#include  <inttypes.h>


int main(int argc,char *argv[]){

            /** ffmpeg layers **/
            const char *filename;
            /** steps **/
            /** 1.demuxing **/
            AVFormatContext *format_ctx=avformat_alloc_context();
            /* avformatcontext hold the informations about the media container */
            avformat_open_input(&format_ctx,filename,NULL,NULL);
            avformat_find_stream_info(format_ctx,NULL);

            /** 2. Decoding **/
            /** prepare codec structures i.e avcodec and avcodecparameter **/
            AVCodec *pcodec=NULL;//represent codec
            AVCodecParameters *codec_para=NULL; // hold codec properties
            int stream_index=-1; //represent stream number in the media container

            for(int i=0;i<format_ctx->nb_streams;++i){

                AVCodecParameters *cp=NULL;
                cp=format_ctx->streams[i]->codecpar;

                AVCodec *c=avcodec_find_decoder(cp->codec_id);

                /** finding registered codec **/

                switch(cp->codec_type){
            case AVMEDIA_TYPE_VIDEO:
                stream_index=i;
                pcodec=c;
                codec_para=cp;
                break;
                }


            }
            /** allocate codec_context **/
                AVCodecContext *codec_ctx=avcodec_alloc_context3(pcodec);

                //fill codec context with codec parameters

                avcodec_parameters_to_context(codec_ctx,codec_para);
                //open codec context
                avcodec_open2(codec_ctx,pcodec);

                /** allocate frame and packets ready for decoding **/
                AVFrame *frame=av_frame_alloc();
                AVPacket *packets=av_packet_alloc();
                int decoding_result=0;

                while(av_read_frame(format_ctx,packets))>=0{

                    if(packets->stream_index==stream_index){

                        printf("AVPacket->pts%" PRId64,packets->pts);
                    }
                }
}
