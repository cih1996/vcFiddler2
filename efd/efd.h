using namespace Fiddler;


struct EFD_pmMessage {
	int type;
	int count;
	char* pmdata1;
	char* pmdata2;
};

#pragma once

//typedef void (WINAPI *RecvCallbackFun)(char * url);
//typedef void (WINAPI* SendCallbackFun)(char* url);

//触发响应数据的回调参数
//pmmessage - 指针,在操作修改数据包时才需要提供
//url - 监听到的网址
//head - 监听到的协议头信息
//cookie - 监听到的cookie
//raw - 监听到的响应主体数据指针开始地址
//rawLen - 监听到的响应主体数据长度
typedef void (WINAPI *RecvCallbackFun)(EFD_pmMessage* pmmessage,char * url,char * head,char * cookie,unsigned int raw, unsigned int rawLen);

//触发请求数据的回调参数
//pmmessage - 指针,在操作修改数据包时才需要提供
//url - 监听到的网址
//head - 监听到的协议头信息
//cookie - 监听到的cookie
//post - 监听到的请求POST数据指针开始地址
//rawLen - 监听到的请求POST数据长度
typedef void (WINAPI* SendCallbackFun)(EFD_pmMessage* pmmessage, char* url, char* head, char* cookie, unsigned int post, unsigned int postLen);

//初始化运行Fiddler服务
extern "C" _declspec(dllexport) int __stdcall InitFiddler(int port, int recvCallback, int sendCallback);

//关闭Fiddler服务
extern "C" _declspec(dllexport) void __stdcall CloseFiddler();

//设置自动注册系统代理(InitFiddler前执行)
extern "C" _declspec(dllexport) void __stdcall AutoStartFiddlerProxy(bool start);

//开启SSL模式抓包(InitFiddler前执行)
extern "C" _declspec(dllexport) void __stdcall StartSSL(bool start);

extern "C" _declspec(dllexport) void __stdcall SetBase64(int* url);

//创建SSL根证书
extern "C" _declspec(dllexport) int __stdcall CreateRootCert();

//安装SSL根证书到系统证书列表
extern "C" _declspec(dllexport) int __stdcall InstCert();

//判断是否已安装根证书
extern "C" _declspec(dllexport) bool __stdcall rootCertIsTrusted();
extern "C" _declspec(dllexport) bool __stdcall rootCertIsMachineTrusted();

//判断根证书是否已创建
extern "C" _declspec(dllexport) bool __stdcall rootCertExists();
extern "C" _declspec(dllexport) bool __stdcall removeCerts();

//(仅在recv回调内使用)替换响应数据的指定关键字
extern "C" _declspec(dllexport) int  __stdcall RecvRepeatHtml(EFD_pmMessage*, char*, char*);

//(仅在recv回调内使用)清除所有响应数据并重新设置
extern "C" _declspec(dllexport) int  __stdcall RecvResetHtml(EFD_pmMessage*, char*);

//(仅在recv回调内使用)在响应BODY数据顶部新增数据
extern "C" _declspec(dllexport) int  __stdcall RecvInsertBody(EFD_pmMessage*, char*);

//(仅在recv回调内使用)插入响应的cookie
extern "C" _declspec(dllexport) int  __stdcall RecvInsertCookie(EFD_pmMessage*, char*);

//(仅在recv回调内使用)清空响应的所有cookie
extern "C" _declspec(dllexport) int  __stdcall RecvRemoveCookie(EFD_pmMessage*);

//(仅在recv回调内使用)修改响应的状态码
extern "C" _declspec(dllexport) int  __stdcall RecvResetState(EFD_pmMessage*, char*, char*);

//(仅在send回调内使用)设置新的POST数据(将二进制编码成base64后传递)
extern "C" _declspec(dllexport) int  __stdcall SendResetPostBytes(EFD_pmMessage * pmmessage, char* newdataBase64);

//(仅在send回调内使用)设置新的POST请求数据
extern "C" _declspec(dllexport) int  __stdcall SendResetPostStr(EFD_pmMessage * pmmessage, char* newdata);

//(仅在send回调内使用)设置新的URL请求网址
extern "C" _declspec(dllexport) int  __stdcall SendResetURL(EFD_pmMessage * pmmessage, char* newUrl);

//(仅在send回调内使用)替换URL网址
extern "C" _declspec(dllexport) int  __stdcall SendReplaceURL(EFD_pmMessage * pmmessage, char* rawUrl, char* newUrl);

//(仅在send回调内使用)替换指定关键字POST数据
extern "C" _declspec(dllexport) int  __stdcall SendReplacePost(EFD_pmMessage * pmmessage, char* rawPost, char* newPost);

//(仅在send回调内使用)设置新请求Cookies
extern "C" _declspec(dllexport) int  __stdcall SendResetCookie(EFD_pmMessage * pmmessage, char* newCookie);

//(仅在send回调内使用)设置或修改header中的值
extern "C" _declspec(dllexport) int  __stdcall SendResetHeader(EFD_pmMessage * pmmessage, char* headerKey, char* headerVal);

extern "C" _declspec(dllexport) char* __stdcall sslGetCert();
extern "C" _declspec(dllexport) char* __stdcall sslGetKey();
extern "C" _declspec(dllexport) void __stdcall sslSetCert(char*);
extern "C" _declspec(dllexport) void __stdcall sslSetKey(char*);
extern "C" _declspec(dllexport) void __stdcall SetUpstreamGatewayTo(char*);
extern "C" _declspec(dllexport) void __stdcall UpdateConfig(int);
extern "C" _declspec(dllexport) void __stdcall customCertificate(char*);



#define RECV_INSERT_BODY 2001
#define RECV_REPLACE_BODY 2002
#define RECV_RESET_BODY 2003
#define RECV_REMOVE_COOKIE 2004
#define RECV_INSERT_COOKIE 2005
#define RECV_RESET_STATE 2006

#define SEND_RESET_POST_BYTES  1001
#define SEND_RESET_POST_STR  1002
#define SEND_RESET_URL 1003
#define SEND_REPLACE_URL 1004
#define SEND_REPLACE_POST 1005
#define SEND_RESET_COOKIE 1006
#define SEND_RESET_HEADER 1007

int nextPmIndex(EFD_pmMessage* pmmessage) {
	EFD_pmMessage pmIndex = *(pmmessage);
	pmIndex.count = pmIndex.count + 1;
	*(pmmessage) = pmIndex;
	return pmIndex.count;
}
