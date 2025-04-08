
%%根据给定的杆长计算雅可比矩阵



clc;
clear all;
syms q0 q1 q2 q3 q4 side;


TR=[1,1,1,1;
    1,1,1,side;
    1,1,1,1
    1,1,1,1];


%这个是实际物品的偏移
f0=rotate_z(q0)*(trans(-0.0309,-0.22475,0.03714).*TR);%%
f1=rotate_x(q1)*(trans(0.0805,0,-0.123).*TR);%%这里点乘TR是应为在这两个矩阵坐标变换中，y是需要区分左右的，side取正负1来区分
f2=rotate_y(q2)*trans(-0.096,0.0395,0);
f3=rotate_y(q3)*(trans(-0.16813,-0.0285,-0.307).*TR);
f4=rotate_y(q4)*trans(0.23264,0,-0.32169);

%这里关于y轴方向的全部要写正，因为在ros中他使用一个side区分了左右腿

%这个是原理作者原来部分的偏移
% f0=rotate_z(q0)*(trans(-0.015,0.02,-0.06).*TR);%%
% f1=rotate_x(q1)*(trans(0,0.023,0).*TR);%%这里点乘TR是应为在这两个矩阵坐标变换中，y是需要区分左右的，side取正负1来区分
% f2=rotate_y(q2)*trans(0,0,-0.22);
% f3=rotate_y(q3)*trans(0,0,-0.22);
% f4=rotate_y(q4)*trans(0,0,-0.036);

%作者原来模型的参数偏移
% f0=rotate_z(q0)*(trans(0.0465,0.015,-0.0705).*TR);%%
% f1=rotate_x(q1)*(trans(-0.06,0.018,0).*TR);%%这里点乘TR是应为在这两个矩阵坐标变换中，y是需要区分左右的，side取正负1来区分
% f2=rotate_y(q2)*trans(0,0,-0.22);
% f3=rotate_y(q3)*trans(0,0,-0.22);
% f4=rotate_y(q4)*trans(0,0,-0.036);



k=f0*f1*f2*f3*f4;
% f0
% f0*f1
% f0*f1*f2*f3*f4 



% px=-cos(q0)*(0.04*sin(q2+q3+q4)+0.22*sin(q2+q3)+0.22*sin(q2)+0.0135)+sin(q0)*(0.015*side+cos(q1)*(0.018*side+0.0025)-sin(q1)*(0.04*cos(q2+q3+q4)+0.22*cos(q2+q3)+0.22*cos(q2)));
% py=-cos(q0)*(0.015*side+cos(q1)*(0.018*side+0.0025)-sin(q1)*(0.04*cos(q2+q3+q4)+0.22*cos(q2+q3)+0.22*cos(q2)))-sin(q0)*(0.04*sin(q2+q3+q4)+0.22*sin(q2+q3)+0.22*sin(q2)+0.0135);
% pz=-cos(q1)*(0.04*cos(q2+q3+q4)+0.22*cos(q2+q3)+0.22*cos(q2))-sin(q1)*(0.018*side+0.0025);

px=k(1,4);
py=k(2,4);
pz=k(3,4);

