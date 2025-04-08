function [q1,q2,q3]=ARM(T)
% format long
% syms d1 d2 d3 d4 d5 d6 
% syms theta1 theta2 theta3 theta4 theta5 theta6 
% syms theta_i theta_i_1 alpha_i_1 alpha_i d_i a_i_1
% syms a1 a2 a3 a4 a5 a6
% syms alpha1 alpha2 alpha3 alpha4 alpha5 alpha6
% syms r11 r12 r13 r21 r22 r23 r31 r32 r33 Px Py Pz
% syms T_i
%机器人学PUMA560机械臂参数
a = T(1);
b = T(2);
c = T(3);
X = T(4);
Y = T(5);
Z = T(6);
R= [cos(b)*cos(c), cos(c)*sin(a)*sin(b) - cos(a)*sin(c), sin(a)*sin(c) + cos(a)*cos(c)*sin(b),  X ;
    cos(b)*sin(c), cos(a)*cos(c) + sin(a)*sin(b)*sin(c), cos(a)*sin(b)*sin(c) - cos(c)*sin(a),  Y ; 
    -sin(b)      , cos(b)*sin(a)                       , cos(a)*cos(b)                       ,  Z ;
         0       ,   0                                 , 0                                   ,  1 ;]; 
d1 = 0.03487*1000;
d2 = 0.01215*1000;
d3 = 0.1157*1000;
d4 = 0.0015*1000;
d5 = 0.00717*1000;
d6 = 0.1256*1000;
%连杆长度
a0 = 0;
a1 = 0.002*1000;
a2 = 0.025*1000;
a3 = 0;
a4 = 0.059*1000;
a5 = 0;

%连杆长度

a11 = 0.002*1000;
a22 = 0.025*1000;
a33 = 0;
a44 = 0.059*1000;
a55 = 0;
%连杆扭角

alpha1 = pi/2;
alpha2 = -pi/2;
alpha3 = pi/2;
alpha4 = pi/2;
alpha5 = -pi/2;
alpha6 = 0;
% 
% L1=Link([0     d1       a0       alpha0     ],'modified');%设置连杆参数，注：使用的是改进型DH参数，所以最后参数为'modified'
% L2=Link([0     d2       a1       alpha1     ],'modified');
% L3=Link([0     d3       a2        alpha2     ],'modified');
% L4=Link([pi/2     d4       a3       alpha3     ],'modified');
% L5=Link([-pi/2     d5       a4       alpha4     ],'modified');
% L6=Link([0     d6       a5       alpha5     ],'modified');
% robot=SerialLink([L1 L2 L3 L4 L5 L6],'name','RobotArm');%将不同连杆链接起来

L1=Link([0     d1       a11        alpha1     ],'standard');%设置连杆参数，注：使用的是改进型DH参数，所以最后参数为'modified'
L2=Link([0     d2       a22        alpha2     ],'standard');
L3=Link([0     d3       a33        alpha3     ],'standard');
L4=Link([pi/2   d4       a44       alpha4     ],'standard');
L5=Link([-pi/2  d5       a55       alpha5     ],'standard');
L6=Link([0      d6       a55       alpha6     ],'standard');
robot=SerialLink([L1 L2 L3 L4 L5 L6],'name','RobotArm');%将不同连杆链接起来



% robot.plot([0,0,0,pi/2,-pi/2,0]);%输出机器人模型，后面的六个角为输出时的theta姿态,用弧度制
% robot.display();%打印出机器人D-H参数表
% T=robot.fkine([0,0,0,pi/2,-pi/2,0]);%求机械臂正解
% robot.teach%机械臂示教
% robot.ikine([ 1 1 1])
% T= [ 0.16 -0.76 0.64 69.54 ;
%      -0.11 -0.65 -0.75 -84.80 ;
%      0.98 0.05 -0.19 168.77 ;
%      0 0 0 1;
%     ];
T=[ 1 0 0 X;
    0 1 0 Y;
    0 0 1 Z;
    0 0 0 1;];

Inv_q=robot.ikine(T);
q1=Inv_q(1)*180/pi;
q2=Inv_q(2)*180/pi;
q3=Inv_q(3)*180/pi;
q4=Inv_q(4)*180/pi;
q5=Inv_q(5)*180/pi;
q6=Inv_q(6)*180/pi;
%使用改进型DH法，根据机器人学中对PUMA560机械臂建模方法实现运动学正解
end
