# -*- coding: utf-8 -*-
import os
import sys
import copy

qssFolder = os.sep.join([os.getcwd(), 'skin', 'qss'])
qssTemplatePath = os.sep.join([qssFolder, 'template.qss'])


theme = {
    'main_gradient_color': "qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgb(24, 148, 120), stop:0.5 rgb(220, 220, 220), stop:1 rgb(14, 148, 246))",
    'main_background_color': "qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgb(24, 148, 120), stop:1 rgb(14, 148, 246))",
    'main_hover_color': "rgb(153, 217, 234)",
    'main_select_color': "rgb(21, 206, 109)",
    'Ftitle_color': 'white',
    'Label_color': "black",
    'PushButton_background_color': "rgb(24, 148, 120)",
    'Combox_background_color': "rgb(0, 0, 64)",
    'ScrollBar_background_color': "qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgb(24, 148, 120), stop:1 rgb(14, 148, 246))",
    'ScrollBar_handle_color': "lightgray",
    'HeadView_background_color': "rgb(21, 206, 109)",
    'TableTree_background_color': "rgb(24, 148, 120)"
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
