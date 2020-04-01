# Notepad-=2
## Notepad-=2

Qt学习练手项目，做一个简单的记事本。上一个版本叫Notepad-- (致敬Notepad++、Notepad) 

图标来源：[阿里巴巴矢量图标库](https://www.iconfont.cn/search/index?q=)等
****
### BUGS/TODOS

* ~~文件是否更改判断逻辑有问题~~  
* ~~打开查找框之后关闭主窗口显示程序异常退出(怀疑是内存泄漏)~~  
* ~~响应窗口关闭事件，忽略事件无效(event->ignore()不起作用)~~
* 查找模式切换逻辑有问题(待后续完善)  
* Undo、Redo操作有问题
* 完成查找模式选择
* 设置ini文件，保存设置

****

### NOTES

#### **0.3.0 :** 2020.4.1
>添加自动换行功能  
>将字体风格修改设为全局  
>完善编辑操作功能  
>在编辑区底部显示行列号(利用QLable, 很丑)

**0.2.2 :** 2020.4.1
>修复内存泄漏的bug  
>修复事件忽略无效的bug（逻辑错误）

**0.2.1 :** 2020.4.1
>修复文件保存时的bug

#### **0.2.0 :** 2020.3.31   
>添加功能[查找]，[帮助]，[关于Notepad-=2]  
>菜单栏添加预设功能  

#### **0.1.0 :** 2020.3.31  
>初次提交，功能缺失，现有功能  
>>文件打开、保存、新建  

#### **start :** 2020.3.30  						

