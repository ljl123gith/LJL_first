%位置插值
foot_lx = gait(:,4);
foot_ly = gait(:,5);
foot_lz = gait(:,6);

foot_rx = gait(:,11);
foot_ry = gait(:,12);
foot_rz = gait(:,13);

%速度插值
foot_lx_d = gait(:,7);
foot_ly_d = gait(:,5);
foot_lz_d=  gait(:,9);

foot_rx_d = gait(:,14);
foot_ry_d = gait(:,12);
foot_rz_d = gait(:,16);

%加速度插值
foot_lx_dd = gait(:,8);
foot_ly_dd = gait(:,5);
foot_lz_dd=  gait(:,10);

foot_rx_dd = gait(:,15);
foot_ry_dd = gait(:,12);
foot_rz_dd = gait(:,17);
t=gait(:,1);
% gait
%规划离散的点
discPoint_l=[0,0.5,1.5,2.5,3.5,4.5,5.5,6.5,7;
           0.1,0.1,0.1 0.1 0.1 0.1 0.1 0.1 0.1];
discPoint_r=[0,1  ,2  , 3 , 4,  5,  6,   7;
           -0.1,-0.1,-0.1 -0.1 -0.1 -0.1 -0.1 -0.1 ];

% % 设置坐标轴范围
% 
% CoM_x = gait(:,2);
% CoM_y = gait(:,3);
% % 生成矩阵
% CoM_z = ones(8501, 1) * 1.15;
% 
% %位置
% plot3(foot_lx,foot_ly,foot_lz,'-.','LineWidth',2);
% hold on 
% % plot3(foot_rx,foot_ry,foot_rz,'LineWidth',2,"LineSpec","x");
% plot3(foot_rx, foot_ry, foot_rz, 'LineWidth', 2 ); 
% 
% % plot3(CoM_x,CoM_y,CoM_z,'MarkerSize',10);
% axis([0,9,-0.2,0.2,0,0.5]);
% %设置Y轴网格
% set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% 
% legend("左脚足端轨迹","右脚足端轨迹")
% xlabel("前行方向x/m")
% ylabel("水平方向y/m")
% zlabel("竖直高度z/m")
% 
% figure
%  plot3(CoM_x,CoM_y,CoM_z,'LineWidth',2);
%  hold on;
%  scatter(discPoint_l(1, :), discPoint_l(2, :), 'bo', 'filled');
% hold on;
% % 绘制右侧点
% scatter(discPoint_r(1, :), discPoint_r(2, :), 'ro', 'filled');
%  axis([-0.1,7.5,-0.15,0.15,0,1.5]);
% %设置Y轴网格
% % set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% 
% legend("质心运动轨迹",'左脚落脚点', '右脚落脚点')
% xlabel("前行方向的步态长度x/m")
% ylabel("水平侧身移动幅度y/m")
% zlabel("竖直高度z/m")

% figure
% subplot(2,2,1);
% xlim([0 , 9])
% ylim([-0.001,0.005])
% plot(t,foot_lx_d  ,'LineWidth',2);
% xlabel("时间t/s")
% ylabel("轨迹速度v(m/s)")
% title("左脚末端x方向轨迹速度图")
% grid on
% 
% subplot(2,2,2);
% plot(t,foot_lz_d, 'LineWidth',2);
% set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% 
% xlabel("时间t/s")
% ylabel("轨迹速度v(m/s)")
% title("左脚末端z方向轨迹速度图")
% grid on
% 
% subplot(2,2,3);
% 
% plot(t,foot_lx_dd, 'LineWidth',2);
% set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% xlabel("时间t/s")
% ylabel("轨迹加速度v(m/s^2)")
% title("左脚末端x方向轨迹加速度图")
% grid on

% subplot(2,2,4);
% plot(t,foot_lz_dd, 'LineWidth',2);
%  set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% xlabel("时间t/s")
% ylabel("轨迹加速度v(m/s^2)")
% title("左脚末端z方向轨迹加速度图")
% grid on

figure 
time = 0:0.01:(size(q, 1)-1)*0.01;

% 提取各个变量的数据
L_Hip_Yaw = q(:, 1);
L_Hip_Roll = q(:, 2);
L_Hip_Pitch = q(:, 3);
L_knee = q(:, 4);
L_Ankle_Pitch = q(:, 5);
L_Ankle_Roll = q(:, 6);

% 创建一个图形窗口
figure;

% 绘制L_Hip_Yaw
subplot(3, 2, 1);
plot(time, L_Hip_Yaw,'LineWidth',2);
title('L\_Hip\_Yaw');
xlabel('时间 (s)');
ylabel('角度 (°)');

% 绘制L_Hip_Roll
subplot(3, 2, 2);
plot(time, L_Hip_Roll,'LineWidth',2);
title('L\_Hip\_Roll');
xlabel('时间 (s)');
ylabel('角度 (°)');

% 绘制L_Hip_Pitch
subplot(3, 2, 3);
plot(time, L_Hip_Pitch,'LineWidth',2);
title('L\_Hip\_Pitch');
xlabel('时间 (s)');
ylabel('角度 (°)');