% px= - (3*cos(q0))/200 - (9*sin(q4)*(cos(q3)*(cos(q0)*cos(q2) - sin(q0)*sin(q1)*sin(q2)) - sin(q3)*(cos(q0)*sin(q2) + cos(q2)*sin(q0)*sin(q1))))/250 - (11*cos(q0)*sin(q2))/50 - ( (side)*sin(q0))/50 - (11*cos(q3)*(cos(q0)*sin(q2) + cos(q2)*sin(q0)*sin(q1)))/50 - (11*sin(q3)*(cos(q0)*cos(q2) - sin(q0)*sin(q1)*sin(q2)))/50 - (9*cos(q4)*(cos(q3)*(cos(q0)*sin(q2) + cos(q2)*sin(q0)*sin(q1)) + sin(q3)*(cos(q0)*cos(q2) - sin(q0)*sin(q1)*sin(q2))))/250 - (23*cos(q1)* (side)*sin(q0))/1000 - (11*cos(q2)*sin(q0)*sin(q1))/50;
% py=(cos(q0)* (side))/50 - (9*sin(q4)*(cos(q3)*(cos(q2)*sin(q0) + cos(q0)*sin(q1)*sin(q2)) - sin(q3)*(sin(q0)*sin(q2) - cos(q0)*cos(q2)*sin(q1))))/250 - (3*sin(q0))/200 - (11*sin(q0)*sin(q2))/50 - (11*cos(q3)*(sin(q0)*sin(q2) - cos(q0)*cos(q2)*sin(q1)))/50 - (11*sin(q3)*(cos(q2)*sin(q0) + cos(q0)*sin(q1)*sin(q2)))/50 - (9*cos(q4)*(cos(q3)*(sin(q0)*sin(q2) - cos(q0)*cos(q2)*sin(q1)) + sin(q3)*(cos(q2)*sin(q0) + cos(q0)*sin(q1)*sin(q2))))/250 + (23*cos(q0)*cos(q1)* (side))/1000 + (11*cos(q0)*cos(q2)*sin(q1))/50;
% pz=(23*(side)*sin(q1))/1000 - (11*cos(q1)*cos(q2))/50 - (9*cos(q4)*(cos(q1)*cos(q2)*cos(q3) - cos(q1)*sin(q2)*sin(q3)))/250 + (9*sin(q4)*(cos(q1)*cos(q2)*sin(q3) + cos(q1)*cos(q3)*sin(q2)))/250 - (11*cos(q1)*cos(q2)*cos(q3))/50 + (11*cos(q1)*sin(q2)*sin(q3))/50 - 3.0/50.0;

%%对位置求导

jfx0=diff(px,q0);
jfx1=diff(px,q1);
jfx2=diff(px,q2);
jfx3=diff(px,q3);
jfx4=diff(px,q4);

jfy0=diff(py,q0);
jfy1=diff(py,q1);
jfy2=diff(py,q2);
jfy3=diff(py,q3);
jfy4=diff(py,q4);


jfz0=diff(pz,q0);
jfz1=diff(pz,q1);
jfz2=diff(pz,q2);
jfz3=diff(pz,q3);
jfz4=diff(pz,q4);

% 打开一个文本文件用于写入
fileID = fopen('matlab生成hector求雅可比.txt', 'w');

fprintf(fileID, 'if(J_f_m)\n');
fprintf(fileID, '{\n');
fprintf(fileID, 'J_f_m->operator()(0, 0) = %s;\n', char(jfx0));
fprintf(fileID, 'J_f_m->operator()(1, 0) = %s;\n', char(jfy0));
fprintf(fileID, 'J_f_m->operator()(2, 0) = %s;\n', char(jfz0));%x,y,z分别对q0求导
fprintf(fileID, 'J_f_m->operator()(3, 0) = 0.0;\n');
fprintf(fileID, 'J_f_m->operator()(4, 0) = 0.0;\n');
fprintf(fileID, 'J_f_m->operator()(5, 0) = 1.0;\n');
fprintf(fileID, '\n');

fprintf(fileID, 'J_f_m->operator()(0, 1) = %s;\n', char(jfx1));
fprintf(fileID, 'J_f_m->operator()(1, 1) = %s;\n', char(jfy1));
fprintf(fileID, 'J_f_m->operator()(2, 1) = %s;\n', char(jfz1));%x,y,z分别对q1求导
fprintf(fileID, 'J_f_m->operator()(3, 1) = cos(q0);\n');
fprintf(fileID, 'J_f_m->operator()(4, 1) = sin(q0);\n');
fprintf(fileID, 'J_f_m->operator()(5, 1) = 0.0;\n');
fprintf(fileID, '\n');

