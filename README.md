这是一个基于LQR求解器的ZMP步态算法规划代码，其中包含不同的开发方式。
1.文件夹control里包含了controlCore和其他文件夹。
1.1运行行走的demo只需要首先在MATLAB中运行 biped_robot_contr_Core.mlx ，该实时编辑脚本将是步态行走的核心代码，运行后将会生成步态离线数据。
1.2.其次你需要打开control目录下的 Mini_HR100_V5.slx  ，开始运行仿真即可。
实际仿真效果如下：
![MiniHR_双腿_斜角_9s](https://github.com/user-attachments/assets/f8a1b403-ee97-4179-a979-493c1790b6e0)
![MiniHR_双腿_侧向_9s](https://github.com/user-attachments/assets/05424185-b8b9-4970-9f28-c251377cdc10)
2.机器人的三维设计模型 （仿真考虑计算机计算资源，对STL文件进行了简化）
MiniHR100_简要说明文档

2.1.机器人结构参数
2.1.1机器人的整体参数
机器人的总高：79.246 cm
![图片1](https://github.com/user-attachments/assets/f378ab4d-ee31-4819-ac10-712353cb7163)

单手到身体中心轴的距离为：44.469 cm
![图片2](https://github.com/user-attachments/assets/c4fa27f4-c712-4bc8-b94e-cc28bd08b8d8)

左右髋部的距离为：25.787 cm  。
![图片3](https://github.com/user-attachments/assets/028a1f86-4662-4f5e-bebd-6e3848b659c3)

单只脚掌占地面积为：125.1808 cm^2 。
![图片4](https://github.com/user-attachments/assets/e6d40e5f-f953-4524-ad01-5a35df56f3ad)

设计理论总重量：7.785 千克 。

![图片5](https://github.com/user-attachments/assets/00216bf8-103b-431f-9555-bcf473635b67)

2.1.2机器人的活动限制
机器人整体腿部角度的最大角度限制。腿部最大侧摆的角度为朝内（两脚合拢）19°和朝外56°，角度限制来自实际机器人的关节物理限制。 

![图片6](https://github.com/user-attachments/assets/93d01f00-abb6-488a-b16b-997989cd7db3)

侧向限制，以当前直腿站立为初始0位值，髋关节朝前伸最大角度为73°，往后最大角度107°。
![图片7](https://github.com/user-attachments/assets/d36ba3af-7520-46d3-8db5-09f435bc5b6f)

膝关节初始直腿位初始0位，工作区间为往后[0 , 100°]。脚部的关节限制为往前15°和往后35°。
2.1.3全身自由度
小人形机器人的全身由28个关节控制，不包含两个假爪的工具坐标系。其中，单手6自由度；头部两自由度（head link 1、head link 2）；腰部为三个坐标系（零坐标系base link 、腰部关节1 base link 1 、 base link 2），两个实际可控关节。下图红色箭头为关节旋转轴的方向。
![图片8](https://github.com/user-attachments/assets/3d09ec8e-b712-46de-9e60-8a8f0c31a2d8)

全身关节坐标系如下：
![图片9](https://github.com/user-attachments/assets/3101da30-1e02-4713-b9bc-5464a34dc356)

以下为全身关节舵机的型号已经ID编号。⚪为舵机的ID号码，不同颜色对应不同的舵机型号。旁边的数字为舵机的工作范围和安装时零位置的物理初始角度。
![图片10](https://github.com/user-attachments/assets/338795a5-5f86-43b7-9570-3aab99586a09)






2.2.仿真操作流程

![图片11](https://github.com/user-attachments/assets/022f33be-6d31-417a-a630-4928d08f84b2)

![图片12](https://github.com/user-attachments/assets/1f117163-0b89-4739-9e87-ea6afa126a3f)



可以通过滚轮调整左面的大小。

![图片13](https://github.com/user-attachments/assets/d4578ea3-8d85-40c7-a963-4ea0fdd6a240)


2.3.代码解析
2.3.1主函数部分
主函数有三部分组成，第一部分是初始参数的设置；

![图片14](https://github.com/user-attachments/assets/efcd1716-9f34-4b0f-ab92-eb86acbd9ee4)

初始参数设置。
第二部分为机器人从直腿下蹲；

![图片14](https://github.com/user-attachments/assets/3a074918-fc9e-483c-9a6d-3bce80d75a08)


第三部分是规划曲线的可视化代码。

![图片16](https://github.com/user-attachments/assets/913ba42b-d2de-4b0b-87f6-ca648da25f21)

2.3.2逆运动学求解函数
这部分的输入是 【质心位置pc、落脚点位置pf、左右腿标志位lr】
![图片17](https://github.com/user-attachments/assets/1d579bc3-7096-4293-b61c-db38160ec261)

2.3.3多项式插值
![图片18](https://github.com/user-attachments/assets/f367cdfb-e146-4aff-8da1-743571d0fc56)

2.3.4质心运动规划
2.3.4.1 落脚点规划
首先生成一个落脚点的表perf[ ].
第一列是时间，第二列是ZMP的x，第三列是ZMP的y
![图片19](https://github.com/user-attachments/assets/3735c95e-14f0-4662-9d7a-b7556ace396a)
![图片20](https://github.com/user-attachments/assets/5ddd26ef-0d42-4d96-b9db-3be7654e15de)


以下是将perf[ ] 中的标志位的序号挑选出来，生成不同的左右腿位置Rfoot[ ], Lfoot[ ] 
![图片21](https://github.com/user-attachments/assets/ff7b53dc-f0e4-4a95-b848-c93f7fa69300)
接着的代码是把跳出来的位置数据进行多项式插值形式轨迹曲线。下图分别是 左脚插值代码图、轨迹插值效果图、右脚插值代码图。
![图片22](https://github.com/user-attachments/assets/94b51cf6-a39f-40ae-a8dc-d98f6c6907f6)
![图片23](https://github.com/user-attachments/assets/13f86e52-6bb2-40b8-981a-04c393b412b2)
![图片24](https://github.com/user-attachments/assets/3e21444d-600b-4894-a068-49cabe65d3f2)


2.2.4.2 质心轨迹规划

![图片25](https://github.com/user-attachments/assets/ee92c7ba-62c1-4155-987e-ec3741962b33)
![图片26](https://github.com/user-attachments/assets/5a598688-3428-4fd9-b3c0-0cdb0c5256c9)
![图片27](https://github.com/user-attachments/assets/706e6c5b-2272-4096-acc4-8ae6cfeeced6)

3.基于embedcode 的代码生成在文件夹MBD_C 中
4.基于RL的 控制方式