% 绘制L_knee
subplot(3, 2, 4);
plot(time, L_knee,'LineWidth',2);
title('L\_knee');
xlabel('时间 (s)');
ylabel('角度 (°)');

% 绘制L_Ankle_Pitch
subplot(3, 2, 5);
plot(time, L_Ankle_Pitch,'LineWidth',2);
title('L\_Ankle\_Pitch');
xlabel('时间 (s)');
ylabel('角度 (°)');
% 绘制L_Ankle_Roll
subplot(3, 2, 6);
plot(time, L_Ankle_Roll,'LineWidth',2);
title('L\_Ankle\_Roll');
xlabel('时间 (s)');
ylabel('角度 (°)');

% sgtitle('左腿6关节角度规划图');

grid on





% %%
% 
% %二维图
% figure
% subplot(2,1,1);
% plot(foot_lx,foot_lz,'LineWidth',2);
% xlim([-0.2 , 7.2])
% ylim([-0.01,0.115])
% %设置Y轴网格
% set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% 
% % legend("左脚轨迹位置","右脚轨迹位置")
% xlabel("前行方向x/m")
% ylabel("竖直高度z/m")
% title("五次多项式插值的左脚轨迹位置图")
% grid on
% 
% subplot(2,1,2);
% plot(foot_rx,foot_rz, 'LineWidth',2); 
% xlim([-0.2 , 7.2])
% ylim([-0.01,0.115])
% %设置Y轴网格
% set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% xlabel("前行方向x/m")
% ylabel("竖直高度z/m")
% title("五次多项式插值的右脚轨迹位置图")
% grid on
% 
% 
% %速度
% figure
% subplot(2,1,1);
% % xlim([-0.001 0.005])
% % ylim([-0.00000 0.00415])
% plot(t,foot_lx_d  ,'LineWidth',2);
% 
% xlabel("时间t/s")
% ylabel("轨迹速度v(m/s)")
% title("五次多项式插值的左脚x方向轨迹速度图")
% grid on
% subplot(2,1,2);
% plot(t,foot_rx_d, 'LineWidth',2);
% % legend("左脚轨迹速度","右脚轨迹速度")
%  set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% 
% xlabel("时间t/s")
% ylabel("轨迹速度v(m/s)")
% title("五次多项式插值的右脚x方向轨迹速度图")
% grid on
% 
% figure
% subplot(2,1,1);
% plot(t,foot_lz_d, 'LineWidth',2);
% set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% % 
% % legend("左脚轨迹速度")
% xlabel("时间t/s")
% ylabel("轨迹速度v(m/s)")
% title("五次多项式插值的左脚z方向轨迹速度图")
% grid on
% subplot(2,1,2);
% plot(t,foot_rz_d, 'LineWidth',2);
% set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% % 
% % legend("右脚轨迹速度")
% xlabel("时间t/s")
% ylabel("轨迹速度v(m/s)")
% title("五次多项式插值的右脚z方向轨迹速度图")
% grid on
% 
% 
% 
% %加速度
% figure
% subplot(2,1,1);
% % xlim([-0.001 0.005])
% % ylim([-0.00000 0.00415])
% plot(t,foot_lx_dd, 'LineWidth',2);
% set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% % legend("左脚轨迹速度","右脚轨迹速度")
% xlabel("时间t/s")
% ylabel("轨迹加速度v(m/s^2)")
% title("五次多项式插值的左脚x方向轨迹加速度图")
% grid on
% subplot(2,1,2);
% plot(t,foot_rx_dd, 'LineWidth',2);
% set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% % legend("左脚轨迹速度","右脚轨迹速度")
% xlabel("时间t/s")
% ylabel("轨迹加速度v(m/s^2)")
% title("五次多项式插值的右脚x方向轨迹加速度图")
% grid on
% figure
% subplot(2,1,1);
% plot(t,foot_lz_dd, 'LineWidth',2);
%  set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% xlabel("时间t/s")
% ylabel("轨迹加速度v(m/s^2)")
% title("五次多项式插值的左脚z方向轨迹加速度图")
% grid on
% subplot(2,1,2);
% plot(t,foot_rz_dd, 'LineWidth',2);
%  set(gca,"XGrid","on","YGrid","off","ZGrid","off")
% % legend("左脚轨迹加速度","右脚轨迹加速度")
% xlabel("时间t/s")
% ylabel("轨迹加速度v(m/s^2)")
% title("五次多项式插值的右脚z方向轨迹加速度图")
% grid on
% 
% figure 
% 
% grid on



% 
% % 绘制离散的落脚点
% figure;
% % 绘制左侧点
% scatter(discPoint_l(1, :), discPoint_l(2, :), 'bo', 'filled');
% hold on;
% % 绘制右侧点
% scatter(discPoint_r(1, :), discPoint_r(2, :), 'ro', 'filled');
% xlim([-0.2 9])
% ylim([-0.2,0.2])
% % 添加标签和标题
% xlabel('前行方向的步态长度x/m');
% ylabel('水平侧身移动幅度y/m');
% title('双足机器人足端落脚点规划');
% 
% % 添加图例
% legend('左脚落脚点', '右脚落脚点');
% 
% grid on


