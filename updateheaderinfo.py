# -*- coding: utf-8 -*-
import os
import sys
import copy

def getCHppFiles(rootpath):
    hfiles = []
    cppfiles = []
    for root, dirs, files in os.walk(rootpath) :
        if '.git' not in root:
            # print root, dirs, files
            for f in files:
                fpath = os.sep.join([root, f])
                if f.endswith(".h"):
                    hfiles.append(fpath)
                elif f.endswith(".cpp"):
                    print f
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
        if headerInfo not in hcontent:
            content = headerInfo + "\n" + hcontent
            with open(hf, 'w') as fd:
                fd.write(content)


if __name__ == '__main__':
    main()
