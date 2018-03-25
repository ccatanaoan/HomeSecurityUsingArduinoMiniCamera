#include "B4RDefines.h"

B4R::Serial* b4r_main::_serial1;
B4R::B4RESPWiFi* b4r_main::_wifi;
B4R::WiFiServerSocket* b4r_main::_server;
B4R::AsyncStreams* b4r_main::_async;
B4R::ByteConverter* b4r_main::_bc;
static B4R::Serial be_gann1_3;
static B4R::B4RESPWiFi be_gann2_3;
static B4R::WiFiServerSocket be_gann3_3;
static B4R::AsyncStreams be_gann4_3;
static B4R::ByteConverter be_gann5_3;


     void SetIP(B4R::Object* o) {
        B4R::Array* b = (B4R::Array*)B4R::Object::toPointer(o);
        IPAddress ip(ByteFromArray(b, 0),ByteFromArray(b, 1) , ByteFromArray(b, 2), ByteFromArray(b, 3));
        IPAddress gateway(192, 168, 0, 1);
        IPAddress subnet(255, 255, 255, 0);
        WiFi.config(ip, gateway, subnet);
    }
	
    void GetMacAddress(B4R::Object* o) {
		Serial.println();
		Serial.print("MAC = ");
		Serial.println(WiFi.macAddress());
    }	
