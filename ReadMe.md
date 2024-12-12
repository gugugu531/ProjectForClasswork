# 学生通讯录系统

本项目采用 **CMake** 搭建，**CMake**最低版本要求为2.8

***

学生通讯录基本信息主要包括：学号、姓名、性别、所属院系、专业、通讯地址、电话、QQ号、Email等。  
系统能对这些基本信息进行管理。

具有以下功能：
* 添加新学生信息、删除和修改指定学生信息、列表浏览所有学生信息、按条件查询、排序、统计等功能。  
* 录入数据的文件存储功能，运行过程的日志存储功能。  
* 支持通信录导入或导出为csv和vcard格式。  
* 从指定文件中拿到期末挂科学生的学号和科目名称等信息，自动发送Email到学生邮箱中。  
* 支持“模糊查询”（如姓氏查询等）。  
* 统计内容自行确定，但应能将统计结果以表格形式输出至屏幕；或转成xls文件在excel中打开显示。  