 /*
 * Module:   TRTCCloudCallback @ TXLiteAVSDK
 *
 * Function: ��Ѷ����Ƶͨ�����ܵĻص��ӿ���
 *
 */
 
#ifndef __TRTCENGINECALLBACK_H__
#define __TRTCENGINECALLBACK_H__

#include "TRTCCloudDef.h"
#include "TRTCStatistics.h"
#include "TXLiteAVCode.h"

/**
 * ��Ѷ����Ƶͨ�����ܵĻص��ӿ���
 */
class ITRTCCloudCallback
{
public:
    virtual ~ITRTCCloudCallback() {}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      ��һ�������¼��;����¼�
    //
    /////////////////////////////////////////////////////////////////////////////////
    /// @name ͨ���¼��ص�
    /// @{

    /**
    * 1.1 ����ص���SDK ���ɻָ��Ĵ���һ��Ҫ����������������û��ʵ��Ľ�����ʾ��
    *
    * @param errCode 	������
    * @param errMsg 	������Ϣ
    * @param extraInfo ��չ��Ϣ�ֶΣ������������ܻ���������Ϣ������λ����
    */
    virtual void onError(TXLiteAVError errCode, const char* errMsg, void* extraInfo) = 0;

    /**
    * 1.2 ����ص������ڸ�֪��һЩ�����������⣬��������˿��ٻ��߿ɻָ��Ľ���ʧ�ܡ�
    *
    * @param warningCode ������
    * @param warningMsg ������Ϣ
    * @param extraInfo ��չ��Ϣ�ֶΣ����𾯸�����ܻ���������Ϣ������λ����
    */
    virtual void onWarning(TXLiteAVWarning warningCode, const char* warningMsg, void* extraInfo) = 0;
    /// @}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      �����������¼��ص�
    //
    /////////////////////////////////////////////////////////////////////////////////
    /// @name �����¼��ص�
    /// @{
    /**
    * 2.1 �Ѽ��뷿��Ļص�
    *
    * ���� TRTCCloud �е� enterRoom() �ӿ�ִ�н��������󣬻��յ����� SDK �� onEnterRoom(result) �ص���
    * �������ɹ���result ����һ��������result > 0�����������뷿���ʱ�����ģ���λ�Ǻ��루ms����
    * �������ʧ�ܣ�result ����һ��������result < 0������������ʧ�ܵĴ����롣
    * ����ʧ�ܵĴ����뺬�������[�������](https://cloud.tencent.com/document/product/647/32257)��
    *
    * @note �� Ver6.6 ֮ǰ�İ汾��ֻ�н����ɹ����׳� onEnterRoom(result) �ص�������ʧ���� onError() �ص��׳���
    *       �� Ver6.6 ��֮���Ϊ�������ɹ��������� result������ʧ�ܷ��ظ��� result��ͬʱ����ʧ��Ҳ���� onError() �ص��׳���
    *
    * @param result result > 0 ʱΪ������ʱ��ms����result < 0 ʱΪ���������롣
    */
    virtual void onEnterRoom(int result) = 0;

    /**
    * 2.2 �뿪������¼��ص�
    *
    * ���� TRTCCloud �е� exitRoom() �ӿڻ�ִ���˳����������߼��������ͷ�����Ƶ�豸��Դ�ͱ��������Դ�ȡ�
    * ����Դ�ͷ����֮��SDK ��ͨ�� onExitRoom() �ص�֪ͨ������
    *
    * �����Ҫ�ٴε��� enterRoom() �����л�������������Ƶ SDK����ȴ� onExitRoom() �ص�����֮����ִ����ز�����
    * ������ܻ�����������ͷ����˷��豸��ǿռ�ȸ����쳣���⡣
    *
    * @param reason �뿪����ԭ��0���������� exitRoom �˷���1�����������߳���ǰ���䣻2����ǰ������������ɢ��
    */
    virtual void onExitRoom(int reason) = 0;

