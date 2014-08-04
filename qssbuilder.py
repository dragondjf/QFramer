# -*- coding: utf-8 -*-
import os
import sys
import copy

qssFolder = os.sep.join([os.getcwd(), 'skin', 'qss'])
qssTemplatePath = os.sep.join([qssFolder, 'template.qss'])


theme = {
    'main_background_color': "white",   # 主窗体背景颜色
    'nav_background_color': "rgb(94, 183, 38)", # 导航条背景颜色
    'main_hover_color': "rgb(127, 199, 82)", # 导航条hover背景颜色
    'main_select_color': "rgb(76, 148, 31)", # 导航条select背景颜色
    'border_separator': "0px solid rgb(0, 206, 161)", # 分割线背景
    'Ftitle_color': 'white', # 标题title字体颜色
    'Menu_border_left': "5px solid rgb(255, 127, 39)", # 菜单左边界
    'AntimationLine_background-color': 'green', # 页面切换时动画进度条的背景颜色
    'Label_color': "rgb(255, 127, 39)", # label字体颜色
    'PushButton_color': "white", # 按钮字体颜色
    'PushButton_background_color': "rgb(88, 197, 1)", #按钮背景颜色
    'PushButton_border_left': "5px solid rgb(255, 127, 39)", #按钮左边界颜色
    'PushButton_border_bottom': "0px solid rgb(255, 127, 39)", #按钮下边界颜色
    'Combox_background_color': "rgb(0, 0, 64)", #combox背景颜色
    'ScrollBar_background_color': "white", #滚动条背景颜色
    'ScrollBar_handle_color': "lightgray", #滚动条滚动颜色
    'HeadView_background_color': "rgb(21, 206, 109)", # headview背景颜色
    'TableTree_background_color': "rgb(88, 197, 1)" # tabtree背景颜色
}


if __name__ == '__main__':
    if len(sys.argv) >= 2:
        newQssFileName = sys.argv[1]
    else:
        newQssFileName = "test.qss"

    qssOutFileName = os.sep.join([qssFolder, newQssFileName])

    with open(qssTemplatePath) as f:
        qssContent = f.read()
        for key, value in theme.items():
            qssContent = qssContent.replace(key, value)

    with open(qssOutFileName, 'w') as f:
        f.write(qssContent)
