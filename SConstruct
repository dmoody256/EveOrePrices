# This file is licensed under the MIT License.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

import os
import json
import sys
import glob
import re
from sys import platform

def CreateNewEnv():

    env = Environment();

    env.VariantDir('build', 'src', duplicate=0)
    sourceFiles = ["build/EveOrePricesApp.cpp"]

    env = ConfigPlatformEnv(env)
    prog = env.Program("build/EveOrePrices", sourceFiles)

    env = ConfigPlatformIDE(env, sourceFiles, prog)

    return env

def ConfigPlatformEnv(env):

    if platform == "linux" or platform == "linux2":
        print("Eclipse C++ project not implemented yet")
    elif platform == "darwin":
        print("XCode project not implemented yet")
    elif platform == "win32":

        degugDefine = 'DEBUG',
        debugFlag = "/Od"
        degug = '/DEBUG:FULL',
        debugRuntime = "/MDd",
        env.Append(CPPDEFINES=[
            degugDefine,
        ])

        env.Append(CCFLAGS= [
            debugFlag,                 
            debugRuntime,               
        ])

        env.Append(LINKFLAGS=[
            "/SUBSYSTEM:CONSOLE",
            degug
        ])

    return env

def ConfigPlatformIDE(env, sourceFiles, program):
    if platform == "linux" or platform == "linux2":
        print("Eclipse C++ project not implemented yet")
    elif platform == "darwin":
        print("XCode project not implemented yet")
    elif platform == "win32":
        files = []
        for file in sourceFiles:
            files.append(re.sub("^build", "../src", file))
        buildSettings = {
            'LocalDebuggerCommand':os.path.abspath(Dir('.').abspath).replace('\\', '/') + "/build/EveOrePrices.exe"
        }
        env.MSVSProject(target = 'VisualStudio/EveOrePricesApp' + env['MSVSPROJECTSUFFIX'],
                    srcs = files,
                    buildtarget = program,
                    DebugSettings = buildSettings,
                    variant = 'Debug|Win32')
    return env


CreateNewEnv()