    /**
     * 2.3 �л���ɫ���¼��ص�
     *
     * ���� TRTCCloud �е� switchRole() �ӿڻ��л������͹��ڵĽ�ɫ���ò��������һ����·�л��Ĺ��̣�
     * �� SDK �л���ɺ󣬻��׳� onSwitchRole() �¼��ص���
     *
     * @param errCode �����룬ERR_NULL �����л��ɹ������������[�������](https://cloud.tencent.com/document/product/647/32257)��
     * @param errMsg  ������Ϣ��
     */
    virtual void onSwitchRole(TXLiteAVError errCode, const char* errMsg) {}

    /**
    * 2.4 ����緿ͨ�������� PK���Ľ���ص�
    *
    * ���� TRTCCloud �е� connectOtherRoom() �ӿڻὫ������ͬ�����е�������ͨ��Ƶͨ����Ҳ������ν�ġ�����PK�����ܡ�
    * �����߻��յ� onConnectOtherRoom() �ص�����֪�緿ͨ���Ƿ�ɹ���
    * ����ɹ������������е������û������յ� PK ������ onUserVideoAvailable() �ص���
    *
    * @param userId Ҫ PK ��Ŀ������ userId��
    * @param errCode �����룬ERR_NULL �����л��ɹ������������[�������](https://cloud.tencent.com/document/product/647/32257)��
    * @param errMsg  ������Ϣ��
    */
    virtual void onConnectOtherRoom(const char* userId, TXLiteAVError errCode, const char* errMsg) {}

    /**
    * 2.5 �����緿ͨ�������� PK���Ľ���ص�
    */
    virtual void onDisconnectOtherRoom(TXLiteAVError errCode, const char* errMsg) {}
    /// @}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      ��������Ա�¼��ص�
    //
    /////////////////////////////////////////////////////////////////////////////////
    /// @name ��Ա�¼��ص�
    /// @{
    /**
    * 3.1 ���û������������뵱ǰ����
    *
    * û�п�������Ƶ���еĹ����ڼ��뷿��ʱ���ᴥ����֪ͨ��ֻ�п�������Ƶ���е��������뷿��ʱ�Żᴥ����֪ͨ��
    * ֪ͨ�����е� userId Ҳ��һ�����ǿ�����Ƶ�ģ�����ֻ���������������С�
    *
    * ���Ҫ��ʾԶ�̻��棬���Ƽ����� onUserVideoAvailable() �¼��ص���
    *
    * @param userId �û���ʶ
    */
    virtual void onUserEnter(const char* userId) = 0;

    /**
    * 3.2 ���û����������뿪��ǰ����
    *
    * @param userId �û���ʶ
    * @param reason �뿪ԭ����룬�����û��������뿪����������������ߵ�ԭ���뿪��
    */
    virtual void onUserExit(const char* userId, int reason) = 0;

    /**
    * 3.3 �û��Ƿ�������ͷ��Ƶ
    *
    * �����յ� onUserVideoAvailable(userId, YES) ֪ͨʱ��������·�����Ѿ��п��õ���Ƶ����֡���
    * ֮������Ҫ���� startRemoteView(userId) �ӿڼ��ظ��û���Զ�̻��档
    * ��֮���������յ���Ϊ onFirstVideoFrame(userId) ����֡������Ⱦ�ص���
    *
    * �����յ��� onUserVideoAvailable(userId, NO) ֪ͨʱ��������·Զ�̻����Ѿ����رգ��������
    * ���ڸ��û������� muteLocalVideo() �� stopLocalPreview() ���¡�
    *
    * @param userId �û���ʶ
    * @param available �����Ƿ���
    */
    virtual void onUserVideoAvailable(const char* userId, bool available) {}

    /**
    * 3.4 �û��Ƿ�����Ļ����
    *
    * @note ��ʾ��·����ʹ�õĺ������� startRemoteView() ���� startRemoteSubStreamView()��
    * @param userId �û���ʶ
    * @param available ��Ļ�����Ƿ���
    */
    virtual void onUserSubStreamAvailable(const char* userId, bool available) {}

    /**
    * 3.5 �û��Ƿ�����Ƶ����
    *
    * @param userId �û���ʶ
    * @param available �����Ƿ���
    */
    virtual void onUserAudioAvailable(const char* userId, bool available) {}

