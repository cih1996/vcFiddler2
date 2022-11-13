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

//������Ӧ���ݵĻص�����
//pmmessage - ָ��,�ڲ����޸����ݰ�ʱ����Ҫ�ṩ
//url - ����������ַ
//head - ��������Э��ͷ��Ϣ
//cookie - ��������cookie
//raw - ����������Ӧ��������ָ�뿪ʼ��ַ
//rawLen - ����������Ӧ�������ݳ���
typedef void (WINAPI *RecvCallbackFun)(EFD_pmMessage* pmmessage,char * url,char * head,char * cookie,unsigned int raw, unsigned int rawLen);

//�����������ݵĻص�����
//pmmessage - ָ��,�ڲ����޸����ݰ�ʱ����Ҫ�ṩ
//url - ����������ַ
//head - ��������Э��ͷ��Ϣ
//cookie - ��������cookie
//post - ������������POST����ָ�뿪ʼ��ַ
//rawLen - ������������POST���ݳ���
typedef void (WINAPI* SendCallbackFun)(EFD_pmMessage* pmmessage, char* url, char* head, char* cookie, unsigned int post, unsigned int postLen);

//��ʼ������Fiddler����
extern "C" _declspec(dllexport) int __stdcall InitFiddler(int port, int recvCallback, int sendCallback);

//�ر�Fiddler����
extern "C" _declspec(dllexport) void __stdcall CloseFiddler();

//�����Զ�ע��ϵͳ����(InitFiddlerǰִ��)
extern "C" _declspec(dllexport) void __stdcall AutoStartFiddlerProxy(bool start);

//����SSLģʽץ��(InitFiddlerǰִ��)
extern "C" _declspec(dllexport) void __stdcall StartSSL(bool start);

extern "C" _declspec(dllexport) void __stdcall SetBase64(int* url);

//����SSL��֤��
extern "C" _declspec(dllexport) int __stdcall CreateRootCert();

//��װSSL��֤�鵽ϵͳ֤���б�
extern "C" _declspec(dllexport) int __stdcall InstCert();

//�ж��Ƿ��Ѱ�װ��֤��
extern "C" _declspec(dllexport) bool __stdcall rootCertIsTrusted();
extern "C" _declspec(dllexport) bool __stdcall rootCertIsMachineTrusted();

//�жϸ�֤���Ƿ��Ѵ���
extern "C" _declspec(dllexport) bool __stdcall rootCertExists();
extern "C" _declspec(dllexport) bool __stdcall removeCerts();

//(����recv�ص���ʹ��)�滻��Ӧ���ݵ�ָ���ؼ���
extern "C" _declspec(dllexport) int  __stdcall RecvRepeatHtml(EFD_pmMessage*, char*, char*);

//(����recv�ص���ʹ��)���������Ӧ���ݲ���������
extern "C" _declspec(dllexport) int  __stdcall RecvResetHtml(EFD_pmMessage*, char*);

//(����recv�ص���ʹ��)����ӦBODY���ݶ�����������
extern "C" _declspec(dllexport) int  __stdcall RecvInsertBody(EFD_pmMessage*, char*);

//(����recv�ص���ʹ��)������Ӧ��cookie
extern "C" _declspec(dllexport) int  __stdcall RecvInsertCookie(EFD_pmMessage*, char*);

//(����recv�ص���ʹ��)�����Ӧ������cookie
extern "C" _declspec(dllexport) int  __stdcall RecvRemoveCookie(EFD_pmMessage*);

//(����recv�ص���ʹ��)�޸���Ӧ��״̬��
extern "C" _declspec(dllexport) int  __stdcall RecvResetState(EFD_pmMessage*, char*, char*);

//(����send�ص���ʹ��)�����µ�POST����(�������Ʊ����base64�󴫵�)
extern "C" _declspec(dllexport) int  __stdcall SendResetPostBytes(EFD_pmMessage * pmmessage, char* newdataBase64);

//(����send�ص���ʹ��)�����µ�POST��������
extern "C" _declspec(dllexport) int  __stdcall SendResetPostStr(EFD_pmMessage * pmmessage, char* newdata);

//(����send�ص���ʹ��)�����µ�URL������ַ
extern "C" _declspec(dllexport) int  __stdcall SendResetURL(EFD_pmMessage * pmmessage, char* newUrl);

//(����send�ص���ʹ��)�滻URL��ַ
extern "C" _declspec(dllexport) int  __stdcall SendReplaceURL(EFD_pmMessage * pmmessage, char* rawUrl, char* newUrl);

//(����send�ص���ʹ��)�滻ָ���ؼ���POST����
extern "C" _declspec(dllexport) int  __stdcall SendReplacePost(EFD_pmMessage * pmmessage, char* rawPost, char* newPost);

//(����send�ص���ʹ��)����������Cookies
extern "C" _declspec(dllexport) int  __stdcall SendResetCookie(EFD_pmMessage * pmmessage, char* newCookie);

//(����send�ص���ʹ��)���û��޸�header�е�ֵ
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