fprintf(fileID, 'J_f_m->operator()(0, 2) = %s;\n', char(jfx2));
fprintf(fileID, 'J_f_m->operator()(1, 2) = %s;\n', char(jfy2));
fprintf(fileID, 'J_f_m->operator()(2, 2) = %s;\n', char(jfz2));%x,y,z分别对q2求导
fprintf(fileID, 'J_f_m->operator()(3, 2) = -cos(q1)*sin(q0);\n');
fprintf(fileID, 'J_f_m->operator()(4, 2) = cos(q0)*cos(q1);\n');
fprintf(fileID, 'J_f_m->operator()(5, 2) = sin(q1);\n');
fprintf(fileID, '\n');

fprintf(fileID, 'J_f_m->operator()(0, 3) = %s;\n', char(jfx3));
fprintf(fileID, 'J_f_m->operator()(1, 3) = %s;\n', char(jfy3));
fprintf(fileID, 'J_f_m->operator()(2, 3) = %s;\n', char(jfz3));%x,y,z分别对q3求导
fprintf(fileID, 'J_f_m->operator()(3, 3) = -cos(q1)*sin(q0);\n');
fprintf(fileID, 'J_f_m->operator()(4, 3) = cos(q0)*cos(q1);\n');
fprintf(fileID, 'J_f_m->operator()(5, 3) = sin(q1);\n');
fprintf(fileID, '\n');

fprintf(fileID, 'J_f_m->operator()(0, 4) = %s;\n', char(jfx4));
fprintf(fileID, 'J_f_m->operator()(1, 4) = %s;\n', char(jfy4));
fprintf(fileID, 'J_f_m->operator()(2, 4) = %s;\n', char(jfz4));%x,y,z分别对q4求导
fprintf(fileID, 'J_f_m->operator()(3, 4) = -cos(q1)*sin(q0);\n');
fprintf(fileID, 'J_f_m->operator()(4, 4) = cos(q0)*cos(q1);\n');
fprintf(fileID, 'J_f_m->operator()(5, 4) = sin(q1);\n');
fprintf(fileID, '}\n');
fprintf(fileID, 'if(J_f)\n');
fprintf(fileID, '{\n');
fprintf(fileID, 'J_f->operator()(0, 0) = %s;\n', char(jfx0));
fprintf(fileID, 'J_f->operator()(1, 0) = %s;\n', char(jfy0));
fprintf(fileID, 'J_f->operator()(2, 0) = %s;\n', char(jfz0));%x,y,z分别对q0求导
fprintf(fileID, '\n');
fprintf(fileID, 'J_f->operator()(0, 1) = %s;\n', char(jfx1));
fprintf(fileID, 'J_f->operator()(1, 1) = %s;\n', char(jfy1));
fprintf(fileID, 'J_f->operator()(2, 1) = %s;\n', char(jfz1));%x,y,z分别对q1求导
fprintf(fileID, '\n');
fprintf(fileID, 'J_f->operator()(0, 2) = %s;\n', char(jfx2));
fprintf(fileID, 'J_f->operator()(1, 2) = %s;\n', char(jfy2));
fprintf(fileID, 'J_f->operator()(2, 2) = %s;\n', char(jfz2));%x,y,z分别对q2求导
fprintf(fileID, '\n');
fprintf(fileID, 'J_f->operator()(0, 3) = %s;\n', char(jfx3));
fprintf(fileID, 'J_f->operator()(1, 3) = %s;\n', char(jfy3));
fprintf(fileID, 'J_f->operator()(2, 3) = %s;\n', char(jfz3));%x,y,z分别对q3求导
fprintf(fileID, '\n');
fprintf(fileID, 'J_f->operator()(0, 4) = %s;\n', char(jfx4));
fprintf(fileID, 'J_f->operator()(1, 4) = %s;\n', char(jfy4));
fprintf(fileID, 'J_f->operator()(2, 4) = %s;\n', char(jfz4));%x,y,z分别对q4求导
fprintf(fileID, '}\n');
% 将力的分量写入文件
fprintf(fileID, 'if(p)\n');
fprintf(fileID, '{\n');
fprintf(fileID, 'p->operator()(0) = %s;\n', char(px));
fprintf(fileID, 'p->operator()(1) = %s;\n', char(py));
fprintf(fileID, 'p->operator()(2) = %s;\n', char(pz));
fprintf(fileID, '}\n');




