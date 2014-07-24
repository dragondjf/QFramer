// asrdemo.c : Defines the entry point for the console application.
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

#define  BUFFER_NUM  4096 
#define MAX_KEYWORD_LEN 4096
char GrammarID[128];

const char*  get_audio_file(void)
{
	char key = 0;
	while(key != 27)//按Esc则退出
	{
		system("cls");//清屏
		printf("请选择音频文件：\n");
		printf("1.科大讯飞\n");
		printf("2.阿里山龙胆\n");
		printf("3.齐鲁石化\n");
		printf("4.一二三四五六七八九十\n");
		printf("注意：第三条的音频故意结巴说出来的，用于展示效果。\n      关键字列表中没有第四条，展示如果用户说的词语不在列表中，会得到什么结果。\n");
		key = getchar();
		switch(key)
		{
		case '1':
			printf("1.科大讯飞\n");
			return "wav/iflytek01.wav";                               //iflytek01对应的音频内容“科大讯飞”
		case '2':
			printf("2.阿里山龙胆\n");
			return "wav/iflytek02.wav";                               //iflytek02对应的音频内容“阿里山龙胆”
		case '3':
			printf("3.齐鲁石化\n");
			return "wav/iflytek03.wav";                               //iflytek03对应的音频内容“齐鲁石化”
		case '4':
			printf("4.一二三四五六七八九十\n");
			return "wav/iflytek04.wav";                               //iflytek04对应的音频内容"一二三四五六七八九十"
		default:
			continue;
		}
	}
	exit(0);
	return NULL;
}

int get_grammar_id( int upload)
{
	int ret = MSP_SUCCESS;
	const char * sessionID = NULL;
	char UserData[MAX_KEYWORD_LEN];
	unsigned int len = 0;
	const char* testID = NULL;
	FILE *fp = NULL;
	memset(UserData, 0, MAX_KEYWORD_LEN);
	if (0 == upload)

	{
		strcpy(GrammarID, "e7eb1a443ee143d5e7ac52cb794810fe");
		//这个ID是我上传之后记录下来的。语法上传之后永久保存在服务器上，所以不要反复上传同样的语法
		return ret;
	}	
	//如果想要重新上传语法，传入参数upload置为TRUE，就可以走下面的上传语法流程
	fp = fopen("asr_keywords_utf8.txt", "rb");//关键字列表文件必须是utf8格式
	if (fp == NULL)
	{   
		ret = -1 ;
		printf("keyword file cannot open\n");
		return ret;
	}
	len = (unsigned int)fread(UserData, 1, MAX_KEYWORD_LEN, fp);
	UserData[len] = 0;
	fclose(fp);
    testID = MSPUploadData("userword", UserData, len, "dtt = userword, sub = asr", &ret);// sub 参数必需，否则返回空串
	if(ret != MSP_SUCCESS)
	{
		printf("UploadData with errorCode: %d \n", ret);
		return ret;
	}
	memcpy((void*)GrammarID, testID, strlen(testID));
	printf("GrammarID: \"%s\" \n", GrammarID);//将获得的GrammarID输出到屏幕上
	return ret;
}

int run_asr(const char* asrfile ,  const char* param)
{
	char rec_result[1024*4] = {0};
	const char *sessionID;
	FILE *f_pcm = NULL;
	char *pPCM = NULL;
	int lastAudio = 0 ;
	int audStat = MSP_AUDIO_SAMPLE_CONTINUE ;
	int epStatus = MSP_EP_LOOKING_FOR_SPEECH;
	int recStatus = MSP_REC_STATUS_SUCCESS ;
	long pcmCount = 0;
	long pcmSize = 0;
	int errCode = 0 ;
	sessionID = QISRSessionBegin(GrammarID, param, &errCode); //开始一路会话
	f_pcm = fopen(asrfile, "rb");
	if (NULL != f_pcm) {
		fseek(f_pcm, 0, SEEK_END);
		pcmSize = ftell(f_pcm);
		fseek(f_pcm, 0, SEEK_SET);
		pPCM = (char *)malloc(pcmSize);
		fread((void *)pPCM, pcmSize, 1, f_pcm);
		fclose(f_pcm);
		f_pcm = NULL;
	}//读取音频文件
	while (1) {
		unsigned int len = 6400;
		int ret;

		if (pcmSize < 12800) {
			len = pcmSize;
			lastAudio = 1;
		}
		audStat = MSP_AUDIO_SAMPLE_CONTINUE;//有后继音频
		if (pcmCount == 0)
			audStat = MSP_AUDIO_SAMPLE_FIRST;
		if (len<=0)
		{
			break;
		}
		printf("csid=%s,count=%d,aus=%d,",sessionID,pcmCount/len,audStat);
		ret = QISRAudioWrite(sessionID, (const void *)&pPCM[pcmCount], len, audStat, &epStatus, &recStatus);//写音频
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
	while (recStatus != MSP_REC_STATUS_COMPLETE && 0 == errCode) {
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
	return errCode ;
}

int main(int argc, char* argv[])
{
	const char* login_config = "appid = 53d11199, work_dir =   .  ";//登录参数
	const char* param = "sub=asr,aue=speex-wb,auf=audio/L16;rate=16000,ent=sms16k"; //注意sub=asr
	int ret = 0 ;
	char key = 0 ;
	int grammar_flag = 0 ;//0:不上传词表；1：上传词表
	const char* asrfile = get_audio_file();//选择待识别的语音文件
	ret = MSPLogin(NULL, NULL, login_config);//第一个参数为用户名，第二个参数为密码，第三个参数是登录参数，用户名和密码需要在http://open.voicecloud.cn注册并获取appid
	if ( ret != MSP_SUCCESS )
	{
		printf("MSPLogin failed , Error code %d.\n",ret);
		goto exit ;
	}
	memset(GrammarID, 0, sizeof(GrammarID));
	ret = get_grammar_id(grammar_flag);
	if(ret != MSP_SUCCESS)
	{
		printf("get_grammar_id with errorCode: %d \n", ret);
		goto exit ;
	}
 	ret = run_asr(asrfile, param);
	if(ret != MSP_SUCCESS)
	{
		printf("run_asr with errorCode: %d \n", ret);
		goto exit;
	}
	exit:
	MSPLogout();//退出登录
	key = _getch();
	return 0;
}

