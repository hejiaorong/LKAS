C = who; %按字母顺序列出当前活动工作区中的所有变量的名称
PSA1_Num=0;
Sensor_Num=0;
Time_Num=0;
for k=1:length(C)
      if isequal(C{k},'GW_550_PSA1__LKA_main_switch')
      PSA1_Num=1;  
      end
      if isequal(C{k},'Video_Lane_Left_A__C0_5FA')
      Sensor_Num=1;  
      end
      if isequal(C{k},'Time')
      Time_Num=1;
      end
end
%判断变量中是否有时间参数
if Time_Num~=1
   Time = 0:0.01:10;
   Time = Time'; 
end
Time_len=length(Time);   
%添加缺少的CAN数据 
if  PSA1_Num==1&&Sensor_Num==1
    fprintf('2.文件包含PSA1_CAN和Sensor_CAN数据；\n')
elseif PSA1_Num==1&&Sensor_Num==0
      Video_Lane_Left_A__C3_5FA = zeros(Time_len,1);
      Video_Lane_Left_A__C2_5FA = zeros(Time_len,1);
      Video_Lane_Left_A__C1_5FA = zeros(Time_len,1);
      Video_Lane_Left_A__C0_5FA = zeros(Time_len,1)-2;
      Video_Lane_Left_A__Quality_5FA = zeros(Time_len,1)+3;
      Video_Lane_Left_A__Line_Type_5FA = zeros(Time_len,1);
      Video_Lane_Left_B__View_Range_5FC = zeros(Time_len,1);
      Video_Lane_Left_B__TLC_5FC = zeros(Time_len,1);
      Video_Lane_Right_A__C3_5FD = zeros(Time_len,1);
      Video_Lane_Right_A__C2_5FD = zeros(Time_len,1);
      Video_Lane_Right_A__C1_5FD = zeros(Time_len,1);
      Video_Lane_Right_A__C0_5FD = zeros(Time_len,1)+2;
      Video_Lane_Right_A__Quality_5FD = zeros(Time_len,1)+3;
      Video_Lane_Right_A__Line_Type_5FD = zeros(Time_len,1);
      Video_Lane_Right_B__View_Range_5FF = zeros(Time_len,1);
      Video_Lane_Right_B__TLC_5FF = zeros(Time_len,1);
      fprintf('2.已添加Sensor_CAN数据；\n');
elseif PSA1_Num==1&&Sensor_Num==0
      GW_550_PSA1__LKA_main_switch = ones(Time_len,1);
      GW_550_PSA1__LC_Mode = zeros(Time_len,1);
      EPS_495_PSA1__State_of_EPS_for_LKA_function = zeros(Time_len,1);
      EPS_495_PSA1__Steering_wheel_torque = zeros(Time_len,1);
      ESC_3CD_PSA1__Lateral_acceleration = zeros(Time_len,1);
      ESC_3CD_PSA1__Yaw_speed = zeros(Time_len,1);
      ESC_38D_PSA1__Vehicle_speed_of_wheelsensor = zeros(Time_len,1);
      GW_32D_PSA1__ACCEL_LONGI_CALIB = zeros(Time_len,1);
      ESC_3CD_PSA1__TMC_pressure = zeros(Time_len,1);
      EPS_305_PSA1__Steering_wheel_angle = zeros(Time_len,1);
      EPS_305_PSA1__Steering_wheel_rotation_speed = zeros(Time_len,1);
      GW_452_PSA1__BCM_Status_Indicator = zeros(Time_len,1);
      GW_349_PSA1__TCU_Gear_lever_position = zeros(Time_len,1);
      fprintf('2.已添加PSA1_CAN数据；\n');
else
      Video_Lane_Left_A__C3_5FA = zeros(Time_len,1);
      Video_Lane_Left_A__C2_5FA = zeros(Time_len,1);
      Video_Lane_Left_A__C1_5FA = zeros(Time_len,1);
      Video_Lane_Left_A__C0_5FA = zeros(Time_len,1)-2;
      Video_Lane_Left_A__Quality_5FA = zeros(Time_len,1)+3;
      Video_Lane_Left_A__Line_Type_5FA = zeros(Time_len,1);
      Video_Lane_Left_B__View_Range_5FC = zeros(Time_len,1);
      Video_Lane_Left_B__TLC_5FC = zeros(Time_len,1);
      Video_Lane_Right_A__C3_5FD = zeros(Time_len,1);
      Video_Lane_Right_A__C2_5FD = zeros(Time_len,1);
      Video_Lane_Right_A__C1_5FD = zeros(Time_len,1);
      Video_Lane_Right_A__C0_5FD = zeros(Time_len,1)+2;
      Video_Lane_Right_A__Quality_5FD = zeros(Time_len,1)+3;
      Video_Lane_Right_A__Line_Type_5FD = zeros(Time_len,1);
      Video_Lane_Right_B__View_Range_5FF = zeros(Time_len,1);
      Video_Lane_Right_B__TLC_5FF = zeros(Time_len,1);  
      GW_550_PSA1__LKA_main_switch = ones(Time_len,1);
      GW_550_PSA1__LC_Mode = zeros(Time_len,1);
      EPS_495_PSA1__State_of_EPS_for_LKA_function = zeros(Time_len,1);
      EPS_495_PSA1__Steering_wheel_torque = zeros(Time_len,1);
      ESC_3CD_PSA1__Lateral_acceleration = zeros(Time_len,1);
      ESC_3CD_PSA1__Yaw_speed = zeros(Time_len,1);
      ESC_38D_PSA1__Vehicle_speed_of_wheelsensor = zeros(Time_len,1);
      GW_32D_PSA1__ACCEL_LONGI_CALIB = zeros(Time_len,1);
      ESC_3CD_PSA1__TMC_pressure = zeros(Time_len,1);
      EPS_305_PSA1__Steering_wheel_angle = zeros(Time_len,1);
      EPS_305_PSA1__Steering_wheel_rotation_speed = zeros(Time_len,1);
      GW_452_PSA1__BCM_Status_Indicator = zeros(Time_len,1);
      GW_349_PSA1__TCU_Gear_lever_position = zeros(Time_len,1);
      fprintf('2.已添加PSA1_CAN和Sensor_CAN数据；\n');
end
clear('C','filename', 'filepath', 'k', 'PSA1_Num', 'Sensor_Num', 'Time_len', 'Time_Num');