    /**
    * 3.6 ��ʼ��Ⱦ���ػ�Զ���û�����֡����
    *
    * ��� userId Ϊ null��������ʼ��Ⱦ���زɼ�������ͷ���棬��Ҫ���ȵ��� startLocalPreview ������
    * ��� userId ��Ϊ null��������ʼ��ȾԶ���û�����֡���棬��Ҫ���ȵ��� startRemoteView ������
    *
    * @note ֻ�е������� startLocalPreview()��startRemoteView() �� startRemoteSubStreamView() ֮�󣬲Żᴥ���ûص���
    *
    * @param userId ���ػ�Զ���û� ID����� userId == null �������أ�userId != null ����Զ�̡�
    * @param streamType ��Ƶ�����ͣ�����ͷ����Ļ������
    * @param width  �������
    * @param height ����߶�
    */
    virtual void onFirstVideoFrame(const char* userId, const TRTCVideoStreamType streamType, const int width, const int height) {}

    /**
    * 3.7 ��ʼ����Զ���û�����֡��Ƶ�����������ݲ�֪ͨ��
    *
    * @param userId Զ���û� ID��
    */
    virtual void onFirstAudioFrame(const char* userId) {}

    /**
    * 3.8 ��֡������Ƶ�����Ѿ����ͳ�
    *
    * SDK ���� enterRoom() �� startLocalPreview() �ɹ���ʼ����ͷ�ɼ��������ɼ����Ļ�����б��롣
    * �� SDK �ɹ����ƶ��ͳ���һ֡��Ƶ���ݺ󣬻��׳�����ص��¼���
    *
    * @param streamType ��Ƶ�����ͣ����滹��С����������棨��Ļ������
    */
    virtual void onSendFirstLocalVideoFrame(const TRTCVideoStreamType streamType) {}

    /**
    * 3.9 ��֡������Ƶ�����Ѿ����ͳ�
    *
    * SDK ���� enterRoom() �� startLocalAudio() �ɹ���ʼ��˷�ɼ��������ɼ������������б��롣
    * �� SDK �ɹ����ƶ��ͳ���һ֡��Ƶ���ݺ󣬻��׳�����ص��¼���
    */
    virtual void onSendFirstLocalAudioFrame() {}
    /// @}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      ���ģ�ͳ�ƺ������ص�
    //
    /////////////////////////////////////////////////////////////////////////////////
    /// @name ͳ�ƺ������ص�
    /// @{
    /**
    * 4.1 �����������ûص�ÿ2�봥��һ�Σ�ͳ�Ƶ�ǰ��������к���������
    *
    * @note userId == null �����Լ���ǰ����Ƶ����
    *
    * @param localQuality ������������
    * @param remoteQuality ������������
    * @param remoteQualityCount �������������������С
    */
    virtual void onNetworkQuality(TRTCQualityInfo localQuality, TRTCQualityInfo* remoteQuality, uint32_t remoteQualityCount) {}

    /**
    * 4.2 ����ָ��ͳ�ƻص�
    *
    * ���������Ϥ����Ƶ��������������ͨ������ص���ȡ SDK �����м���ָ�ꡣ
    * ��������״ο�������Ƶ�����Ŀ������ֻ��ע onNetworkQuality �ص���
    *
    * @param statis ͳ�����ݣ��������غ�Զ�̵�
    * @note ÿ2��ص�һ��
    */
    virtual void onStatistics(const TRTCStatistics& statis) {}
    /// @}


    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      ���壩�������¼��ص�
    //
    /////////////////////////////////////////////////////////////////////////////////

    /// @name �������¼��ص�
    /// @{

    /**
    * 5.1 SDK �������������ӶϿ�
    */
    virtual void onConnectionLost() {}

    /**
    * 5.2 SDK �����������ӵ�������
    */
    virtual void onTryToReconnect() {}

    /**
    * 5.3 SDK �������������ӻָ�
    */
    virtual void onConnectionRecovery() {}

    /**
    * 5.4 ���������ٵĻص���SDK �Զ�������� IP �����٣�ÿ�� IP �Ĳ��ٽ��ͨ������ص�֪ͨ
    *
    * @param currentResult ��ǰ��ɵĲ��ٽ��
    * @param finishedCount ����ɲ��ٵķ���������
    * @param totalCount ��Ҫ���ٵķ�����������
    */
    virtual void onSpeedTest(const TRTCSpeedTestResult& currentResult, uint32_t finishedCount, uint32_t totalCount) {}
    /// @}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      ������Ӳ���豸�¼��ص�
    //
    /////////////////////////////////////////////////////////////////////////////////
    /// @name Ӳ���豸�¼��ص�
    /// @{
    /**
    * 6.1 ����ͷ׼������
    */
    virtual void onCameraDidReady() {}

