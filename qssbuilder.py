# -*- coding: utf-8 -*-
import os
import sys
import copy

qssFolder = os.sep.join([os.getcwd(), 'skin', 'qss'])
qssTemplatePath = os.sep.join([qssFolder, 'template.qss'])


theme = {
    'main_gradient_color': "green",
    'main_background_color': "gray",
    'main_hover_color': "red",
    'main_select_color': "white",
    'combox_background_color': "black"
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
