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

def getCHppFiles(rootpath):
    hfiles = []
    cppfiles = []
    for root, dirs, files in os.walk(rootpath) :
        if '.git' not in root:
            for f in files:
                fpath = os.sep.join([root, f])
                if f.endswith(".h"):
                    hfiles.append(fpath)
                elif f.endswith(".cpp"):
                    cppfiles.append(fpath)
    return hfiles, cppfiles

def getHeaderInfo(headerpath):
    if os.path.exists(headerpath):
        with open(headerpath, 'r') as f:
            content = f.read()
        return content
    else:
        return None

def main():
    hfiles, cppfiles = getCHppFiles(os.getcwd())
    headerInfo = getHeaderInfo(os.sep.join([os.getcwd(), 'header.info']))
    for hf in hfiles + cppfiles:
        with open(hf, 'r+') as fd:
            hcontent = fd.read()
            index = hcontent.rfind('*' * 76 + "/")
            if index != -1:
                index += 77
                validContent = hcontent[index:].lstrip()
            else:
                validContent = hcontent
                print validContent[:50]
            content = headerInfo + "\n" + validContent
            with open(hf, 'w') as fd:
                fd.write(content)
        print "update %s success" % hf


if __name__ == '__main__':
    main()
