#pragma once

int  __stdcall RecvRepeatHtml(EFD_pmMessage* pmmessage, char* rawdata, char* newdata) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = RECV_REPLACE_BODY;
	pm.pmdata1 = rawdata;
	pm.pmdata2 = newdata;
	*(pmmessage + index) = pm;
	return index;
}


//recv_��д���ص�����
int  __stdcall RecvResetHtml(EFD_pmMessage* pmmessage, char* newdata) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = RECV_RESET_BODY;
	pm.pmdata1 = newdata;
	*(pmmessage + index) = pm;
	return index;
}

//recv_�����������
int  __stdcall RecvInsertBody(EFD_pmMessage* pmmessage, char* adddata) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = RECV_INSERT_BODY;
	pm.pmdata1 = adddata;
	*(pmmessage + index) = pm;
	return index;
}

//recv_������������µ�cookie
int  __stdcall RecvInsertCookie(EFD_pmMessage* pmmessage, char* cookie) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = RECV_INSERT_COOKIE;
	pm.pmdata1 = cookie;
	*(pmmessage + index) = pm;
	return index;
}

//recv_�����������
int  __stdcall RecvRemoveCookie(EFD_pmMessage* pmmessage, char* adddata) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = RECV_REMOVE_COOKIE;
	*(pmmessage + index) = pm;
	return index;
}

//recv_���¸ı䷵�ص�״̬���״̬�ı�
int  __stdcall RecvResetState(EFD_pmMessage* pmmessage, char* stateCode, char* stateText) {
	int index = nextPmIndex(pmmessage);
	EFD_pmMessage pm = *(pmmessage + index);
	pm.type = RECV_RESET_STATE;
	pm.pmdata1 = stateCode;
	pm.pmdata2 = stateText;
	*(pmmessage + index) = pm;
	return index;
}
