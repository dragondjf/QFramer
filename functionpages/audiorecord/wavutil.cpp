/****************************************************************************
**
** Copyright (C) 2014 dragondjf
**
** QFramer is a frame based on Qt5.3, you will be more efficient with it. 
** As an Qter, Qt give us a nice coding experience. With user interactive experience(UE) 
** become more and more important in modern software, deveployers should consider business and UE.
** So, QFramer is born. QFramer's goal is to be a mature solution 
** which you only need to be focus on your business but UE for all Qters.
**
** Version	: 0.2.5.0
** Author	: dragondjf
** Website	: https://github.com/dragondjf
** Project	: https://github.com/dragondjf/QCFramer
** Blog		: http://my.oschina.net/dragondjf/home/?ft=atme
** Wiki		: https://github.com/dragondjf/QCFramer/wiki
** Lincence: LGPL V2
** QQ: 465398889
** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
** 
****************************************************************************/

#include "wavutil.h"

char GrammarID[128];
// This function returns the maximum possible sample value for a given audio format
qreal getPeakValue(const QAudioFormat& format)
{
    // Note: Only the most common sample formats are supported
    if (!format.isValid())
        return qreal(0);

    if (format.codec() != "audio/pcm")
        return qreal(0);

    switch (format.sampleType()) {
    case QAudioFormat::Unknown:
        break;
    case QAudioFormat::Float:
        if (format.sampleSize() != 32) // other sample formats are not supported
            return qreal(0);
        return qreal(1.00003);
    case QAudioFormat::SignedInt:
        if (format.sampleSize() == 32)
            return qreal(INT_MAX);
        if (format.sampleSize() == 16)
            return qreal(SHRT_MAX);
        if (format.sampleSize() == 8)
            return qreal(CHAR_MAX);
        break;
    case QAudioFormat::UnSignedInt:
        if (format.sampleSize() == 32)
            return qreal(UINT_MAX);
        if (format.sampleSize() == 16)
            return qreal(USHRT_MAX);
        if (format.sampleSize() == 8)
            return qreal(UCHAR_MAX);
        break;
    }

    return qreal(0);
}

// returns the audio level for each channel
QVector<qreal> getBufferLevels(const QAudioBuffer& buffer)
{
    QVector<qreal> values;

    if (!buffer.format().isValid() || buffer.format().byteOrder() != QAudioFormat::LittleEndian)
        return values;

    if (buffer.format().codec() != "audio/pcm")
        return values;

    int channelCount = buffer.format().channelCount();
    values.fill(0, channelCount);
    qreal peak_value = getPeakValue(buffer.format());
    if (qFuzzyCompare(peak_value, qreal(0)))
        return values;

    switch (buffer.format().sampleType()) {
    case QAudioFormat::Unknown:
    case QAudioFormat::UnSignedInt:
        if (buffer.format().sampleSize() == 32)
            values = getBufferLevels(buffer.constData<quint32>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 16)
            values = getBufferLevels(buffer.constData<quint16>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 8)
            values = getBufferLevels(buffer.constData<quint8>(), buffer.frameCount(), channelCount);
        for (int i = 0; i < values.size(); ++i)
            values[i] = qAbs(values.at(i) - peak_value / 2) / (peak_value / 2);
        break;
    case QAudioFormat::Float:
        if (buffer.format().sampleSize() == 32) {
            values = getBufferLevels(buffer.constData<float>(), buffer.frameCount(), channelCount);
            for (int i = 0; i < values.size(); ++i)
                values[i] /= peak_value;
        }
        break;
    case QAudioFormat::SignedInt:
        if (buffer.format().sampleSize() == 32)
            values = getBufferLevels(buffer.constData<qint32>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 16)
            values = getBufferLevels(buffer.constData<qint16>(), buffer.frameCount(), channelCount);
        if (buffer.format().sampleSize() == 8)
            values = getBufferLevels(buffer.constData<qint8>(), buffer.frameCount(), channelCount);
        for (int i = 0; i < values.size(); ++i)
            values[i] /= peak_value;
        break;
    }

    return values;
}

template <class T>
QVector<qreal> getBufferLevels(const T *buffer, int frames, int channels)
{
    QVector<qreal> max_values;
    max_values.fill(0, channels);

    for (int i = 0; i < frames; ++i) {
        for (int j = 0; j < channels; ++j) {
            qreal value = qAbs(qreal(buffer[i * channels + j]));
            if (value > max_values.at(j))
                max_values.replace(j, value);
        }
    }

    return max_values;
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

int run_asr(const char* asrfile ,  const char* param, char* rec_result)
{
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

QString wavToText(const char *wavfilename)
{
    const char* login_config = "appid = 53d11199, work_dir =   .  ";//登录参数
    const char* param = "sub=asr,aue=speex-wb,auf=audio/L16;rate=16000,ent=sms16k"; //注意sub=asr
    int ret = 0 ;
    char key = 0 ;
    int grammar_flag = 0 ;//0:不上传词表；1：上传词表
    const char* asrfile = wavfilename;//选择待识别的语音文件
    char rec_result[1024*4] = {0};
    ret = MSPLogin("465398889@qq.com", "ding123456789", login_config);//第一个参数为用户名，第二个参数为密码，第三个参数是登录参数，用户名和密码需要在http://open.voicecloud.cn注册并获取appid
    if ( ret != MSP_SUCCESS )
    {
        printf("MSPLogin failed , Error code %d.\n",ret);
        return "0";
    }
    memset(GrammarID, 0, sizeof(GrammarID));
    ret = get_grammar_id(grammar_flag);
    if(ret != MSP_SUCCESS)
    {
        printf("get_grammar_id with errorCode: %d \n", ret);
        return "1";
    }
    ret = run_asr(asrfile, param, rec_result);
    if(ret != MSP_SUCCESS)
    {
        printf("run_asr with errorCode: %d \n", ret);
        return "2";
    }
    MSPLogout();//退出登录
}
