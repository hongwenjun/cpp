import os
import azure.cognitiveservices.speech as speechsdk

import win32clipboard as w

def get_clipboard_text():
    w.OpenClipboard()
    try:
        text = w.GetClipboardData()
    except TypeError:
        text = ""
    w.CloseClipboard()
    return text

class SPEECH:
    def __init__(self):
        # 需要转语音的文本文字
        # 设置音频保存本地地址
        self.output_file = "r:\\output.wav"
        # 从环境变量中获取订阅密钥和区域信息
        self.speech_config = speechsdk.SpeechConfig(subscription=os.environ.get('SPEECH_KEY'),
                                                    region=os.environ.get('SPEECH_REGION'))
        # 设置语音合成使用的语言——  云枫  
        self.speech_config.speech_synthesis_language = "zh-CN"
        # self.speech_config.speech_synthesis_voice_name = 'zh-CN-YunfengNeural'    # 云枫
        self.speech_config.speech_synthesis_voice_name = 'zh-CN-XiaoxiaoNeural'     # 晓晓

    def speak_txt(self):
        # 配置音频输出为默认扬声器
        audio_config = speechsdk.audio.AudioOutputConfig(use_default_speaker=True)
        return audio_config

    def down_audio(self):
        # 配置音频输出为默认扬声器
        audio_config = speechsdk.audio.AudioOutputConfig(filename=self.output_file)
        return audio_config

    def run(self, text, audio_config):

        # 创建语音合成器
        speech_synthesizer = speechsdk.SpeechSynthesizer(speech_config=self.speech_config, audio_config=audio_config)

        # 调用语音合成API将文本转换为语音
        speech_synthesis_result = speech_synthesizer.speak_text_async(text).get()

        # 检查语音合成的结果并进行相应的处理
        if speech_synthesis_result.reason == speechsdk.ResultReason.SynthesizingAudioCompleted:
            print("Speech synthesized for text [{}]".format(text))
        elif speech_synthesis_result.reason == speechsdk.ResultReason.Canceled:
            cancellation_details = speech_synthesis_result.cancellation_details
            print("Speech synthesis canceled: {}".format(cancellation_details.reason))
            if cancellation_details.reason == speechsdk.CancellationReason.Error:
                if cancellation_details.error_details:
                    print("Error details: {}".format(cancellation_details.error_details))
                    print("Did you set the speech resource key and region values?")


if __name__ == "__main__":
    my_speech = SPEECH()

    # 从剪贴板获取要转换为语音的文本
    text = get_clipboard_text()
    
    if not text:
        print("剪贴板没有内容，请复制一些文本。")
    else:
        # 保存到本地
        # my_speech.run(text, my_speech.down_audio())
        print(text)
        # 输出语音播放
        my_speech.run(text, my_speech.speak_txt())