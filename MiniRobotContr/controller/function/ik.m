function [L_Hip_Yaw,L_Hip_Roll,L_Hip_Pitch,L_knee,L_Ankle_Pitch,L_Ankle_Roll]=ik(pc,pf,lr)
%腿部逆运动学
%已知质心位置pc，脚底中心位置pf，计算左腿关节角度
%输出结果为从上到下依次关节角度，默认膝关节前弯
% pc=[0,0,Hmax-a];
% 
%    pf=[0.00055,-0.095,0];
if lr==1 %左腿
    phip=pc+[-0.0011  0.095  -0.013327] ;%髋关节位置  [-0.0011  0.095  -0.013327]

    phip2_roll=phip+[-0.00185, 0,   -0.024];
    knee=phip2_roll+[ 0,        -0.00525,  -0.02315]+[ -0.0045,   0.0000,  -0.128];
     pankle=pf-[ 0, 0, -0.037];

else %右腿
    phip=pc+[-0.0011 -0.095 -0.013327]; %髋关节位置 [-0.0011 -0.095 -0.013327 ]
    phip2_roll=phip+[ -0.00185,  0,   -0.024];

    knee=phip2_roll+[ 0         ,0.00525,  -0.02315]+[  -0.0045,   0.0000,  -0.128];
    pankle=pf-[ 0, 0, -0.037];
end

%% 三杆长度计算
 l2 =0.1183;
 l1=norm(phip-knee);

 %踝关节位置   
Lleg = norm(pankle-phip)+3.813e-04; %腿长  
Rleg=norm([phip2_roll(2),phip2_roll(3)]-[pf(2),pf(3)]);

%膝关节角度




  % L_knee1=pi-2*asin(Lleg);  % Π -2

%% 三角形几何解
% L_knee=(-acos((l1^2+l2^2-Lleg^2)/(2*l1*l2))+pi);
% L_Ankle_Pitch=-asin((l1*sin(pi-L_knee)/Lleg));

L_knee = (-acos(max(-1, min(1, (l1^2 + l2^2 - Lleg^2) / (2 * l1 * l2)))) + pi);
% L_Ankle_Pitch =asin((knee(1)-pankle(1)+0.008)/l2)+0.5*L_knee;
 % L_Ankle_Pitch=-asin(max(-1,min(1,(pankle(1)-phip(1)/Lleg ))));+asin((abs(pankle(1)-phip(1)-0.00165)/Lleg));asin(abs(knee(1)-pankle(1))/l2);
% % L_Hip_Pitch=L_knee-abs(asin(max(-1, min(1, (l1 * sin(pi - L_knee) / Lleg)))));+atan((pankle(1)-phip(1)-0.00055)/(-pankle(3)+phip(3)))
L_Hip_Pitch=acos(max(-1, min(1, (l1^2 + Lleg^2 - l2^2) / (2 * l1 * Lleg))));
L_Ankle_Pitch =L_knee-L_Hip_Pitch;
 


%% 侧摆
% L_Hip_Roll=-asin((abs(pf(2)-phip2_roll(2))-0.0055)/norm(phip2_roll(2:3)-pf(2:3)));
L_Hip_Roll=asin((phip2_roll(2)-pf(2))/Rleg);
L_Ankle_Roll=-L_Hip_Roll;
L_Hip_Yaw=0;

end

