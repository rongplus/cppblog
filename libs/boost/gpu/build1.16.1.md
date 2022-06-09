
Based on KindDragons and CPlusPlus OOA and D answers I compiled Boost 1.63. For 64bit. Run "x64 Native Tools Command Prompt for VS 2017" command prompt:

1) Run: bootstrap.bat

2) open project-config.jam. Here is mine:

import option ; 

using msvc : 14.0 : "c:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.10.25017\bin\HostX64\x64\cl.exe"; 

option.set keep-going : false ;

3)32-bit: b2 toolset=msvc-14.1 --build-dir=.x86 --stagedir=stage_x86

   64-bit: b2 toolset=msvc-14.29 address-model=64 --build-dir=.x64 --stagedir=stage_x64 (link=shared) (link=static)
   --prefix=DIR 