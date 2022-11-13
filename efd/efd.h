using namespace Fiddler;


struct EFD_pmMessage {
	int type;
	int count;
	char* pmdata1;
	char* pmdata2;
};

#pragma once
typedef void (WINAPI *RecvCallbackFun)(char * url);
typedef void (WINAPI* SendCallbackFun)(char* url);
/*
typedef void (WINAPI *RecvCallbackFun)(int* pmmessage,char * url,char * head,char * cookie,unsigned int raw, unsigned int rawLen);
typedef void (WINAPI* SendCallbackFun)(int* pmmessage, char* url, char* head, char* cookie, unsigned int post, unsigned int postLen);
*/
extern "C" _declspec(dllexport) int __stdcall InitFiddler(int port, int callback);
extern "C" _declspec(dllexport) void __stdcall CloseFiddler();
extern "C" _declspec(dllexport) void __stdcall AutoStartFiddlerProxy(bool start);
extern "C" _declspec(dllexport) void __stdcall StartSSL(bool start);
extern "C" _declspec(dllexport) void __stdcall SetBase64(int* url);
extern "C" _declspec(dllexport) int __stdcall CreateRootCert();
extern "C" _declspec(dllexport) int __stdcall InstCert();
extern "C" _declspec(dllexport) bool __stdcall rootCertIsTrusted();
extern "C" _declspec(dllexport) bool __stdcall rootCertIsMachineTrusted();
extern "C" _declspec(dllexport) bool __stdcall rootCertExists();
extern "C" _declspec(dllexport) bool __stdcall removeCerts();
extern "C" _declspec(dllexport) char* __stdcall sslGetCert();
extern "C" _declspec(dllexport) char* __stdcall sslGetKey();
extern "C" _declspec(dllexport) void __stdcall sslSetCert(char *);
extern "C" _declspec(dllexport) void __stdcall sslSetKey(char *);
extern "C" _declspec(dllexport) void __stdcall SetUpstreamGatewayTo(char *);
extern "C" _declspec(dllexport) void __stdcall UpdateConfig(int);
extern "C" _declspec(dllexport) void __stdcall customCertificate(char*);
extern "C" _declspec(dllexport) int  __stdcall RecvRepeatHtml(EFD_pmMessage*, char*, char*);
extern "C" _declspec(dllexport) int  __stdcall RecvResetHtml(EFD_pmMessage*, char*);
extern "C" _declspec(dllexport) int  __stdcall RecvInsertBody(EFD_pmMessage*, char*);
extern "C" _declspec(dllexport) int  __stdcall RecvInsertCookie(EFD_pmMessage*, char*);
extern "C" _declspec(dllexport) int  __stdcall RecvRemoveCookie(EFD_pmMessage*);
extern "C" _declspec(dllexport) int  __stdcall RecvResetState(EFD_pmMessage*, char*, char*);
extern "C" _declspec(dllexport) int  __stdcall SendResetPostBytes(EFD_pmMessage * pmmessage, char* newdataBase64);
extern "C" _declspec(dllexport) int  __stdcall SendResetPostStr(EFD_pmMessage * pmmessage, char* newdata);
extern "C" _declspec(dllexport) int  __stdcall SendResetURL(EFD_pmMessage * pmmessage, char* newUrl);
extern "C" _declspec(dllexport) int  __stdcall SendReplaceURL(EFD_pmMessage * pmmessage, char* rawUrl, char* newUrl);
extern "C" _declspec(dllexport) int  __stdcall SendReplacePost(EFD_pmMessage * pmmessage, char* rawPost, char* newPost);
extern "C" _declspec(dllexport) int  __stdcall SendResetCookie(EFD_pmMessage * pmmessage, char* newCookie);
extern "C" _declspec(dllexport) int  __stdcall SendResetHeader(EFD_pmMessage * pmmessage, char* headerKey, char* headerVal);





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
