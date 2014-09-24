QFramer 基于Qt5的快速开发框架
============
####1.Introduction

作为一名Qter，我们都知道Qt的强大带给我们nice的编码体验。伴随着用户交互体验越来越受到重视，移动端UI交互体验的冲击，PC端UI交互体验的提升近在眼前。Qt基于c++的跨平台开发框架，已经帮我们做了很多繁琐和苦累的工作，提供一套优美的api和多种开发模式： 
1. `QtWidgets + qss`    
2. `QtWebkit 开发基于web(html5)的桌面应用`         
3. `QtQuick技术，提供新一代描述语言类json的语言qml, 高效完美`        

对于软件大小没有严格限制的软件而言，在qt5里面可以完美结合三种开发方式，极大提高生产效率，但存在技术门槛较高，坑也较多，资料相对较少的缺陷。为此，QFramer应运而生，采用基于QtWidgets + qss的开发模式，自定义核心控件，提供一套完整风格的自定义控件，使开发者能够将更多的精力专注于业务逻辑，无需过于担心UI体验。

QFramer必将不负您的期望。
####2. 版本支持：
    支持版本Qt4.8和5.3，目前已经在Qt4.8.6、Qt5.3.0、Qt5.3.1上做过验证。
####3. 特性
+ `自定义标题栏`: 支持自定义设置menu,皮肤切换menu,锁屏解屏按钮，最小化最大化关闭按钮
+ `自定义top导航tab`:  支持随意添加导航条，只需要关联上相应的功能页面，即可根据tab切换页面
+ `自定义系统托盘`: 支持系统托盘关联自定义菜单
+ `自定义悬浮窗`: 支持悬浮窗
+ `自定义left导航条`: 支持随意添加导航条，只需要关联上相应的功能页面，即可根据tab切换页面
+ `自定义皮肤主题`:  内置BB和BW两种主题，提供自定义主题接口，增加脚本qssbuilder.py，根据skin/qss/template.qss模板生成自定义的主题qss文件
+ `一键绿色版`： 增加脚本deploywin.py,  用于收集QFramer需要的依赖；
+ `内置QCustomPlot`: 高效2d绘图库
+ 更多的特性等你来挖掘......

####4 下载
+ `source:` https://github.com/dragondjf/QCFramer/archive/develop.zip
+ `windows realease`: http://pan.baidu.com/s/1qWI2lXi

####5: 快照
![6](doc/v0.25_1.png)
![7](doc/v0.25_2.png)
![8](doc/v0.25_3.png)
![9](doc/v0.25_4.png)

####6.Contact
+ `Email:` ding465398889@163.com or dragondjf@gmail.com or 465398889@qq.com
+ `Github:` https://github.com/dragondjf/QCFramer

>  `如果你觉得QFramer对你有些许帮助，请加个星，您的支持将是QFramer前进路上的最好的见证！`
