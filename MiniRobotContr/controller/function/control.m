function [] = control
dt=0.001;
q=zeros(9501,13);
q(:,1)=0:dt:9.5;

%下蹲
Tsqu=0.5; %下蹲时间
Hmax=0.343477; %0位质心高度z
Hwalk=0.343477-0.05; %下蹲后质心高度z 

for i=1:round(Tsqu/dt)
    t=(i-1)*dt;
    A=0.05; %高度变化量

    %多项式插值函数选择
    %五次多项式插值
    [a,~,~] = Quintic_polynomial_interpolation_general(0,A,0,0,0,0,Tsqu,t); 
    %三次多项式插值
     % [a,~,~] = Cubic_polynomial_interpolation(0,A,0,0,Tsqu,t);

    pc=[0,0,Hmax-a]; %[0 0 0.3405]
    pfl=[0.00055,0.095,0];
    [L_Hip_Yaw,L_Hip_Roll,L_Hip_Pitch,L_knee,L_Ankle_Pitch,L_Ankle_Roll]=ik(pc,pfl,1);
    pfr=[0.00055,-0.095,0];
    [R_Hip_Yaw,R_Hip_Roll,R_Hip_Pitch,R_knee,R_Ankle_Pitch,R_Ankle_Roll]=ik(pc,pfr,2);
    q(500+i,2:13)=[L_Hip_Yaw,L_Hip_Roll,L_Hip_Pitch,L_knee,L_Ankle_Pitch,L_Ankle_Roll,R_Hip_Yaw,R_Hip_Roll,R_Hip_Pitch,R_knee,R_Ankle_Pitch,R_Ankle_Roll];
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
    q(1000+i,2:13)=[L_Hip_Yaw,L_Hip_Roll,L_Hip_Pitch,L_knee,L_Ankle_Pitch,L_Ankle_Roll,R_Hip_Yaw,R_Hip_Roll,R_Hip_Pitch,R_knee,R_Ankle_Pitch,R_Ankle_Roll];
end
end

