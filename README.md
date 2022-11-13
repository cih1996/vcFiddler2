# VCFiddler2
项目由2017年开始进行第一次封装，由于C#开发DLL调用比较麻烦，特意再次封装为C++动态库进行调用。
> 由于之前是专门为易语言而开发的dll，大部分的功能传递都是通过指针进行完成，对于其它语言的调用就非常不由好。
由此推出2.0版并命名为vcfiddler，做成全接口模式，以供其它开发语言调用，如python、Java、c++、vbs、等Windows应用程序语言开发工具。


## 简介
- 基于Fiddler的SDK二次封装
- 内核为32位,仅支持32位应用调用,如JAVA,Python调用则需要安装32位的环境
- 监听获取HTTP/HTTPS请求及响应数据
- 拦截修改请求及响应数据
- 支持WEBSOCKET链接的拦截与修改

## 编译
- 使用Visual Studio 2019开发环境
- Windows SDK 10.0.19041.0
- 打开efd.sln
- 切换到`debug x86`模式下编译
- 使用快捷键Ctrl+B 或者打开菜单的 生成-生成efd 执行编译

## 使用
所有函数请查看efd.h头文件,已做注释说明,只要知道如何调用外部DLL那么基本上轻而易举的使用本项目功能

- 首次使用需调用`AutoStartFiddlerProxy` `StartSSL` 配置监听抓包时是否开启注册代理及SSL抓包
- 如果开启SSL则需要调用`rootCertIsTrusted`判断是否已经安装SSL证书
- 如未安装则需要调用`CreateRootCert`进行创建以及`InstCert`进行安装
- 最后执行`InitFiddler`设置要监听的端口以及回调用函数即可开启抓包之旅
- 具体回调的参数定义参考efd.h的`RecvCallbackFun`及`SendCallbackFun`

### 易语言
- 将编译成功后的efd.dll FiddlerCore4.dll makecert.exe放到vcfiddlerDemo.e源码目录下
- 运行vcfiddlerDemo.e源码并运行即可调用例子
- 源码提供了简单的请求/响应数据的监听及修改

### Java
暂无例子...

### Python
暂无例子...

### Node.JS
暂无例子...

### C/C++
暂无例子...

### 按键精灵
暂无例子...



## 2021-4-28
- 增加了发送数据的监听
- 增加修改发送出去的URL
- 增加替换发送的POST数据
- 增加重写发送的POST数据
- 增加修改发送时的cookie
- 增加设置发送时的协议头