% 关闭文件
fclose(fileID);


 % 
  cc= k(1,4);
  d_cc=diff(cc,q0);


% q_0 = pi/4;
% q_1=pi/6;
% q_2=pi/2;
% q_3=pi/4;
% q_4=pi/5;
% side_=1;
% mm=sin(q0)*(0.04*sin(q2 + q3 + q4) + 0.22*sin(q2 + q3) + 0.22*sin(q2) + 0.0135) + cos(q0)*(0.015*side + cos(q1)*(0.018*side + 0.0025) - 1.0*sin(q1)*(0.04*cos(q2 + q3 + q4) + 0.22*cos(q2 + q3) + 0.22*cos(q2)));
% mm_value=double (subs(mm,[q0,q1,q2,q3,q4,side],[q_0,q_1,q_2,q_3,q_4,side_]));
% cc_value=double(subs(d_cc,[q0,q1,q2,q3,q4,side],[q_0,q_1,q_2,q_3,q_4,side_]));
% pp=cc_value-mm_value;
% % disp(mm_value);
% % disp(cc_value);

% 
% % 创建一个示例4x4矩阵
% a0=trans(-0.015,0.02,-0.06);
% a1=trans(0,0.023,0);
% a2=trans(0,0,-0.22);
% a3=trans(0,0,-0.22);
% a4=trans(0,0,-0.036);
% % Open a text file for writing
% fileID = fopen('transformation_matrices.txt', 'w');
% 
% % Write each matrix to the file
% fprintf(fileID, 'Transformation Matrix a0:\n');
% fprintf(fileID, '%g\t%g\t%g\t%g\n', a0.');
% 
% fprintf(fileID, 'Transformation Matrix a1:\n');
% fprintf(fileID, '%g\t%g\t%g\t%g\n', a1.');
% 
% fprintf(fileID, 'Transformation Matrix a2:\n');
% fprintf(fileID, '%g\t%g\t%g\t%g\n', a2.');
% 
% fprintf(fileID, 'Transformation Matrix a3:\n');
% fprintf(fileID, '%g\t%g\t%g\t%g\n', a3.');
% 
% fprintf(fileID, 'Transformation Matrix a4:\n');
% fprintf(fileID, '%g\t%g\t%g\t%g\n', a4.');
% 
% % Close the file
% fclose(fileID);


function T = rotate2_x(theta)
    R = rotx(theta);
    T = eye(4);
    T(1:3,1:3)=R;

end


function R = rotate_z(theta)
    % 使用符号变量
    syms t real;

    % 构建绕 Z 轴的旋转矩阵
    R = [cos(t), -sin(t), 0,0;
         sin(t), cos(t), 0,0;
         0, 0, 1,0;
         0,0,0,1];

    % 用实际角度替代符号变量
    R = subs(R, t, theta);
end





function R = rotate_y(theta)
    % 使用符号变量
    syms t real;

    % 构建绕 Y 轴的旋转矩阵
    R = [cos(t), 0,sin(t), 0;
           0   , 1,  0   , 0;
         -sin(t),0,cos(t), 0;
         0,      0,     0, 1];

    % 用实际角度替代符号变量
    R = subs(R, t, theta);
end

function R = rotate_x(theta)
    % 使用符号变量
    syms t real;

    % 构建绕 X 轴的旋转矩阵
    R = [1, 0, 0,0;
         0, cos(t), -sin(t),0;
         0, sin(t), cos(t),0;
         0,0,0,1];

    % 用实际角度替代符号变量
    R = subs(R, t, theta);
end

function T = trans(x, y, z)
    % 创建平移矩阵
    T = makehgtform('translate', [x, y, z]);
end
