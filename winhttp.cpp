#include  <windows.h>
#include  <winhttp.h>
#include  <iostream>

using namespace std;

int main(int argc,char *argv[]){

    DWORD dsize=0;
    DWORD ndownloaded=0;
    LPSTR buffer;
    BOOL results;
    HINTERNET session=NULL,iconnect=NULL,req=NULL;

    session=WinHttpOpen(
    L"winhttp example/1.o",
    WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
    WINHTTP_NO_PROXY_NAME,
    WINHTTP_NO_PROXY_BYPASS,
    0
    );
    if(session){
        iconnect=WinHttpConnect(session,L"portal.ncnd.vodacom.co.tz",INTERNET_DEFAULT_HTTP_PORT,0);

        if(iconnect){

           req=WinHttpOpenRequest(
              iconnect,
              L"GET",
              NULL,
              NULL,
              WINHTTP_NO_REFERER,
              WINHTTP_DEFAULT_ACCEPT_TYPES,
              WINHTTP_FLAG_SECURE
           );
           if(req){

            results=WinHttpSendRequest(
                req,
                WINHTTP_NO_ADDITIONAL_HEADERS,0,
                WINHTTP_NO_REQUEST_DATA,0,0,0
                );
                if(results){
                    results=WinHttpReceiveResponse(req,NULL);

                    if(results){

                            do{

                                dsize=0;
                                if(!WinHttpQueryDataAvailable(req,&dsize))
                                    cout<<"no data is available"<<endl;
                                buffer=new char[dsize+1];
                                if(!buffer){
                                    cout<<"out of memory"<<endl;
                                    dsize=0;
                                }
                                else{
                                    ZeroMemory(buffer,dsize+1);
                                    WinHttpReadData(req,(LPVOID)buffer,dsize,&ndownloaded);
                                    cout<<buffer<<endl;
                                    delete [] buffer;
                                }

                            }
                            while(dsize>0);


                    }else{

                    cout<<"failed to retrieve the results"<<endl;


                    }
                    if(!results)
                    {

                        cout<<"an error has occured"<<GetLastError()<<endl;
                    }else{

                    WinHttpCloseHandle(req);
                    WinHttpCloseHandle(iconnect);
                    WinHttpCloseHandle(session);

                    }




                }



           }
           else{
            cout<<"request failed"<<endl;
           }

        }else{

        cout<<"failed to connect to the server"<<endl;

        }


    }
    else{


        cout<<"failed to get session"<<endl;
    }




}
