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
import xml.etree.cElementTree as ET

def Indent(elem, level = 0):
    i = "\n" + level * "\t"
    if len(elem):
        if not elem.text or not elem.text.strip():
            elem.text = i + "\t"
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
        for elem in elem:
            Indent(elem, level + 1)
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
    else:
        if level and (not elem.tail or not elem.tail.strip()):
            elem.tail = i

def CreateNewEnv():

    AddOption(
        '--debug_build',
        dest='debug_build',
        action='store_true',
        metavar='DIR',
        default=False,
        help='Build in debug mode'
    )

    env = Environment(DEBUG_BUILD = GetOption('debug_build'),TARGET_ARCH='x86');

    baseProjectDir = os.path.abspath(Dir('.').abspath).replace('\\', '/')
    print("BASE_DIR="+baseProjectDir)
    env.VariantDir('build', 'src', duplicate=0)

    sourceFiles = [
        "build/EveOrePricesApp.cpp",
        "build/Precompiled.cpp",
        "build/BaseManager.cpp",
        "build/InputManager.cpp",
        "build/PointerManager.cpp",
        "build/ResourceSDLPointer.cpp",
    ]
    headerFiles = [
        "src/Main.h",
        "src/Precompiled.h",
        "src/EveOrePricesApp.h",
        "src/BaseManager.h",
        "src/InputManager.h",
        "src/PointerManager.h",
        "src/ResourceSDLPointer.h",
    ]

    env.Append(CPPPATH=[
        baseProjectDir + "/MyGUI/include",
        baseProjectDir + "/OpenGLPlatform/include",
        baseProjectDir + "/SDL2/include",
        baseProjectDir + "/SDL_image/include",
    ])

    libType = "Release"
    if(env['DEBUG_BUILD']):
        libType = 'Debug'

    env.Append(LIBPATH=[
        baseProjectDir + "/MyGUI/lib/"+libType,
        baseProjectDir + "/OpenGLPlatform/lib/"+libType,
        baseProjectDir + "/SDL2/lib/"+libType,
        baseProjectDir + "/SDL_image/lib/"+libType,
    ])

    env.Append(LIBS=[
        'MyGUIEngine',
        'MyGUI.OpenGLPlatform',
        'SDL2',
        'SDL2_image',
    ])

    root = ET.Element("Paths")
    ET.SubElement(root, "Path", root="true").text = baseProjectDir + "/layout"
    ET.SubElement(root, "Path").text = baseProjectDir + "/layout/MyGUI_Media"
    Indent(root)
    tree = ET.ElementTree(root)
    tree.write(baseProjectDir + "/layout/resources.xml", xml_declaration = True, encoding = 'utf-8')

    prog = env.Program("build/EveOrePrices", sourceFiles)
    env = ConfigPlatformEnv(env, baseProjectDir)
    env = ConfigPlatformIDE(env, sourceFiles, headerFiles, prog)

    return env

def ConfigPlatformEnv(env, baseProjectDir):

    if platform == "linux" or platform == "linux2":
        print("Eclipse C++ project not implemented yet")
    elif platform == "darwin":
        print("XCode project not implemented yet")
    elif platform == "win32":

        degugDefine = 'NDEBUG',
        debugFlag = "/O2"
        degug = '/DEBUG:NONE',
        debugRuntime = "/MD",
        libType = "Release"
        if(env['DEBUG_BUILD']):
            degugDefine = 'DEBUG',
            debugFlag = "/Od"
            degug = '/DEBUG:FULL',
            debugRuntime = "/MDd",
            libType = 'Debug'

        env.Append(CPPDEFINES=[
            'NOMINMAX',
            "WIN32",
            degugDefine,
        ])

        env.Append(CCFLAGS= [
            "/analyze-",
            "/GS",
            "/Zc:wchar_t",
            "/W1",
            "/Z7",
            "/Gm-",
            debugFlag,
            "/WX-",
            '/FC',
            "/Zc:forScope",             # Force Conformance in for Loop Scope
            "/GR",                      # Enable Run-Time Type Information
            "/Oy-",                     # Disable Frame-Pointer Omission
            debugRuntime,               # Use Multithread DLL version of the runt-time library
            "/EHsc",
            "/nologo",
        ])

        env.Append(LINKFLAGS=[
            degug
        ])

        env.Append(LIBS=[
            'OpenGL32',
            'user32',
        ])

        env.Install(baseProjectDir+"/build", baseProjectDir + "/MyGUI/bin/"+libType+"/MyGUIEngine.dll")
        env.Install(baseProjectDir+"/build", baseProjectDir + "/SDL2/bin/"+libType+"/SDL2.dll")
        env.Install(baseProjectDir+"/build", baseProjectDir + "/SDL_image/bin/"+libType+"/SDL2_image.dll")

    return env

def ConfigPlatformIDE(env, sourceFiles, headerFiles, program):
    if platform == "linux" or platform == "linux2":
        print("Eclipse C++ project not implemented yet")
    elif platform == "darwin":
        print("XCode project not implemented yet")
    elif platform == "win32":
        variantSourceFiles = []
        for file in sourceFiles:
            variantSourceFiles.append(re.sub("^build", "../src", file))
        variantHeaderFiles = []
        for file in headerFiles:
                variantHeaderFiles.append(re.sub("^src", "../src", file))
        buildSettings = {
            'LocalDebuggerCommand':os.path.abspath(Dir('.').abspath).replace('\\', '/') + "/build/EveOrePrices.exe"
        }
        buildVariant = 'Debug|Win32'
        if(env['DEBUG_BUILD']):
            buildVariant = 'Release|Win32'
        env.MSVSProject(target = 'VisualStudio/EveOrePricesApp' + env['MSVSPROJECTSUFFIX'],
                    srcs = variantSourceFiles,
                    localincs = variantHeaderFiles,
                    buildtarget = program,
                    DebugSettings = buildSettings,
                    variant = buildVariant)
    return env


CreateNewEnv()
