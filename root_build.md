# ROOTのビルド

ROOTをビルドした際に困ったとことか

## makeの際にfatal error : #include<unicode/uncv.h> がインクルードできない  
インクルードパスを通してみた。  
~/.bash_profile に  
    export CPLUS_INCLUDE_PATH = "/opt/local/include:$CPLUS_INCLUDE_PATH"  

## 実行バイナリのPATHを通す
    export ROOTSYS="~/Downloads/root-6.18.00"  
    export PATH="$ROOTSYS/obj/bin:$PATH"  
これでrootと打てば通る    