    /**
    * 6.2 ��˷�׼������
    */
    virtual void onMicDidReady() {}

    /**
    * 6.3 ������ʾ������С�Ļص�,����ÿ�� userId ��������Զ��������
    *
    * ������ͨ������ TRTCCloud �е� enableAudioVolumeEvaluation �ӿ�����������ص������������Ĵ��������
    * ��Ҫע����ǣ����� enableAudioVolumeEvaluation ���������ص�������Ƶ�����Ƿ�����˵�������ᰴ���õ�ʱ������������ص�;
    * ���û����˵������ userVolumes Ϊ�գ�totalVolume Ϊ0��
    *
    * @param userVolumes ��������˵���ķ����Ա��������ȡֵ��Χ0 - 100��
    * @param userVolumesCount �����Ա����
    * @param totalVolume ����Զ�˳�Ա��������, ȡֵ��Χ0 - 100��
    * @note userId Ϊ null ʱ��ʾ�Լ���������userVolumes �ڽ���������˵����������Ϊ0�����û�������Ϣ��
    */
    virtual void onUserVoiceVolume(TRTCVolumeInfo* userVolumes, uint32_t userVolumesCount, uint32_t totalVolume) {}

    /**
    * 6.4 �����豸ͨ�ϻص�
    *
    * @param deviceId �豸 ID
    * @param type �豸����
    * @param state �¼�����
    */
    virtual void onDeviceChange(const char* deviceId, TRTCDeviceType type, TRTCDeviceState state) {}

    /**
    * 6.5 ��˷���������ص�
    * 
    * ��˷���Խӿ� startMicDeviceTest �ᴥ������ص�
    *
    * @param volume ����ֵ��ȡֵ��Χ0 - 100
    */
    virtual void onTestMicVolume(uint32_t volume) {}

    /**
    * 6.6 ���������������ص�
    * 
    * ���������Խӿ� startSpeakerDeviceTest �ᴥ������ص�
    *
    * @param volume ����ֵ��ȡֵ��Χ0 - 100
    */
    virtual void onTestSpeakerVolume(uint32_t volume) {}
    /// @}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      ���ߣ��Զ�����Ϣ�Ľ��ջص�
	//
    /////////////////////////////////////////////////////////////////////////////////
    /// @name �Զ�����Ϣ�Ľ��ջص�
    /// @{
    /**
    * 7.1 �յ��Զ�����Ϣ�ص�
    *
    * �������е�ĳ���û�ʹ�� sendCustomCmdMsg �����Զ�����Ϣʱ�������е������û�����ͨ�� onRecvCustomCmdMsg �ӿڽ�����Ϣ
    *
    * @param userId �û���ʶ
    * @param cmdID ���� ID
    * @param seq   ��Ϣ���
    * @param message ��Ϣ����
    * @param messageSize ��Ϣ���ݴ�С
    */
    virtual void onRecvCustomCmdMsg(const char* userId, int32_t cmdID, uint32_t seq, const uint8_t* message, uint32_t messageSize) {}

    /**
    * 7.2 �Զ�����Ϣ��ʧ�ص�
    *
    * TRTC ��ʹ�õĴ���ͨ��Ϊ UDP ͨ�������Լ�ʹ������ reliable��Ҳ������100%����ʧ��ֻ�Ƕ���Ϣ���ʼ��ͣ������㳣��ɿ���Ҫ��
    * �ڹ�ȥ��һ��ʱ���ڣ�ͨ��Ϊ5s�����Զ�����Ϣ�ڴ���;�ж�ʧ����Ϣ������ͳ�ƣ�SDK ����ͨ���˻ص�֪ͨ������
    *
    * @note  ֻ���ڷ��Ͷ������˿ɿ����䣨reliable�������շ������յ���Ϣ�Ķ�ʧ�ص�
    * @param userId �û���ʶ
    * @param cmdID ���� ID
    * @param errCode ������
    * @param missed ��ʧ����Ϣ����
    */
    virtual void onMissCustomCmdMsg(const char* userId, int32_t cmdID, int32_t errCode, int32_t missed) {}


