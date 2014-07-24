// iatdemo_with_user_vocabulary.c : Defines the entry point for the console application.
//

#include "stdlib.h"
#include "stdio.h"
#include <windows.h>
#include <conio.h>
#include <errno.h>

#include "../../include/qisr.h"
#include "../../include/msp_cmn.h"
#include "../../include/msp_errors.h"


#ifdef _WIN64
#pragma comment(lib,"../../lib/msc_x64.lib")//x64
#else
#pragma comment(lib,"../../lib/msc.lib")//x86
#endif

#define  BUFFER_NUM 1024 * 4
#define  AMR_HEAD_SIZE  6
#define  MAX_KEYWORD_LEN 4096

int upload_user_vocabulary() 
{
	int ret = -1;
	char UserData[MAX_KEYWORD_LEN];
	unsigned int len = 0;
	FILE *fp = NULL;
	memset(UserData, 0, MAX_KEYWORD_LEN);
	fp = fopen("userwords.txt", "rb");//用户词表，必须为jason格式
	if (fp == NULL)
	{
		printf("userwords file cannot open\n");
		return ret;
	}
	len = (unsigned int)fread(UserData, 1, MAX_KEYWORD_LEN, fp);
	UserData[len] = 0;
	fclose(fp);
	MSPUploadData("userwords", UserData, len, "dtt=userword,sub=uup", &ret);
	if(ret != MSP_SUCCESS)
	{
		printf("QISRUploadData with errorCode: %d \n", ret);
		return ret;
	}
	return ret;
}

void run_iat(const char* src_wav_filename ,  const char* param)
{
	char rec_result[1024] = {0};
	const char *sessionID = NULL;
	FILE *f_pcm = NULL;
	char *pPCM = NULL;
	int lastAudio = 0 ;
	int audStat = MSP_AUDIO_SAMPLE_CONTINUE ;
	int epStatus = MSP_EP_LOOKING_FOR_SPEECH;
	int recStatus = MSP_REC_STATUS_SUCCESS ;
	long pcmCount = 0;
	long pcmSize = 0;
	int errCode = 10 ;

	sessionID = QISRSessionBegin(NULL, param, &errCode);
	f_pcm = fopen(src_wav_filename, "rb");
	if (NULL != f_pcm) {
		fseek(f_pcm, 0, SEEK_END);
		pcmSize = ftell(f_pcm);
		fseek(f_pcm, 0, SEEK_SET);
		pPCM = (char *)malloc(pcmSize);
		fread((void *)pPCM, pcmSize, 1, f_pcm);
		fclose(f_pcm);
		f_pcm = NULL;
	}
	while (1) {
		unsigned int len = 6400;
		int ret = 0;
		if (pcmSize < 12800) {
			len = pcmSize;
			lastAudio = 1;
		}
		audStat = MSP_AUDIO_SAMPLE_CONTINUE;
		if (pcmCount == 0)
			audStat = MSP_AUDIO_SAMPLE_FIRST;
		if (len<=0)
		{
			break;
		}
		printf("csid=%s,count=%d,aus=%d,",sessionID,pcmCount/len,audStat);
		ret = QISRAudioWrite(sessionID, (const void *)&pPCM[pcmCount], len, audStat, &epStatus, &recStatus);
		printf("eps=%d,rss=%d,ret=%d\n",epStatus,recStatus,errCode);
		if (ret != 0)
			break;
		pcmCount += (long)len;
		pcmSize -= (long)len;
		if (recStatus == MSP_REC_STATUS_SUCCESS) {
			const char *rslt = QISRGetResult(sessionID, &recStatus, 0, &errCode);
			if (NULL != rslt)
				strcat(rec_result,rslt);
		}
		if (epStatus == MSP_EP_AFTER_SPEECH)
			break;
		_sleep(150);//模拟人说话时间间隙
	}
	QISRAudioWrite(sessionID, (const void *)NULL, 0, MSP_AUDIO_SAMPLE_LAST, &epStatus, &recStatus);
	free(pPCM);
	pPCM = NULL;
	while (recStatus != MSP_REC_STATUS_COMPLETE && 0 == errCode ) {
		const char *rslt = QISRGetResult(sessionID, &recStatus, 0, &errCode);
		if (NULL != rslt)
		{
			strcat(rec_result,rslt);
		}
		_sleep(150);
	}
	QISRSessionEnd(sessionID, NULL);
	printf("=============================================================\n");
	printf("The result is: %s\n",rec_result);
	printf("=============================================================\n");
}

int main(int argc, char* argv[])
{
	///APPID请勿随意改动
	const char* login_configs = "dvc=hpsupokkkk1234567,appid = 53d11199, work_dir =   .  ";//dvc为设备号，用户词表上传后，再次使用时需要传入正确的设备号才能使用用户词表
	const char* param = "sub=iat,ssm=1,auf=audio/L16;rate=16000,aue=speex-wb;7,ent=sms16k,rst=plain,rse=gb2312";
	int ret = 0;
	char key = 0;

	//用户登录
	ret = MSPLogin(NULL, NULL, login_configs);//第一个参数为用户名，第二个参数为密码，第三个参数是登录参数，用户名和密码需要在http://open.voicecloud.cn注册并获取appid
	if ( ret != MSP_SUCCESS )
	{
		printf("MSPLogin failed , Error code %d.\n",ret);
		goto exit ;
	}
	//上传用户词表，
	upload_user_vocabulary();
	//开始一路转写会话
	run_iat("wav/iflytek10.wav" ,  param);//iflytek10音频内容为“杨光很好”如果MSPLogin设备号错误，识别结果为：“阳光很好”。
	exit:
	MSPLogout();//退出登录
	key = _getch();
	return 0;
}

