# -*- coding: utf-8 -*-
import os
import sys
import copy
import shutil
import subprocess
try:
    import xml.etree.cElementTree as ET
except ImportError:
    import xml.etree.ElementTree as ET

distWinPath = os.sep.join([os.getcwd(), 'distwin'])

def delete_file_folder(src):
    '''delete files and folders'''
    if os.path.isfile(src):
        try:
            os.remove(src)
        except:
            pass
    elif os.path.isdir(src):
        for item in os.listdir(src):
            itemsrc = os.path.join(src, item)
            delete_file_folder(itemsrc)
        try:
            os.rmdir(src)
        except Exception, e:
            print e

if __name__ == '__main__':
    buildPaths = []
    tree = ET.parse('QCFramer.pro.user')
    root = tree.getroot()
    for child in root:
        for cchild in child:
            for ccchild in cchild:
                for cccchild in ccchild:
                    if cccchild.attrib['key'] == "ProjectExplorer.BuildConfiguration.BuildDirectory":
                        buildPaths.append(cccchild.text)
    delete_file_folder(distWinPath)
    for item in ['distwin']:
        os.mkdir(os.sep.join([os.getcwd(), item]))
    exePath = os.sep.join([buildPaths[1], 'release', 'QCFramer.exe'])
    shutil.copyfile(exePath, os.sep.join([distWinPath, 'QCFramer.exe']))
    os.chdir(distWinPath)
    subprocess.call(["windeployqt.exe", "QCFramer.exe"])