    /**
    * 7.3 �յ� SEI ��Ϣ�Ļص�
    *
    * �������е�ĳ���û�ʹ�� sendSEIMsg ��������ʱ�������е������û�����ͨ�� onRecvSEIMsg �ӿڽ������ݡ�
    *
    * @param userId   �û���ʶ
    * @param message  ����
    * @param messageSize ���ݴ�С
    */
    virtual void onRecvSEIMsg(const char* userId, const uint8_t* message, uint32_t messageSize) {};
    /// @}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      ���ˣ�CDN ��·ת�ƻص�
    //
    /////////////////////////////////////////////////////////////////////////////////
    /// @name CDN ��·ת�ƻص�
    /// @{
    /**
    * 8.1 ������·������ CDN ��ɵĻص�
    *
    * ��Ӧ�� TRTCCloud �е� startPublishCDNStream() �ӿ�
    *
    * @note Start �ص�����ɹ���ֻ��˵��ת�������Ѿ��ɹ���֪����Ѷ�ƣ����Ŀ�� CDN ���쳣�������п��ܻ�ת��ʧ�ܡ�
    */
    virtual void onStartPublishCDNStream(int errCode, const char* errMsg) {};

    /**
    * 8.2 ֹͣ��·������ CDN ��ɵĻص�
    *
    * ��Ӧ�� TRTCCloud �е� stopPublishCDNStream() �ӿ�
    *
    */
    virtual void onStopPublishCDNStream(int errCode, const char* errMsg) {};

    /**
    * 8.3 �����ƶ˵Ļ���ת������Ļص�����Ӧ�� TRTCCloud �е� setMixTranscodingConfig() �ӿ�
    *
    * @param errCode 0��ʾ�ɹ�������ֵ��ʾʧ��
    * @param errMsg �������ԭ��
    */
    virtual void onSetMixTranscodingConfig(int errCode, const char* errMsg) {};
    /// @}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      ���ţ���Ļ�����ص�
	//
    //
    /////////////////////////////////////////////////////////////////////////////////
    /// @name ��Ļ�����ص�
    /// @{
    /**
    * 9.1 ����Ļ�������ڱ��ڵ��޷���������ʱ��SDK ��ͨ���˻ص�֪ͨ�����ڴ˻ص���֪ͨ�û��ƿ��ڵ�����
    */
    virtual void onScreenCaptureCovered() {};

    /**
    * 9.2 ����Ļ������ʼʱ��SDK ��ͨ���˻ص�֪ͨ
    */
    virtual void onScreenCaptureStarted() {};

    /**
    * 9.3 ����Ļ������ͣʱ��SDK ��ͨ���˻ص�֪ͨ
    *
    * @param reason ֹͣԭ��0����ʾ�û�������ͣ��1����ʾ������Ļ�����������µ���ͣ��2����ʾ��Ļ�������ڱ���С�����µ���ͣ��3����ʾ��Ļ�������ڱ����ص��µ���ͣ
    */
    virtual void onScreenCapturePaused(int reason) {};

    /**
    * 9.4 ����Ļ�����ָ�ʱ��SDK ��ͨ���˻ص�֪ͨ
    *
    * @param reason ֹͣԭ��0����ʾ�û������ָ���1����ʾ��Ļ��������������Ϻ��Զ��ָ���2����ʾ��Ļ�������ڴ���С�����ָ���3����ʾ��Ļ�������ڴ����ر��ָ�
    */
    virtual void onScreenCaptureResumed(int reason) {};

    /**
    * 9.5 ����Ļ����ֹͣʱ��SDK ��ͨ���˻ص�֪ͨ
    *
    * @param reason ֹͣԭ��0����ʾ�û�����ֹͣ��1����ʾ��Ļ�������ڱ��ر�
    */
    virtual void onScreenCaptureStoped(int reason) {};
    /// @}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      ��ʮ�����������¼��ص�
    //
    /////////////////////////////////////////////////////////////////////////////////
    /// @name ���������¼��ص�
    /// @{