void b4r_main::_appstart(){
const UInt cp = B4R::StackMemory::cp;
Byte be_ann10_19e1[4];
B4R::Array be_ann10_19e2;
B4R::Array* _b = NULL;
B4R::Object be_ann11_6;
B4R::B4RString be_ann12_5;
B4R::B4RString be_ann12_7;
 //BA.debugLineNum = 11;BA.debugLine="Private Sub AppStart";
 //BA.debugLineNum = 12;BA.debugLine="Serial1.Initialize(115200)";
b4r_main::_serial1->Initialize((ULong) (115200));
 //BA.debugLineNum = 13;BA.debugLine="Log(\"AppStart\")";
B4R::Common::LogHelper(1,102,F("AppStart"));
 //BA.debugLineNum = 16;BA.debugLine="Dim b() As Byte = Array As Byte(192, 168, 0, 88)";
_b = be_ann10_19e2.create(be_ann10_19e1,4,1,(Byte) (192),(Byte) (168),(Byte) (0),(Byte) (88));
 //BA.debugLineNum = 17;BA.debugLine="RunNative(\"SetIP\", b)";
Common_RunNative(SetIP,be_ann11_6.wrapPointer(_b));
 //BA.debugLineNum = 18;BA.debugLine="If WiFi.Connect2(\"Rise Above This Home\",\"SteelRes";
if (b4r_main::_wifi->Connect2(be_ann12_5.wrap("Rise Above This Home"),be_ann12_7.wrap("SteelReserve"))) { 
 //BA.debugLineNum = 19;BA.debugLine="Log(\"Access point Available\")";
B4R::Common::LogHelper(1,102,F("Access point Available"));
 //BA.debugLineNum = 20;BA.debugLine="Log(\"IP = \", WiFi.LocalIp)";
B4R::Common::LogHelper(2,102,F("IP = "),101,b4r_main::_wifi->getLocalIp()->data);
 //BA.debugLineNum = 21;BA.debugLine="RunNative(\"GetMacAddress\", Null)";
Common_RunNative(GetMacAddress,Common_Null);
 //BA.debugLineNum = 23;BA.debugLine="server.Initialize(80, \"server_NewConnection\")";
b4r_main::_server->Initialize((UInt) (80),_server_newconnection);
 //BA.debugLineNum = 24;BA.debugLine="server.Listen";
b4r_main::_server->Listen();
 };
 //BA.debugLineNum = 26;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_async_error(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 55;BA.debugLine="Sub aSync_Error";
 //BA.debugLineNum = 56;BA.debugLine="Log(\"Error\")";
B4R::Common::LogHelper(1,102,F("Error"));
 //BA.debugLineNum = 57;BA.debugLine="server.Listen";
b4r_main::_server->Listen();
 //BA.debugLineNum = 58;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_async_newdata(B4R::Array* _buffer){
const UInt cp = B4R::StackMemory::cp;
B4R::Object be_ann25_2;
B4R::B4RString be_ann26_7;
B4R::B4RString be_ann27_7;
B4R::B4RString be_ann28_4;
B4R::B4RString be_ann28_11;
B4R::B4RString be_ann29_4;
B4R::B4RString be_ann29_11;
B4R::B4RString be_ann29_18;
B4R::B4RString be_ann30_4;
B4R::B4RString be_ann33_4;
B4R::B4RString be_ann33_11;
B4R::B4RString be_ann34_4;
B4R::B4RString be_ann34_11;
B4R::B4RString be_ann34_18;
B4R::B4RString be_ann35_4;
B4R::B4RString be_ann35_11;
 //BA.debugLineNum = 33;BA.debugLine="Sub aSync_NewData (Buffer() As Byte)";
 //BA.debugLineNum = 34;BA.debugLine="Log(Buffer)";
B4R::Common::LogHelper(1,100,be_ann25_2.wrapPointer(_buffer));
 //BA.debugLineNum = 35;BA.debugLine="If bc.IndexOf(Buffer, \"GET\") <> -1 Then";
if (b4r_main::_bc->IndexOf(_buffer,(be_ann26_7.wrap("GET"))->GetBytes())!=-1) { 
 //BA.debugLineNum = 36;BA.debugLine="If bc.IndexOf(Buffer, \"GET /login\") <> -1 Then";
if (b4r_main::_bc->IndexOf(_buffer,(be_ann27_7.wrap("GET /login"))->GetBytes())!=-1) { 
 //BA.debugLineNum = 37;BA.debugLine="aSync.Write(\"HTTP/1.1 200 OK\").write(CRLF)";
b4r_main::_async->Write((be_ann28_4.wrap("HTTP/1.1 200 OK"))->GetBytes())->Write((be_ann28_11.wrap(Common_CRLF))->GetBytes());
 //BA.debugLineNum = 38;BA.debugLine="aSync.Write(\"Content-Type: text/html\").Write(CR";
b4r_main::_async->Write((be_ann29_4.wrap("Content-Type: text/html"))->GetBytes())->Write((be_ann29_11.wrap(Common_CRLF))->GetBytes())->Write((be_ann29_18.wrap(Common_CRLF))->GetBytes());
 //BA.debugLineNum = 39;BA.debugLine="aSync.Write(\"<b>Hello World</b><br/><a href=\"\"h";
b4r_main::_async->Write((be_ann30_4.wrap("<b>Hello World</b><br/><a href=\"https://www.b4x.com\">B4X</a>"))->GetBytes());
 //BA.debugLineNum = 40;BA.debugLine="Log(\"login - \", Buffer.Length)";
B4R::Common::LogHelper(2,102,F("login - "),3,_buffer->length);
 }else {
 //BA.debugLineNum = 42;BA.debugLine="aSync.Write(\"HTTP/1.1 404\").Write(CRLF)";
b4r_main::_async->Write((be_ann33_4.wrap("HTTP/1.1 404"))->GetBytes())->Write((be_ann33_11.wrap(Common_CRLF))->GetBytes());
 //BA.debugLineNum = 43;BA.debugLine="aSync.Write(\"Content-Type: text/html\").Write(CR";
b4r_main::_async->Write((be_ann34_4.wrap("Content-Type: text/html"))->GetBytes())->Write((be_ann34_11.wrap(Common_CRLF))->GetBytes())->Write((be_ann34_18.wrap(Common_CRLF))->GetBytes());
 //BA.debugLineNum = 44;BA.debugLine="aSync.Write(\"What's up world?\").Write(CRLF)";
b4r_main::_async->Write((be_ann35_4.wrap("What's up world?"))->GetBytes())->Write((be_ann35_11.wrap(Common_CRLF))->GetBytes());
 };
 //BA.debugLineNum = 46;BA.debugLine="CallSubPlus(\"CloseConnection\", 100, 0)";
B4R::__c->CallSubPlus(_closeconnection,(ULong) (100),(Byte) (0));
 };
 //BA.debugLineNum = 48;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_closeconnection(Byte _u){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 50;BA.debugLine="Sub CloseConnection(u As Byte)";
 //BA.debugLineNum = 51;BA.debugLine="Log(\"writing\")";
B4R::Common::LogHelper(1,102,F("writing"));
 //BA.debugLineNum = 52;BA.debugLine="server.Socket.Close";
b4r_main::_server->getSocket()->Close();
 //BA.debugLineNum = 53;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}

void b4r_main::initializeProcessGlobals() {
     B4R::StackMemory::buffer = (byte*)malloc(STACK_BUFFER_SIZE);
     b4r_main::_process_globals();

   
}
void b4r_main::_process_globals(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 1;BA.debugLine="Sub Process_Globals";
 //BA.debugLineNum = 4;BA.debugLine="Public Serial1 As Serial";
b4r_main::_serial1 = &be_gann1_3;
 //BA.debugLineNum = 5;BA.debugLine="Private WiFi As ESP8266WiFi";
b4r_main::_wifi = &be_gann2_3;
 //BA.debugLineNum = 6;BA.debugLine="Private server As WiFiServerSocket";
b4r_main::_server = &be_gann3_3;
 //BA.debugLineNum = 7;BA.debugLine="Private aSync As AsyncStreams";
b4r_main::_async = &be_gann4_3;
 //BA.debugLineNum = 8;BA.debugLine="Private bc As ByteConverter";
b4r_main::_bc = &be_gann5_3;
 //BA.debugLineNum = 9;BA.debugLine="End Sub";
}
void b4r_main::_server_newconnection(B4R::WiFiSocket* _newsocket){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 28;BA.debugLine="Sub server_NewConnection (NewSocket As WiFiSocket)";
 //BA.debugLineNum = 29;BA.debugLine="Log(\"connected\")";
B4R::Common::LogHelper(1,102,F("connected"));
 //BA.debugLineNum = 30;BA.debugLine="aSync.Initialize(NewSocket.Stream, \"aSync_NewData";
b4r_main::_async->Initialize(_newsocket->getStream(),_async_newdata,_async_error);
 //BA.debugLineNum = 31;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
