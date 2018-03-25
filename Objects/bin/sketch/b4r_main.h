
#ifndef b4r_main_h
#define b4r_main_h

class b4r_main {
public:

static void initializeProcessGlobals();
static void _appstart();
static void _async_error();
static void _async_newdata(B4R::Array* _buffer);
static void _closeconnection(Byte _u);
static void _process_globals();
static B4R::Serial* _serial1;
static B4R::B4RESPWiFi* _wifi;
static B4R::WiFiServerSocket* _server;
static B4R::AsyncStreams* _async;
static B4R::ByteConverter* _bc;
static void _server_newconnection(B4R::WiFiSocket* _newsocket);
};

#endif