#pragma once

//send ����post����base64�����byte��
int  __stdcall SendResetPostBytes(EFD_pmMessage* pmmessage, char* newdataBase64) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = SEND_RESET_POST_BYTES;
	pm.pmdata1 = newdataBase64;
	*(pmmessage + index) = pm;
	return index;
}

//send ����post����base64�����str��
int  __stdcall SendResetPostStr(EFD_pmMessage* pmmessage, char* newdata) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = SEND_RESET_POST_STR;
	pm.pmdata1 = newdata;
	*(pmmessage + index) = pm;
	return index;
}

//send �����ύ��ȥ��URL
int  __stdcall SendResetURL(EFD_pmMessage* pmmessage, char* newUrl) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = SEND_RESET_URL;
	pm.pmdata1 = newUrl;
	*(pmmessage + index) = pm;
	return index;
}


//send �滻URL
int  __stdcall SendReplaceURL(EFD_pmMessage* pmmessage,char* rawUrl, char* newUrl) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = SEND_REPLACE_URL;
	pm.pmdata1 = rawUrl;
	pm.pmdata2 = newUrl;
	*(pmmessage + index) = pm;
	return index;
}


//send �滻POST������
int  __stdcall SendReplacePost(EFD_pmMessage* pmmessage, char* rawPost, char* newPost) {
	
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = SEND_REPLACE_POST;
	pm.pmdata1 = rawPost;
	pm.pmdata2 = newPost;
	*(pmmessage + index) = pm;
	return index;
}

//send �����µ�cookie
int  __stdcall SendResetCookie(EFD_pmMessage* pmmessage, char* newCookie) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = SEND_RESET_COOKIE;
	pm.pmdata1 = newCookie;
	*(pmmessage + index) = pm;
	return index;
}

//send ����/����µ�headerЭ��ͷ
int  __stdcall SendResetHeader(EFD_pmMessage* pmmessage, char* headerKey,char* headerVal) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = SEND_RESET_HEADER;
	pm.pmdata1 = headerKey;
	pm.pmdata2 = headerVal;
	*(pmmessage + index) = pm;
	return index;
}
