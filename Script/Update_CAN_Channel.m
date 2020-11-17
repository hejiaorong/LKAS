eval('clear all');
eval('clc');
%% 1.打开LKAS_RealTime
try
    open_system('LKAS');
    sltest.harness.open('LKAS/LKAS/LL','LKAS_RealTime');
catch
    return;
end
%% 2.获取CAN Configuration设备名称
Channel1= get_param('LKAS_RealTime/CAN Configuration','Device');
Channel2= get_param('LKAS_RealTime/CAN Configuration1','Device');
%% 3.更新CAN_Recive通道
CAN_Recive = find_system('LKAS_RealTime/SignalBusCreator','SearchDepth',2);
CAN_Recive_Num=size(CAN_Recive);
for k=1:CAN_Recive_Num
a{k}=CAN_Recive{k}(end-6:end);
CAN_Recive_Name{k}=a{k}(1:6);
if isequal (CAN_Recive_Name{k},'Sensor') 
    set_param(CAN_Recive{k},'Device',Channel2);
elseif isequal (CAN_Recive_Name{k},'PSACAN')
    set_param(CAN_Recive{k},'Device',Channel1);
else
  continue
end
end
fprintf('1.已完成CAN_Recive通道更新;\n');
%% 4.更新CAN_Transmit通道
CAN_Transmit = find_system('LKAS_RealTime/LLOut','SearchDepth',2);
CAN_Transmit_Num=size(CAN_Transmit);
for i=1:CAN_Transmit_Num
CAN_Transmit_Len=length(CAN_Transmit{i});
CAN_Transmit_Name=CAN_Transmit{i}(1:CAN_Transmit_Len-1);
if isequal (CAN_Transmit_Name,'LKAS_RealTime/LLOut/Monitor') 
    set_param(CAN_Transmit{i},'Device',Channel2);
elseif isequal (CAN_Transmit_Name,'LKAS_RealTime/LLOut/Control')
    set_param(CAN_Transmit{i},'Device',Channel1);
else
     continue
end
end
fprintf('2.已完成CAN_Transmit通道更新;\n');
delete_line('LKAS_RealTime','LLClb/1','bsLLClb/1');
delete_block(strcat('LKAS_RealTime','/','LLClb'));
add_block(strcat('LKAS','/','LKAS','/','LLClb'),strcat('LKAS_RealTime','/LLClb'),'Position',[100 415 350 515]);
add_line('LKAS_RealTime','LLClb/1','bsLLClb/1');
eval('clear all');


