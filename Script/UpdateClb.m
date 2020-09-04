eval('clear all');
eval('clc');
%% 1.打开模型并获取标定量名称
path = cd;
scriptpath = strcat(path,'\Script');
getFileName=ls(strcat(scriptpath,'\*.slx')); %  *脚本和slx放在同一个文件夹该文件夹下有且只有一个slx文件
FileNum = size(getFileName);
if  isequal(getFileName,'') % 防止选择空文件夹
    fprintf('当前目录下没有找到*.slx文件\n');
    eval('clear all');
    return;
elseif  FileNum ~= 1
    fprintf('当前目录下存在不止1个*.slx文件\n');
    eval('clear all');
    return;
else
    fprintf('1.您的目标*.slx文件是:[%s]\n',getFileName);
end
filename = getFileName(1:length(getFileName)-4);    %获取slx文件名
warning('off');
open_system(strcat(filename,'/CAN Monitor (CANMon)/Monitor'));
Monitor = find_system(strcat(filename,'/CAN Monitor (CANMon)/Monitor'),'SearchDepth',1,'BlockType','From');
MonitorNum = size(Monitor);
for i = 1:MonitorNum(1)
    Monitor(i) = get_param(Monitor(i),'GotoTag');
%     set_param(Monitor{i},'GotoTag','CLB_LKASWASyn_M0')
end