    /**
    * 10.1 ��ʼ���ű�������
    *
    * @param errCode ������
    */
    virtual void onPlayBGMBegin(TXLiteAVError errCode) {}

    /**
    * 10.2 ���ű������ֵĽ���
    *
    * @param progressMS �Ѳ���ʱ��
    * @param durationMS ��ʱ��
    */
    virtual void onPlayBGMProgress(uint32_t progressMS, uint32_t durationMS) {}

    /**
    * 10.3 ���ű������ֽ���
    *
    * @param errCode ������
    */
    virtual void onPlayBGMComplete(TXLiteAVError errCode) {}
    /// @}
};


/////////////////////////////////////////////////////////////////////////////////
//
//                      ��ʮһ���Զ�����Ƶ��Ⱦ�ص�
//
/////////////////////////////////////////////////////////////////////////////////

/// �Զ�����Ƶ��Ⱦ�ص�
class ITRTCVideoRenderCallback
{
public:
    virtual ~ITRTCVideoRenderCallback() {}
    /**
    * 11.1 �Զ�����Ƶ��Ⱦ�ص�
    * 
    * ����ͨ�� setLocalVideoRenderCallback �� setRemoteVideoRenderCallback �ӿ������Զ�����Ⱦ�ص�
    *
    * @param userId     �û���ʶ
    * @param streamType	�����ͣ�������ͷ������Ļ����
    * @param frame      ��Ƶ֡����
    */
    virtual void onRenderVideoFrame(const char* userId, TRTCVideoStreamType streamType, TRTCVideoFrame* frame) {}
};


/////////////////////////////////////////////////////////////////////////////////
//
//                      ��ʮ������Ƶ���ݻص�
//
/////////////////////////////////////////////////////////////////////////////////

class ITRTCAudioFrameCallback
{
public:
    virtual ~ITRTCAudioFrameCallback() {}
    /**
    * 12.1 ������˷�ɼ�������Ƶ���ݻص�
    * @note - �벻Ҫ�ڴ˻ص����������κκ�ʱ����������ֱ�ӿ�������һ�߳̽��д���������ᵼ�¸����������⡣
    *       - �˽ӿڻص�������Ƶ������ֻ���ģ���֧���޸ġ�
    */
    virtual void onCapturedAudioFrame(TRTCAudioFrame *frame) {};

    /**
    * 12.2 ����ǰ��ÿһ·Զ���û�����Ƶ���ݣ�������Ҫ��ĳһ·��������������ת��������Ҫʹ�������ԭʼ���ݣ������ǻ���֮������ݣ�
    * 
    * @param frame      ��Ƶ����
    * @param userId     �û���ʶ
    * @note - �벻Ҫ�ڴ˻ص����������κκ�ʱ����������ֱ�ӿ�������һ�߳̽��д���������ᵼ�¸����������⡣
    *       - �˽ӿڻص�������Ƶ������ֻ���ģ���֧���޸ġ�
    */
    virtual void onPlayAudioFrame(TRTCAudioFrame *frame, const char* userId) {};
    /**
    * 12.3 ��·��Ƶ���ݻ�Ϻ��������Ȳ��ŵ���Ƶ����
    * @note - �벻Ҫ�ڴ˻ص����������κκ�ʱ����������ֱ�ӿ�������һ�߳̽��д���������ᵼ�¸����������⡣
    *       - �˽ӿڻص�������Ƶ������ֻ���ģ���֧���޸ġ�
    */
    virtual void onMixedPlayAudioFrame(TRTCAudioFrame *frame) {};
};

/////////////////////////////////////////////////////////////////////////////////
//
//                      ��ʮ����Log ��Ϣ�ص�
//
/////////////////////////////////////////////////////////////////////////////////

/// ��־��ػص�
class ITRTCLogCallback
{
public:
    virtual ~ITRTCLogCallback() {}
    /**
    * 13.1 ����־��ӡʱ�Ļص�
    *
    * @param log ��־����
    * @param level ��־�ȼ� �μ� TRTCLogLevel
    * @param module ���޾������壬ĿǰΪ�̶�ֵ TXLiteAVSDK
    */
    virtual void onLog(const char* log, TRTCLogLevel level, const char* module) {}
};

#endif /* __TRTCENGINECALLBACK_H__ */