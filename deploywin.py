# -*- coding: utf-8 -*-
# /****************************************************************************
# **
# ** Copyright (C) 2014 dragondjf
# **
# ** QFramer is a frame based on Qt5.3, you will be more efficient with it. 
# ** As an Qter，Qt give us a nice coding experience. With user interactive experience(UE) 
# ** become more and more important in modern software, deveployers should consider business and UE.
# ** So, QFramer is born. QFramer's goal is to be a mature solution 
# ** which you only need to be focus on your business but UE for all Qters.
# **
# ** Version  : 0.2.2.0
# ** Author   : dragondjf
# ** Website  : https://github.com/dragondjf
# ** Project  : https://github.com/dragondjf/QCFramer
# ** Blog     : http://my.oschina.net/dragondjf/home/?ft=atme
# ** Wiki     : https://github.com/dragondjf/QCFramer/wiki
# ** Lincence: LGPL V2
# ** QQ: 465398889
# ** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
# ** 
# ****************************************************************************/

import os
import sys
import copy
import shutil
import subprocess
try:
    import xml.etree.cElementTree as ET
except ImportError:
    import xml.etree.ElementTree as ET

workspacePath = os.getcwd()
destinationPath = os.sep.join([os.getcwd(), 'distwin'])

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

def getFilesBySuffix(rootpath, suffix):
    fnames = []
    for d, fd, fl in os.walk(rootpath):
        if d == rootpath:
            for item in fl:
                if item.endswith(suffix):
                    fnames.append(os.sep.join([rootpath, item]))
    return fnames

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
    delete_file_folder(destinationPath)
    for item in ['distwin']:
        os.mkdir(os.sep.join([os.getcwd(), item]))
    exePath = os.sep.join([buildPaths[1], 'release', 'QCFramer.exe'])
    shutil.copyfile(exePath, os.sep.join([destinationPath, 'QCFramer.exe']))
    os.chdir(destinationPath)
    subprocess.call(["windeployqt.exe", "QCFramer.exe"])

    for item in getFilesBySuffix(destinationPath, '.qm'):
        delete_file_folder(item)

    for item in ['qss']:
        shutil.copytree(os.sep.join([workspacePath, 'skin', item]), os.sep.join([destinationPath ,item]))
