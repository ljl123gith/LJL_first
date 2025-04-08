clear
clc
dt=0.1;
q=zeros(951,13);
q(:,1)=0:dt:95;
% d(:,1)=0:dt:9.5;

%下蹲
Tsqu=5; %下蹲时间
Hmax=0.343477; %0位质心高度z
Hwalk=0.343477-0.08; %下蹲后质心高度z 

for i=1:round(Tsqu/dt)
    t=(i-1)*dt;  %（1~50）*0.1
    A=0.08; %高度变化量

    %多项式插值函数选择
    %五次多项式插值
    % [a,~,~] = Quintic_polynomial_interpolation_general(0,A,0,0,0,0,Tsqu,t); 
    %三次多项式插值
     [a,~,~] = Cubic_polynomial_interpolation(0,A,0,0,Tsqu,t);

    pc=[0,0,Hmax-a]; %[0 0 0.3405]
    pfl=[0.00055,0.095,0];
    [L_Hip_Yaw,L_Hip_Roll,L_Hip_Pitch,L_knee,L_Ankle_Pitch,L_Ankle_Roll]=ik(pc,pfl,1);
    pfr=[0.00055,-0.095,0];
    [R_Hip_Yaw,R_Hip_Roll,R_Hip_Pitch,R_knee,R_Ankle_Pitch,R_Ankle_Roll]=ik(pc,pfr,2);
    q(50+i,2:13)=[L_Hip_Yaw,L_Hip_Roll,L_Hip_Pitch,L_knee,L_Ankle_Pitch,L_Ankle_Roll,R_Hip_Yaw,R_Hip_Roll,R_Hip_Pitch,R_knee,R_Ankle_Pitch,R_Ankle_Roll];
  
    [left_arm1,~,~] = Cubic_polynomial_interpolation(0,1,0,0,Tsqu,t);
    [left_arm_2,~,~] = Cubic_polynomial_interpolation(0,0.8,0,0,Tsqu,t);
    [left_arm_3,~,~] = Cubic_polynomial_interpolation(0,0.8,0,0,Tsqu,t);
    [right_arm1,~,~] = Cubic_polynomial_interpolation(0,2,0,0,Tsqu,t);
    [right_arm_2,~,~] = Cubic_polynomial_interpolation(0,0.6,0,0,Tsqu,t);
    [right_arm_3,~,~] = Cubic_polynomial_interpolation(0,1,0,0,Tsqu,t);

    d(50+i,2:7)=[right_arm1,right_arm_2,right_arm_3,left_arm1,left_arm_2,left_arm_3];
    
end

%行走
gait=generate_gait();

for i=1:size(gait,1)
    pc=[gait(i,2),gait(i,3),Hmax-a];
    pfl=[gait(i,4)+0.00055,gait(i,5),gait(i,6)];
    pfr=[gait(i,11)+0.00055,gait(i,12),gait(i,13)];
 
%膝关节角度 
    [L_Hip_Yaw,L_Hip_Roll,L_Hip_Pitch,L_knee,L_Ankle_Pitch,L_Ankle_Roll]=ik(pc,pfl,1);  
    [R_Hip_Yaw,R_Hip_Roll,R_Hip_Pitch,R_knee,R_Ankle_Pitch,R_Ankle_Roll]=ik(pc,pfr,2);
    q(100+i,2:13)=[L_Hip_Yaw,L_Hip_Roll,L_Hip_Pitch,L_knee,L_Ankle_Pitch,L_Ankle_Roll,R_Hip_Yaw,R_Hip_Roll,R_Hip_Pitch,R_knee,R_Ankle_Pitch,R_Ankle_Roll];

end
% figure
% H=ones(8501, 1) * Hwalk-0.05;
% plot3(gait(:,2)+( -0.00110)+( -0.00185),gait(:,3)+( 0.095)+(0),H+( -0.013327)+( -0.024));
% hold on 
% plot3(gait(:,4)+(-0.00055),gait(:,5)+(0),gait(:,6)+(0));
% hold on 
% plot3(gait(:,11),gait(:,12),gait(:,13));
% hold on
% plot3(gait(:,2)+( -0.00110)+( -0.00185),gait(:,3)+( -0.095)+(0),H+( -0.013327)+( -0.024));
% % 
figure 

subplot(6,1,1);
plot(q(:,1),q(:,2)*180/pi);

subplot(6,1,2);
plot(q(:,1),q(:,3)*180/pi);

subplot(6,1,3);
plot(q(:,1),q(:,4)*180/pi);
subplot(6,1,4);
plot(q(:,1),q(:,5)*180/pi);
subplot(6,1,5);
plot(q(:,1),q(:,6)*180/pi);
subplot(6,1,6);
plot(q(:,1),q(:,7)*180/pi);
% figure 
% 
subplot(6,1,1);
plot(q(:,1),d(:,7)*180/pi);

subplot(6,1,2);
plot(q(:,1),d(:,2)*180/pi);
subplot(6,1,3);
plot(q(:,1),d(:,3)*180/pi);
subplot(6,1,4);
plot(q(:,1),d(:,4)*180/pi);
subplot(6,1,5);
plot(q(:,1),d(:,5)*180/pi);
subplot(6,1,6);
plot(q(:,1),d(:,6)*180/pi);
